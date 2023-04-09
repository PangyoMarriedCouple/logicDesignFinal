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
module modeControl(
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
	 
	 reg [2:0] isUsing; // 0:clock 2:alarm 4:displaycontrol
	 wire is12; // global variable put into clock. modified in displayControl 
	 wire is12changed;
	 wire [5:0] sec;
	 wire [5:0] m;
	 wire [5:0] h;
	 //wire newset;
	 
	 wire alarmon;
	 wire alarmoff;
	 
	 
	 wire [6:0] clockd1;
	 wire [6:0] clockd2;
	 wire [6:0] clockd3;
	 wire [6:0] clockd4;
	 wire [6:0] clockd5;
	 wire [6:0] clockd6;
	 
	 wire [6:0] calendard1;
	 wire [6:0] calendard2;
	 wire [6:0] calendard3;
	 wire [6:0] calendard4;
	 wire [6:0] calendard5;
	 wire [6:0] calendard6;
	 
	 wire calendarled1,calendarled2,calendarled3,calendarled4,calendarled5,calendarled6;
	 
	 wire [6:0] ad1;
	 wire [6:0] ad2;
	 wire [6:0] ad3;
	 wire [6:0] ad4;
	 wire [6:0] ad5;
	 wire [6:0] ad6;
	 
	 wire [6:0] dcd1;
	 wire [6:0] dcd2;
	 wire [6:0] dcd3;
	 wire [6:0] dcd4;
	 wire [6:0] dcd5;
	 wire [6:0] dcd6;
	 
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
	 
	 clock c1( .alarmon(alarmon), .isUsing(isUsing), .clkBoard(clkBoard), .reset(reset), .set(set), .up(up), .down(down), .is12in(is12changed),
	 .is12out(is12),
    .d1(clockd1),
    .d2(clockd2),
    .d3(clockd3),
    .d4(clockd4),
    .d5(clockd5),
    .d6(clockd6),
	 .secout(sec),
	 .mout(m),
	 .hout(h),
	 .alarmoff(alarmoff)
	 );
	 
	 displayControl dc1(.is12in(is12), .isUsing(isUsing), .clkBoard(clkBoard), .reset(reset), .set(set), .up(up), .down(down),
	 .is12out(is12changed),
	 .d1(dcd1),
    .d2(dcd2),
    .d3(dcd3),
    .d4(dcd4),
    .d5(dcd5),
    .d6(dcd6));
	 
	 alarm a1(
	 .alarmoff(alarmoff),
	 .sec(sec),
	 .m(m),
	 .h(h),
	 .is12(is12changed),
	 .isUsing(isUsing),
    .clkBoard(clkBoard),
	 .reset(reset),
    .set(set),
    .up(up),
    .down(down),
    .d1(ad1),
    .d2(ad2),
    .d3(ad3),
    .d4(ad4),
    .d5(ad5),
    .d6(ad6),
	 .alarmonout(alarmon)	 
	 );
	 
	 
	 parameter buttonfreq = 7000000;
	 reg [26:0] modecounter;
	 
	 initial begin
		isUsing = 0;
		modecounter=0;
	 end
	 	 
	 always @ (posedge clkBoard)
	 begin
	 
		if( modecounter < buttonfreq )
		begin
				modecounter = modecounter + 1;
		end		
		else 
		begin
			modecounter = 0;
			if(mode==1)
				begin
					if(isUsing < 4)
						isUsing = isUsing + 2;
					else
						isUsing = 0;
				end
			else begin end	
		end
	 
	 
		case(isUsing)
		0:
		begin
			d1 = clockd1;
			d2 = clockd2;
			d3 = clockd3;
			d4 = clockd4;
			d5 = clockd5;
			d6 = clockd6;
			led1=0;
			led2=0;
			led3=0;
			led4=0;
			led5=0;
			led6=0;
		end
		2:
		begin
			d1 = ad1;
			d2 = ad2;
			d3 = ad3;
			d4 = ad4;
			d5 = ad5;
			d6 = ad6;
			led1=0;
			led2=0;
			led3=0;
			led4=0;
			led5=0;
			led6=0;
		end
		4:
		begin
			d1 = dcd1;
			d2 = dcd2;
			d3 = dcd3;
			d4 = dcd4;
			d5 = dcd5;
			d6 = dcd6;
			led1=0;
			led2=0;
			led3=0;
			led4=0;
			led5=0;
			led6=0;
		end
		default :
		begin
			d1 = 0;
			d2 = 0;
			d3 = 0;
			d4 = 0;
			d5 = 0;
			d6 = 0;
			led1=0;
			led2=0;
			led3=0;
			led4=0;
			led5=0;
			led6=0;
		end
		
		endcase
	 end
	 
	 /*
	 pulseGenerator p1(
	 .clk(clkBoard),
	 .input_signal(set),
	 .reset(reset),
	 .output_signal(newset)
	 );
	 */
	 
	 
	 


endmodule
