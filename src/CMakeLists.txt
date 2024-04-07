include(clang-tidy-default)

add_executable(SRB2SDL2 MACOSX_BUNDLE WIN32
	comptime.c
	md5.c
	config.h.in
	string.c
	d_main.c
	d_clisrv.c
	d_net.c
	d_netfil.c
	d_netcmd.c
	dehacked.c
	deh_soc.c
	deh_lua.c
	deh_tables.c
	z_zone.c
	f_finale.c
	f_wipe.c
	g_demo.c
	g_game.c
	g_input.c
	am_map.c
	command.c
	console.c
	hu_stuff.c
	i_time.c
	y_inter.c
	st_stuff.c
	m_aatree.c
	m_anigif.c
	m_argv.c
	m_bbox.c
	m_cheat.c
	m_cond.c
	m_easing.c
	m_fixed.c
	m_menu.c
	m_misc.c
	m_perfstats.c
	m_random.c
	m_queue.c
	info.c
	p_ceilng.c
	p_enemy.c
	p_floor.c
	p_inter.c
	p_lights.c
	p_map.c
	p_maputl.c
	p_mobj.c
	p_polyobj.c
	p_saveg.c
	p_setup.c
	p_sight.c
	p_spec.c
	p_telept.c
	p_tick.c
	p_user.c
	p_slopes.c
	tables.c
	r_bsp.c
	r_data.c
	r_draw.c
	r_fps.c
	r_main.c
	r_plane.c
	r_segs.c
	r_skins.c
	r_sky.c
	r_splats.c
	r_things.c
	r_bbox.c
	r_textures.c
	r_patch.c
	r_patchrotation.c
	r_picformats.c
	r_portal.c
	screen.c
	taglist.c
	v_video.c
	s_sound.c
	sounds.c
	w_wad.c
	filesrch.c
	mserv.c
	http-mserv.c
	i_tcp.c
	lzf.c
	b_bot.c
	u_list.c
	lua_script.c
	lua_baselib.c
	lua_mathlib.c
	lua_hooklib.c
	lua_consolelib.c
	lua_infolib.c
	lua_mobjlib.c
	lua_playerlib.c
	lua_skinlib.c
	lua_thinkerlib.c
	lua_maplib.c
	lua_taglib.c
	lua_polyobjlib.c
	lua_blockmaplib.c
	lua_hudlib.c
	lua_hudlib_drawlist.c
	lua_inputlib.c
)

