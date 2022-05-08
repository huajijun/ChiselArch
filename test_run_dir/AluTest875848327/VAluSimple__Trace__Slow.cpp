// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAluSimple__Syms.h"


//======================

void VAluSimple::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VAluSimple::traceInit, &VAluSimple::traceFull, &VAluSimple::traceChg, this);
}
void VAluSimple::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VAluSimple* t = (VAluSimple*)userthis;
    VAluSimple__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VAluSimple::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAluSimple* t = (VAluSimple*)userthis;
    VAluSimple__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VAluSimple::traceInitThis(VAluSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VAluSimple::traceFullThis(VAluSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAluSimple::traceInitThis__1(VAluSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clock", false,-1);
        vcdp->declBit(c+2,"reset", false,-1);
        vcdp->declBus(c+3,"io_rs1", false,-1, 7,0);
        vcdp->declBus(c+4,"io_rs2", false,-1, 7,0);
        vcdp->declBus(c+5,"io_alu_op", false,-1, 3,0);
        vcdp->declBus(c+6,"io_out", false,-1, 7,0);
        vcdp->declBus(c+7,"io_sum", false,-1, 7,0);
        vcdp->declBit(c+1,"AluSimple clock", false,-1);
        vcdp->declBit(c+2,"AluSimple reset", false,-1);
        vcdp->declBus(c+3,"AluSimple io_rs1", false,-1, 7,0);
        vcdp->declBus(c+4,"AluSimple io_rs2", false,-1, 7,0);
        vcdp->declBus(c+5,"AluSimple io_alu_op", false,-1, 3,0);
        vcdp->declBus(c+6,"AluSimple io_out", false,-1, 7,0);
        vcdp->declBus(c+7,"AluSimple io_sum", false,-1, 7,0);
        vcdp->declBus(c+8,"AluSimple shamt", false,-1, 4,0);
    }
}

void VAluSimple::traceFullThis__1(VAluSimple__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAluSimple* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(oldp+0,(vlTOPp->clock));
        vcdp->fullBit(oldp+1,(vlTOPp->reset));
        vcdp->fullCData(oldp+2,(vlTOPp->io_rs1),8);
        vcdp->fullCData(oldp+3,(vlTOPp->io_rs2),8);
        vcdp->fullCData(oldp+4,(vlTOPp->io_alu_op),4);
        vcdp->fullCData(oldp+5,(vlTOPp->io_out),8);
        vcdp->fullCData(oldp+6,(vlTOPp->io_sum),8);
        vcdp->fullCData(oldp+7,((0x1fU & (IData)(vlTOPp->io_rs2))),5);
    }
}
