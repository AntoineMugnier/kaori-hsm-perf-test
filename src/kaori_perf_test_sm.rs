use defmt::{debug, Format};
use kaori_hsm::*;

// Evt definition
#[derive(Format, Debug, Clone, Copy)]
pub enum SMEvent {
    A,
    B,
    C,
    D,
}

pub struct KaoriPerfTestSM {}

impl KaoriPerfTestSM {
    pub fn new() -> KaoriPerfTestSM {
        KaoriPerfTestSM {}
    }
}
//type KaoriPerfTestSM = StateMachine<BasicData, SMEvent>;

impl ProtoStateMachine for KaoriPerfTestSM {
    type Evt = SMEvent;

    fn init(&mut self) -> InitResult<Self> {
        debug!("TOP_INIT");
        init_transition!(S1)
    }
}

#[state(super_state= Top)]
impl State<S1> for KaoriPerfTestSM {
    fn init(&mut self) -> InitResult<Self> {
        debug!("S1-INIT");
        init_transition!(S12)
    }

    fn exit(&mut self) {
        debug!("S1-EXIT");
    }

    fn entry(&mut self) {
        debug!("S1-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::A => {
                debug!("S1-HANDLES-A");
                handled!()
            }
            SMEvent::D => {
                debug!("S1-HANDLES-D");
                transition!(S1212)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S1)]
impl State<S11> for KaoriPerfTestSM {
    fn init(&mut self) -> InitResult<Self> {
        debug!("S11-INIT");
        init_transition!(S111)
    }

    fn exit(&mut self) {
        debug!("S11-EXIT");
    }

    fn entry(&mut self) {
        debug!("S11-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            _ => ignored!(),
        }
    }
}
#[state(super_state= S11)]
impl State<S111> for KaoriPerfTestSM {
    fn exit(&mut self) {
        debug!("S111-EXIT");
    }

    fn entry(&mut self) {
        debug!("S111-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::B => {
                debug!("S111-HANDLES-B");
                transition!(S1211)
            }
            _ => ignored!(),
        }
    }
}
#[state(super_state= S1)]
impl State<S12> for KaoriPerfTestSM {
    fn init(&mut self) -> InitResult<Self> {
        debug!("S12-INIT");
        init_transition!(S121)
    }

    fn exit(&mut self) {
        debug!("S12-EXIT");
    }

    fn entry(&mut self) {
        debug!("S12-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::C => {
                debug!("S12-HANDLES-C");
                transition!(S111)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S12)]
impl State<S121> for KaoriPerfTestSM {
    fn init(&mut self) -> InitResult<Self> {
        debug!("S121-INIT");
        init_transition!(S1211)
    }

    fn exit(&mut self) {
        debug!("S121-EXIT");
    }

    fn entry(&mut self) {
        debug!("S121-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            _ => ignored!(),
        }
    }
}

#[state(super_state= S121)]
impl State<S1211> for KaoriPerfTestSM {
    fn exit(&mut self) {
        debug!("S1211-EXIT");
    }

    fn entry(&mut self) {
        debug!("S1211-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::B => {
                debug!("S1211-HANDLES-B");
                transition!(S1212)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S121)]
impl State<S1212> for KaoriPerfTestSM {
    fn exit(&mut self) {
        debug!("S1212-EXIT");
    }

    fn entry(&mut self) {
        debug!("S1212-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::B => {
                debug!("S1212-HANDLES-B");
                transition!(S1211)
            }
            SMEvent::C => {
                debug!("S1212-HANDLES-C");
                transition!(S1212)
            }
            _ => ignored!(),
        }
    }
}
