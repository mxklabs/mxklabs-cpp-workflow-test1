#include <iostream>

#include "example_cpp_app/foo.hpp"

int main() {
  example_cpp_app::Foo foo{"example-cpp-app"};
  (&foo)->printMsg();

  return 0;
}

