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
		"src/PLAYSUB.C"
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
		"src/R${ROUND}/EDTBL${ROUND}${ZONE}${TIME}.C"
		"src/R${ROUND}/FRIEND${ROUND}.C"
		"src/R${ROUND}/KOWASI${ROUND}.C"
		"src/R${ROUND}/KUZURE.C"
		"src/R${ROUND}/KUZUR${ROUND}${ZONE}${TIME}.C"
		"src/R${ROUND}/MOVIE${ROUND}.C"
		"src/R${ROUND}/SCR${ROUND}${ZONE}${TIME}.C"
		"src/R${ROUND}/SIKAKE.C"
		"src/R${ROUND}/SHOOT${ROUND}.C"
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
	"src/R1/ACT11A.C"
)

make_level(1 1 B
	"src/R1/ACT11B.C"
)

make_level(1 2 A
	"src/BRANKO1.C"
	"src/R1/ACT12A.C"
)

make_level(1 2 B
	"src/BRANKO1.C"
	"src/R1/ACT12A.C"
)
