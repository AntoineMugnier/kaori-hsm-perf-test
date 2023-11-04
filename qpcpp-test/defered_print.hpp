 #include <cstdio>
 #include <cstring>
 extern char defered_print_buffer[1000];
 extern char print_buffer[1000];
 
 template<typename ...T>
 void print(const char* str, T... params){
   snprintf(print_buffer, 1000, str, params...); 
   strcat(defered_print_buffer, print_buffer);
 }
