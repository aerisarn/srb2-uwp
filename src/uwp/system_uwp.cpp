#include <filesystem>
#include <fstream>
#include <string>

#include <wrl.h>
#include <wrl/client.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include <pix.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <memory>
#include <vector>
#include <agile.h>
#include <concrt.h>



using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

std::string PlatformToStd(Platform::String^ inStr) {
	std::wstring str2(inStr->Begin());
	std::string str3(str2.begin(), str2.end());
	return str3;
}

Platform::String^ StdToPlatform(std::string inStr) {
	std::wstring wid_str = std::wstring(inStr.begin(), inStr.end());
	const wchar_t* w_char = wid_str.c_str();
	return ref new Platform::String(w_char);
}

std::string uwp_GetCWD()
{
    char maxPath[MAX_PATH];
    GetCurrentDirectoryA(sizeof(maxPath), maxPath);
    return maxPath;
}

std::string PickAFolder();

std::string local_app_data;

extern "C" const char* uwp_GetAppDataPath()
{
    std::string local_state = PlatformToStd(Windows::Storage::ApplicationData::Current->LocalFolder->Path);
    std::error_code error_code;
    if (std::filesystem::exists(local_state, error_code) && 
        std::filesystem::is_directory(local_state, error_code) && 
        !error_code)
    {
        std::filesystem::path app_data_redirect_file = local_state; app_data_redirect_file /= "redirect_appdata.txt";
        if (!std::filesystem::exists(app_data_redirect_file, error_code) ||
            !std::filesystem::is_regular_file(app_data_redirect_file, error_code) ||
            error_code)
        {
            std::filesystem::path new_path = PickAFolder();
            if (std::filesystem::exists(new_path, error_code) &&
                std::filesystem::is_directory(new_path, error_code) &&
                !error_code)
            {
                std::ofstream redirect_file_stream(app_data_redirect_file.string(), std::ios::trunc);
                redirect_file_stream << new_path.string() << std::endl;
            }
            else {
                std::ofstream redirect_file_stream(app_data_redirect_file.string(), std::ios::trunc);
                redirect_file_stream << local_state << std::endl;
            }
        }
        std::ifstream redirect_file_stream(app_data_redirect_file.string());
        std::string appdata;
        if (std::getline(redirect_file_stream, appdata) &&
            std::filesystem::exists(appdata, error_code) && 
            !error_code)
        {
            local_app_data = appdata;
            return local_app_data.c_str();
        }
    }

    local_app_data = PlatformToStd(Windows::Storage::ApplicationData::Current->LocalFolder->Path);

    return local_app_data.c_str();
}

unsigned int GenerateRandomNumber()
{
    // Generate a random number.
    unsigned int random = Windows::Security::Cryptography::CryptographicBuffer::GenerateRandomNumber();
    return random;
}

unsigned int uwp_MakeRNGSeed()
{
    return GenerateRandomNumber();
}

template <typename T>
void WaitForAsync(IAsyncOperation<T>^ A)
{
    while (A->Status == Windows::Foundation::AsyncStatus::Started) {
        CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
    }

    Windows::Foundation::AsyncStatus S = A->Status;
}

std::string PickAFolder()
{
    std::string out = "";
    auto folderPicker = ref new Windows::Storage::Pickers::FolderPicker();
    folderPicker->SuggestedStartLocation = Windows::Storage::Pickers::PickerLocationId::Desktop;
    folderPicker->FileTypeFilter->Append("*");

    auto folder_operation = folderPicker->PickSingleFolderAsync();
    WaitForAsync(folder_operation);
    auto folder = folder_operation->GetResults();
    if (folder != nullptr) {
        // Application now has read/write access to all contents in the picked file
        Windows::Storage::AccessCache::StorageApplicationPermissions::FutureAccessList->AddOrReplace("PickedFolderToken", folder);
        auto selected = folder->Path;
        out = std::string(selected->Begin(), selected->End());
    }
    return out;
}

