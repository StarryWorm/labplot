option(ENABLE_TEST_BACKEND_AXIS "Enable Axis Tests" ON)

if(ENABLE_TEST_BACKEND_AXIS)
    add_executable(AxisTest AxisTest.cpp)
    target_link_libraries(AxisTest labplotbackendlib labplotlib labplottest)
    add_test(NAME AxisTest COMMAND AxisTest)

    add_executable(AxisTest2 AxisTest2.cpp)
    target_link_libraries(AxisTest2 labplotbackendlib labplotlib labplottest)
    add_test(NAME AxisTest2 COMMAND AxisTest2)

    add_executable(AxisTest3 AxisTest3.cpp)
    target_link_libraries(AxisTest3 labplotbackendlib labplotlib labplottest)
    add_test(NAME AxisTest3 COMMAND AxisTest3)
endif()
