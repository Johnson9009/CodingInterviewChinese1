# Copyright (c) 2018-present, Johnson9009.
#
# This file is distributed under BSD open source license. See the LICENSE file for details.

# Every directory with source files in it, must have this cmake script file, at the top of this file
# must contain all its sub directory's "source.cmake" by "include" command. If current directory or
# its any sub directories need to be added into include directories by "include_directories"
# command, then all the "include_directories" commands must be placed above any "include" command,
# and any other commands must be placed below all "include" commands. This file only need to give a
# description of the relationship between targets and source files that inside current directory.

include(${CMAKE_CURRENT_LIST_DIR}/01_assignment_operator/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/03_find_in_partially_sorted_matrix/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/04_replace_spaces/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/05_print_list_in_reversed_order/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/06_construct_binary_tree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/07_queue_with_two_stacks/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/08_min_number_in_rotated_array/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/09_fibonacci/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/10_number_of_1_in_binary/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/11_power/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/12_print_1_to_max_of_n_digits/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/13_delete_node_in_list/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/14_reorder_array/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/15_kth_node_from_end/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/16_reverse_list/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/17_merge_sorted_lists/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/18_substructure_in_tree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/19_mirror_of_binary_tree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/20_print_matrix/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/21_min_in_stack/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/22_stack_push_pop_order/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/23_print_tree_from_top_to_bottom/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/24_squence_of_bst/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/25_path_in_tree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/27_convert_binary_search_tree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/28_string_permutation/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/29_more_than_half_number/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/30_k_least_numbers/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/31_greatest_sum_of_subarrays/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/35_first_not_repeating_char/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/36_inverse_pairs/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/37_first_common_nodes_in_lists/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/38_number_of_k/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/39_01_tree_depth/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/39_02_balanced_binary_tree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/40_numbers_appear_once/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/41_01_two_numbers_with_sum/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/41_02_continuous_squence_with_sum/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/42_01_reverse_words_in_sentence/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/42_02_left_rotate_string/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/47_add_two_numbers/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/49_string_to_int/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/50_common_parent_in_tree/source.cmake)
