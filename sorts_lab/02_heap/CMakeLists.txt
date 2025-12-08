project(lab01_heap)

add_executable(lab01_heap
        main.cpp
)

target_link_libraries(lab01_heap PRIVATE my_lib)