#Thanks flyinghead
if (CMAKE_SYSTEM_NAME STREQUAL "WindowsStore")
	message("Adding UWP resources")
	message("SDL2_LIBRARY:" ${SDL2_LIBRARY})

	set(ResourceFiles 
		uwp/Package.appxmanifest
		uwp/SRB2_TemporaryKey.pfx
		${CMAKE_BINARY_DIR}/SDL-uwp-gl/src/main/winrt/SDL2-WinRTResource_BlankCursor.cur
		${CMAKE_BINARY_DIR}/SDL-uwp-gl/src/main/winrt/SDL2-WinRTResources.rc
	)

	set(AssetFiles
		uwp/assets/LockScreenLogo.scale-200.png
		uwp/assets/SplashScreen.scale-200.png
		uwp/assets/Square44x44Logo.scale-200.png
		uwp/assets/Square44x44Logo.targetsize-24_altform-unplated.png
		uwp/assets/Square150x150Logo.scale-200.png
		uwp/assets/StoreLogo.png
		uwp/assets/Wide310x150Logo.scale-200.png
	)
	
	set(ModelsBOSS
${CMAKE_SOURCE_DIR}/assets/models/BOSS/BRAK.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/BRAK_blend.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGM.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGM_blend.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGN.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGN_blend.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGO.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGO_blend.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGP.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGP_blend.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGR1.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGR1_blend.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/METL.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/METL_blend.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/SEBH.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/TANK.png
${CMAKE_SOURCE_DIR}/assets/models/BOSS/BRAK.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGM.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGN.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGO.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGGP.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/EGR1.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/METL.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/SEBH.md3
${CMAKE_SOURCE_DIR}/assets/models/BOSS/TANK.md3
	)

	set(ModelsENMY
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ARCH.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ARCH_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BGOM.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BMNE.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BRKN.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BUMB.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BUMB_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BUZZ.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BUZZ_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CACO.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CANA.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CANA_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CBBS.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CBFS.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CBFS_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CCOM.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CCOM_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CR2B.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CR2B_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CRAB.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CRAB_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CSTA.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DETN.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DETN_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DRAB.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DRAB_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DRIL.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ESHI.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ESHI_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/FAKE.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/FISH.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/FISH_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/FLSH.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GOOM.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GSNH.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GSNL.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GSNP.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GSNP_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/HBAT.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/HBAT_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/HIVE.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/HIVE_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JETB.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JETB_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JETG.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JETG_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JJAW.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JJAW_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/MEDR.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/MNUS.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/MNUS_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PENG.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PENG_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PNTY.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PNTY_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/POPH.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/POPH_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/POSS.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/POSS_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PTER.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PTER_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PYRE.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PYRE_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/RBUZ.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/RBUZ_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ROBO3.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ROBO3_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/RSNP.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SBOB.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SBOB_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SFOT.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SHRP.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SHRP_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SKIM.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SKIM_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SNLR.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SNLR_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SPOS.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SPOS_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SPSH.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SPSH_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SSHL.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SSHL_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/TRET.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/TURR.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/TURR_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/UNID.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/UNID_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/VLTR.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/VLTR_blend.png
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ARCH.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BGOM.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BMNE.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BRKN.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BUMB.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/BUZZ.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CACO.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CANA.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CBBS.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CBFS.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CCOM.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CR2B.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CRAB.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/CSTA.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DETN.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DRAB.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/DRIL.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ESHI.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/FAKE.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/FISH.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/FLSH.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GOOM.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GSNH.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GSNL.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/GSNP.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/HBAT.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/HIVE.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JETB.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JETG.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/JJAW.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/MEDR.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/MNUS.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PENG.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PNTY.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/POPH.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/POSS.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PTER.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/PYRE.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/RBUZ.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/ROBO3.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/RSNP.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SBOB.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SFOT.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SHRP.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SKIM.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SNLR.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SPOS.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SPSH.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/SSHL.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/TRET.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/TURR.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/UNID.md3
${CMAKE_SOURCE_DIR}/assets/models/ENMY/VLTR.md3
	)

	set(ModelsOBJE
${CMAKE_SOURCE_DIR}/assets/models/OBJE/ARMB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/ARMF.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BAR2.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BARR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BGAR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BHSP.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BLNK.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BLON.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BMCE.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BMSL.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BOMB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSPB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSPR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSTR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSTY.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BUBS.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BUMP.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CEMG.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/COIN.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CORK.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CRID.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CSPR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/EGGL.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/EMBM.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/ESTA.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FFWR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FIRE.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FLMS.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FMCE.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FUFO.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/GARG.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/GSHL.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/HMCE.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/IDYA.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/LVLA.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/MAGN.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/MCRT.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/MSTV.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/MSVT.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/NBMP.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/NDRN.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/OSHD.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/OSPR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/PBOM.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/PITY.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/PUMI.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RHSP.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RING.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RSPB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RSPR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SHED.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SHRD.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SIGN.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SMCE.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SOBB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SORB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPHR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRG.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRY.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/STPT.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TBRI.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/THNS.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/THOK.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TOKE.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TRRI.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TV1K.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TV1P.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TV1U.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVAR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVAT.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVBB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVEG.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVEL.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVFL.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVFO.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVGV.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVIV.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVMX.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVMY.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVPI.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVRC.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVRI.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVSS.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVTK.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVTU.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVWW.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVZP.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/USPK.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/VBRI.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/VRRI.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/WSPK.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/XLTV.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/YHSP.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/YSPB.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/YSPR.md3
${CMAKE_SOURCE_DIR}/assets/models/OBJE/ARMB.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/ARMF.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BAR2.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BARR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BGAR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BHSP.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BLON.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BLON_blend.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BMCE.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BMSL.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BOMB.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSPB.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSPR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSTR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BSTY.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/BUBS.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CEMG.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/COIN.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CORK.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CRID.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/CSPR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/EGGL.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/ESTA.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FFWR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FLMS.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FMCE.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/FUFO.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/GARG.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/GSHL.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/HMCE.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/MCRT.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/MSTV.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/MSVT.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/NBMP.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/OSHD.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/OSPR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/PITY.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/PITY_blend.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/PUMI.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/PUMI_blend.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RHSP.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RING.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RING_blend.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RSPB.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/RSPR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SHRD.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SIGN.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SIGN_blend.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SMCE.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPHR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRB.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRG.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/SPRY.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/STPT.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TBRI.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/THNS.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TOKE.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TRRI.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TV1K.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TV1P.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TV1U.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVAR.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVAT.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVBB.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVEG.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVEL.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVFL.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVFO.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVGV.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVIV.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVMX.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVMY.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVPI.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVRC.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVRI.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVSS.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVTK.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVTU.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVWW.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/TVZP.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/USPK.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/VBRI.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/VRRI.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/WPSK.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/WSPK.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/XLTV.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/YHSP.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/YSPB.png
${CMAKE_SOURCE_DIR}/assets/models/OBJE/YSPR.png
	)

	set(ModelsPLAY
${CMAKE_SOURCE_DIR}/assets/models/PLAY/AMY.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/AMY_blend.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/FANG.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/FANG_blend.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/KNUCKLES.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/KNUCKLES_blend.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/METAL_SONIC.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/METAL_SONIC_blend.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/SONIC.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/SONIC_blend.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/TAILS.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/TAILS_blend.png
${CMAKE_SOURCE_DIR}/assets/models/PLAY/AMY.md3
${CMAKE_SOURCE_DIR}/assets/models/PLAY/FANG.md3
${CMAKE_SOURCE_DIR}/assets/models/PLAY/KNUCKLES.md3
${CMAKE_SOURCE_DIR}/assets/models/PLAY/METAL_SONIC.md3
${CMAKE_SOURCE_DIR}/assets/models/PLAY/SONIC.md3
${CMAKE_SOURCE_DIR}/assets/models/PLAY/TAILS.md3
	)

	source_group("models\\BOSS" "${ModelsBOSS}") 
	source_group("models\\ENMY" "${ModelsENMY}") 
	source_group("models\\OBGE" "${ModelsOBGE}") 
	source_group("models\\PLAY" "${ModelsPLAY}") 

	set(DepFiles
		../assets/models.dat
		../assets/music.dta
		../assets/patch.pk3
		../assets/player.dta
		../assets/patch.pk3
		../assets/srb2.pk3
		../assets/zones.pk3	
		C:/Program\ Files\ \(x86\)/Windows\ Kits/10/Redist/D3D/x64/dxil.dll
		${CMAKE_BINARY_DIR}/mesa-uwp/opengl32.dll
		${CMAKE_BINARY_DIR}/mesa-uwp/libglapi.dll
		${CMAKE_BINARY_DIR}/mesa-uwp/libgallium_wgl.dll
		${CMAKE_BINARY_DIR}/mesa-uwp/z-1.dll
		${CMAKE_BINARY_DIR}/SDL-uwp-gl/VisualC-WinRT/x64/${CMAKE_BUILD_TYPE}/SDL-UWP/SDL2.dll
	)

	target_sources(SRB2SDL2 PRIVATE
		${ResourceFiles}
		${AssetFiles}
		${DepFiles}
		${ModelsBOSS}
		${ModelsENMY}
		${ModelsOBGE}
		${ModelsPLAY}
		uwp/system_uwp.cpp
		uwp/gamepad_uwp.cpp
		${CMAKE_BINARY_DIR}/SDL-uwp-gl/src/main/winrt/SDL_winrt_main_NonXAML.cpp)
	set_source_files_properties (uwp/system_uwp.cpp
		PROPERTIES COMPILE_OPTIONS "-permissive;-ZW")
	set_source_files_properties( uwp/system_uwp.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS TRUE )
	set_source_files_properties (${CMAKE_BINARY_DIR}/SDL-uwp-gl/src/main/winrt/SDL_winrt_main_NonXAML.cpp 
		PROPERTIES COMPILE_OPTIONS "-permissive;-ZW")
	set_source_files_properties( ${CMAKE_BINARY_DIR}/SDL-uwp-gl/src/main/winrt/SDL_winrt_main_NonXAML.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS TRUE )
	
	set_property(SOURCE ${AssetFiles} PROPERTY VS_DEPLOYMENT_CONTENT 1)
	set_property(SOURCE ${AssetFiles} PROPERTY VS_DEPLOYMENT_LOCATION "Assets")

	set_property(SOURCE ${DepFiles} PROPERTY VS_DEPLOYMENT_CONTENT 1)
	set_property(SOURCE ${DepFiles} PROPERTY VS_DEPLOYMENT_LOCATION ".")

	set_property(SOURCE ${ModelsBOSS} PROPERTY VS_DEPLOYMENT_CONTENT 1)
	set_property(SOURCE ${ModelsBOSS} PROPERTY VS_DEPLOYMENT_LOCATION "models/BOSS")

	set_property(SOURCE ${ModelsENMY} PROPERTY VS_DEPLOYMENT_CONTENT 1)
	set_property(SOURCE ${ModelsENMY} PROPERTY VS_DEPLOYMENT_LOCATION "models/ENMY")

	set_property(SOURCE ${ModelsOBGE} PROPERTY VS_DEPLOYMENT_CONTENT 1)
	set_property(SOURCE ${ModelsOBGE} PROPERTY VS_DEPLOYMENT_LOCATION "models/OBGE")

	set_property(SOURCE ${ModelsPLAY} PROPERTY VS_DEPLOYMENT_CONTENT 1)
	set_property(SOURCE ${ModelsPLAY} PROPERTY VS_DEPLOYMENT_LOCATION "models/PLAY")
	
	set_target_properties(SRB2SDL2 PROPERTIES RESOURCE 
		"${ResourceFiles} ${DepFiles} ${AssetFiles} ${ModelsBOSS} ${ModelsENMY} ${ModelsOBGE} ${ModelsPLAY}")
	
	target_link_options(SRB2SDL2 PRIVATE 
		/nodefaultlib:vccorlib$<$<CONFIG:Debug>:d>
		/nodefaultlib:msvcrt$<$<CONFIG:Debug>:d>
		vccorlib$<$<CONFIG:Debug>:d>.lib 
		msvcrt$<$<CONFIG:Debug>:d>.lib)
