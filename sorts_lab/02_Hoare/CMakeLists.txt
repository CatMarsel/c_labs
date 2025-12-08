project(lab01_hoare)

add_executable(lab01_hoare
        main.cpp
)

target_link_libraries(lab01_hoare PRIVATE my_lib)
