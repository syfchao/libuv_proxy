PROJECT(STServer)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

IF(DEBUG_MODE)
ADD_DEFINITIONS(-DDEBUG -DLINUX)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib) 
MESSAGE("Debug mode--------------------------------")
ELSE()
ADD_DEFINITIONS(-DLINUX -DNDEBUG)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib) 
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -finline-functions -Wall")
MESSAGE("Release mode------------------------------")
ENDIF()

ADD_DEFINITIONS("-std=c++11")


INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(./common)
INCLUDE_DIRECTORIES(./interface)
INCLUDE_DIRECTORIES(./tinyxml2)

ADD_SUBDIRECTORY(pluginBag)
ADD_SUBDIRECTORY(pluginCharacter)
ADD_SUBDIRECTORY(pluginFight)
ADD_SUBDIRECTORY(pluginGM)
ADD_SUBDIRECTORY(pluginNPC)
ADD_SUBDIRECTORY(pluginSkill)
ADD_SUBDIRECTORY(pluginTask)