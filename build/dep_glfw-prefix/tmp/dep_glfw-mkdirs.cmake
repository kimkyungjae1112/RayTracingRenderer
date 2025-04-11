# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Work/Graphics_Practice/build/dep_glfw-prefix/src/dep_glfw"
  "C:/Work/Graphics_Practice/build/dep_glfw-prefix/src/dep_glfw-build"
  "C:/Work/Graphics_Practice/build/dep_glfw-prefix"
  "C:/Work/Graphics_Practice/build/dep_glfw-prefix/tmp"
  "C:/Work/Graphics_Practice/build/dep_glfw-prefix/src/dep_glfw-stamp"
  "C:/Work/Graphics_Practice/build/dep_glfw-prefix/src"
  "C:/Work/Graphics_Practice/build/dep_glfw-prefix/src/dep_glfw-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Work/Graphics_Practice/build/dep_glfw-prefix/src/dep_glfw-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Work/Graphics_Practice/build/dep_glfw-prefix/src/dep_glfw-stamp${cfgdir}") # cfgdir has leading slash
endif()
