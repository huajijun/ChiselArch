// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAdderS__Syms.h"


//======================

void VAdderS::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAdderS* t = (VAdderS*)userthis;
    VAdderS__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VAdderS::traceChgThis(VAdderS__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAdderS::traceChgThis__2(VAdderS__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->clock));
        vcdp->chgBit(oldp+1,(vlTOPp->reset));
        vcdp->chgCData(oldp+2,(vlTOPp->io_a),8);
        vcdp->chgCData(oldp+3,(vlTOPp->io_b),8);
        vcdp->chgCData(oldp+4,(vlTOPp->io_out),8);
    }
}
