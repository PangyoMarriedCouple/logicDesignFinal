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

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//modeControl.v:84
    if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
	vlTOPp->top__DOT__m1__DOT__isUsing = 2U;
    } else {
	if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
	    vlTOPp->top__DOT__m1__DOT__isUsing = 4U;
	} else {
	    if ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		vlTOPp->top__DOT__m1__DOT__isUsing = 0U;
	    }
	}
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//alarm.v:78
    if (vlTOPp->push_switch6) {
	vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 = 0U;
	vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus = 0U;
	vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm = 0U;
	vlTOPp->top__DOT__m1__DOT__a1__DOT__ah = 0U;
	vlTOPp->top__DOT__m1__DOT__a1__DOT__am = 0U;
	vlTOPp->top__DOT__m1__DOT__a1__DOT__asec = 0U;
    }
    if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus))) {
	if (vlTOPp->push_switch2) {
	    if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 = 0U;
		vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm = 1U;
		vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus = 1U;
	    }
	}
	vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 
	    = (0x7ffffffU & ((0x1e8480U > vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1)
			      ? ((IData)(1U) + vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1)
			      : 0U));
    } else {
	if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus))) {
	    if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1)) {
		vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 
		    = (0x7ffffffU & ((IData)(1U) + vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1));
	    } else {
		vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 = 0U;
		if (vlTOPp->push_switch3) {
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__ah 
			= (0x3fU & ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
				     ? ((0xbU < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					 ? ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
					    - (IData)(0xcU))
					 : ((IData)(0xcU) 
					    + (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah)))
				     : ((0x17U > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					 ? ((IData)(1U) 
					    + (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					 : 0U)));
		}
		if (vlTOPp->push_switch4) {
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__ah 
			= (0x3fU & ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
				     ? ((0xbU < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					 ? ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
					    - (IData)(0xcU))
					 : ((IData)(0xcU) 
					    + (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah)))
				     : ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					 ? ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
					    - (IData)(1U))
					 : 0x17U)));
		}
	    }
	    if (vlTOPp->push_switch2) {
		if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm = 1U;
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus = 2U;
		}
	    }
	} else {
	    if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus))) {
		if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1)) {
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 
			= (0x7ffffffU & ((IData)(1U) 
					 + vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1));
		} else {
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 = 0U;
		    if (vlTOPp->push_switch3) {
			if (vlTOPp->top__DOT__m1__DOT__is12changed) {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__ah 
				= (0x3fU & ((0x17U 
					     > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					     ? ((IData)(1U) 
						+ (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					     : 0U));
			} else {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__am 
				= (0x3fU & ((0x3bU 
					     > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))
					     ? ((IData)(1U) 
						+ (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))
					     : 0U));
			}
		    }
		    if (vlTOPp->push_switch4) {
			if (vlTOPp->top__DOT__m1__DOT__is12changed) {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__ah 
				= (0x3fU & ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					     ? ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						- (IData)(1U))
					     : 0x17U));
			} else {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__am 
				= (0x3fU & ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))
					     ? ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am) 
						- (IData)(1U))
					     : 0x3bU));
			}
		    }
		}
		if (vlTOPp->push_switch2) {
		    if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
			if (vlTOPp->top__DOT__m1__DOT__is12changed) {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus = 3U;
			} else {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm = 1U;
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus = 0U;
			}
		    }
		}
	    } else {
		if ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus))) {
		    if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1)) {
			vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 
			    = (0x7ffffffU & ((IData)(1U) 
					     + vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1));
		    } else {
			vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 = 0U;
			if (vlTOPp->push_switch3) {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__am 
				= (0x3fU & ((0x3bU 
					     > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))
					     ? ((IData)(1U) 
						+ (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))
					     : 0U));
			}
			if (vlTOPp->push_switch4) {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__am 
				= (0x3fU & ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))
					     ? ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am) 
						- (IData)(1U))
					     : 0x3bU));
			}
		    }
		    if (vlTOPp->push_switch2) {
			if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm = 1U;
			    vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus = 0U;
			}
		    }
		}
	    }
	}
    }
    if ((0x3bU < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec))) {
	vlTOPp->top__DOT__m1__DOT__a1__DOT__asec = 0U;
    }
    if ((0x3bU < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))) {
	vlTOPp->top__DOT__m1__DOT__a1__DOT__am = 0U;
    }
    if ((0x17U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))) {
	vlTOPp->top__DOT__m1__DOT__a1__DOT__ah = 0U;
    }
    if (((0U == (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus)) 
	 & (IData)(vlTOPp->push_switch3))) {
	vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm = 0U;
    }
    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))) {
	vlTOPp->top__DOT__m1__DOT__a1__DOT__m1 = 5U;
	vlTOPp->top__DOT__m1__DOT__a1__DOT__m2 = (0xfU 
						  & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am) 
						     - (IData)(2U)));
    } else {
	if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))) {
	    vlTOPp->top__DOT__m1__DOT__a1__DOT__m1 = 4U;
	    vlTOPp->top__DOT__m1__DOT__a1__DOT__m2 
		= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am) 
			   - (IData)(8U)));
	} else {
	    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))) {
		vlTOPp->top__DOT__m1__DOT__a1__DOT__m1 = 3U;
		vlTOPp->top__DOT__m1__DOT__a1__DOT__m2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am) 
			       - (IData)(0xeU)));
	    } else {
		if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))) {
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__m1 = 2U;
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__m2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am) 
				   - (IData)(4U)));
		} else {
		    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am))) {
			vlTOPp->top__DOT__m1__DOT__a1__DOT__m1 = 1U;
			vlTOPp->top__DOT__m1__DOT__a1__DOT__m2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am) 
				       - (IData)(0xaU)));
		    } else {
			vlTOPp->top__DOT__m1__DOT__a1__DOT__m1 = 0U;
			vlTOPp->top__DOT__m1__DOT__a1__DOT__m2 
			    = (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__am));
		    }
		}
	    }
	}
    }
    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec))) {
	vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1 = 5U;
	vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2 = 
	    (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec) 
		     - (IData)(2U)));
    } else {
	if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec))) {
	    vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1 = 4U;
	    vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2 
		= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec) 
			   - (IData)(8U)));
	} else {
	    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec))) {
		vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1 = 3U;
		vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec) 
			       - (IData)(0xeU)));
	    } else {
		if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec))) {
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1 = 2U;
		    vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec) 
				   - (IData)(4U)));
		} else {
		    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec))) {
			vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1 = 1U;
			vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec) 
				       - (IData)(0xaU)));
		    } else {
			vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1 = 0U;
			vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2 
			    = (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__asec));
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__m1__DOT__ad1 = ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm)
				       ? ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
					   ? ((0xcU 
					       > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					       ? 0x77U
					       : 0x67U)
					   : ((0xaU 
					       > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					       ? 0x7eU
					       : ((0x14U 
						   > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						   ? 0x30U
						   : 0x6dU)))
				       : 1U);
    vlTOPp->top__DOT__m1__DOT__ad2 = ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm)
				       ? ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
					   ? 0U : (
						   (0xaU 
						    > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						    ? 
						   ((0x20U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						     ? 0U
						     : 
						    ((0x10U 
						      & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						      ? 0U
						      : 
						     ((8U 
						       & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						       ? 
						      ((4U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						        ? 0U
						        : 
						       ((2U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 0U
							 : 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							  ? 0x7bU
							  : 0x7fU)))
						       : 
						      ((4U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						        ? 
						       ((2U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							  ? 0x70U
							  : 0x5fU)
							 : 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							  ? 0x5bU
							  : 0x33U))
						        : 
						       ((2U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							  ? 0x79U
							  : 0x6dU)
							 : 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							  ? 0x30U
							  : 0x7eU))))))
						    : 
						   ((0x14U 
						     > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						     ? 
						    (((((((((0U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							      - (IData)(0xaU))) 
							    | (1U 
							       == 
							       ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
								- (IData)(0xaU)))) 
							   | (2U 
							      == 
							      ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							       - (IData)(0xaU)))) 
							  | (3U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							      - (IData)(0xaU)))) 
							 | (4U 
							    == 
							    ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							     - (IData)(0xaU)))) 
							| (5U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							    - (IData)(0xaU)))) 
						       | (6U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							   - (IData)(0xaU)))) 
						      | (7U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							  - (IData)(0xaU))))
						      ? 
						     ((0U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							- (IData)(0xaU)))
						       ? 0x7eU
						       : 
						      ((1U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							 - (IData)(0xaU)))
						        ? 0x30U
						        : 
						       ((2U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							  - (IData)(0xaU)))
							 ? 0x6dU
							 : 
							((3U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							   - (IData)(0xaU)))
							  ? 0x79U
							  : 
							 ((4U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							    - (IData)(0xaU)))
							   ? 0x33U
							   : 
							  ((5U 
							    == 
							    ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							     - (IData)(0xaU)))
							    ? 0x5bU
							    : 
							   ((6U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							      - (IData)(0xaU)))
							     ? 0x5fU
							     : 0x70U)))))))
						      : 
						     ((8U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							- (IData)(0xaU)))
						       ? 0x7fU
						       : 
						      ((9U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							 - (IData)(0xaU)))
						        ? 0x7bU
						        : 0U)))
						     : 
						    ((0U 
						      == 
						      ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						       - (IData)(0x14U)))
						      ? 0x7eU
						      : 
						     ((1U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							- (IData)(0x14U)))
						       ? 0x30U
						       : 
						      ((2U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							 - (IData)(0x14U)))
						        ? 0x6dU
						        : 
						       ((3U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							  - (IData)(0x14U)))
							 ? 0x79U
							 : 0U)))))))
				       : 1U);
    vlTOPp->top__DOT__m1__DOT__ad3 = ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm)
				       ? ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
					   ? ((0xcU 
					       > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					       ? ((0xaU 
						   > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						   ? 0x7eU
						   : 0x30U)
					       : ((0xaU 
						   > 
						   ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						    - (IData)(0xcU)))
						   ? 0x7eU
						   : 0x30U))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
					       ? 0U
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						     ? 0x30U
						     : 0x7eU)))))
				       : 1U);
    vlTOPp->top__DOT__m1__DOT__ad4 = ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm)
				       ? ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
					   ? ((0xcU 
					       > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
					       ? ((0xaU 
						   > (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						   ? 
						  ((0x20U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						    ? 0U
						    : 
						   ((0x10U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						     ? 0U
						     : 
						    ((8U 
						      & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						      ? 
						     ((4U 
						       & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						       ? 0U
						       : 
						      ((2U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						        ? 0U
						        : 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 0x7bU
							 : 0x7fU)))
						      : 
						     ((4U 
						       & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						       ? 
						      ((2U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						        ? 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 0x70U
							 : 0x5fU)
						        : 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 0x5bU
							 : 0x33U))
						       : 
						      ((2U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
						        ? 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 0x79U
							 : 0x6dU)
						        : 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah))
							 ? 0x30U
							 : 0x7eU))))))
						   : 
						  ((0U 
						    == 
						    ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						     - (IData)(0xaU)))
						    ? 0x7eU
						    : 
						   ((1U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						      - (IData)(0xaU)))
						     ? 0x30U
						     : 0U)))
					       : ((0xaU 
						   > 
						   ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						    - (IData)(0xcU)))
						   ? 
						  (((((((((0U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							    - (IData)(0xcU))) 
							  | (1U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							      - (IData)(0xcU)))) 
							 | (2U 
							    == 
							    ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							     - (IData)(0xcU)))) 
							| (3U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							    - (IData)(0xcU)))) 
						       | (4U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							   - (IData)(0xcU)))) 
						      | (5U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							  - (IData)(0xcU)))) 
						     | (6U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							 - (IData)(0xcU)))) 
						    | (7U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							- (IData)(0xcU))))
						    ? 
						   ((0U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						      - (IData)(0xcU)))
						     ? 0x7eU
						     : 
						    ((1U 
						      == 
						      ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						       - (IData)(0xcU)))
						      ? 0x30U
						      : 
						     ((2U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							- (IData)(0xcU)))
						       ? 0x6dU
						       : 
						      ((3U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							 - (IData)(0xcU)))
						        ? 0x79U
						        : 
						       ((4U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							  - (IData)(0xcU)))
							 ? 0x33U
							 : 
							((5U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							   - (IData)(0xcU)))
							  ? 0x5bU
							  : 
							 ((6U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
							    - (IData)(0xcU)))
							   ? 0x5fU
							   : 0x70U)))))))
						    : 
						   ((8U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						      - (IData)(0xcU)))
						     ? 0x7fU
						     : 
						    ((9U 
						      == 
						      ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						       - (IData)(0xcU)))
						      ? 0x7bU
						      : 0U)))
						   : 
						  ((0U 
						    == 
						    ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						     - (IData)(0x16U)))
						    ? 0x7eU
						    : 
						   ((1U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__ah) 
						      - (IData)(0x16U)))
						     ? 0x30U
						     : 0U))))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x30U
						     : 0x7eU)))))
				       : 1U);
    vlTOPp->top__DOT__m1__DOT__ad5 = ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm)
				       ? ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
					   ? ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
					       ? 0U
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m1))
						     ? 0x30U
						     : 0x7eU))))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1))
					       ? 0U
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1))
						     ? 0x30U
						     : 0x7eU)))))
				       : 1U);
    vlTOPp->top__DOT__m1__DOT__ad6 = ((IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm)
				       ? ((IData)(vlTOPp->top__DOT__m1__DOT__is12changed)
					   ? ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__m2))
						     ? 0x30U
						     : 0x7eU))))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2))
						     ? 0x30U
						     : 0x7eU)))))
				       : 1U);
    // ALWAYS at ../..//clock.v:83
    vlTOPp->top__DOT__m1__DOT__c1__DOT__is12 = vlTOPp->top__DOT__m1__DOT__is12changed;
    vlTOPp->top__DOT__m1__DOT__is12 = vlTOPp->top__DOT__m1__DOT__c1__DOT__is12;
    if (vlTOPp->push_switch6) {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 = 0U;
	vlTOPp->top__DOT__m1__DOT__c1__DOT__h = 0U;
	vlTOPp->top__DOT__m1__DOT__c1__DOT__m = 0U;
	vlTOPp->top__DOT__m1__DOT__c1__DOT__sec = 0U;
    }
    if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus))) {
	if (vlTOPp->push_switch2) {
	    if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 = 0U;
		vlTOPp->top__DOT__m1__DOT__c1__DOT__sec = 0U;
		vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus = 1U;
	    }
	}
	if ((0x1e8480U > vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1)) {
	    vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 
		= (0x7ffffffU & ((IData)(1U) + vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1));
	} else {
	    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec 
		= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec)));
	    vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 = 0U;
	}
    } else {
	if ((1U == (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus))) {
	    if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1)) {
		vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 
		    = (0x7ffffffU & ((IData)(1U) + vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1));
	    } else {
		vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 = 0U;
		if (vlTOPp->push_switch3) {
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__h 
			= (0x3fU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
				     ? ((0xbU < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					 ? ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
					    - (IData)(0xcU))
					 : ((IData)(0xcU) 
					    + (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h)))
				     : ((0x17U > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					 ? ((IData)(1U) 
					    + (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					 : 0U)));
		}
		if (vlTOPp->push_switch4) {
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__h 
			= (0x3fU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
				     ? ((0xbU < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					 ? ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
					    - (IData)(0xcU))
					 : ((IData)(0xcU) 
					    + (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h)))
				     : ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					 ? ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
					    - (IData)(1U))
					 : 0x17U)));
		}
	    }
	    if (vlTOPp->push_switch2) {
		if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus = 2U;
		}
	    }
	} else {
	    if ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus))) {
		if (vlTOPp->push_switch2) {
		    if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
			vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus 
			    = ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
			        ? 3U : 0U);
		    }
		}
		if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1)) {
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 
			= (0x7ffffffU & ((IData)(1U) 
					 + vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1));
		} else {
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 = 0U;
		    if (vlTOPp->push_switch3) {
			if (vlTOPp->top__DOT__m1__DOT__c1__DOT__is12) {
			    vlTOPp->top__DOT__m1__DOT__c1__DOT__h 
				= (0x3fU & ((0x17U 
					     > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					     ? ((IData)(1U) 
						+ (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					     : 0U));
			} else {
			    vlTOPp->top__DOT__m1__DOT__c1__DOT__m 
				= (0x3fU & ((0x3bU 
					     > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))
					     ? ((IData)(1U) 
						+ (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))
					     : 0U));
			}
		    }
		    if (vlTOPp->push_switch4) {
			if (vlTOPp->top__DOT__m1__DOT__c1__DOT__is12) {
			    vlTOPp->top__DOT__m1__DOT__c1__DOT__h 
				= (0x3fU & ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					     ? ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						- (IData)(1U))
					     : 0x17U));
			} else {
			    vlTOPp->top__DOT__m1__DOT__c1__DOT__m 
				= (0x3fU & ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))
					     ? ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m) 
						- (IData)(1U))
					     : 0x3bU));
			}
		    }
		}
	    } else {
		if ((3U == (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus))) {
		    if ((0x9c40U > vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1)) {
			vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 
			    = (0x7ffffffU & ((IData)(1U) 
					     + vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1));
		    } else {
			vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 = 0U;
			if (vlTOPp->push_switch3) {
			    vlTOPp->top__DOT__m1__DOT__c1__DOT__m 
				= (0x3fU & ((0x3bU 
					     > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))
					     ? ((IData)(1U) 
						+ (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))
					     : 0U));
			}
			if (vlTOPp->push_switch4) {
			    vlTOPp->top__DOT__m1__DOT__c1__DOT__m 
				= (0x3fU & ((0U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))
					     ? ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m) 
						- (IData)(1U))
					     : 0x3bU));
			}
		    }
		    if (vlTOPp->push_switch2) {
			if ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
			    vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus = 0U;
			}
		    }
		}
	    }
	}
    }
    if ((0x3bU < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec))) {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__m = (0x3fU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m)));
	vlTOPp->top__DOT__m1__DOT__c1__DOT__sec = 0U;
    }
    if ((0x3bU < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))) {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__h = (0x3fU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h)));
	vlTOPp->top__DOT__m1__DOT__c1__DOT__m = 0U;
    }
    if ((0x17U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))) {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__h = 0U;
    }
    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))) {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__m1 = 5U;
	vlTOPp->top__DOT__m1__DOT__c1__DOT__m2 = (0xfU 
						  & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m) 
						     - (IData)(2U)));
    } else {
	if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))) {
	    vlTOPp->top__DOT__m1__DOT__c1__DOT__m1 = 4U;
	    vlTOPp->top__DOT__m1__DOT__c1__DOT__m2 
		= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m) 
			   - (IData)(8U)));
	} else {
	    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))) {
		vlTOPp->top__DOT__m1__DOT__c1__DOT__m1 = 3U;
		vlTOPp->top__DOT__m1__DOT__c1__DOT__m2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m) 
			       - (IData)(0xeU)));
	    } else {
		if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))) {
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__m1 = 2U;
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__m2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m) 
				   - (IData)(4U)));
		} else {
		    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m))) {
			vlTOPp->top__DOT__m1__DOT__c1__DOT__m1 = 1U;
			vlTOPp->top__DOT__m1__DOT__c1__DOT__m2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m) 
				       - (IData)(0xaU)));
		    } else {
			vlTOPp->top__DOT__m1__DOT__c1__DOT__m1 = 0U;
			vlTOPp->top__DOT__m1__DOT__c1__DOT__m2 
			    = (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m));
		    }
		}
	    }
	}
    }
    if ((0x31U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec))) {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1 = 5U;
	vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2 = 
	    (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec) 
		     - (IData)(2U)));
    } else {
	if ((0x27U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec))) {
	    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1 = 4U;
	    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2 
		= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec) 
			   - (IData)(8U)));
	} else {
	    if ((0x1dU < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec))) {
		vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1 = 3U;
		vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2 
		    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec) 
			       - (IData)(0xeU)));
	    } else {
		if ((0x13U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec))) {
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1 = 2U;
		    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2 
			= (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec) 
				   - (IData)(4U)));
		} else {
		    if ((9U < (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec))) {
			vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1 = 1U;
			vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2 
			    = (0xfU & ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec) 
				       - (IData)(0xaU)));
		    } else {
			vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1 = 0U;
			vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2 
			    = (0xfU & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec));
		    }
		}
	    }
	}
    }
    if ((0x30d40U > vlTOPp->top__DOT__m1__DOT__c1__DOT__blinkcounter)) {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__blinkcounter 
	    = (0x7fffffffU & ((IData)(1U) + vlTOPp->top__DOT__m1__DOT__c1__DOT__blinkcounter));
    } else {
	vlTOPp->top__DOT__m1__DOT__c1__DOT__blinkcounter = 0U;
	vlTOPp->top__DOT__m1__DOT__c1__DOT__blink = 
	    (1U & (~ (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__blink)));
    }
    vlTOPp->top__DOT__m1__DOT__clockd1 = ((((1U == (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus)) 
					    & (0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) 
					   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__blink))
					   ? 0U : ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
						    ? 
						   ((0xcU 
						     > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						     ? 0x77U
						     : 0x67U)
						    : 
						   ((0xaU 
						     > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						     ? 0x7eU
						     : 
						    ((0x14U 
						      > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						      ? 0x30U
						      : 0x6dU))));
    vlTOPp->top__DOT__m1__DOT__clockd2 = ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
					   ? 0U : (
						   (0xaU 
						    > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						    ? 
						   ((0x20U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						     ? 0U
						     : 
						    ((0x10U 
						      & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						      ? 0U
						      : 
						     ((8U 
						       & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						       ? 
						      ((4U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						        ? 0U
						        : 
						       ((2U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 0U
							 : 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							  ? 0x7bU
							  : 0x7fU)))
						       : 
						      ((4U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						        ? 
						       ((2U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							  ? 0x70U
							  : 0x5fU)
							 : 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							  ? 0x5bU
							  : 0x33U))
						        : 
						       ((2U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							  ? 0x79U
							  : 0x6dU)
							 : 
							((1U 
							  & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							  ? 0x30U
							  : 0x7eU))))))
						    : 
						   ((0x14U 
						     > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						     ? 
						    (((((((((0U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							      - (IData)(0xaU))) 
							    | (1U 
							       == 
							       ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
								- (IData)(0xaU)))) 
							   | (2U 
							      == 
							      ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							       - (IData)(0xaU)))) 
							  | (3U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							      - (IData)(0xaU)))) 
							 | (4U 
							    == 
							    ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							     - (IData)(0xaU)))) 
							| (5U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							    - (IData)(0xaU)))) 
						       | (6U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							   - (IData)(0xaU)))) 
						      | (7U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							  - (IData)(0xaU))))
						      ? 
						     ((0U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							- (IData)(0xaU)))
						       ? 0x7eU
						       : 
						      ((1U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							 - (IData)(0xaU)))
						        ? 0x30U
						        : 
						       ((2U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							  - (IData)(0xaU)))
							 ? 0x6dU
							 : 
							((3U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							   - (IData)(0xaU)))
							  ? 0x79U
							  : 
							 ((4U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							    - (IData)(0xaU)))
							   ? 0x33U
							   : 
							  ((5U 
							    == 
							    ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							     - (IData)(0xaU)))
							    ? 0x5bU
							    : 
							   ((6U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							      - (IData)(0xaU)))
							     ? 0x5fU
							     : 0x70U)))))))
						      : 
						     ((8U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							- (IData)(0xaU)))
						       ? 0x7fU
						       : 
						      ((9U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							 - (IData)(0xaU)))
						        ? 0x7bU
						        : 0U)))
						     : 
						    ((0U 
						      == 
						      ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						       - (IData)(0x14U)))
						      ? 0x7eU
						      : 
						     ((1U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							- (IData)(0x14U)))
						       ? 0x30U
						       : 
						      ((2U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							 - (IData)(0x14U)))
						        ? 0x6dU
						        : 
						       ((3U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							  - (IData)(0x14U)))
							 ? 0x79U
							 : 0U)))))));
    vlTOPp->top__DOT__m1__DOT__clockd3 = ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
					   ? ((0xcU 
					       > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					       ? ((0xaU 
						   > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						   ? 0x7eU
						   : 0x30U)
					       : ((0xaU 
						   > 
						   ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						    - (IData)(0xcU)))
						   ? 0x7eU
						   : 0x30U))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
					       ? 0U
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						     ? 0x30U
						     : 0x7eU)))));
    vlTOPp->top__DOT__m1__DOT__clockd4 = ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
					   ? ((0xcU 
					       > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
					       ? ((0xaU 
						   > (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						   ? 
						  ((0x20U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						    ? 0U
						    : 
						   ((0x10U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						     ? 0U
						     : 
						    ((8U 
						      & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						      ? 
						     ((4U 
						       & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						       ? 0U
						       : 
						      ((2U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						        ? 0U
						        : 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 0x7bU
							 : 0x7fU)))
						      : 
						     ((4U 
						       & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						       ? 
						      ((2U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						        ? 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 0x70U
							 : 0x5fU)
						        : 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 0x5bU
							 : 0x33U))
						       : 
						      ((2U 
							& (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
						        ? 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 0x79U
							 : 0x6dU)
						        : 
						       ((1U 
							 & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h))
							 ? 0x30U
							 : 0x7eU))))))
						   : 
						  ((0U 
						    == 
						    ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						     - (IData)(0xaU)))
						    ? 0x7eU
						    : 
						   ((1U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						      - (IData)(0xaU)))
						     ? 0x30U
						     : 0U)))
					       : ((0xaU 
						   > 
						   ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						    - (IData)(0xcU)))
						   ? 
						  (((((((((0U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							    - (IData)(0xcU))) 
							  | (1U 
							     == 
							     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							      - (IData)(0xcU)))) 
							 | (2U 
							    == 
							    ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							     - (IData)(0xcU)))) 
							| (3U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							    - (IData)(0xcU)))) 
						       | (4U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							   - (IData)(0xcU)))) 
						      | (5U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							  - (IData)(0xcU)))) 
						     | (6U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							 - (IData)(0xcU)))) 
						    | (7U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							- (IData)(0xcU))))
						    ? 
						   ((0U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						      - (IData)(0xcU)))
						     ? 0x7eU
						     : 
						    ((1U 
						      == 
						      ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						       - (IData)(0xcU)))
						      ? 0x30U
						      : 
						     ((2U 
						       == 
						       ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							- (IData)(0xcU)))
						       ? 0x6dU
						       : 
						      ((3U 
							== 
							((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							 - (IData)(0xcU)))
						        ? 0x79U
						        : 
						       ((4U 
							 == 
							 ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							  - (IData)(0xcU)))
							 ? 0x33U
							 : 
							((5U 
							  == 
							  ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							   - (IData)(0xcU)))
							  ? 0x5bU
							  : 
							 ((6U 
							   == 
							   ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
							    - (IData)(0xcU)))
							   ? 0x5fU
							   : 0x70U)))))))
						    : 
						   ((8U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						      - (IData)(0xcU)))
						     ? 0x7fU
						     : 
						    ((9U 
						      == 
						      ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						       - (IData)(0xcU)))
						      ? 0x7bU
						      : 0U)))
						   : 
						  ((0U 
						    == 
						    ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						     - (IData)(0x16U)))
						    ? 0x7eU
						    : 
						   ((1U 
						     == 
						     ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__h) 
						      - (IData)(0x16U)))
						     ? 0x30U
						     : 0U))))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x30U
						     : 0x7eU)))));
    vlTOPp->top__DOT__m1__DOT__clockd5 = ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
					   ? ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
					       ? 0U
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m1))
						     ? 0x30U
						     : 0x7eU))))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1))
					       ? 0U
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1))
						     ? 0x30U
						     : 0x7eU)))));
    vlTOPp->top__DOT__m1__DOT__clockd6 = ((IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__is12)
					   ? ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__m2))
						     ? 0x30U
						     : 0x7eU))))
					   : ((8U & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
					       ? ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						   ? 0U
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						    ? 0U
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						     ? 0x7bU
						     : 0x7fU)))
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						     ? 0x70U
						     : 0x5fU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						     ? 0x5bU
						     : 0x33U))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						     ? 0x79U
						     : 0x6dU)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2))
						     ? 0x30U
						     : 0x7eU)))));
}

