project(lab00_shaker)

add_executable(lab00_shaker
        main.cpp
)

target_link_libraries(lab00_shaker PRIVATE my_lib)
