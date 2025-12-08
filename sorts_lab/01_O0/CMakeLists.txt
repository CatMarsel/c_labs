project(01_O0)

add_executable(01_O0
        main.cpp
)

target_link_libraries(01_O0 PRIVATE my_lib)
target_compile_options(01_O0 PRIVATE -O0)
