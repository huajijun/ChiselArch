// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAccum__Syms.h"


//======================

void VAccum::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VAccum::traceInit, &VAccum::traceFull, &VAccum::traceChg, this);
}
void VAccum::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VAccum* t = (VAccum*)userthis;
    VAccum__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VAccum::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAccum* t = (VAccum*)userthis;
    VAccum__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VAccum::traceInitThis(VAccum__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VAccum::traceFullThis(VAccum__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAccum::traceInitThis__1(VAccum__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+2,"clock", false,-1);
        vcdp->declBit(c+3,"reset", false,-1);
        vcdp->declBit(c+4,"io_in", false,-1);
        vcdp->declBus(c+5,"io_out", false,-1, 7,0);
        vcdp->declBit(c+2,"Accum clock", false,-1);
        vcdp->declBit(c+3,"Accum reset", false,-1);
        vcdp->declBit(c+4,"Accum io_in", false,-1);
        vcdp->declBus(c+5,"Accum io_out", false,-1, 7,0);
        vcdp->declBus(c+1,"Accum reg_", false,-1, 7,0);
    }
}

void VAccum::traceFullThis__1(VAccum__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAccum* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullCData(oldp+0,(vlTOPp->Accum__DOT__reg_),8);
        vcdp->fullBit(oldp+1,(vlTOPp->clock));
        vcdp->fullBit(oldp+2,(vlTOPp->reset));
        vcdp->fullBit(oldp+3,(vlTOPp->io_in));
        vcdp->fullCData(oldp+4,(vlTOPp->io_out),8);
    }
}