endif()

# This updates the modification time for comptime.c at the
# end of building so when the build system is ran next time,
# that file gets flagged. comptime.c will always be rebuilt.
#
# This begs the question, why always rebuild comptime.c?
# Some things like the git commit must be checked each time
# the program is built. But the build system determines which
# files should be rebuilt before anything else. So
# comptime.c, which only needs to be rebuilt based on
# information known at build time, must be told to rebuild
# before that information can be ascertained.
add_custom_command(
	TARGET SRB2SDL2
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E touch_nocreate ${CMAKE_CURRENT_SOURCE_DIR}/comptime.c
)

# config.h is generated by this command. It should be done at
# build time for accurate git information and before anything
# that needs it, obviously.
add_custom_target(_SRB2_reconf ALL
	COMMAND ${CMAKE_COMMAND} -DGIT_EXECUTABLE=${GIT_EXECUTABLE} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DBINARY_DIR=${CMAKE_CURRENT_BINARY_DIR}/.. -P ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Comptime.cmake
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
)
add_dependencies(SRB2SDL2 _SRB2_reconf)

if("${CMAKE_COMPILER_IS_GNUCC}" AND "${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
	target_link_options(SRB2SDL2 PRIVATE "-Wl,--disable-dynamicbase")
	if(NOT "${SRB2_CONFIG_STATIC_STDLIB}")
		# On MinGW with internal libraries, link the standard library statically
		target_link_options(SRB2SDL2 PRIVATE "-static")
	endif()
	if(CMAKE_SIZEOF_VOID_P EQUAL 4)
		target_link_options(SRB2SDL2 PRIVATE "-Wl,--large-address-aware")
	endif()
endif()

target_compile_features(SRB2SDL2 PRIVATE c_std_11 cxx_std_17)

### Configuration
set(SRB2_CONFIG_DEV_BUILD OFF CACHE BOOL
	"Compile a development build of SRB2.")

add_subdirectory(blua)

# OS macros
if (UNIX)
	target_compile_definitions(SRB2SDL2 PRIVATE -DUNIXCOMMON)
endif()

if (BSD MATCHES "FreeBSD")
	target_compile_definitions(SRB2SDL2 PRIVATE -DFREEBSD)
endif()

if(CMAKE_COMPILER_IS_GNUCC)
	find_program(OBJCOPY objcopy)
endif()

if("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
	target_compile_definitions(SRB2SDL2 PRIVATE -DLINUX)
	if(${SRB2_SYSTEM_BITS} EQUAL 64)
		target_compile_definitions(SRB2SDL2 PRIVATE -DLINUX64)
	endif()
endif()

if("${CMAKE_SYSTEM_NAME}" MATCHES "Darwin")
	target_compile_definitions(SRB2SDL2 PRIVATE -DMACOSX)
endif()

if("${SRB2_CONFIG_USE_GME}")
	target_link_libraries(SRB2SDL2 PRIVATE gme)
	target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_GME)
	if(NOT "${SRB2_CONFIG_SYSTEM_LIBRARIES}")
		# this sucks but gme doesn't use modern cmake to delineate public headers
		target_include_directories(SRB2SDL2 PRIVATE "${libgme_SOURCE_DIR}")
	endif()
endif()

target_compile_definitions(SRB2SDL2 PRIVATE -D_LARGEFILE64_SOURCE)

set(SRB2_HAVE_THREADS ON)
target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_THREADS)