void Vtop::_initial__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ../..//alarm.v:62
    vlTOPp->top__DOT__m1__DOT__a1__DOT__sec1 = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__sec2 = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__m1 = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__m2 = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__counter1 = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__setStatus = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__hasalarm = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__ah = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__am = 0U;
    vlTOPp->top__DOT__m1__DOT__a1__DOT__asec = 0U;
    // INITIAL at ../..//clock.v:64
    vlTOPp->top__DOT__m1__DOT__c1__DOT__blinkcounter = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__blink = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec1 = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec2 = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__m1 = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__m2 = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__counter1 = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__h = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__m = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__sec = 0U;
    vlTOPp->top__DOT__m1__DOT__c1__DOT__setStatus = 0U;
    // INITIAL at ../..//modeControl.v:80
    vlTOPp->top__DOT__m1__DOT__isUsing = 0U;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//modeControl.v:93
    vlTOPp->segment1 = ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__clockd1)
			 : ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__ad1)
			     : ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
				 ? 0x3dU : (IData)(vlTOPp->top__DOT__m1__DOT__clockd1))));
    // ALWAYS at ../..//modeControl.v:93
    vlTOPp->segment2 = ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__clockd2)
			 : ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__ad2)
			     : ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
				 ? 0x4eU : (IData)(vlTOPp->top__DOT__m1__DOT__clockd2))));
    // ALWAYS at ../..//modeControl.v:93
    vlTOPp->segment3 = ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__clockd3)
			 : ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__ad3)
			     : ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
				 ? 0U : (IData)(vlTOPp->top__DOT__m1__DOT__clockd3))));
    // ALWAYS at ../..//modeControl.v:93
    vlTOPp->segment4 = ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__clockd4)
			 : ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__ad4)
			     : ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
				 ? 0U : (IData)(vlTOPp->top__DOT__m1__DOT__clockd4))));
    // ALWAYS at ../..//modeControl.v:93
    vlTOPp->segment5 = ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__clockd5)
			 : ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__ad5)
			     : ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
				 ? 0U : (IData)(vlTOPp->top__DOT__m1__DOT__clockd5))));
    // ALWAYS at ../..//modeControl.v:93
    vlTOPp->segment6 = ((0U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			 ? (IData)(vlTOPp->top__DOT__m1__DOT__clockd6)
			 : ((2U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
			     ? (IData)(vlTOPp->top__DOT__m1__DOT__ad6)
			     : ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))
				 ? 0U : (IData)(vlTOPp->top__DOT__m1__DOT__clockd6))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../..//displayControl.v:38
    if ((4U == (IData)(vlTOPp->top__DOT__m1__DOT__isUsing))) {
	vlTOPp->top__DOT__m1__DOT__is12changed = (1U 
						  & (~ (IData)(vlTOPp->top__DOT__m1__DOT__is12)));
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->push_switch1) & (~ (IData)(vlTOPp->__Vclklast__TOP__push_switch1)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->push_switch1) & (~ (IData)(vlTOPp->__Vclklast__TOP__push_switch1))))) {
	vlTOPp->_multiclk__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->push_switch2) & (~ (IData)(vlTOPp->__Vclklast__TOP__push_switch2)))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__push_switch2 = vlTOPp->push_switch2;
    vlTOPp->__Vclklast__TOP__push_switch1 = vlTOPp->push_switch1;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__push_switch2 = vlTOPp->push_switch2;
    vlTOPp->__Vclklast__TOP__push_switch1 = vlTOPp->push_switch1;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__4(vlSymsp);
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
    vlTOPp->_multiclk__TOP__5(vlSymsp);
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
    top__DOT__m1__DOT__is12 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__is12changed = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__clockd1 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__clockd2 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__clockd3 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__clockd4 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__clockd5 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__clockd6 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__ad1 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__ad2 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__ad3 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__ad4 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__ad5 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__ad6 = VL_RAND_RESET_I(7);
    top__DOT__m1__DOT__c1__DOT__blinkcounter = VL_RAND_RESET_I(31);
    top__DOT__m1__DOT__c1__DOT__blink = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__c1__DOT__sec1 = VL_RAND_RESET_I(3);
    top__DOT__m1__DOT__c1__DOT__sec2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__c1__DOT__m1 = VL_RAND_RESET_I(3);
    top__DOT__m1__DOT__c1__DOT__m2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__c1__DOT__sec = VL_RAND_RESET_I(6);
    top__DOT__m1__DOT__c1__DOT__m = VL_RAND_RESET_I(6);
    top__DOT__m1__DOT__c1__DOT__h = VL_RAND_RESET_I(6);
    top__DOT__m1__DOT__c1__DOT__counter1 = VL_RAND_RESET_I(27);
    top__DOT__m1__DOT__c1__DOT__is12 = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__c1__DOT__setStatus = VL_RAND_RESET_I(2);
    top__DOT__m1__DOT__a1__DOT__sec1 = VL_RAND_RESET_I(3);
    top__DOT__m1__DOT__a1__DOT__sec2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__a1__DOT__m1 = VL_RAND_RESET_I(3);
    top__DOT__m1__DOT__a1__DOT__m2 = VL_RAND_RESET_I(4);
    top__DOT__m1__DOT__a1__DOT__counter1 = VL_RAND_RESET_I(27);
    top__DOT__m1__DOT__a1__DOT__setStatus = VL_RAND_RESET_I(2);
    top__DOT__m1__DOT__a1__DOT__hasalarm = VL_RAND_RESET_I(1);
    top__DOT__m1__DOT__a1__DOT__ah = VL_RAND_RESET_I(6);
    top__DOT__m1__DOT__a1__DOT__am = VL_RAND_RESET_I(6);
    top__DOT__m1__DOT__a1__DOT__asec = VL_RAND_RESET_I(6);
}
