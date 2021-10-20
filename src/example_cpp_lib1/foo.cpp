#include "example_cpp_lib1/foo.hpp"

#include <iostream>

namespace example_cpp_lib1 {

Foo::Foo(const std::string& msg_) :
    msg{msg_} {

}

void Foo::printMsg() {
  std::cout << "from example_cpp_lib1> " << msg << std::endl;
}

}
