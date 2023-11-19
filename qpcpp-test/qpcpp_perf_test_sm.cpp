//$file${.::qpcpp_perf_test_sm.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: qpcpp_perf_test_sm.qm
// File:  ${.::qpcpp_perf_test_sm.cpp}
//
// This code has been generated by QM 5.3.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This generated code is open source software: you can redistribute it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// NOTE:
// Alternatively, this generated code may be distributed under the terms
// of Quantum Leaps commercial licenses, which expressly supersede the GNU
// General Public License and are specifically designed for licensees
// interested in retaining the proprietary status of their code.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${.::qpcpp_perf_test_sm.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "qpcpp_perf_test_sm.hpp"
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

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${HSM::QPCPPPerfTestSM} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${HSM::QPCPPPerfTestSM} ....................................................

//${HSM::QPCPPPerfTestSM::QPCPPPerfTestSM} ...................................
QPCPPPerfTestSM::QPCPPPerfTestSM()
: QP::QHsm(&initial)

{}

//${HSM::QPCPPPerfTestSM::SM} ................................................
Q_STATE_DEF(QPCPPPerfTestSM, initial) {
    //${HSM::QPCPPPerfTestSM::SM::initial}
    PRINT("TOP_INIT");
    return tran(&S1);
}

//${HSM::QPCPPPerfTestSM::SM::S1} ............................................
Q_STATE_DEF(QPCPPPerfTestSM, S1) {
    QP::QState status_;
    switch (e->sig) {
        //${HSM::QPCPPPerfTestSM::SM::S1::initial}
        case Q_INIT_SIG: {
            PRINT("S1-INIT");
            status_ = tran(&S12);
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::A}
        case A_SIG: {
            PRINT("S1-HANDLES-A");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::D}
        case D_SIG: {
            PRINT("S1-HANDLES-D");
            status_ = tran(&S1212);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}

//${HSM::QPCPPPerfTestSM::SM::S1::S12} .......................................
Q_STATE_DEF(QPCPPPerfTestSM, S12) {
    QP::QState status_;
    switch (e->sig) {
        //${HSM::QPCPPPerfTestSM::SM::S1::S12}
        case Q_ENTRY_SIG: {
            PRINT("S12-ENTRY");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12}
        case Q_EXIT_SIG: {
            PRINT("S12-EXIT");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::initial}
        case Q_INIT_SIG: {
            PRINT("S12-INIT");
            status_ = tran(&S121);
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::B}
        case B_SIG: {
            PRINT("S12-HANDLES-B");
            status_ = tran(&S111);
            break;
        }
        default: {
            status_ = super(&S1);
            break;
        }
    }
    return status_;
}

//${HSM::QPCPPPerfTestSM::SM::S1::S12::S121} .................................
Q_STATE_DEF(QPCPPPerfTestSM, S121) {
    QP::QState status_;
    switch (e->sig) {
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121}
        case Q_ENTRY_SIG: {
            PRINT("S121-ENTRY");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121}
        case Q_EXIT_SIG: {
            PRINT("S121-EXIT");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::initial}
        case Q_INIT_SIG: {
            PRINT("S121-INIT");
            status_ = tran(&S1211);
            break;
        }
        default: {
            status_ = super(&S12);
            break;
        }
    }
    return status_;
}

//${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1211} ..........................
Q_STATE_DEF(QPCPPPerfTestSM, S1211) {
    QP::QState status_;
    switch (e->sig) {
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1211}
        case Q_ENTRY_SIG: {
            PRINT("S1211-ENTRY");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1211}
        case Q_EXIT_SIG: {
            PRINT("S1211-EXIT");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1211::B}
        case B_SIG: {
            PRINT("S1211-HANDLES-B");
            status_ = tran(&S1212);
            break;
        }
        default: {
            status_ = super(&S121);
            break;
        }
    }
    return status_;
}

//${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1212} ..........................
Q_STATE_DEF(QPCPPPerfTestSM, S1212) {
    QP::QState status_;
    switch (e->sig) {
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1212}
        case Q_ENTRY_SIG: {
            PRINT("S1212-ENTRY");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1212}
        case Q_EXIT_SIG: {
            PRINT("S1212-EXIT");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1212::C}
        case C_SIG: {
            PRINT("S1212-HANDLES-C");
            status_ = tran(&S1212);
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S12::S121::S1212::B}
        case B_SIG: {
            PRINT("S1212-HANDLES-B");
            status_ = tran(&S1211);
            break;
        }
        default: {
            status_ = super(&S121);
            break;
        }
    }
    return status_;
}

//${HSM::QPCPPPerfTestSM::SM::S1::S11} .......................................
Q_STATE_DEF(QPCPPPerfTestSM, S11) {
    QP::QState status_;
    switch (e->sig) {
        //${HSM::QPCPPPerfTestSM::SM::S1::S11}
        case Q_ENTRY_SIG: {
            PRINT("S11-ENTRY");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S11}
        case Q_EXIT_SIG: {
            PRINT("S11-EXIT");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S11::initial}
        case Q_INIT_SIG: {
            PRINT("S11-INIT");
            status_ = tran(&S111);
            break;
        }
        default: {
            status_ = super(&S1);
            break;
        }
    }
    return status_;
}

//${HSM::QPCPPPerfTestSM::SM::S1::S11::S111} .................................
Q_STATE_DEF(QPCPPPerfTestSM, S111) {
    QP::QState status_;
    switch (e->sig) {
        //${HSM::QPCPPPerfTestSM::SM::S1::S11::S111}
        case Q_ENTRY_SIG: {
            PRINT("S111-ENTRY");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S11::S111}
        case Q_EXIT_SIG: {
            PRINT("S111-ENTRY");
            status_ = Q_RET_HANDLED;
            break;
        }
        //${HSM::QPCPPPerfTestSM::SM::S1::S11::S111::B}
        case B_SIG: {
            PRINT("S111-HANDLES-B");
            status_ = tran(&S1211);
            break;
        }
        default: {
            status_ = super(&S11);
            break;
        }
    }
    return status_;
}
//$enddef${HSM::QPCPPPerfTestSM} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
