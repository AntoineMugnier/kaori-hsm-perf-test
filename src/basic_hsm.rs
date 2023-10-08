use kaori_hsm::*;
use defmt::{Format, debug};

// Evt definition
#[derive(Format)]
pub enum BasicEvt {
    A,
    B,
    C,
    D,
}

pub struct BasicStateMachine {
    a: u8,
}

impl BasicStateMachine {
    pub fn new() -> BasicStateMachine {
        BasicStateMachine { a: 0 }
    }
}
//type BasicStateMachine = StateMachine<BasicData, BasicEvt>;

impl ProtoStateMachine for BasicStateMachine {
    type Evt = BasicEvt;

    fn init(&mut self) -> InitResult<Self> {
        debug!("TOP_INIT");
        init_transition!(S11)
    }
}

#[state(super_state= Top)]
impl State<S1> for BasicStateMachine {
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

    fn handle(&mut self, evt: &BasicEvt) -> HandleResult<Self> {
        match evt {
            BasicEvt::A => {
                debug!("S1-HANDLES-A");
                handled!()
            }
            BasicEvt::C => {
                debug!("S1-HANDLES-C");
                transition!(S122)
            }
            BasicEvt::D => {
                debug!("S1-HANDLES-D");
                transition!(S1)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S1)]
impl State<S11> for BasicStateMachine {
    fn exit(&mut self) {
        debug!("S11-EXIT");
    }

    fn entry(&mut self) {
        debug!("S11-ENTRY");
    }

    fn handle(&mut self, evt: &BasicEvt) -> HandleResult<Self> {
        match evt {
            BasicEvt::A => {
                debug!("S11-HANDLES-A");
                transition!(S121)
            }
            BasicEvt::B => {
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
impl State<S12> for BasicStateMachine {
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

    fn handle(&mut self, evt: &BasicEvt) -> HandleResult<Self> {
        match evt {
            BasicEvt::B => {
                debug!("S12-HANDLES-B");
                handled!()
            }
            BasicEvt::D => {
                debug!("S12-HANDLES-D");
                transition!(S121)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S12)]
impl State<S121> for BasicStateMachine {
    fn exit(&mut self) {
        debug!("S121-EXIT");
    }

    fn entry(&mut self) {
        debug!("S121-ENTRY");
    }

    fn handle(&mut self, evt: &BasicEvt) -> HandleResult<Self> {
        match evt {
            BasicEvt::A => {
                debug!("S121-HANDLES-A");
                transition!(S122)
            }
            BasicEvt::B => {
                debug!("S121-HANDLES-B");
                transition!(S12)
            }
            BasicEvt::C => {
                debug!("S121-HANDLES-C");
                transition!(S11)
            }
            _ => ignored!(),
        }
    }
}

#[state(super_state= S12)]
impl State<S122> for BasicStateMachine {
    fn exit(&mut self) {
        debug!("S122-EXIT");
    }

    fn entry(&mut self) {
        debug!("S122-ENTRY");
    }

    fn handle(&mut self, evt: &BasicEvt) -> HandleResult<Self> {
        match evt {
            BasicEvt::B => {
                debug!("S122-HANDLES-B");
                handled!()
            }
            BasicEvt::C => {
                debug!("S122-HANDLES-C");
                transition!(S122)
            }
            BasicEvt::D => {
                debug!("S122-HANDLES-D");
                transition!(S1)
            }
            _ => ignored!(),
        }
    }
}

