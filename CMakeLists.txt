cmake_minimum_required (VERSION 2.8)
project (CMakeHelloWorld)

#version number
set (CMakeHelloWorld_VERSION_MAJOR 1)
set (CMakeHelloWorld_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost COMPONENTS
  serialization
  system
) 

if(NOT Boost_FOUND)
  message(SEND_ERROR "Boost not found")
endif()

enable_testing()
find_package(GTest REQUIRED)

if (NOT GTEST_FOUND)
  message(SEND_ERROR "Google tests are not found")
endif()

include_directories(${Boost_INCLUDE_DIRS}) 
  
file(GLOB files "libs/*")
foreach(file ${files})
  #include the subdirectory containing our libs
  add_subdirectory (${file})
  include_directories(${file})
  #indicate the entry point for the executable
  set(libraries ${libraries} ${file})
  get_filename_component(file_name "${file}" NAME)
  set(libraries_names ${libraries_names} ${file_name})

endforeach()

#GLOB RECRSE IS EVIL https://stackoverflow.com/questions/32411963/why-is-cmake-file-glob-evil
file(GLOB_RECURSE src_files "src/*")
foreach(file ${src_files})
  set(SRC_FILES ${SRC_FILES} ${file})
endforeach()

add_executable (patterns ${libraries} 
  ${SRC_FILES} main.cpp
)
target_link_libraries(patterns ${Boost_LIBRARIES})
install (TARGETS patterns DESTINATION bin)

#test
add_executable(tests test.cpp ${SRC_FILES})
target_link_libraries(tests 
  ${libraries} 
  ${Boost_LIBRARIES} 
  GTest::GTest GTest::Main)
add_test(AllTests tests)