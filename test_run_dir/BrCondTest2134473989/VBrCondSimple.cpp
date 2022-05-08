// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VBrCondSimple.h for the primary calling header

#include "VBrCondSimple.h"
#include "VBrCondSimple__Syms.h"

//==========

VL_CTOR_IMP(VBrCondSimple) {
    VBrCondSimple__Syms* __restrict vlSymsp = __VlSymsp = new VBrCondSimple__Syms(this, name());
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VBrCondSimple::__Vconfigure(VBrCondSimple__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VBrCondSimple::~VBrCondSimple() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VBrCondSimple::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VBrCondSimple::eval\n"); );
    VBrCondSimple__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("BrCondSimple.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VBrCondSimple::_eval_initial_loop(VBrCondSimple__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("BrCondSimple.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VBrCondSimple::_combo__TOP__1(VBrCondSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::_combo__TOP__1\n"); );
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->BrCondSimple__DOT__eq = ((IData)(vlTOPp->io_rs1) 
                                     == (IData)(vlTOPp->io_rs2));
    vlTOPp->BrCondSimple__DOT__lt = VL_LTS_III(1,8,8, (IData)(vlTOPp->io_rs1), (IData)(vlTOPp->io_rs2));
    vlTOPp->BrCondSimple__DOT__ltu = ((IData)(vlTOPp->io_rs1) 
                                      < (IData)(vlTOPp->io_rs2));
    vlTOPp->io_taken = (((((((3U == (IData)(vlTOPp->io_br_type)) 
                             & (IData)(vlTOPp->BrCondSimple__DOT__eq)) 
                            | ((6U == (IData)(vlTOPp->io_br_type)) 
                               & (~ (IData)(vlTOPp->BrCondSimple__DOT__eq)))) 
                           | ((2U == (IData)(vlTOPp->io_br_type)) 
                              & (IData)(vlTOPp->BrCondSimple__DOT__lt))) 
                          | ((5U == (IData)(vlTOPp->io_br_type)) 
                             & (~ (IData)(vlTOPp->BrCondSimple__DOT__lt)))) 
                         | ((1U == (IData)(vlTOPp->io_br_type)) 
                            & (IData)(vlTOPp->BrCondSimple__DOT__ltu))) 
                        | ((4U == (IData)(vlTOPp->io_br_type)) 
                           & (~ (IData)(vlTOPp->BrCondSimple__DOT__ltu))));
}

void VBrCondSimple::_eval(VBrCondSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::_eval\n"); );
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
}

void VBrCondSimple::_eval_initial(VBrCondSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::_eval_initial\n"); );
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VBrCondSimple::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::final\n"); );
    // Variables
    VBrCondSimple__Syms* __restrict vlSymsp = this->__VlSymsp;
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VBrCondSimple::_eval_settle(VBrCondSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::_eval_settle\n"); );
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VBrCondSimple::_change_request(VBrCondSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::_change_request\n"); );
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VBrCondSimple::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_br_type & 0xf8U))) {
        Verilated::overWidthError("io_br_type");}
}
#endif  // VL_DEBUG

void VBrCondSimple::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBrCondSimple::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_rs1 = VL_RAND_RESET_I(8);
    io_rs2 = VL_RAND_RESET_I(8);
    io_br_type = VL_RAND_RESET_I(3);
    io_taken = VL_RAND_RESET_I(1);
    BrCondSimple__DOT__eq = VL_RAND_RESET_I(1);
    BrCondSimple__DOT__lt = VL_RAND_RESET_I(1);
    BrCondSimple__DOT__ltu = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
