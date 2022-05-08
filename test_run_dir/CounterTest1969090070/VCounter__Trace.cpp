// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCounter__Syms.h"


//======================

void VCounter::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VCounter* t = (VCounter*)userthis;
    VCounter__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VCounter::traceChgThis(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VCounter::traceChgThis__2(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgCData(oldp+0,(vlTOPp->Counter__DOT__REG),8);
    }
}

void VCounter::traceChgThis__3(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+2);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->clock));
        vcdp->chgBit(oldp+1,(vlTOPp->reset));
        vcdp->chgBit(oldp+2,(vlTOPp->io_inc));
        vcdp->chgCData(oldp+3,(vlTOPp->io_amt),4);
        vcdp->chgCData(oldp+4,(vlTOPp->io_tot),8);
    }
}
