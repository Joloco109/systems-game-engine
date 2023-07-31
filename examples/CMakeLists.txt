add_custom_target(examples ALL)

MACRO(ADD_NEW_EXAMPLE name)
  add_executable(examples.${name} ${name}.cpp)
  target_include_directories(examples.${name} PRIVATE ${PROJECT_SOURCE_DIR}/include)

  add_dependencies(examples examples.${name})
ENDMACRO()

