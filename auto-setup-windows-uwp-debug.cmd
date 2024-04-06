@echo off
goto aftercopyright

**
** auto-setup-windows-arm.cmd
** Automatic (easy) setup and build script for Windows ARM (cross compiling on x64) - please have a
** build of x64 in your build folder ready before executing this script!
**
** Note that this script assumes you have both 'git' and 'cmake' installed properly and in your PATH!
** This script also assumes you have installed a build system that cmake can automatically detect.
** Such as Visual Studio Community. Requires appropriate SDK installed too!
** Without these items, this script will FAIL! So make sure you have your build environment properly
** set up in order for this script to succeed.
**
** The purpose of this script is to get someone easily going with a full working compile of GZDoom.
** This allows anyone to make simple changes or tweaks to the engine as they see fit and easily
** compile their own copy without having to follow complex instructions to get it working.
** Every build environment is different, and every computer system is different - this should work
** in most typical systems under Windows but it may fail under certain types of systems or conditions.
** Not guaranteed to work and your mileage will vary.
**
**---------------------------------------------------------------------------
** Copyright 2024 Rachael Alexanderson and the GZDoom team
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**---------------------------------------------------------------------------
**

:aftercopyright


setlocal
rem -- Always operate within the build-arm folder
if not exist "%~dp0\build-uwp-debug" mkdir "%~dp0\build-uwp-debug"
pushd "%~dp0\build-uwp-debug"

if exist ..\build\vcpkg if exist ..\build\vcpkg\* git -C ../build/vcpkg pull

if not exist mesa-uwp (
	mkdir mesa-uwp
	pushd mesa-uwp
	curl.exe -o alpha-2-resfix.zip -L0 https://github.com/aerisarn/mesa-uwp/releases/download/alpha-2-resfix/alpha-2-resfix.zip
	tar -xf alpha-2-resfix.zip
	popd
)

if exist sdl-uwp-gl if exist sdl-uwp-gl\* git -C ./sdl-uwp-gl pull
if not exist sdl-uwp-gl git clone https://github.com/aerisarn/SDL-uwp-gl.git

MSBuild.exe sdl-uwp-gl/VisualC-WinRT/SDL-UWP.sln /property:Configuration=Debug

mkdir "%~dp0\build-uwp-debug\vcpkg_installed"

cmake -S .. -B . ^
	-DVCPKG_TARGET_TRIPLET="x64-uwp-static-md" ^
	-DCMAKE_TOOLCHAIN_FILE=../build/vcpkg/scripts/buildsystems/vcpkg.cmake ^
	-DVCPKG_INSTALLLED_DIR=./vcpkg_installed/ ^
	-DFORCE_CROSSCOMPILE=TRUE ^
	-DCMAKE_SYSTEM_NAME="WindowsStore" ^
	-DCMAKE_SYSTEM_VERSION="10.0" ^
	-DCMAKE_BUILD_TYPE=Debug
rem cmake --build . --config Release -- -maxcpucount -verbosity:minimal

rem -- If successful, show the build	
rem if exist Release\gzdoom.exe explorer.exe Release

