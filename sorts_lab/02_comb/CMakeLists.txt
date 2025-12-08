project(lab02_comb)

add_executable(lab02_comb
        main.cpp
)

target_link_libraries(lab02_comb PRIVATE my_lib)
