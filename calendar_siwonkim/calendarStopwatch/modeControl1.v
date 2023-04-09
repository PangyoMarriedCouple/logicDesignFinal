`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:36:33 12/16/2022 
// Design Name: 
// Module Name:    modeControl 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module modeControl1(
	 input mode,
    input clkBoard,
	 input reset,
    input set,
    input up,
    input down,
    output reg [6:0] d1,
    output reg [6:0] d2,
    output reg [6:0] d3,
    output reg [6:0] d4,
    output reg [6:0] d5,
    output reg [6:0] d6,
	 output reg led1,
	 output reg led2,
	 output reg led3,
	 output reg led4,
	 output reg led5,
	 output reg led6
    );
	 
	 reg [2:0] isUsing; // 0:clock 1:calendar 2:alarm 3:stopwatch 4:displaycontrol
	 
	 wire [6:0] calendard1;
	 wire [6:0] calendard2;
	 wire [6:0] calendard3;
	 wire [6:0] calendard4;
	 wire [6:0] calendard5;
	 wire [6:0] calendard6;
	 
	 wire calendarled1,calendarled2,calendarled3,calendarled4,calendarled5,calendarled6;
	 
	 wire [6:0] stopwatchd1;
	 wire [6:0] stopwatchd2;
	 wire [6:0] stopwatchd3;
	 wire [6:0] stopwatchd4;
	 wire [6:0] stopwatchd5;
	 wire [6:0] stopwatchd6;
	 
	 wire stopwatchled1,stopwatchled2,stopwatchled3,stopwatchled4,stopwatchled5,stopwatchled6;
	 
	 initial begin
		isUsing = 1;
	 end
	 
	 parameter buttonfreq = 7000000;
	 
	 reg [26:0] modecounter;
	 
	 /*how to use
	 parameter buttonfreq = 7000000;
	 
	 reg [26:0] setcounter;
	 
	 if( setcounter < buttonfreq )
		begin
				setcounter = setcounter + 1;
		end		
	 else 
	 begin
			setcounter = 0;
			if(set)
				begin
				// your code here
				
					
				// your code here
				end
			else begin end	
	 end
	 */
	 

	 
	 always @ (posedge clkBoard)
	 begin
		
		if( modecounter < buttonfreq )
		begin
				modecounter = modecounter + 1;
		end		
		 else 
		 begin
				modecounter = 0;
				if(mode)
					begin
					// your code here
					if(isUsing<3)
						isUsing = isUsing+2;
					else
						isUsing = 1;			
					// your code here
					end
				else begin end	
		 end
	 
		case(isUsing)
		1:
		begin
			d1 = calendard1;
			d2 = calendard2;
			d3 = calendard3;
			d4 = calendard4;
			d5 = calendard5;
			d6 = calendard6;
			led1 = calendarled1;
			led2 = calendarled2;
			led3 = calendarled3;
			led4 = calendarled4;
			led5 = calendarled5;
			led6 = calendarled6;
		end
		3:
		begin
			d1 = stopwatchd1;
			d2 = stopwatchd2;
			d3 = stopwatchd3;
			d4 = stopwatchd4;
			d5 = stopwatchd5;
			d6 = stopwatchd6;
			led1 = stopwatchled1;
			led2 = stopwatchled2;
			led3 = stopwatchled3;
			led4 = stopwatchled4;
			led5 = stopwatchled5;
			led6 = stopwatchled6;
		end
		default :
		begin
			d1 = calendard1;
			d2 = calendard2;
			d3 = calendard3;
			d4 = calendard4;
			d5 = calendard5;
			d6 = calendard6;
			led1 = calendarled1;
			led2 = calendarled2;
			led3 = calendarled3;
			led4 = calendarled4;
			led5 = calendarled5;
			led6 = calendarled6;
		end
		
		endcase
	 end


	 calendar cal1(
	 .clkBoard(clkBoard),	 
	 .isUsing(isUsing),
	 .reset(reset),
    .set(set),
    .up(up),
    .down(down),
    .d1(calendard1),
    .d2(calendard2),
    .d3(calendard3),
    .d4(calendard4),
    .d5(calendard5),
    .d6(calendard6),
	 .led1(calendarled1),
	 .led2(calendarled2),
	 .led3(calendarled3),
	 .led4(calendarled4),
	 .led5(calendarled5),
	 .led6(calendarled6));
	 
	 stopwatch s1(
		.clkBoard(clkBoard),
		.isUsing(isUsing),
		.reset(reset),
		.set(set),
		.up(up),
		.down(down),
		.d1(stopwatchd1),
		.d2(stopwatchd2),
		.d3(stopwatchd3),
		.d4(stopwatchd4),
		.d5(stopwatchd5),
		.d6(stopwatchd6),
		.led1(stopwatchled1),
		.led2(stopwatchled2),
		.led3(stopwatchled3),
		.led4(stopwatchled4),
		.led5(stopwatchled5),
		.led6(stopwatchled6)
	 );
	 
	 


endmodule
