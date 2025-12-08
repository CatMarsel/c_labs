cmake_minimum_required(VERSION 3.26)
project(mipt_c_labs)

set(CMAKE_CXX_STANDARD 20)

# ---- общая библиотека из libs ----
add_library(my_lib
    libs/Timer.cpp
        libs/Random.cpp
        libs/RandomArray.cpp
        libs/BubbleSorter.cpp
        libs/ShakerSorter.cpp
        libs/SelectionSorter.cpp
        libs/HeapSorter.cpp
        libs/HoareSorter.cpp
        libs/CombSorter.cpp
        libs/SortedArray.cpp
        libs/ReverseSortedArray.cpp
)

target_include_directories(my_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs
)

# ---- подпроекты с программами ----
add_subdirectory(00_bubble)
add_subdirectory(02_heap)
add_subdirectory(00_shaker)
add_subdirectory(00_selected)
add_subdirectory(02_Hoare)
add_subdirectory(02_comb)
add_subdirectory(04_00_bubble_bad)
add_subdirectory(04_00_bubble_best)
add_subdirectory(04_00_selected_bad)
add_subdirectory(04_00_selected_best)
add_subdirectory(04_00_shaker_bad)
add_subdirectory(04_00_shaker_best)
add_subdirectory(04_02_comb_bad)
add_subdirectory(04_02_comb_best)
add_subdirectory(04_02_heap_bad)
add_subdirectory(04_02_heap_best)
add_subdirectory(04_02_hoare_bad)
add_subdirectory(04_02_hoare_best)
add_subdirectory(01_O0)
add_subdirectory(01_O1)
add_subdirectory(01_O2)
add_subdirectory(01_O3)