inline float ConvertDipsToPixels(float dips, float dpi)
{
    static const float dipsPerInch = 96.0f;
    return floorf(dips * dpi / dipsPerInch + 0.5f); // Arrotonda all'intero più vicino.
}

bool is_running_on_xbox(void)
{
    Platform::String^ device_family = Windows::System::Profile::AnalyticsInfo::VersionInfo->DeviceFamily;
    return (device_family == L"Windows.Xbox");
}

extern "C" int uwp_get_height(void)
{
    /* This function must be performed within UI thread,
     * otherwise it will cause a crash in specific cases
     * https://github.com/libretro/RetroArch/issues/13491 */
    float surface_scale = 0;
    int ret = -1;
    volatile bool finished = false;
    Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(
        CoreDispatcherPriority::Normal,
        ref new Windows::UI::Core::DispatchedHandler([&surface_scale, &ret, &finished]()
            {
                if (is_running_on_xbox())
                {
                    const Windows::Graphics::Display::Core::HdmiDisplayInformation^ hdi = Windows::Graphics::Display::Core::HdmiDisplayInformation::GetForCurrentView();
                    if (hdi)
                        ret = Windows::Graphics::Display::Core::HdmiDisplayInformation::GetForCurrentView()->GetCurrentDisplayMode()->ResolutionHeightInRawPixels;
                }

                if (ret == -1)
                {
                    const LONG32 resolution_scale = static_cast<LONG32>(Windows::Graphics::Display::DisplayInformation::GetForCurrentView()->ResolutionScale);
                    surface_scale = static_cast<float>(resolution_scale) / 100.0f;
                    ret = static_cast<LONG32>(
                        CoreWindow::GetForCurrentThread()->Bounds.Height
                        * surface_scale);
                }
                finished = true;
            }));
    Windows::UI::Core::CoreWindow^ corewindow = Windows::UI::Core::CoreWindow::GetForCurrentThread();
    while (!finished)
    {
        if (corewindow)
            corewindow->Dispatcher->ProcessEvents(Windows::UI::Core::CoreProcessEventsOption::ProcessAllIfPresent);
    }
    return ret;
}

extern "C" int uwp_get_width(void)
{
    /* This function must be performed within UI thread,
     * otherwise it will cause a crash in specific cases
     * https://github.com/libretro/RetroArch/issues/13491 */
    float surface_scale = 0;
    int returnValue = -1;
    volatile bool finished = false;
    Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(
        CoreDispatcherPriority::Normal,
        ref new Windows::UI::Core::DispatchedHandler([&surface_scale, &returnValue, &finished]()
            {
                if (is_running_on_xbox())
                {
                    const Windows::Graphics::Display::Core::HdmiDisplayInformation^ hdi = Windows::Graphics::Display::Core::HdmiDisplayInformation::GetForCurrentView();
                    if (hdi)
                        returnValue = Windows::Graphics::Display::Core::HdmiDisplayInformation::GetForCurrentView()->GetCurrentDisplayMode()->ResolutionWidthInRawPixels;
                }

                if (returnValue == -1)
                {
                    const LONG32 resolution_scale = static_cast<LONG32>(Windows::Graphics::Display::DisplayInformation::GetForCurrentView()->ResolutionScale);
                    surface_scale = static_cast<float>(resolution_scale) / 100.0f;
                    returnValue = static_cast<LONG32>(
                        CoreWindow::GetForCurrentThread()->Bounds.Width
                        * surface_scale);
                }
                finished = true;
            }));
    Windows::UI::Core::CoreWindow^ corewindow = Windows::UI::Core::CoreWindow::GetForCurrentThread();
    while (!finished)
    {
        if (corewindow)
            corewindow->Dispatcher->ProcessEvents(Windows::UI::Core::CoreProcessEventsOption::ProcessAllIfPresent);
    }

    return returnValue;
}