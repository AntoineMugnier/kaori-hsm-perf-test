#include "defered_print.hpp"
#include "stdint.h"
#include <cstddef>
#include <cstdint>
char print_buffer[1000];
static char* next_buff_start;

void reset_print_buffer()
{
   next_buff_start = &print_buffer[0];
}

// Basically just a strcpy without any security
void print(const char* src){
  size_t idx = 0;
  while (src[idx] != '\0'){
    next_buff_start[idx] = src[idx];
    idx++;
  }
  next_buff_start[idx] = '\r';
  next_buff_start[idx+1] = '\n';
  next_buff_start += (idx + 2);
}
void close_buffer(){
 *next_buff_start = '\0';
}
 
