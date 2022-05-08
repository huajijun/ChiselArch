// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VBrCondSimple__Syms.h"


//======================

void VBrCondSimple::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VBrCondSimple::traceInit, &VBrCondSimple::traceFull, &VBrCondSimple::traceChg, this);
}
void VBrCondSimple::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VBrCondSimple* t = (VBrCondSimple*)userthis;
    VBrCondSimple__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VBrCondSimple::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VBrCondSimple* t = (VBrCondSimple*)userthis;
    VBrCondSimple__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VBrCondSimple::traceInitThis(VBrCondSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VBrCondSimple::traceFullThis(VBrCondSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VBrCondSimple::traceInitThis__1(VBrCondSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+7,"clock", false,-1);
        vcdp->declBit(c+8,"reset", false,-1);
        vcdp->declBus(c+9,"io_rs1", false,-1, 7,0);
        vcdp->declBus(c+10,"io_rs2", false,-1, 7,0);
        vcdp->declBus(c+11,"io_br_type", false,-1, 2,0);
        vcdp->declBit(c+12,"io_taken", false,-1);
        vcdp->declBit(c+7,"BrCondSimple clock", false,-1);
        vcdp->declBit(c+8,"BrCondSimple reset", false,-1);
        vcdp->declBus(c+9,"BrCondSimple io_rs1", false,-1, 7,0);
        vcdp->declBus(c+10,"BrCondSimple io_rs2", false,-1, 7,0);
        vcdp->declBus(c+11,"BrCondSimple io_br_type", false,-1, 2,0);
        vcdp->declBit(c+12,"BrCondSimple io_taken", false,-1);
        vcdp->declBit(c+1,"BrCondSimple eq", false,-1);
        vcdp->declBit(c+2,"BrCondSimple neq", false,-1);
        vcdp->declBit(c+3,"BrCondSimple lt", false,-1);
        vcdp->declBit(c+4,"BrCondSimple ge", false,-1);
        vcdp->declBit(c+5,"BrCondSimple ltu", false,-1);
        vcdp->declBit(c+6,"BrCondSimple geu", false,-1);
    }
}

void VBrCondSimple::traceFullThis__1(VBrCondSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VBrCondSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(oldp+0,(vlTOPp->BrCondSimple__DOT__eq));
        vcdp->fullBit(oldp+1,((1U & (~ (IData)(vlTOPp->BrCondSimple__DOT__eq)))));
        vcdp->fullBit(oldp+2,(vlTOPp->BrCondSimple__DOT__lt));
        vcdp->fullBit(oldp+3,((1U & (~ (IData)(vlTOPp->BrCondSimple__DOT__lt)))));
        vcdp->fullBit(oldp+4,(vlTOPp->BrCondSimple__DOT__ltu));
        vcdp->fullBit(oldp+5,((1U & (~ (IData)(vlTOPp->BrCondSimple__DOT__ltu)))));
        vcdp->fullBit(oldp+6,(vlTOPp->clock));
        vcdp->fullBit(oldp+7,(vlTOPp->reset));
        vcdp->fullCData(oldp+8,(vlTOPp->io_rs1),8);
        vcdp->fullCData(oldp+9,(vlTOPp->io_rs2),8);
        vcdp->fullCData(oldp+10,(vlTOPp->io_br_type),3);
        vcdp->fullBit(oldp+11,(vlTOPp->io_taken));
    }
}
