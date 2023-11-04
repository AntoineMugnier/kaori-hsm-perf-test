
extern "C" {
enum class INTERFACE_SIGNAL{
  A,
  B,
  C,
  D
};


const char* dispatch_evt(INTERFACE_SIGNAL sig);
}
