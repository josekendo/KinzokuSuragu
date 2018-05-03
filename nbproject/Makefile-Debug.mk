#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Bullet.o \
	${OBJECTDIR}/Camara.o \
	${OBJECTDIR}/Colision.o \
	${OBJECTDIR}/Controles.o \
	${OBJECTDIR}/Coordenadas.o \
	${OBJECTDIR}/Els.o \
	${OBJECTDIR}/Enemigos.o \
	${OBJECTDIR}/Estado.o \
	${OBJECTDIR}/FabricarNivel.o \
	${OBJECTDIR}/GestionArchivos.o \
	${OBJECTDIR}/Hud.o \
	${OBJECTDIR}/Juego.o \
	${OBJECTDIR}/Jugadores.o \
	${OBJECTDIR}/Menus.o \
	${OBJECTDIR}/Motor2D.o \
	${OBJECTDIR}/Nivel.o \
	${OBJECTDIR}/TileMap.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/tinystr.o \
	${OBJECTDIR}/tinyxml.o \
	${OBJECTDIR}/tinyxmlerror.o \
	${OBJECTDIR}/tinyxmlparser.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libsfml-window.so /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-system.so libbox2d.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase: /usr/lib/x86_64-linux-gnu/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase: /usr/lib/x86_64-linux-gnu/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase: libbox2d.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Bullet.o: Bullet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bullet.o Bullet.cpp

${OBJECTDIR}/Camara.o: Camara.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Camara.o Camara.cpp

${OBJECTDIR}/Colision.o: Colision.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Colision.o Colision.cpp

${OBJECTDIR}/Controles.o: Controles.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Controles.o Controles.cpp

${OBJECTDIR}/Coordenadas.o: Coordenadas.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Coordenadas.o Coordenadas.cpp

${OBJECTDIR}/Els.o: Els.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Els.o Els.cpp

${OBJECTDIR}/Enemigos.o: Enemigos.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enemigos.o Enemigos.cpp

${OBJECTDIR}/Estado.o: Estado.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Estado.o Estado.cpp

${OBJECTDIR}/FabricarNivel.o: FabricarNivel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FabricarNivel.o FabricarNivel.cpp

${OBJECTDIR}/GestionArchivos.o: GestionArchivos.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GestionArchivos.o GestionArchivos.cpp

${OBJECTDIR}/Hud.o: Hud.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hud.o Hud.cpp

${OBJECTDIR}/Juego.o: Juego.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Juego.o Juego.cpp

${OBJECTDIR}/Jugadores.o: Jugadores.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Jugadores.o Jugadores.cpp

${OBJECTDIR}/Menus.o: Menus.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menus.o Menus.cpp

${OBJECTDIR}/Motor2D.o: Motor2D.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor2D.o Motor2D.cpp

${OBJECTDIR}/Nivel.o: Nivel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nivel.o Nivel.cpp

${OBJECTDIR}/TileMap.o: TileMap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TileMap.o TileMap.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/tinystr.o: tinystr.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinystr.o tinystr.cpp

${OBJECTDIR}/tinyxml.o: tinyxml.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxml.o tinyxml.cpp

${OBJECTDIR}/tinyxmlerror.o: tinyxmlerror.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxmlerror.o tinyxmlerror.cpp

${OBJECTDIR}/tinyxmlparser.o: tinyxmlparser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -IBox2D -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxmlparser.o tinyxmlparser.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juegobase

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
