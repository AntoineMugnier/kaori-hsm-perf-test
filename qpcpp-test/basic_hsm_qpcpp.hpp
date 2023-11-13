#pragma once
#include "qpcpp.hpp"

enum AppSignals : QP::QSignal {
    DUMMY_SIG = QP::Q_USER_SIG,
    A,
    B,
    C,
    D
};

class BasicStateMachine : public QP::QHsm {

public:
    BasicStateMachine();

protected:
    Q_STATE_DECL(initial);
    Q_STATE_DECL(S1);
    Q_STATE_DECL(S2);
    Q_STATE_DECL(S11);
    Q_STATE_DECL(S12);
    Q_STATE_DECL(S121);
    Q_STATE_DECL(S122);
};


