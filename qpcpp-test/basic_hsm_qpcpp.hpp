#include "qpcpp.hpp"

enum AppSignals : QP::QSignal {
    DUMMY_SIG = QP::Q_USER_SIG,
    MAX_PUB_SIG,  // the last published signal
    TIMEOUT_SIG,
    MAX_SIG       // the last signal
};

class Blinky : public QP::QHsm {

public:
    Blinky();

protected:
    Q_STATE_DECL(initial);
    Q_STATE_DECL(off);
    Q_STATE_DECL(on);
};


