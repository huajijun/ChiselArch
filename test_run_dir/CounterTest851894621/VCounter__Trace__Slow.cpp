// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCounter__Syms.h"


//======================

void VCounter::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VCounter::traceInit, &VCounter::traceFull, &VCounter::traceChg, this);
}
void VCounter::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VCounter* t = (VCounter*)userthis;
    VCounter__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VCounter::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VCounter* t = (VCounter*)userthis;
    VCounter__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VCounter::traceInitThis(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VCounter::traceFullThis(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VCounter::traceInitThis__1(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+2,"clock", false,-1);
        vcdp->declBit(c+3,"reset", false,-1);
        vcdp->declBit(c+4,"io_inc", false,-1);
        vcdp->declBus(c+5,"io_amt", false,-1, 3,0);
        vcdp->declBus(c+6,"io_tot", false,-1, 7,0);
        vcdp->declBit(c+2,"Counter clock", false,-1);
        vcdp->declBit(c+3,"Counter reset", false,-1);
        vcdp->declBit(c+4,"Counter io_inc", false,-1);
        vcdp->declBus(c+5,"Counter io_amt", false,-1, 3,0);
        vcdp->declBus(c+6,"Counter io_tot", false,-1, 7,0);
        vcdp->declBus(c+1,"Counter REG", false,-1, 7,0);
    }
}

void VCounter::traceFullThis__1(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullCData(oldp+0,(vlTOPp->Counter__DOT__REG),8);
        vcdp->fullBit(oldp+1,(vlTOPp->clock));
        vcdp->fullBit(oldp+2,(vlTOPp->reset));
        vcdp->fullBit(oldp+3,(vlTOPp->io_inc));
        vcdp->fullCData(oldp+4,(vlTOPp->io_amt),4);
        vcdp->fullCData(oldp+5,(vlTOPp->io_tot),8);
    }
}
