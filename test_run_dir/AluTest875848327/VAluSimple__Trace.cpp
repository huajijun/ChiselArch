// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAluSimple__Syms.h"


//======================

void VAluSimple::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAluSimple* t = (VAluSimple*)userthis;
    VAluSimple__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VAluSimple::traceChgThis(VAluSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAluSimple::traceChgThis__2(VAluSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->clock));
        vcdp->chgBit(oldp+1,(vlTOPp->reset));
        vcdp->chgCData(oldp+2,(vlTOPp->io_rs1),8);
        vcdp->chgCData(oldp+3,(vlTOPp->io_rs2),8);
        vcdp->chgCData(oldp+4,(vlTOPp->io_alu_op),4);
        vcdp->chgCData(oldp+5,(vlTOPp->io_out),8);
        vcdp->chgCData(oldp+6,(vlTOPp->io_sum),8);
        vcdp->chgCData(oldp+7,((0x1fU & (IData)(vlTOPp->io_rs2))),5);
    }
}