if("${SRB2_CONFIG_HWRENDER}")
	target_compile_definitions(SRB2SDL2 PRIVATE -DHWRENDER)
	add_subdirectory(hardware)

	if("${SRB2_CONFIG_STATIC_OPENGL}")
		find_package(OpenGL)
		if(${OPENGL_FOUND})
			target_compile_definitions(SRB2SDL2 PRIVATE -DSTATIC_OPENGL)
		else()
			message(WARNING "You have specified static opengl but opengl was not found. Not setting HWRENDER.")
		endif()
	endif()
endif()

# Targets

# If using CCACHE, then force it.
# https://github.com/Cockatrice/Cockatrice/pull/3052/files
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Darwin")
	get_property(RULE_LAUNCH_COMPILE GLOBAL PROPERTY RULE_LAUNCH_COMPILE)
	if(RULE_LAUNCH_COMPILE)
		MESSAGE(STATUS "Force enabling CCache usage under macOS")
		# Set up wrapper scripts
		configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/launch-c.in   ${CMAKE_BINARY_DIR}/launch-c)
		configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/launch-cxx.in ${CMAKE_BINARY_DIR}/launch-cxx)
		execute_process(COMMAND chmod a+rx
			"${CMAKE_BINARY_DIR}/launch-c"
			"${CMAKE_BINARY_DIR}/launch-cxx")

		# Set Xcode project attributes to route compilation through our scripts
		set(CMAKE_XCODE_ATTRIBUTE_CC         "${CMAKE_BINARY_DIR}/launch-c")
		set(CMAKE_XCODE_ATTRIBUTE_CXX        "${CMAKE_BINARY_DIR}/launch-cxx")
		set(CMAKE_XCODE_ATTRIBUTE_LD         "${CMAKE_BINARY_DIR}/launch-c")
		set(CMAKE_XCODE_ATTRIBUTE_LDPLUSPLUS "${CMAKE_BINARY_DIR}/launch-cxx")
	endif()
