// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//modeControl.v:66
    if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
	vlTOPp->top__DOT__m1__DOT__isUsing = 3U;
    } else {
	if ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
	    vlTOPp->top__DOT__m1__DOT__isUsing = 1U;
	}
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//stopwatch.v:72
    vlTOPp->top__DOT__m1__DOT__stopwatchled1 = 0U;
    // ALWAYS at ../..//stopwatch.v:72
    if (vlTOPp->push_switch6) {
	vlTOPp->top__DOT__m1__DOT__s1__DOT__m = 0U;
	vlTOPp->top__DOT__m1__DOT__s1__DOT__sec = 0U;
	vlTOPp->top__DOT__m1__DOT__s1__DOT__msec = 0U;
	vlTOPp->top__DOT__m1__DOT__s1__DOT__isrunning = 0U;
    }
    if (vlTOPp->top__DOT__m1__DOT__s1__DOT__isrunning) {
	if (vlTOPp->top__DOT__m1__DOT__s1__DOT__isrunning) {
	    if ((0x4e20U > vlTOPp->top__DOT__m1__DOT__s1__DOT__counter1)) {
		vlTOPp->top__DOT__m1__DOT__s1__DOT__counter1 
		    = (0x7ffffffU & ((IData)(1U) + vlTOPp->top__DOT__m1__DOT__s1__DOT__counter1));
	    } else {
		vlTOPp->top__DOT__m1__DOT__s1__DOT__msec 
		    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec)));
		vlTOPp->top__DOT__m1__DOT__s1__DOT__counter1 = 0U;
	    }
	    if (vlTOPp->push_switch2) {
		if ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		    vlTOPp->top__DOT__m1__DOT__s1__DOT__isrunning = 0U;
		}
	    }
	}
    } else {
	if (vlTOPp->push_switch2) {
	    if ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		vlTOPp->top__DOT__m1__DOT__s1__DOT__counter1 = 0U;
		vlTOPp->top__DOT__m1__DOT__s1__DOT__isrunning = 1U;
	    }
	}
	if (vlTOPp->push_switch3) {
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__m = 0U;
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec = 0U;
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec = 0U;
	}
    }
    if ((0x63U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
	vlTOPp->top__DOT__m1__DOT__s1__DOT__sec = (0x7fU 
						   & ((IData)(1U) 
						      + (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec)));
	vlTOPp->top__DOT__m1__DOT__s1__DOT__msec = 0U;
    }
    if ((0x3bU < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec))) {
	vlTOPp->top__DOT__m1__DOT__s1__DOT__sec = 0U;
	if ((0x3bU > (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m))) {
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__m = 
		(0x7fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m)));
	} else {
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec = 0x3bU;
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec = 0x63U;
	}
    }
    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m))) {
	vlTOPp->top__DOT__m1__DOT__s1__DOT__m1 = 5U;
	vlTOPp->top__DOT__m1__DOT__s1__DOT__m2 = (0xfU 
						  & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m) 
						     - (IData)(2U)));
    } else {
	if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m))) {
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__m1 = 4U;
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__m2 
		= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m) 
			   - (IData)(8U)));
	} else {
	    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m))) {
		vlTOPp->top__DOT__m1__DOT__s1__DOT__m1 = 3U;
		vlTOPp->top__DOT__m1__DOT__s1__DOT__m2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m) 
			       - (IData)(0xeU)));
	    } else {
		if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m))) {
		    vlTOPp->top__DOT__m1__DOT__s1__DOT__m1 = 2U;
		    vlTOPp->top__DOT__m1__DOT__s1__DOT__m2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m) 
				   - (IData)(4U)));
		} else {
		    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m))) {
			vlTOPp->top__DOT__m1__DOT__s1__DOT__m1 = 1U;
			vlTOPp->top__DOT__m1__DOT__s1__DOT__m2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m) 
				       - (IData)(0xaU)));
		    } else {
			vlTOPp->top__DOT__m1__DOT__s1__DOT__m1 = 0U;
			vlTOPp->top__DOT__m1__DOT__s1__DOT__m2 
			    = (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m));
		    }
		}
	    }
	}
    }
    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec))) {
	vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1 = 5U;
	vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2 = 
	    (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec) 
		     - (IData)(2U)));
    } else {
	if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec))) {
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1 = 4U;
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2 
		= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec) 
			   - (IData)(8U)));
	} else {
	    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec))) {
		vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1 = 3U;
		vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec) 
			       - (IData)(0xeU)));
	    } else {
		if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec))) {
		    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1 = 2U;
		    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec) 
				   - (IData)(4U)));
		} else {
		    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec))) {
			vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1 = 1U;
			vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec) 
				       - (IData)(0xaU)));
		    } else {
			vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1 = 0U;
			vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2 
			    = (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec));
		    }
		}
	    }
	}
    }
    if ((0x59U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
	vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 9U;
	vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 = 
	    (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
		     - (IData)(0xaU)));
    } else {
	if ((0x4fU < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 8U;
	    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
		= (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec));
	} else {
	    if ((0x45U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
		vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 7U;
		vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
			       - (IData)(6U)));
	    } else {
		if ((0x3bU < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
		    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 6U;
		    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
				   - (IData)(0xcU)));
		} else {
		    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
			vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 5U;
			vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
				       - (IData)(2U)));
		    } else {
			if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
			    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 4U;
			    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
				= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
					   - (IData)(8U)));
			} else {
			    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
				vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 3U;
				vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
				    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
					       - (IData)(0xeU)));
			    } else {
				if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
				    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 2U;
				    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
					= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
						   - (IData)(4U)));
				} else {
				    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec))) {
					vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 1U;
					vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
					    = (0xfU 
					       & ((IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec) 
						  - (IData)(0xaU)));
				    } else {
					vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 0U;
					vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 
					    = (0xfU 
					       & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec));
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__m1__DOT__stopwatchd1 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m1))
						     ? 0x30U
						     : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__stopwatchd2 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__m2))
						     ? 0x30U
						     : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__stopwatchd3 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1))
						     ? 0x30U
						     : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__stopwatchd4 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2))
						     ? 0x30U
						     : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__stopwatchd5 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1))
						     ? 0x30U
						     : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__stopwatchd6 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2))
						     ? 0x30U
						     : 0x7eU))));
    // ALWAYS at ../..//calendar.v:87
    if (vlTOPp->push_switch6) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__y = 0U;
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__m = 1U;
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 1U;
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil = 0U;
    }
    if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus))) {
	if (vlTOPp->push_switch2) {
	    if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 = 0U;
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus = 1U;
	    }
	}
    } else {
	if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus))) {
	    if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1)) {
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 
		    = (0x7ffffffU & ((IData)(1U) + vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1));
	    } else {
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 = 0U;
		if (vlTOPp->push_switch3) {
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y 
			= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y)));
		}
		if (vlTOPp->push_switch4) {
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y 
			= (0x7fU & ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))
				     ? 0x63U : ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
						- (IData)(1U))));
		}
	    }
	    if (vlTOPp->push_switch2) {
		if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus = 2U;
		}
	    }
	} else {
	    if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus))) {
		if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1)) {
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 
			= (0x7ffffffU & ((IData)(1U) 
					 + vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1));
		} else {
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 = 0U;
		    if (vlTOPp->push_switch3) {
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__m 
			    = (0xfU & ((IData)(1U) 
				       + (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m)));
		    }
		    if (vlTOPp->push_switch4) {
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__m 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m) 
				       - (IData)(1U)));
		    }
		}
		if (vlTOPp->push_switch2) {
		    if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus = 3U;
		    }
		}
	    } else {
		if ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus))) {
		    if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1)) {
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 
			    = (0x7ffffffU & ((IData)(1U) 
					     + vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1));
		    } else {
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 = 0U;
			if (vlTOPp->push_switch3) {
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day 
				= (0x3fU & ((IData)(1U) 
					    + (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day)));
			}
			if (vlTOPp->push_switch4) {
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day 
				= (0x3fU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day) 
					    - (IData)(1U)));
			}
		    }
		    if (vlTOPp->push_switch2) {
			if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus = 4U;
			}
		    }
		} else {
		    if ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus))) {
			if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1)) {
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 
				= (0x7ffffffU & ((IData)(1U) 
						 + vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1));
			} else {
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 = 0U;
			    if (vlTOPp->push_switch3) {
				vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil 
				    = (0xfU & ((IData)(1U) 
					       + (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil)));
			    }
			    if (vlTOPp->push_switch4) {
				vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil 
				    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil) 
					       - (IData)(1U)));
			    }
			}
			if (vlTOPp->push_switch2) {
			    if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
				vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus = 0U;
			    }
			}
		    }
		}
	    }
	}
    }
    if ((0x63U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__y = 0U;
    }
    if ((0xcU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__m = 1U;
    }
    if ((1U > (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__m = 0xcU;
    }
    if ((((((((1U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m)) 
	      | (3U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) 
	     | (5U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) 
	    | (7U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) 
	   | (8U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) 
	  | (0xaU == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) 
	 | (0xcU == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m)))) {
	if ((0x1fU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 1U;
	}
	if ((1U > (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 0x1fU;
	}
    }
    if (((((4U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m)) 
	   | (6U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) 
	  | (9U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) 
	 | (0xbU == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m)))) {
	if ((0x1eU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 1U;
	}
	if ((1U > (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 0x1eU;
	}
    }
    if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) {
	if ((0x1cU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 1U;
	}
	if ((1U > (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 0x1cU;
	}
    }
    if ((6U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil = 0U;
    }
    if ((0x59U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 9U;
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 = 
	    (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
		     - (IData)(0xaU)));
    } else {
	if ((0x4fU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 8U;
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
		= (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y));
	} else {
	    if ((0x45U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 7U;
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
			       - (IData)(6U)));
	    } else {
		if ((0x3bU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 6U;
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
				   - (IData)(0xcU)));
		} else {
		    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 5U;
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
				       - (IData)(2U)));
		    } else {
			if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 4U;
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
				= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
					   - (IData)(8U)));
			} else {
			    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
				vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 3U;
				vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
				    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
					       - (IData)(0xeU)));
			    } else {
				if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
				    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 2U;
				    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
					= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
						   - (IData)(4U)));
				} else {
				    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y))) {
					vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 1U;
					vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
					    = (0xfU 
					       & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y) 
						  - (IData)(0xaU)));
				    } else {
					vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 0U;
					vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 
					    = (0xfU 
					       & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y));
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__m1 = 1U;
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2 = 
	    (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m) 
		     - (IData)(0xaU)));
    } else {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__m1 = 0U;
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2 = vlTOPp->top__DOT__m1__DOT__cal1__DOT__m;
    }
    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1 = 3U;
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2 
	    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day) 
		       - (IData)(0xeU)));
    } else {
	if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1 = 2U;
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2 
		= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day) 
			   - (IData)(4U)));
	} else {
	    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day))) {
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1 = 1U;
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day) 
			       - (IData)(0xaU)));
	    } else {
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1 = 0U;
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2 
		    = (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day));
	    }
	}
    }
    vlTOPp->top__DOT__m1__DOT__calendard1 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
					      ? ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						  ? 0U
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						   ? 0U
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						    ? 0x7bU
						    : 0x7fU)))
					      : ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						    ? 0x70U
						    : 0x5fU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						    ? 0x5bU
						    : 0x33U))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						    ? 0x79U
						    : 0x6dU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1))
						    ? 0x30U
						    : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__calendard2 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
					      ? ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						  ? 0U
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						   ? 0U
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						    ? 0x7bU
						    : 0x7fU)))
					      : ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						    ? 0x70U
						    : 0x5fU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						    ? 0x5bU
						    : 0x33U))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						    ? 0x79U
						    : 0x6dU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2))
						    ? 0x30U
						    : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__calendard3 = ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m1)
					      ? ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m1)
						  ? 0x30U
						  : 0U)
					      : 0x7eU);
    vlTOPp->top__DOT__m1__DOT__calendard4 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
					      ? ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						  ? 0U
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						   ? 0U
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						    ? 0x7bU
						    : 0x7fU)))
					      : ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						    ? 0x70U
						    : 0x5fU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						    ? 0x5bU
						    : 0x33U))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						    ? 0x79U
						    : 0x6dU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2))
						    ? 0x30U
						    : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__calendard5 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1))
					      ? 0U : 
					     ((4U & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1))
					       ? 0U
					       : ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1))
						    ? 0x79U
						    : 0x6dU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1))
						    ? 0x30U
						    : 0x7eU))));
    vlTOPp->top__DOT__m1__DOT__calendard6 = ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
					      ? ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						  ? 0U
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						   ? 0U
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						    ? 0x7bU
						    : 0x7fU)))
					      : ((4U 
						  & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						    ? 0x70U
						    : 0x5fU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						    ? 0x5bU
						    : 0x33U))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						    ? 0x79U
						    : 0x6dU)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2))
						    ? 0x30U
						    : 0x7eU))));
    if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
	vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 0x3fU;
    } else {
	if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
	    vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 0x20U;
	} else {
	    if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
		vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 0x10U;
	    } else {
		if ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
		    vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 8U;
		} else {
		    if ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
			vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 4U;
		    } else {
			if ((5U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
			    vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 2U;
			} else {
			    if ((6U == (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil))) {
				vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__m1__DOT__calendarled1 = (1U & 
					       ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit) 
						>> 5U));
    vlTOPp->top__DOT__m1__DOT__calendarled2 = (1U & 
					       ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit) 
						>> 4U));
    vlTOPp->top__DOT__m1__DOT__calendarled3 = (1U & 
					       ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit) 
						>> 3U));
    vlTOPp->top__DOT__m1__DOT__calendarled4 = (1U & 
					       ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit) 
						>> 2U));
    vlTOPp->top__DOT__m1__DOT__calendarled5 = (1U & 
					       ((IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit) 
						>> 1U));
    vlTOPp->top__DOT__m1__DOT__calendarled6 = (1U & (IData)(vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit));
}

