#include <iostream>
#include <gtest/gtest.h>

#include "component.hpp"
#include "connection.hpp"
#include "domain.hpp"

TEST(component, default_ctor) {
  component_ptr system = component::create();
}

TEST(component, name_ctor) {
  component_ptr system = component::create("System");
}

TEST(connection, ctor) {
  auto s1=component::create("S1"), s2=component::create("S2");
  connection<component,component> c {s1,s2};
}

TEST(domain, ctor) {
}