endif()

# Compatibility flag with later versions of GCC
# We should really fix our code to not need this
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	if (CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|x64|amd64|AMD64|em64t|EM64T)")
		target_compile_options(SRB2SDL2 PRIVATE -mno-ms-bitfields)
	endif()
endif()

# Compiler warnings configuration
target_compile_options(SRB2SDL2 PRIVATE
	# Using generator expressions to handle per-language compile options

	# C, GNU
	# This is a direct translation from versions.mk
	$<$<AND:$<COMPILE_LANGUAGE:C>,$<C_COMPILER_ID:GNU>>:
		-Wall
		-Wextra
		-Wno-trigraphs
		-W # Was controlled by RELAXWARNINGS
		-Wfloat-equal
		-Wundef
		-Wpointer-arith
		-Wbad-function-cast
		-Wcast-qual
		-Wcast-align # Was controlled by NOCASTALIGNWARN
		-Wwrite-strings
		-Wsign-compare
		-Waggregate-return
		-Wmissing-prototypes
		-Wmissing-declarations
		-Wmissing-noreturn
		-Wnested-externs
		-Winline
		-Wformat-y2k
		-Wformat-security
		-fwrapv

		$<$<VERSION_LESS:$<C_COMPILER_VERSION>,2.9.5>:
			-Wno-div-by-zero
			-Wendif-labels
			-Wdisabled-optimization
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,4.0.0>:
			-Wold-style-definition
			-Wmissing-field-initializers
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,4.1.0>:
			-Wshadow
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,4.3.0>:
			-funit-at-a-time
			-Wlogical-op
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,4.5.0>:
			-Wlogical-op
			#-Wno-error=array-bounds
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,4.6.0>:
			-Wno-suggest-attribute=noreturn
			-Wno-error=suggest-attribute=noreturn
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,5.4.0>:
			-Wno-logical-op
			-Wno-error=logical-op
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,6.1.0>:
			-Wno-tautological-compare
			-Wno-error=tautological-compare
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,7.1.0>:
			-Wno-error=format-overflow=2
			-Wimplicit-fallthrough=4
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,8.1.0>:
			-Wno-error=format-overflow
			-Wno-format-overflow
			-Wno-error=multistatement-macros
		>

		$<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,9.1.0>:
			-Wno-error=address-of-packed-member
		>
	>

	# C, Clang and Apple Clang
	$<$<AND:$<COMPILE_LANGUAGE:C>,$<OR:$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:Clang>>>:
		-Wall
		-Wno-absolute-value
		-Wextra
		-Wno-trigraphs
		-Wconditional-uninitialized
		-Wno-error=non-literal-null-conversion
		-Wno-error=constant-conversion
		-Wno-error=unused-but-set-variable
		-fwrapv
	>

	# C, MSVC
	$<$<AND:$<COMPILE_LANGUAGE:C>,$<C_COMPILER_ID:MSVC>>:
		# All warnings at and before Visual Studio 2019 RTM
		# https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warnings-by-compiler-version?view=msvc-170
		/Wv:19.20.27004.0
	>

	# C++, GNU, Clang and Apple Clang
	$<$<AND:$<COMPILE_LANGUAGE:CXX>,$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:Clang>>>:
		-Wall
		-Wextra
		-Wno-trigraphs
		-Wconditional-uninitialized
	>

	# C++, MSVC
	$<$<AND:$<COMPILE_LANGUAGE:C>,$<C_COMPILER_ID:MSVC>>:
		/Wv:19.20.27004.0
	>
)
if(SRB2_CONFIG_ERRORMODE)
	target_compile_options(SRB2SDL2 PRIVATE
		$<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:Clang>>:
			-Werror
		>

		$<$<C_COMPILER_ID:MSVC>:
			/WX
		>
	)
