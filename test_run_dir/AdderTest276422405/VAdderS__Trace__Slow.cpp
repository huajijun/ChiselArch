// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAdderS__Syms.h"


//======================

void VAdderS::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VAdderS::traceInit, &VAdderS::traceFull, &VAdderS::traceChg, this);
}
void VAdderS::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VAdderS* t = (VAdderS*)userthis;
    VAdderS__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VAdderS::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAdderS* t = (VAdderS*)userthis;
    VAdderS__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VAdderS::traceInitThis(VAdderS__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VAdderS::traceFullThis(VAdderS__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAdderS::traceInitThis__1(VAdderS__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clock", false,-1);
        vcdp->declBit(c+2,"reset", false,-1);
        vcdp->declBus(c+3,"io_a", false,-1, 7,0);
        vcdp->declBus(c+4,"io_b", false,-1, 7,0);
        vcdp->declBus(c+5,"io_out", false,-1, 7,0);
        vcdp->declBit(c+1,"AdderS clock", false,-1);
        vcdp->declBit(c+2,"AdderS reset", false,-1);
        vcdp->declBus(c+3,"AdderS io_a", false,-1, 7,0);
        vcdp->declBus(c+4,"AdderS io_b", false,-1, 7,0);
        vcdp->declBus(c+5,"AdderS io_out", false,-1, 7,0);
    }
}

void VAdderS::traceFullThis__1(VAdderS__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdderS* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(oldp+0,(vlTOPp->clock));
        vcdp->fullBit(oldp+1,(vlTOPp->reset));
        vcdp->fullCData(oldp+2,(vlTOPp->io_a),8);
        vcdp->fullCData(oldp+3,(vlTOPp->io_b),8);
        vcdp->fullCData(oldp+4,(vlTOPp->io_out),8);
    }
}
