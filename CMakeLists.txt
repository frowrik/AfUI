cmake_minimum_required(VERSION 3.2)

project(AfUI_project C CXX)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4") # enable all warnings
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")  # enable all warnings
endif ()

#special flags for debug
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# c++ standart
set(CMAKE_CXX_STANDARD 23) 		
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# folder in visualstudio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# main dirs
set(CMAKE_INCLUDES_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/project/intermediates")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/project/intermediates")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/$<0:>") 
set(CMAKE_BUILD_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/project") 

# sub code dirs
set(DEPS_DIRECTORY    ${CMAKE_CURRENT_SOURCE_DIR}/deps)
set(SOURCES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/sources)
include_directories(${DEPS_DIRECTORY})
include_directories(${SOURCES_DIRECTORY})

# find opengl
set(OpenGL_GL_PREFERENCE GLVND) # использование устаревшей библиотеки GL.
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
	
# find x11 for linux
if (CMAKE_SYSTEM_NAME STREQUAL Linux)
  find_package(X11 REQUIRED)
  if (NOT X11_Xi_FOUND)
    message(FATAL_ERROR "X11 Xi library is required")
  endif ()
endif ()

#libs
include("cmake/sdl3.cmake")
include("cmake/imgui.cmake")

# AfUI
file(GLOB AfUI_SOURCES_FILES  "${SOURCES_DIRECTORY}/AfUI/*.cpp" "${SOURCES_DIRECTORY}/AfUI/*.h")  
file(GLOB AfUI_SOURCES_FILES2  "${SOURCES_DIRECTORY}/AfUI/elements/*.cpp" "${SOURCES_DIRECTORY}/AfUI/elements/*.h")  
add_library(AfUI STATIC ${AfUI_SOURCES_FILES} ${AfUI_SOURCES_FILES2} )
source_group("sources"  FILES  ${AfUI_SOURCES_FILES})
source_group("sources/elements"  FILES  ${AfUI_SOURCES_FILES2})
target_link_libraries(AfUI PRIVATE ${IMGUI_LIBRARIES})
include_directories("${SOURCES_DIRECTORY}/AfUI/")
target_precompile_headers(AfUI PRIVATE "${SOURCES_DIRECTORY}/AfUI/AfUI.h")

# main app
set(APP_ICON_RESOURCE_WINDOWS "${SOURCES_DIRECTORY}/main/appicon.rc")
set_source_files_properties(${APP_ICON_RESOURCE_WINDOWS} PROPERTIES GENERATED ON)
file(GLOB EXE_FILES   "${SOURCES_DIRECTORY}/main/*.cpp" "${SOURCES_DIRECTORY}/main/*.h" )
add_executable(main ${EXE_FILES} ${APP_ICON_RESOURCE_WINDOWS})
source_group("sources"  FILES  ${EXE_FILES})
target_link_libraries(main PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(main PRIVATE ${SDL3_LIBRARIES})
target_link_libraries(main PRIVATE ${IMGUI_LIBRARIES})
target_link_libraries(main PRIVATE AfUI)
set_target_properties(main PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}") # set dir options for visualstudio