endif()

# Yes we know we use insecure CRT functions...
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_definitions(SRB2SDL2 PRIVATE -D_CRT_NONSTDC_NO_DEPRECATE)
    target_compile_definitions(SRB2SDL2 PRIVATE -D_CRT_SECURE_NO_WARNINGS)
	target_compile_definitions(SRB2SDL2 PRIVATE -D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif()

# Link warnings configuration
target_link_options(SRB2SDL2 PRIVATE
	$<$<C_COMPILER_ID:GNU>:
		# -Wl,--as-needed   - Was controlled by NOLDWARNING
	>
)

if(${SRB2_CONFIG_DEV_BUILD})
	target_compile_definitions(SRB2SDL2 PRIVATE -DDEVELOP)
endif()
target_compile_definitions(SRB2SDL2 PRIVATE -DCMAKECONFIG)

# Misc. build options from Makefiles
if(SRB2_CONFIG_DEBUGMODE)
	target_compile_definitions(SRB2SDL2 PRIVATE -DZDEBUG -DPARANOIA -DRANGECHECK -DPACKETDROP)
endif()
if(SRB2_CONFIG_MOBJCONSISTANCY)
	target_compile_definitions(SRB2SDL2 PRIVATE -DMOBJCONSISTANCY)
endif()
if(SRB2_CONFIG_PACKETDROP)
	target_compile_definitions(SRB2SDL2 PRIVATE -DPACKETDROP)
endif()
if(SRB2_CONFIG_EXECINFO)
else()
	target_compile_definitions(SRB2SDL2 PRIVATE -DNOEXECINFO)
	message(STATUS "You have disabled stack trace dump support")
endif()
if(SRB2_CONFIG_ZDEBUG)
	target_compile_definitions(SRB2SDL2 PRIVATE -DZDEBUG)
endif()
if(SRB2_CONFIG_PROFILEMODE AND "${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
	target_compile_options(SRB2SDL2 PRIVATE -pg)
	target_link_options(SRB2SDL2 PRIVATE -pg)
endif()

add_subdirectory(sdl)

if(TARGET ZLIB::ZLIB)
	target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_ZLIB)
	message(STATUS "Zlib Found")
else()
	message(STATUS "No Zlib Found")
endif()

if(TARGET PNG::PNG)
	target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_PNG)
	target_sources(SRB2SDL2 PRIVATE apng.c ${libapng_HEADER})
	target_include_directories(SRB2SDL2 PRIVATE ${libapng_INCLUDE_DIRS} ${libpng_BINARY_DIR})
	#message(STATUS "libpng inc DIRS at ${libapng_INCLUDE_DIRS}")
	#message(STATUS "libpng bin DIRS at ${libpng_BINARY_DIR}")
	#message(STATUS "png.h at ${libapng_HEADER}")
	message(STATUS "libpng Found")
