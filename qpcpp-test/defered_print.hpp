#pragma once

void reset_print_buffer();
#ifdef ENABLE_PRINT 
  #define RESET_PRINT_BUFFER() reset_print_buffer();
#else
  #define RESET_PRINT_BUFFER() do{} while(0)
#endif


void print(const char* str);
#ifdef ENABLE_PRINT 
  #define PRINT(str) print(str)
#else
  #define PRINT(str) do{} while(0)
#endif

void close_buffer();
#ifdef ENABLE_PRINT 
  #define CLOSE_BUFFER() close_buffer()
#else
  #define CLOSE_BUFFER() do{} while(0)
#endif

