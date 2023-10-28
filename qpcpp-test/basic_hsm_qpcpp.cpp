#include "basic_hsm_qpcpp.hpp"

// local objects --------------------------------------------------------------
Blinky inst;
extern "C" {

Q_NORETURN Q_onError(char const * const module, int_t const id) {
    // NOTE: this implementation of the assertion handler is intended only
    // for debugging and MUST be changed for deployment of the application
    // (assuming that you ship your production code with assertions enabled).
    Q_UNUSED_PAR(module);
    Q_UNUSED_PAR(id);
    QS_ASSERTION(module, id, 10000U);
}
}
//............................................................................
Blinky::Blinky()
  : QP::QHsm(&initial)
{
    // empty
}

// HSM definition ------------------------------------------------------------
Q_STATE_DEF(Blinky, initial) {
    (void)e; // unused parameter

    // arm the time event to expire in half a second and every half second
    return tran(&off);
}
//............................................................................
Q_STATE_DEF(Blinky, off) {
    QP::QState status;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            status = Q_RET_HANDLED;
            break;
        }
        case TIMEOUT_SIG: {
            status = tran(&on);
            break;
        }
        default: {
            status = super(&top);
            break;
        }
    }
    return status;
}
//............................................................................
Q_STATE_DEF(Blinky, on) {
    QP::QState status;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            status = Q_RET_HANDLED;
            break;
        }
        case TIMEOUT_SIG: {
            status = tran(&off);
            break;
        }
        default: {
            status = super(&top);
            break;
        }
    }
    return status;
}

const char* toto(){
  static char str[] = "Hello World";
  return str;
}
