# Copyright (c) 2018-present, Johnson9009.
#
# This file is distributed under BSD open source license. See the LICENSE file for details.

# Every directory with source files in it, must have this cmake script file, at the top of this file
# must contain all its sub directory's "source.cmake" by "include" command. If current directory or
# its any sub directories need to be added into include directories by "include_directories"
# command, then all the "include_directories" commands must be placed above any "include" command,
# and any other commands must be placed below all "include" commands. This file only need to give a
# description of the relationship between targets and source files that inside current directory.

include_directories(${CMAKE_CURRENT_LIST_DIR})

include(${CMAKE_CURRENT_LIST_DIR}/01_assignment_operator/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/03_find_in_partially_sorted_matrix/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/04_replace_spaces/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/05_print_list_in_reversed_order/source.cmake)

