#pragma once
#include <cstdio>
#include <cstring>
 void flush_buffer();

#ifdef ENABLE_PRINT 
  #define PRINT(str) print(str)
#else
  #define PRINT(str) do{} while(0)
#endif

void print(const char* str);
