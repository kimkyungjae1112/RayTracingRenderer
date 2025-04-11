# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/src/dep_spdlog"
  "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/src/dep_spdlog-build"
  "C:/Work/Graphics_Practice/build/dep_spdlog-prefix"
  "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/tmp"
  "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/src/dep_spdlog-stamp"
  "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/src"
  "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/src/dep_spdlog-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/src/dep_spdlog-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Work/Graphics_Practice/build/dep_spdlog-prefix/src/dep_spdlog-stamp${cfgdir}") # cfgdir has leading slash
endif()
