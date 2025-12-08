project(lab00_bubble)

add_executable(lab00_bubble
        main.cpp
)

target_link_libraries(lab00_bubble PRIVATE my_lib)
