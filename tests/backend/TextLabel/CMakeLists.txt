option(ENABLE_TEST_BACKEND_TEXTLABEL "Enable Textlabel Tests" ON)

if(ENABLE_TEST_BACKEND_TEXTLABEL)
    add_executable (TextLabelTest TextLabelTest.cpp)

    target_link_libraries(TextLabelTest labplotbackendlib labplotlib labplottest)

    add_test(NAME TextLabelTest COMMAND TextLabelTest)
endif()
