cmake_minimum_required(VERSION 3.20)

project(SonicCD LANGUAGES C)

function(make_level ROUND ZONE TIME)
	set(SOURCES
		"src/ACTION.C"
		"src/ACTSET.C"
		"src/BLOCK.C"
		"src/BMP.C"
		"src/DAI_K.C"
		"src/DAI_RD1.C"
		"src/DIRCOL.C"
		"src/DUMMY.C"
		"src/EDIT.C"
		"src/ENEMY.C"
		"src/EQU.C"
		"src/ET1.C"
		"src/ETC.C"
		"src/FCOL.C"
		"src/GAME.C"
		"src/GOAL.C"
		"src/IO.C"
		"src/ITEM.C"
		"src/LOADER2.C"
		"src/PLAYER.C"
		"src/PLAYPAT1.C"
		"src/PLAYSP.C"
		"src/PLCHG.C"
		"src/RIDECHK.C"
		"src/RING.C"
		"src/SAVE.C"
		"src/SCORE.C"
		"src/SCRCHK.C"
		"src/SPRING.C"
		"src/SUICIDE.C"
		"src/TAKI.C"
		"src/TBL0.C"
		"src/TBL1.C"
		"src/TREE.C"
		"src/ZONE.C"
		"src/ZONETBL1.C"
		"src/R${ROUND}/COL${ROUND}${TIME}.C"
		"src/R${ROUND}/COLI${ROUND}.C"
		"src/R${ROUND}/DEV${ROUND}${ZONE}${TIME}.C"
		"src/R${ROUND}/FRIEND${ROUND}.C"
		"src/R${ROUND}/MOVIE${ROUND}.C"
		"src/R${ROUND}/SCR${ROUND}${ZONE}${TIME}.C"
		"src/R${ROUND}/Z${ROUND}${ZONE}ACT.C"
		"src/R${ROUND}/Z${ROUND}${ZONE}${TIME}TBL.C"
		"src/LAUNCHER/MAIN.C"
		"src/LAUNCHER/IO.C"
		"src/LAUNCHER/LZSS.C"
		"src/LAUNCHER/SZDD.C"
		${ARGN}
	)

	set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE C)

	set(EXECUTABLE_NAME "R${ROUND}${ZONE}${TIME}")

	add_executable(${EXECUTABLE_NAME} WIN32
		${SOURCES}
	)

	set_target_properties(${EXECUTABLE_NAME} PROPERTIES
		C_STANDARD 99
	)

	target_compile_definitions(${EXECUTABLE_NAME} PRIVATE R${ROUND} R${ROUND}${ZONE} R${ROUND}${ZONE}${TIME})
	target_compile_definitions(${EXECUTABLE_NAME} PRIVATE LEVEL_ROUND=${ROUND} LEVEL_ZONE=${ZONE} LEVEL_TIME=${TIME})

	target_link_libraries(${EXECUTABLE_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2)
endfunction()

find_package(SDL2 REQUIRED)

make_level(1 1 A
	"src/EMIE1.C"
	"src/EMIE1CG.C"
	"src/PLAYSUB.C"
	"src/R1/ACT11A.C"
	"src/R1/EDTBL11A.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR11A.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 1 B
	"src/PLAYSUB.C"
	"src/R1/ACT11B.C"
	"src/R1/EDTBL11B.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR11B.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 1 C
	"src/PLAYSUB.C"
	"src/R1/ACT11B.C"
	"src/R1/EDTBL11C.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR11C.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 1 D
	"src/PLAYSUB.C"
	"src/R1/ACT11B.C"
	"src/R1/EDTBL11D.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR11D.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 2 A
	"src/BRANKO1.C"
	"src/PLAYSUB.C"
	"src/R1/ACT12A.C"
	"src/R1/EDTBL12A.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR12A.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 2 B
	"src/BRANKO1.C"
	"src/PLAYSUB.C"
	"src/R1/ACT12A.C"
	"src/R1/EDTBL12B.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR12B.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 2 C
	"src/BRANKO1.C"
	"src/PLAYSUB.C"
	"src/R1/ACT12A.C"
	"src/R1/EDTBL12C.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR12C.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 2 D
	"src/BRANKO1.C"
	"src/PLAYSUB.C"
	"src/R1/ACT12A.C"
	"src/R1/EDTBL12D.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR12D.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 3 C
	"src/PLAYSUB.C"
	"src/R1/ACT13C.C"
	"src/R1/BOSS_1.C"
	"src/R1/EDTBL13C.C"
	"src/R1/KOWASI1.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(1 3 D
	"src/PLAYSUB.C"
	"src/R1/ACT13C.C"
	"src/R1/BOSS_1.C"
	"src/R1/EDTBL13C.C"
	"src/R1/KOWASI1.C"
	"src/R1/SHOOT1.C"
	"src/R1/SIKAKE.C"
)

make_level(3 1 A
	"src/PLAYSUB.C"
	"src/R3/ACT31A.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL31A.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MECASNC.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3A.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 1 B
	"src/PLAYSUB.C"
	"src/R3/ACT31B.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL31B.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3B.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 1 C
	"src/PLAYSUB.C"
	"src/R3/ACT31B.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL31C.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3D.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 1 D
	"src/PLAYSUB.C"
	"src/R3/ACT31B.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL31D.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3D.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 2 A
	"src/PLAYSUB.C"
	"src/R3/ACT32A.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL32A.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MECASNC.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3A.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 2 B
	"src/PLAYSUB.C"
	"src/R3/ACT32A.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL32B.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3B.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 2 C
	"src/PLAYSUB.C"
	"src/R3/ACT32A.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL32C.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3D.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 2 D
	"src/PLAYSUB.C"
	"src/R3/ACT32A.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/EDTBL32D.C"
	"src/R3/GA3.C"
	"src/R3/KAMA.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3D.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 3 C
	"src/PLAYSUB.C"
	"src/R3/ACT33C.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/BOSS_3.C"
	"src/R3/EDTBL33C.C"
	"src/R3/GA3.C"
	"src/R3/GATE.C"
	"src/R3/KAMA.C"
	"src/R3/LIGHT.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/ROLLPLAT.C"
	"src/R3/SIKAKE33.C"
	"src/R3/STOPPER.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3D.C"
	"src/R3/TRAP_R3.C"
)

make_level(3 3 D
	"src/PLAYSUB.C"
	"src/R3/ACT33C.C"
	"src/R3/BANPA.C"
	"src/R3/BOBIN.C"
	"src/R3/BOBINB.C"
	"src/R3/BOSS_3.C"
	"src/R3/EDTBL33C.C"
	"src/R3/GA3.C"
	"src/R3/GATE.C"
	"src/R3/KAMA.C"
	"src/R3/LIGHT.C"
	"src/R3/MIRACLE.C"
	"src/R3/MSNCCG.C"
	"src/R3/POCKET.C"
	"src/R3/ROLLPLAT.C"
	"src/R3/SIKAKE33.C"
	"src/R3/STOPPER.C"
	"src/R3/TENTOU.C"
	"src/R3/TOGEBL3D.C"
	"src/R3/TRAP_R3.C"
)

make_level(4 1 A
	"src/R4/ACT41A.C"
	"src/R4/AMENBO.C"
	"src/R4/AWA.C"
	"src/R4/BRUNKO4.C"
	"src/R4/EDTBL41A.C"
	"src/R4/ESCAL4.C"
	"src/R4/FUNSUI4.C"
	"src/R4/HARID4.C"
	"src/R4/HARIR4.C"
	"src/R4/KUZURE4.C"
	"src/R4/PLAYSUB4.C"
	"src/R4/SCREW_A.C"
	"src/R4/SW4.C"
	"src/R4/SWBLK4.C"
	"src/R4/TAGAMEB4.C"
	"src/R4/TEKKYU.C"
	"src/R4/TOBIRA4.C"
	"src/R4/TONBO.C"
	"src/R4/WALL1.C"
	"src/R4/WALLS.C"
	"src/R4/YAGO.C"
)
