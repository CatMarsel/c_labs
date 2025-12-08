project(01_O3)

add_executable(01_O3
        main.cpp
)

target_link_libraries(01_O3 PRIVATE my_lib)
target_compile_options(01_O3 PRIVATE -O3)
