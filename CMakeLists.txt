CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(framework)
MESSAGE(STATUS "src dir:" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "bin dir:" ${PROJECT_BINARY_DIR})

##########################################
ADD_DEFINITIONS(-D__DD_DEBUG__)

#OPTION(ARM_COMPILE "Use arm compile" OFF) 
IF(ARM_COMPILE)
	MESSAGE(STATUS "arm compile")
	INCLUDE_DIRECTORIES(/opt/arm-linux-gnueabihf/usr/include /opt/arm-linux-gnueabihf/usr/include/gio-unix-2.0 /opt/arm-linux-gnueabihf/usr/include/gstreamer-1.0)
	INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/thirdparty/taglib/taglib-1.10/release/include)
	LINK_DIRECTORIES(/opt/arm-linux-gnueabihf/lib /opt/arm-linux-gnueabihf/usr/lib)
	LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/thirdparty/taglib/taglib-1.10/release/lib)
ELSE(ARM_COMPILE)
	MESSAGE(STATUS "pc compile")
	INCLUDE_DIRECTORIES(/usr/include/c++/4.8 /usr/include/glib-2.0 /usr/include/gio-unix-2.0 /usr/include/gstreamer-1.0)
	LINK_DIRECTORIES(/usr/lib /usr/lib/x86_64-linux-gnu)
ENDIF(ARM_COMPILE)
##########################################
ADD_SUBDIRECTORY(src/daemon)
ADD_SUBDIRECTORY(src/launcher)
