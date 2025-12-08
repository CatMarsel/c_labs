project(lab00_selected)

add_executable(lab00_selected
        main.cpp
)

target_link_libraries(lab00_selected PRIVATE my_lib)
