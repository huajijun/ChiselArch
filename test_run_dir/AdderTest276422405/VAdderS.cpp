// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAdderS.h for the primary calling header

#include "VAdderS.h"
#include "VAdderS__Syms.h"

//==========

VL_CTOR_IMP(VAdderS) {
    VAdderS__Syms* __restrict vlSymsp = __VlSymsp = new VAdderS__Syms(this, name());
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VAdderS::__Vconfigure(VAdderS__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VAdderS::~VAdderS() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VAdderS::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAdderS::eval\n"); );
    VAdderS__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("AdderS.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VAdderS::_eval_initial_loop(VAdderS__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("AdderS.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VAdderS::_combo__TOP__1(VAdderS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::_combo__TOP__1\n"); );
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_out = (0xffU & ((IData)(vlTOPp->io_a) 
                               + (IData)(vlTOPp->io_b)));
}

void VAdderS::_eval(VAdderS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::_eval\n"); );
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VAdderS::_eval_initial(VAdderS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::_eval_initial\n"); );
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAdderS::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::final\n"); );
    // Variables
    VAdderS__Syms* __restrict vlSymsp = this->__VlSymsp;
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAdderS::_eval_settle(VAdderS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::_eval_settle\n"); );
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VAdderS::_change_request(VAdderS__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::_change_request\n"); );
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VAdderS::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void VAdderS::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderS::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_a = VL_RAND_RESET_I(8);
    io_b = VL_RAND_RESET_I(8);
    io_out = VL_RAND_RESET_I(8);
    __Vm_traceActivity = 0;
}
