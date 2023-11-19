#include "interface.hpp"
#include "defered_print.hpp"
#include "qpcpp_perf_test_sm.hpp"
extern char print_buffer[1000];

QPCPPPerfTestSM inst;

const char* dispatch_evt(AppSignals sig){
  RESET_PRINT_BUFFER();
  QP::QEvt evt{sig};
  inst.dispatch(&evt, 0);
  CLOSE_BUFFER();
  return print_buffer;
}

const char* init_hsm(){
  RESET_PRINT_BUFFER();
  inst = QPCPPPerfTestSM();
  inst.init(nullptr, 0);
  CLOSE_BUFFER();
  return print_buffer;
}

const char* dispatch_evt_A(){
  return dispatch_evt(AppSignals::A_SIG);
};

const char* dispatch_evt_B(){
  return dispatch_evt(AppSignals::B_SIG);
};
const char* dispatch_evt_C(){
  return dispatch_evt(AppSignals::C_SIG);
};

const char* dispatch_evt_D(){
  return dispatch_evt(AppSignals::D_SIG);
};


