#include "interface.hpp"
#include "defered_print.hpp"
#include "basic_hsm_qpcpp.hpp"
#include <cstring>
char defered_print_buffer[1000];
char print_buffer[1000];

BasicStateMachine inst;

const char* dispatch_evt(AppSignals sig){
  QP::QEvt evt{sig};
  inst.dispatch(&evt, 0);
  return print_buffer;
}

void init_hsm(){
  inst = BasicStateMachine();
  inst.init(nullptr, 0);
}

const char* dispatch_evt_A(){
  return dispatch_evt(AppSignals::A);
};

const char* dispatch_evt_B(){
  return dispatch_evt(AppSignals::B);
};
const char* dispatch_evt_C(){
  return dispatch_evt(AppSignals::C);
};

const char* dispatch_evt_D(){
  return dispatch_evt(AppSignals::D);
};


