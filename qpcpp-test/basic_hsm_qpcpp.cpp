#include <string_view>
const char* toto(){
  static char str[] = "Hello World";
  return str;
}
