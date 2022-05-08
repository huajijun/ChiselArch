// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAccum__Syms.h"


//======================

void VAccum::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAccum* t = (VAccum*)userthis;
    VAccum__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VAccum::traceChgThis(VAccum__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAccum::traceChgThis__2(VAccum__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgCData(oldp+0,(vlTOPp->Accum__DOT__reg_),8);
    }
}

void VAccum::traceChgThis__3(VAccum__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+2);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->clock));
        vcdp->chgBit(oldp+1,(vlTOPp->reset));
        vcdp->chgBit(oldp+2,(vlTOPp->io_in));
        vcdp->chgCData(oldp+3,(vlTOPp->io_out),8);
    }
}