else()
	message(STATUS "No libpng Found")
endif()

if(TARGET PNG::PNG AND TARGET ZLIB::ZLIB)
#libpng links zlib too?
target_link_libraries(SRB2SDL2 PRIVATE PNG::PNG)
endif()

if(NOT TARGET PNG::PNG AND TARGET ZLIB::ZLIB)
#got no libpng? we need zlib
target_link_libraries(SRB2SDL2 PRIVATE ZLIB::ZLIB)
endif()

if(TARGET gme::gme)
	target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_GME)
	target_link_libraries(SRB2SDL2 PRIVATE gme::gme)
	message(STATUS "libgme Found")
else()
	message(STATUS "No libgme Found")
endif()

if(TARGET libopenmpt::libopenmpt)
	target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_OPENMPT)
	target_link_libraries(SRB2SDL2 PRIVATE libopenmpt::libopenmpt)
	message(STATUS "libopenmpt Found")
else()
	message(STATUS "No libopenmpt Found")
endif()

if(TARGET CURL::libcurl)
	target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_CURL)
	target_link_libraries(SRB2SDL2 PRIVATE CURL::libcurl)
	message(STATUS "libcurl Found")
else()
	message(STATUS "No libcurl Found")
endif()

if(TARGET miniupnpc::miniupnpc)
	target_compile_definitions(SRB2SDL2 PRIVATE -DHAVE_MINIUPNPC)
	target_link_libraries(SRB2SDL2 PRIVATE miniupnpc::miniupnpc)
	message(STATUS "miniupnpc Found")
