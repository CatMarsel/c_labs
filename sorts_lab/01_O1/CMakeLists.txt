project(01_O1)

add_executable(01_O1
        main.cpp
)

target_link_libraries(01_O1 PRIVATE my_lib)
target_compile_options(01_O1 PRIVATE -O1)
