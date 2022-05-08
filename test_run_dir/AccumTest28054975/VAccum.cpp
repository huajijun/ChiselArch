// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAccum.h for the primary calling header

#include "VAccum.h"
#include "VAccum__Syms.h"

//==========

VL_CTOR_IMP(VAccum) {
    VAccum__Syms* __restrict vlSymsp = __VlSymsp = new VAccum__Syms(this, name());
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VAccum::__Vconfigure(VAccum__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VAccum::~VAccum() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VAccum::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAccum::eval\n"); );
    VAccum__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Accum.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VAccum::_eval_initial_loop(VAccum__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Accum.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VAccum::_sequent__TOP__1(VAccum__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_sequent__TOP__1\n"); );
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->Accum__DOT__reg_ = 0U;
    } else {
        if (vlTOPp->io_in) {
            vlTOPp->Accum__DOT__reg_ = vlTOPp->Accum__DOT___T_1;
        }
    }
    vlTOPp->Accum__DOT___T_1 = (0xffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->Accum__DOT__reg_)));
    vlTOPp->io_out = vlTOPp->Accum__DOT__reg_;
}

void VAccum::_settle__TOP__2(VAccum__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_settle__TOP__2\n"); );
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Accum__DOT___T_1 = (0xffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->Accum__DOT__reg_)));
    vlTOPp->io_out = vlTOPp->Accum__DOT__reg_;
}

void VAccum::_eval(VAccum__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_eval\n"); );
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VAccum::_eval_initial(VAccum__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_eval_initial\n"); );
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VAccum::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::final\n"); );
    // Variables
    VAccum__Syms* __restrict vlSymsp = this->__VlSymsp;
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAccum::_eval_settle(VAccum__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_eval_settle\n"); );
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VAccum::_change_request(VAccum__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_change_request\n"); );
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VAccum::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_in & 0xfeU))) {
        Verilated::overWidthError("io_in");}
}
#endif  // VL_DEBUG

void VAccum::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAccum::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_in = VL_RAND_RESET_I(1);
    io_out = VL_RAND_RESET_I(8);
    Accum__DOT__reg_ = VL_RAND_RESET_I(8);
    Accum__DOT___T_1 = VL_RAND_RESET_I(8);
    __Vm_traceActivity = 0;
}
