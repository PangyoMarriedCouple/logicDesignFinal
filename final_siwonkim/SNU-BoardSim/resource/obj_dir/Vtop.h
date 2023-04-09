// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated.h"

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clk,0,0);
    VL_IN8(push_switch1,0,0);
    VL_IN8(push_switch2,0,0);
    VL_IN8(push_switch3,0,0);
    VL_IN8(push_switch4,0,0);
    VL_IN8(push_switch5,0,0);
    VL_IN8(push_switch6,0,0);
    VL_OUT8(segment1,6,0);
    VL_OUT8(segment2,6,0);
    VL_OUT8(segment3,6,0);
    VL_OUT8(segment4,6,0);
    VL_OUT8(segment5,6,0);
    VL_OUT8(segment6,6,0);
    VL_IN8(dip_switch1,0,0);
    VL_IN8(dip_switch2,0,0);
    VL_IN8(dip_switch3,0,0);
    VL_IN8(dip_switch4,0,0);
    VL_IN8(dip_switch5,0,0);
    VL_IN8(dip_switch6,0,0);
    VL_IN8(dip_switch7,0,0);
    VL_IN8(dip_switch8,0,0);
    VL_IN8(dip_switch9,0,0);
    VL_IN8(dip_switch10,0,0);
    VL_OUT8(led1_red,0,0);
    VL_OUT8(led2_yellow,0,0);
    VL_OUT8(led3_green,0,0);
    VL_OUT8(led4_red,0,0);
    VL_OUT8(led5_yellow,0,0);
    VL_OUT8(led6_green,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(top__DOT__m1__DOT__isUsing,2,0);
    VL_SIG8(top__DOT__m1__DOT__is12,0,0);
    VL_SIG8(top__DOT__m1__DOT__is12changed,0,0);
    VL_SIG8(top__DOT__m1__DOT__clockd1,6,0);
    VL_SIG8(top__DOT__m1__DOT__clockd2,6,0);
    VL_SIG8(top__DOT__m1__DOT__clockd3,6,0);
    VL_SIG8(top__DOT__m1__DOT__clockd4,6,0);
    VL_SIG8(top__DOT__m1__DOT__clockd5,6,0);
    VL_SIG8(top__DOT__m1__DOT__clockd6,6,0);
    VL_SIG8(top__DOT__m1__DOT__ad1,6,0);
    VL_SIG8(top__DOT__m1__DOT__ad2,6,0);
    VL_SIG8(top__DOT__m1__DOT__ad3,6,0);
    VL_SIG8(top__DOT__m1__DOT__ad4,6,0);
    VL_SIG8(top__DOT__m1__DOT__ad5,6,0);
    VL_SIG8(top__DOT__m1__DOT__ad6,6,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__blink,0,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__sec1,2,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__sec2,3,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__m1,2,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__m2,3,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__sec,5,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__m,5,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__h,5,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__is12,0,0);
    VL_SIG8(top__DOT__m1__DOT__c1__DOT__setStatus,1,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__sec1,2,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__sec2,3,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__m1,2,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__m2,3,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__setStatus,1,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__hasalarm,0,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__ah,5,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__am,5,0);
    VL_SIG8(top__DOT__m1__DOT__a1__DOT__asec,5,0);
    VL_SIG(top__DOT__m1__DOT__c1__DOT__blinkcounter,30,0);
    VL_SIG(top__DOT__m1__DOT__c1__DOT__counter1,26,0);
    VL_SIG(top__DOT__m1__DOT__a1__DOT__counter1,26,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__push_switch2,0,0);
    VL_SIG8(__Vclklast__TOP__push_switch1,0,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _initial__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
