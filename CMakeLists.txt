cmake_minimum_required (VERSION 2.8)
project (CMakeHelloWorld)

#version number
set (CMakeHelloWorld_VERSION_MAJOR 1)
set (CMakeHelloWorld_VERSION_MINOR 0)

file(GLOB files "src/*")
foreach(file ${files})
  #include the subdirectory containing our libs
  add_subdirectory (${file})
  include_directories(${file})
  #indicate the entry point for the executable
  set(libraries ${libraries} ${file})
  get_filename_component(file_name "${file}" NAME)
  set(libraries_names ${libraries_names} ${file_name})
endforeach()

add_executable (CMakeHelloWorld ${libraries} main.cpp)

# Indicate which libraries to include during the link process.
target_link_libraries (CMakeHelloWorld ${libraries_names})

install (TARGETS CMakeHelloWorld DESTINATION bin)