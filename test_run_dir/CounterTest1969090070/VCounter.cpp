// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCounter.h for the primary calling header

#include "VCounter.h"
#include "VCounter__Syms.h"

//==========

VL_CTOR_IMP(VCounter) {
    VCounter__Syms* __restrict vlSymsp = __VlSymsp = new VCounter__Syms(this, name());
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VCounter::__Vconfigure(VCounter__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VCounter::~VCounter() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VCounter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCounter::eval\n"); );
    VCounter__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Counter.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCounter::_eval_initial_loop(VCounter__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Counter.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VCounter::_sequent__TOP__1(VCounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_sequent__TOP__1\n"); );
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->Counter__DOT__REG = 0U;
    } else {
        if (vlTOPp->io_inc) {
            vlTOPp->Counter__DOT__REG = vlTOPp->Counter__DOT___T_1;
        }
    }
    vlTOPp->io_tot = vlTOPp->Counter__DOT__REG;
}

void VCounter::_settle__TOP__2(VCounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_settle__TOP__2\n"); );
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_tot = vlTOPp->Counter__DOT__REG;
    vlTOPp->Counter__DOT___T_1 = (0xffU & ((IData)(vlTOPp->Counter__DOT__REG) 
                                           + (IData)(vlTOPp->io_amt)));
}

VL_INLINE_OPT void VCounter::_combo__TOP__3(VCounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_combo__TOP__3\n"); );
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Counter__DOT___T_1 = (0xffU & ((IData)(vlTOPp->Counter__DOT__REG) 
                                           + (IData)(vlTOPp->io_amt)));
}

void VCounter::_eval(VCounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_eval\n"); );
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VCounter::_eval_initial(VCounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_eval_initial\n"); );
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VCounter::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::final\n"); );
    // Variables
    VCounter__Syms* __restrict vlSymsp = this->__VlSymsp;
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VCounter::_eval_settle(VCounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_eval_settle\n"); );
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VCounter::_change_request(VCounter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_change_request\n"); );
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCounter::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_inc & 0xfeU))) {
        Verilated::overWidthError("io_inc");}
    if (VL_UNLIKELY((io_amt & 0xf0U))) {
        Verilated::overWidthError("io_amt");}
}
#endif  // VL_DEBUG

void VCounter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCounter::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_inc = VL_RAND_RESET_I(1);
    io_amt = VL_RAND_RESET_I(4);
    io_tot = VL_RAND_RESET_I(8);
    Counter__DOT__REG = VL_RAND_RESET_I(8);
    Counter__DOT___T_1 = VL_RAND_RESET_I(8);
    __Vm_traceActivity = 0;
}
