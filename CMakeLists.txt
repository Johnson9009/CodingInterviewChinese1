# Copyright (c) 2018-present, Johnson9009.
#
# This file is distributed under BSD open source license. See the LICENSE file for details.

# The Top CMake Script

cmake_minimum_required(VERSION 3.9)
project(CodingInterviewChinese1 CXX)

# In our project, we organize all source files of each target through CMake script files recursive
# including. Every directory with source files in it, must have a CMake script file "source.cmake",
# and each CMake script file(this file(CMakeLists.txt) no exception) should contain all its sub
# directory's "source.cmake" by "include" command.
include(${CMAKE_CURRENT_LIST_DIR}/src/source.cmake)

# Because source file list of each target, such as "UNIT_TEST_SOURCES", is defined in above CMake
# script files, so we must lay all commands which need source file list, such as "add_executable",
# bellow to any "include" command which aim to include "source.cmake".
