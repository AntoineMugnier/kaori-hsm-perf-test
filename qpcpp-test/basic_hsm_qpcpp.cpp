#include "qpcpp.hpp"

const char* toto(){
  static char str[] = "Hello World";
  return str;
}
