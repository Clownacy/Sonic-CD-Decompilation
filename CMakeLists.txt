cmake_minimum_required(VERSION 3.20)

project(SonicCD LANGUAGES C)

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
#	"src/EMIE1.C"
#	"src/EMIE1CG.C"
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
	"src/R1/ACT11B.C"
	"src/R1/COL1B.C"
	"src/R1/COLI1.C"
	"src/R1/DEV11B.C"
	"src/R1/EDTBL11B.C"
	"src/R1/FRIEND1.C"
	"src/R1/KOWASI1.C"
	"src/R1/KUZURE.C"
	"src/R1/KUZUR11B.C"
	"src/R1/MOVIE1.C"
	"src/R1/SCR11B.C"
	"src/R1/SIKAKE.C"
	"src/R1/SHOOT1.C"
	"src/R1/Z11ACT.C"
	"src/R1/Z11BTBL.C"
	"src/LAUNCHER/MAIN.C"
)

set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE C)

add_executable(game WIN32
	${SOURCES}
)

find_package(SDL2 REQUIRED)
target_link_libraries(game PRIVATE SDL2::SDL2main SDL2::SDL2)
