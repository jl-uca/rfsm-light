Known bugs and limitations
--------------------------

* multi-FSM models are not supported (use `rfsmc` command-line compiler if required)

* Multi-events FSM models are not supported by the VHDL backend

* Synchronous interpretation of actions is not (yet) supported by the CTask and SystemC backends

* Types are limited to `event`, `int` and `bool` (sized ints available in the "full" RFSM language
  are not supported in particular)

* The concept of transition priority used in RFSM is not supported; as a result, simulation may fail due to
  non-deterministic situations.

* A portable way of building on Linux distros is still missing

* When running on a Mac M1 under Mac OS 12 - but this may also occur on other versions - when the Rfsm-Light, 
  app is launched by double-clicking, it seems unable to launch the gtkwave application. This does _not_ happen 
  when the app is launched from the terminal (by invoking "/Applications/Rfsm-light.app/Contents/MacOS/rfsm-light"
  from a terminal for example, or event "open /Applications/Rfsm-light.app").  