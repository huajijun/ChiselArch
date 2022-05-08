// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAluSimple.h for the primary calling header

#include "VAluSimple.h"
#include "VAluSimple__Syms.h"

//==========

VL_CTOR_IMP(VAluSimple) {
    VAluSimple__Syms* __restrict vlSymsp = __VlSymsp = new VAluSimple__Syms(this, name());
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VAluSimple::__Vconfigure(VAluSimple__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VAluSimple::~VAluSimple() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VAluSimple::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAluSimple::eval\n"); );
    VAluSimple__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("AluSimple.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VAluSimple::_eval_initial_loop(VAluSimple__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("AluSimple.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VAluSimple::_combo__TOP__1(VAluSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::_combo__TOP__1\n"); );
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_out = (0xffU & (IData)((VL_ULL(0x7fffffffff) 
                                       & ((0xaU == (IData)(vlTOPp->io_alu_op))
                                           ? (QData)((IData)(vlTOPp->io_rs1))
                                           : ((4U == (IData)(vlTOPp->io_alu_op))
                                               ? (QData)((IData)(
                                                                 ((IData)(vlTOPp->io_rs1) 
                                                                  ^ (IData)(vlTOPp->io_rs2))))
                                               : ((3U 
                                                   == (IData)(vlTOPp->io_alu_op))
                                                   ? (QData)((IData)(
                                                                     ((IData)(vlTOPp->io_rs1) 
                                                                      | (IData)(vlTOPp->io_rs2))))
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->io_alu_op))
                                                    ? (QData)((IData)(
                                                                      ((IData)(vlTOPp->io_rs1) 
                                                                       & (IData)(vlTOPp->io_rs2))))
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlTOPp->io_alu_op))
                                                     ? (QData)((IData)(
                                                                       ((IData)(vlTOPp->io_rs1) 
                                                                        < (IData)(vlTOPp->io_rs2))))
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlTOPp->io_alu_op))
                                                      ? (QData)((IData)(
                                                                        VL_LTS_III(1,8,8, (IData)(vlTOPp->io_rs1), (IData)(vlTOPp->io_rs2))))
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->io_alu_op))
                                                       ? 
                                                      ((QData)((IData)(vlTOPp->io_rs1)) 
                                                       << 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->io_rs2)))
                                                       : (QData)((IData)(
                                                                         (0xffU 
                                                                          & ((9U 
                                                                              == (IData)(vlTOPp->io_alu_op))
                                                                              ? 
                                                                             ((IData)(vlTOPp->io_rs1) 
                                                                              >> 
                                                                              (0x1fU 
                                                                               & (IData)(vlTOPp->io_rs2)))
                                                                              : 
                                                                             ((1U 
                                                                               == (IData)(vlTOPp->io_alu_op))
                                                                               ? 
                                                                              ((IData)(vlTOPp->io_rs1) 
                                                                               - (IData)(vlTOPp->io_rs2))
                                                                               : 
                                                                              ((0U 
                                                                                == (IData)(vlTOPp->io_alu_op))
                                                                                ? 
                                                                               ((IData)(vlTOPp->io_rs1) 
                                                                                + (IData)(vlTOPp->io_rs2))
                                                                                : (IData)(vlTOPp->io_rs2)))))))))))))))));
    vlTOPp->io_sum = (0xffU & ((IData)(vlTOPp->io_rs1) 
                               + ((1U & (IData)(vlTOPp->io_alu_op))
                                   ? (- (IData)(vlTOPp->io_rs2))
                                   : (IData)(vlTOPp->io_rs2))));
}

void VAluSimple::_eval(VAluSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::_eval\n"); );
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VAluSimple::_eval_initial(VAluSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::_eval_initial\n"); );
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAluSimple::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::final\n"); );
    // Variables
    VAluSimple__Syms* __restrict vlSymsp = this->__VlSymsp;
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAluSimple::_eval_settle(VAluSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::_eval_settle\n"); );
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VAluSimple::_change_request(VAluSimple__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::_change_request\n"); );
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VAluSimple::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_alu_op & 0xf0U))) {
        Verilated::overWidthError("io_alu_op");}
}
#endif  // VL_DEBUG

void VAluSimple::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAluSimple::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_rs1 = VL_RAND_RESET_I(8);
    io_rs2 = VL_RAND_RESET_I(8);
    io_alu_op = VL_RAND_RESET_I(4);
    io_out = VL_RAND_RESET_I(8);
    io_sum = VL_RAND_RESET_I(8);
    __Vm_traceActivity = 0;
}
