use kaori_hsm::*;
use defmt::{Format, debug};

// Evt definition
#[derive(Format, Debug, Clone, Copy)]
pub enum SMEvent {
    A,
    B,
    C,
    D,
}

pub struct KaoriPerfTestSM {
    a: u8,
}

impl KaoriPerfTestSM {
    pub fn new() -> KaoriPerfTestSM {
        KaoriPerfTestSM { a: 0 }
    }
}
//type KaoriPerfTestSM = StateMachine<BasicData, SMEvent>;

impl ProtoStateMachine for KaoriPerfTestSM {
    type Evt = SMEvent;

    fn init(&mut self) -> InitResult<Self> {
        debug!("TOP_INIT");
        init_transition!(S11)
    }
}

#[state(super_state= Top)]
impl State<S1> for KaoriPerfTestSM {
    fn init(&mut self) -> InitResult<Self> {
        debug!("S1-INIT");
        init_transition!(S11)
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
            SMEvent::C => {
                debug!("S1-HANDLES-C");
                transition!(S122)
            }
            SMEvent::D => {
                debug!("S1-HANDLES-D");
                transition!(S1)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S1)]
impl State<S11> for KaoriPerfTestSM {
    fn exit(&mut self) {
        debug!("S11-EXIT");
    }

    fn entry(&mut self) {
        debug!("S11-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::A => {
                debug!("S11-HANDLES-A");
                transition!(S121)
            }
            SMEvent::B => {
                debug!("S11-HANDLES-B");

                self.a += 1;

                if self.a == 2 {
                    self.a = 0;
                    transition!(S12)
                } else {
                    ignored!()
                }
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
            SMEvent::B => {
                debug!("S12-HANDLES-B");
                handled!()
            }
            SMEvent::D => {
                debug!("S12-HANDLES-D");
                transition!(S121)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S12)]
impl State<S121> for KaoriPerfTestSM {
    fn exit(&mut self) {
        debug!("S121-EXIT");
    }

    fn entry(&mut self) {
        debug!("S121-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::A => {
                debug!("S121-HANDLES-A");
                transition!(S122)
            }
            SMEvent::B => {
                debug!("S121-HANDLES-B");
                transition!(S12)
            }
            SMEvent::C => {
                debug!("S121-HANDLES-C");
                transition!(S11)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S12)]
impl State<S122> for KaoriPerfTestSM {
    fn exit(&mut self) {
        debug!("S122-EXIT");
    }

    fn entry(&mut self) {
        debug!("S122-ENTRY");
    }

    fn handle(&mut self, evt: &SMEvent) -> HandleResult<Self> {
        match evt {
            SMEvent::B => {
                debug!("S122-HANDLES-B");
                handled!()
            }
            SMEvent::C => {
                debug!("S122-HANDLES-C");
                transition!(S122)
            }
            SMEvent::D => {
                debug!("S122-HANDLES-D");
                transition!(S1)
            }
            _ => ignored!(),
        }
    }
}

