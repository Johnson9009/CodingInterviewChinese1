# Copyright (c) 2018-present, Johnson9009.
#
# This file is distributed under BSD open source license. See the LICENSE file for details.

# Every directory with source files in it, must have this cmake script file, at the top of this file
# must contain all its sub directory's "source.cmake" by "include" command. If current directory or
# its any sub directories need to be added into include directories by "include_directories"
# command, then all the "include_directories" commands must be placed above any "include" command,
# and any other commands must be placed below all "include" commands. This file only need to give a
# description of the relationship between targets and source files that inside current directory.

set(27_CONVERT_BINARY_SEARCH_TREE_SRCS ${27_CONVERT_BINARY_SEARCH_TREE_SRCS}
    ${CMAKE_CURRENT_LIST_DIR}/convert_binary_search_tree.cc
)

# Because source file list of each target, such as "UNIT_TEST_SOURCES", is defined in above CMake
# script files, so we must lay all commands which need source file list, such as "add_executable",
# bellow to any "include" command which aim to include "source.cmake".
add_executable(27_convert_binary_search_tree ${27_CONVERT_BINARY_SEARCH_TREE_SRCS})
# PRIVATE: Target requires some compile features only when it is built itself, but its consumers are
# not required to use a compiler which supports these features.
# PUBLIC or INTERFACE: The interface of target require some compile features.
target_compile_features(27_convert_binary_search_tree PRIVATE cxx_std_11)
target_link_libraries(27_convert_binary_search_tree basic_data_structure)