void Vtop::_initial__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ../..//stopwatch.v:58
    vlTOPp->top__DOT__m1__DOT__s1__DOT__m = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__counter1 = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__isrunning = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__m1 = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__m2 = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec1 = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__sec2 = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec1 = 0U;
    vlTOPp->top__DOT__m1__DOT__s1__DOT__msec2 = 0U;
    // INITIAL at ../..//calendar.v:65
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__led6bit = 0x3fU;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y1 = 0U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y2 = 0U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__m1 = 0U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__m2 = 1U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day1 = 0U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day2 = 1U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__setStatus = 0U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__counter1 = 0U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__y = 0U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__m = 1U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__day = 1U;
    vlTOPp->top__DOT__m1__DOT__cal1__DOT__yoil = 0U;
    // INITIAL at ../..//modeControl.v:62
    vlTOPp->top__DOT__m1__DOT__isUsing = 1U;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment1 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard1)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd1)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard1)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment2 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard2)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd2)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard2)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment3 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard3)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd3)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard3)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment4 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard4)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd4)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard4)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment5 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard5)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd5)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard5)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment6 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard6)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd6)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard6)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led1_red = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled1)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled1)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led2_yellow = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			    ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled2)
			    : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			        ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			        : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled2)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led3_green = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			   ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled3)
			   : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			       ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			       : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled3)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led4_red = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled4)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled4)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led5_yellow = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			    ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled5)
			    : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			        ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			        : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled5)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led6_green = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			   ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled6)
			   : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			       ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			       : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled6)));
}

