#include "interface.hpp"
#include "defered_print.hpp"
#include "basic_hsm_qpcpp.hpp"
extern char print_buffer[1000];

BasicStateMachine inst;

const char* dispatch_evt(AppSignals sig){
  RESET_PRINT_BUFFER();
  QP::QEvt evt{sig};
  inst.dispatch(&evt, 0);
  return print_buffer;
}

const char* init_hsm(){
  RESET_PRINT_BUFFER();
  inst = BasicStateMachine();
  inst.init(nullptr, 0);
  return print_buffer;
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