else()
	message(STATUS "No miniupnpc Found")
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "WindowsStore")
	target_compile_definitions(SRB2SDL2 PRIVATE -D_WINDOWS_UWP)	
endif()

# strip debug symbols into separate file when using gcc.
# to be consistent with Makefile, don't generate for OS X.
if((CMAKE_COMPILER_IS_GNUCC) AND NOT ("${CMAKE_SYSTEM_NAME}" MATCHES Darwin))
	if((${CMAKE_BUILD_TYPE} MATCHES Debug) OR (${CMAKE_BUILD_TYPE} MATCHES RelWithDebInfo))
		if(${CMAKE_BUILD_TYPE} MATCHES Debug)
			set(OBJCOPY_ONLY_KEEP_DEBUG "--only-keep-debug")
		endif()
		message(STATUS "Will make separate debug symbols in *.debug")
		add_custom_command(TARGET SRB2SDL2 POST_BUILD
			COMMAND ${OBJCOPY} ${OBJCOPY_ONLY_KEEP_DEBUG} $<TARGET_FILE:SRB2SDL2> $<TARGET_FILE:SRB2SDL2>.debug
			COMMAND ${OBJCOPY} --strip-debug $<TARGET_FILE:SRB2SDL2>
			COMMAND ${OBJCOPY} --add-gnu-debuglink=$<TARGET_FILE:SRB2SDL2>.debug $<TARGET_FILE:SRB2SDL2>
		)
	endif()
endif()

# copy DLLs to bin/ directory if building internal shared on windows
if("${CMAKE_SYSTEM_NAME}" STREQUAL Windows AND NOT "${SRB2_CONFIG_INTERNAL_LIBRARIES}" AND "${SRB2_CONFIG_SHARED_INTERNAL_LIBRARIES}")
	set(ADDITIONAL_DLLS "")
	if("${CMAKE_C_COMPILER_ID}" STREQUAL GNU)
		# also copy implicitly linked system libraries
		get_filename_component(MINGW_BIN_PATH ${CMAKE_CXX_COMPILER} PATH)
		list(APPEND ADDITIONAL_DLLS
			"libgcc_s_dw2-1.dll"
			"libstdc++-6.dll"
			"libwinpthread-1.dll"
		)
		list(TRANSFORM ADDITIONAL_DLLS PREPEND "${MINGW_BIN_PATH}/")
	endif()
	add_custom_command(TARGET SRB2SDL2 POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			$<TARGET_RUNTIME_DLLS:SRB2SDL2>
			${ADDITIONAL_DLLS}

			$<TARGET_FILE_DIR:SRB2SDL2>
		COMMAND_EXPAND_LISTS
		COMMENT "Copying runtime DLLs"
	)
endif()

# Setup clang-tidy
if(SRB2_CONFIG_ENABLE_CLANG_TIDY_C)
	target_set_default_clang_tidy(SRB2SDL2 C "-*,clang-analyzer-*,-clang-analyzer-cplusplus-*")
endif()
if(SRB2_CONFIG_ENABLE_CLANG_TIDY_CXX)
	target_set_default_clang_tidy(SRB2SDL2 CXX "-*,clang-analyzer-*,modernize-*")
endif()
