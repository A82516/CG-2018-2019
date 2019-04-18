cmake_minimum_required(VERSION 3.5)

project(engine)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

if(NOT GLUT_FOUND)
	message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)


if  (WIN32)

	message(STATUS "GLUT_DIR set to: " ${GLUT_DIR})
	set(GLUT_DIR "" CACHE PATH "Path to GLUT folder")
	if (NOT EXISTS "${GLUT_DIR}/GL/glut.h" OR NOT EXISTS "${GLUT_DIR}/glut32.lib")
		message(ERROR ": GLUT not found")
	endif (NOT EXISTS "${GLUT_DIR}/GL/glut.h" OR NOT EXISTS "${GLUT_DIR}/glut32.lib")
	include_directories(${GLUT_DIR})
	link_directories(${GLUT_DIR})
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_DIR}/glut32.lib )
	if (EXISTS "${GLUT_DIR}/glut32.dll")
		file(COPY ${GLUT_DIR}/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
	endif(EXISTS "${GLUT_DIR}/glut32.dll")
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

else (WIN32) #Linux and Mac

	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-deprecated")
	set_source_files_properties(${sources} PROPERTIES COMPILE_FLAGS
		"-xobjective-c -Wno-deprecated-declarations")
	find_package(OpenGL REQUIRED)
	include_directories(${OpenGL_INCLUDE_DIRS})
	link_directories(${OpenGL_LIBRARY_DIRS})
	add_definitions(${OpenGL_DEFINITIONS})

	if(NOT OPENGL_FOUND)
		message(ERROR " OPENGL not found!")
	endif(NOT OPENGL_FOUND)
endif(WIN32)

# Project Name
project(engine)

set(ENGINE_FILES ./src/engine.cpp ./src/tinyxml2.cpp ./src/Point.cpp ./src/Figure.cpp ./src/Transformation.cpp src/Translate.cpp src/Rotate.cpp src/Scale.cpp src/Camera.cpp headers/Camera.h)

add_executable(engine ${ENGINE_FILES})

if (NOT APPLE)
	find_package(GLEW REQUIRED)
	include_directories(${GLEW_INCLUDE_DIRS})
	link_libraries(${GLEW_LIBRARIES})
	target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
else (NOT APPLE)
	target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
endif(NOT APPLE)

project(generator)
set(GENERATOR_FILES ./src/generator.cpp ./src/Point.cpp ./src/Polygon.cpp ./src/Transformation.cpp ./src/Patch.cpp)

add_executable(generator ${GENERATOR_FILES} )
target_link_libraries(generator ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
