project(01_O2)

add_executable(01_O2
        main.cpp
)

target_link_libraries(01_O2 PRIVATE my_lib)
target_compile_options(01_O2 PRIVATE -O2)
