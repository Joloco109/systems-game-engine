include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
  OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

file(COPY test_component.txt.ref DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_custom_target(tests ALL)

MACRO(ADD_BASE_TEST name)
  add_executable(tests.${name} ${name}.cpp)
  target_link_libraries(tests.${name}
    PRIVATE GTest::gtest_main
  )
  target_include_directories(tests.${name} PRIVATE ${PROJECT_SOURCE_DIR}/include)

  add_dependencies(tests tests.${name})
  gtest_discover_tests(tests.${name})
ENDMACRO()

MACRO(ADD_TUI_TEST name)
  add_executable(tests.${name} ${name}.cpp)
  target_link_libraries(tests.${name}
    PRIVATE GTest::gtest_main
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
  )
  target_include_directories(tests.${name} PRIVATE ${PROJECT_SOURCE_DIR}/include)

  add_dependencies(tests tests.${name})
  gtest_discover_tests(tests.${name})
ENDMACRO()

ADD_BASE_TEST(component)
