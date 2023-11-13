#include "defered_print.hpp"
char defered_print_buffer[1000];
char print_buffer[1000];


void flush_buffer()
{
   defered_print_buffer[0] = 0;
}

void print(const char* str){
   strcat(defered_print_buffer, print_buffer);
}
 
