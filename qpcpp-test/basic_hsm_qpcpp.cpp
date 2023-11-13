#include "basic_hsm_qpcpp.hpp"
#include <array>
#include "defered_print.hpp"
// local objects --------------------------------------------------------------
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
BasicStateMachine::BasicStateMachine()
  : QP::QHsm(&initial)
{
    // empty
}


// HSM definition ------------------------------------------------------------
Q_STATE_DEF(BasicStateMachine, initial) {
    (void)e; // unused parameter
  PRINT("INIT");
    // arm the time event to expire in half a second and every half second
    return tran(&S11);
}
//............................................................................
Q_STATE_DEF(BasicStateMachine, S1) {
    QP::QState status;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            status = Q_RET_HANDLED;
            break;
        }
        case Q_EXIT_SIG:{
            status = Q_RET_HANDLED;
            break;
        }
        default: {
            status = super(&top);
            break;
        }
    }
    return status;
}
Q_STATE_DEF(BasicStateMachine, S11) {
    QP::QState status;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            status = Q_RET_HANDLED;
            break;
        }
        case Q_EXIT_SIG:{
            status = Q_RET_HANDLED;
            break;
        }
        default: {
            status = super(&top);
            break;
        }
    }
    return status;
}
Q_STATE_DEF(BasicStateMachine, S12) {
    QP::QState status;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            status = Q_RET_HANDLED;
            break;
        }
        case Q_EXIT_SIG:{
            status = Q_RET_HANDLED;
            break;
        }
        default: {
            status = super(&top);
            break;
        }
    }
    return status;
}
Q_STATE_DEF(BasicStateMachine, S121) {
    QP::QState status;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            status = Q_RET_HANDLED;
            break;
        }
        case Q_EXIT_SIG:{
            status = Q_RET_HANDLED;
            break;
        }
        default: {
            status = super(&top);
            break;
        }
    }
    return status;
}
Q_STATE_DEF(BasicStateMachine, S122) {
    QP::QState status;
    switch (e->sig) {
        case Q_ENTRY_SIG: {
            status = Q_RET_HANDLED;
            break;
        }
        case Q_EXIT_SIG:{
            status = Q_RET_HANDLED;
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

