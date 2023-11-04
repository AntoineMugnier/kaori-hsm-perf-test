#include "interface.hpp"
#include "basic_hsm_qpcpp.hpp"
char defered_print_buffer[1000];
char print_buffer[1000];

extern BasicStateMachine inst;

extern "C" {
const char* dispatch_evt(INTERFACE_SIGNAL sig){
  AppSignals sm_sig;
  sm_sig = static_cast<AppSignals>(static_cast<QP::QSignal>(sig) + QP::Q_USER_SIG);
  QP::QEvt evt{sm_sig};
  inst.dispatch(&evt, 0);
  return print_buffer;
}
}
