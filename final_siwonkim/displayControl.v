`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:47:47 12/16/2022 
// Design Name: 
// Module Name:    displayControl 
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
module displayControl(
	 input is12in,
	 input [2:0] isUsing,
    input clkBoard,
	 input reset,
    input set,
    input up,
    input down,
	 output reg is12out,
    output reg [6:0] d1,
    output reg [6:0] d2,
    output reg [6:0] d3,
    output reg [6:0] d4,
    output reg [6:0] d5,
    output reg [6:0] d6
    );
	 
	 reg [26:0] setcounter;
	 parameter buttonfreq = 7000000;
	 
	 initial begin
		setcounter = 0;
	 end

	 always @ (posedge clkBoard)
	 begin
	 
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
				//my
			if(isUsing == 4)
			begin
				is12out = ~is12in;
			end
			else
			begin
			end
				// my
				
					
				// your code here
		end
		else begin end	
	 end
		
	 
		d1 = 7'b0111101;
		d2 = 7'b1001110;
		d3 = 7'b0000000;
		d4 = 7'b0000000;
		d5 = 7'b0000000;
		d6 = 7'b0000000;
	 end

endmodule