void Vtop::_settle__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led1_red = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled1)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled1)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment1 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard1)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd1)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard1)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led2_yellow = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			    ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled2)
			    : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			        ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			        : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled2)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment2 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard2)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd2)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard2)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led3_green = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			   ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled3)
			   : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			       ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			       : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled3)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment3 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard3)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd3)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard3)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led4_red = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled4)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled4)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment4 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard4)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd4)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard4)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led5_yellow = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			    ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled5)
			    : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			        ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			        : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled5)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment5 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard5)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd5)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard5)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->led6_green = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			   ? (IData)(vlTOPp->top__DOT__m1__DOT__calendarled6)
			   : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			       ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchled1)
			       : (IData)(vlTOPp->top__DOT__m1__DOT__calendarled6)));
    // ALWAYS at ../..//modeControl.v:74
    vlTOPp->segment6 = ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__calendard6)
			 : ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__stopwatchd6)
			     : (IData)(vlTOPp->top__DOT__m1__DOT__calendard6)));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->push_switch1) & (~ (IData)(vlTOPp->__Vclklast__TOP__push_switch1)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->push_switch1) & (~ (IData)(vlTOPp->__Vclklast__TOP__push_switch1))))) {
	vlTOPp->_multiclk__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__push_switch1 = vlTOPp->push_switch1;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__push_switch1 = vlTOPp->push_switch1;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__3(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((push_switch1 & 0xfeU))) {
	Verilated::overWidthError("push_switch1");}
    if (VL_UNLIKELY((push_switch2 & 0xfeU))) {
	Verilated::overWidthError("push_switch2");}
    if (VL_UNLIKELY((push_switch3 & 0xfeU))) {
	Verilated::overWidthError("push_switch3");}
    if (VL_UNLIKELY((push_switch4 & 0xfeU))) {
	Verilated::overWidthError("push_switch4");}
    if (VL_UNLIKELY((push_switch5 & 0xfeU))) {
	Verilated::overWidthError("push_switch5");}
    if (VL_UNLIKELY((push_switch6 & 0xfeU))) {
	Verilated::overWidthError("push_switch6");}
    if (VL_UNLIKELY((dip_switch1 & 0xfeU))) {
	Verilated::overWidthError("dip_switch1");}
    if (VL_UNLIKELY((dip_switch2 & 0xfeU))) {
	Verilated::overWidthError("dip_switch2");}
    if (VL_UNLIKELY((dip_switch3 & 0xfeU))) {
	Verilated::overWidthError("dip_switch3");}
    if (VL_UNLIKELY((dip_switch4 & 0xfeU))) {
	Verilated::overWidthError("dip_switch4");}
    if (VL_UNLIKELY((dip_switch5 & 0xfeU))) {
	Verilated::overWidthError("dip_switch5");}
    if (VL_UNLIKELY((dip_switch6 & 0xfeU))) {
	Verilated::overWidthError("dip_switch6");}
    if (VL_UNLIKELY((dip_switch7 & 0xfeU))) {
	Verilated::overWidthError("dip_switch7");}
    if (VL_UNLIKELY((dip_switch8 & 0xfeU))) {
	Verilated::overWidthError("dip_switch8");}
    if (VL_UNLIKELY((dip_switch9 & 0xfeU))) {
	Verilated::overWidthError("dip_switch9");}
    if (VL_UNLIKELY((dip_switch10 & 0xfeU))) {
	Verilated::overWidthError("dip_switch10");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    push_switch1 = VL_RAND_RESET_I(1);
    push_switch2 = VL_RAND_RESET_I(1);
    push_switch3 = VL_RAND_RESET_I(1);
    push_switch4 = VL_RAND_RESET_I(1);
    push_switch5 = VL_RAND_RESET_I(1);
    push_switch6 = VL_RAND_RESET_I(1);
    segment1 = VL_RAND_RESET_I(7);
    segment2 = VL_RAND_RESET_I(7);
    segment3 = VL_RAND_RESET_I(7);
    segment4 = VL_RAND_RESET_I(7);
    segment5 = VL_RAND_RESET_I(7);
    segment6 = VL_RAND_RESET_I(7);
    dip_switch1 = VL_RAND_RESET_I(1);
    dip_switch2 = VL_RAND_RESET_I(1);
    dip_switch3 = VL_RAND_RESET_I(1);
    dip_switch4 = VL_RAND_RESET_I(1);
    dip_switch5 = VL_RAND_RESET_I(1);
    dip_switch6 = VL_RAND_RESET_I(1);
    dip_switch7 = VL_RAND_RESET_I(1);
    dip_switch8 = VL_RAND_RESET_I(1);
    dip_switch9 = VL_RAND_RESET_I(1);
    dip_switch10 = VL_RAND_RESET_I(1);
    led1_red = VL_RAND_RESET_I(1);
    led2_yellow = VL_RAND_RESET_I(1);
    led3_green = VL_RAND_RESET_I(1);
    led4_red = VL_RAND_RESET_I(1);
    led5_yellow = VL_RAND_RESET_I(1);
    led6_green = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__isUsing = VL_RAND_RESET_I(3);
    top__DOT__m1__DOT__calendard1 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__calendard2 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__calendard3 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__calendard4 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__calendard5 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__calendard6 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__calendarled1 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__calendarled2 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__calendarled3 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__calendarled4 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__calendarled5 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__calendarled6 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__stopwatchd1 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__stopwatchd2 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__stopwatchd3 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__stopwatchd4 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__stopwatchd5 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__stopwatchd6 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__stopwatchled1 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__cal1__DOT__led6bit = VL_RAND_RESET_I(6);
    top__DOT__m1__DOT__cal1__DOT__y = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__cal1__DOT__m = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__cal1__DOT__day = VL_RAND_RESET_I(6);
    top__DOT__m1__DOT__cal1__DOT__yoil = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__cal1__DOT__counter1 = VL_RAND_RESET_I(27);
    top__DOT__m1__DOT__cal1__DOT__y1 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__cal1__DOT__y2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__cal1__DOT__m1 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__cal1__DOT__m2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__cal1__DOT__day1 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__cal1__DOT__day2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__cal1__DOT__setStatus = VL_RAND_RESET_I(3);
    top__DOT__m1__DOT__s1__DOT__m = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__s1__DOT__sec = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__s1__DOT__msec = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__s1__DOT__counter1 = VL_RAND_RESET_I(27);
    top__DOT__m1__DOT__s1__DOT__m1 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__s1__DOT__m2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__s1__DOT__sec1 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__s1__DOT__sec2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__s1__DOT__msec1 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__s1__DOT__msec2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__s1__DOT__isrunning = VL_RAND_RESET_I(1);
}
