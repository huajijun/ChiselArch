// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VBrCondSimple__Syms.h"


//======================

void VBrCondSimple::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VBrCondSimple* t = (VBrCondSimple*)userthis;
    VBrCondSimple__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VBrCondSimple::traceChgThis(VBrCondSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VBrCondSimple::traceChgThis__2(VBrCondSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->BrCondSimple__DOT__eq));
        vcdp->chgBit(oldp+1,((1U & (~ (IData)(vlTOPp->BrCondSimple__DOT__eq)))));
        vcdp->chgBit(oldp+2,(vlTOPp->BrCondSimple__DOT__lt));
        vcdp->chgBit(oldp+3,((1U & (~ (IData)(vlTOPp->BrCondSimple__DOT__lt)))));
        vcdp->chgBit(oldp+4,(vlTOPp->BrCondSimple__DOT__ltu));
        vcdp->chgBit(oldp+5,((1U & (~ (IData)(vlTOPp->BrCondSimple__DOT__ltu)))));
    }
}

void VBrCondSimple::traceChgThis__3(VBrCondSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+7);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->clock));
        vcdp->chgBit(oldp+1,(vlTOPp->reset));
        vcdp->chgCData(oldp+2,(vlTOPp->io_rs1),8);
        vcdp->chgCData(oldp+3,(vlTOPp->io_rs2),8);
        vcdp->chgCData(oldp+4,(vlTOPp->io_br_type),3);
        vcdp->chgBit(oldp+5,(vlTOPp->io_taken));
    }
}
