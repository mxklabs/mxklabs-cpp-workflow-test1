#ifndef MXKLABS_EXAMPLE_CPP_LIB1_FOO_HPP
#define MXKLABS_EXAMPLE_CPP_LIB1_FOO_HPP

#include <string>

namespace example_cpp_lib1 {

class Foo {
public:
  // Constructor.
  Foo(const std::string& msg);
  // Print message.
  virtual void printMsg();

private:
  // Message to print.
  std::string msg;
};

}

#endif