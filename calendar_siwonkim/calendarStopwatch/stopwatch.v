`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:22:25 12/18/2022 
// Design Name: 
// Module Name:    stopwatch 
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
module stopwatch(
	 input clkBoard,
	 input [2:0] isUsing,
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
	 
	 reg [6:0] m;
	 reg [6:0] sec;
	 reg [6:0] msec;
	 reg [26:0] counter1; // half freq. snuBoard 2000000 / 2. xilinx 50000000 / 2
	 reg [26:0] setcounter;
	 reg [26:0] upcounter;

	 
	 parameter secfreq = 50000000;	// freq. snuBoard 2000000 xilinx 50000000 
	 parameter buttonfreq = 7000000;
	 
	 reg [3:0] m1;
	 reg [3:0] m2;
	 reg [3:0] sec1;
	 reg [3:0] sec2;
	 reg [3:0] msec1;
	 reg [3:0] msec2;
	 reg isrunning;
	 
	 initial begin
      upcounter = 0;	 
		setcounter = 0;
		m=0;
		sec=0;
		msec=0;
		counter1=0;
		isrunning=0;
		m1=0;
		m2=0;
		sec1=0;
		sec2=0;
		msec1=0;
		msec2=0;
	 end
	 
	 always @ (posedge clkBoard)
	 begin
	 
	 if(reset)
	 begin
		m=0;
		sec=0;
		msec=0;
		isrunning=0;
	 end
	 else begin end
	 
	 case (isrunning)
		 0:
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
							if(isUsing==3)
							begin
								counter1 = 0;
								isrunning = 1;
							end
							else begin end
							//my
							// your code here
							end
						else begin end	
				 end

			
				/*
				if( counter1 < secfreq ) // freq / 10 xilinx 50000000 / 2
				begin
					counter1 = counter1 + 1;
				end
				else // second up
				begin
					counter1 = 0;
				end
				*/

			//press up button 
			
			if( upcounter < buttonfreq )
			begin
					upcounter = upcounter + 1;
			end		
			else 
			begin
				upcounter = 0;
				if(up)
				begin
				// your code here
				//my
				m=0;
				sec=0;
				msec=0;
				//my
				// your code here
				end
			else begin end	
			end
			
			
			
			//press up button end
					
		 end // case 0 end
		 
		 1:
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
						if(isUsing==3)
						begin
							isrunning = 0;
						end
						else begin end
						//my
						// your code here
						end
					else begin end	
			 end		
			
			if(	counter1 < 500000 ) // secfreq / 100
			begin // different clock speed when setting - 4 Hz
					counter1 = counter1 + 1;
			end
			else
			begin
					counter1 = 0;
					msec = msec+1;
			end
		 	 
		 end // case 1 end
	 	 
	 endcase
	 
	 //clock logic start
	 if (msec > 99) 
	 begin 
       msec = 0;
       sec = sec + 1;
    end 
	 else begin end
	 
	 if (sec > 59) 
	 begin 
       sec = 0;
		 if(m<59)
		 begin
			m = m + 1;
		 end
		 else
		 begin
			sec=59;
			msec=99;
		 end
    end 
	 else begin end
	 
	 //clock logic end
	 
	 // define m1 m2 sec1 sec2 msec1 msec2
	 
		 // define m1 m2 start
		 if(m>49)
		 begin
			m1 = 5;
			m2 = m-50;
		 end
		 else if(m>39)
		 begin
			m1 = 4;
			m2 = m-40;
		 end
		 else if(m>29)
		 begin
			m1 = 3;
			m2 = m-30;
		 end
		 else if(m>19)
		 begin
			m1 = 2;
			m2 = m-20;
		 end
		 else if(m>9)
		 begin
			m1 = 1;
			m2 = m-10;
		 end
		 else // m is 1 digit
		 begin
			m1 = 0;
			m2 = m;
		 end	
		 //define m1 m2 end
		 
		 //define sec1 sec2 start
		 
			 if(sec>49)
			 begin
				sec1 = 5;
				sec2 = sec-50;
			 end
			 else if(sec>39)
			 begin
				sec1 = 4;
				sec2 = sec-40;
			 end
			 else if(sec>29)
			 begin
				sec1 = 3;
				sec2 = sec-30;
			 end
			 else if(sec>19)
			 begin
				sec1 = 2;
				sec2 = sec-20;
			 end
			 else if(sec>9)
			 begin
				sec1 = 1;
				sec2 = sec-10;
			 end
			 else // m is 1 digit
			 begin
				sec1 = 0;
				sec2 = sec;
			 end
		 
		 //define sec1 sec2 end
		 
		 		 
		 //define msec1 msec2 start
		 
			 if(msec>89)
			 begin
				msec1 = 9;
				msec2 = msec-90;
			 end
			 else if(msec>79)
			 begin
				msec1 = 8;
				msec2 = msec-80;
			 end
			 else if(msec>69)
			 begin
				msec1 = 7;
				msec2 = msec-70;
			 end
			 else if(msec>59)
			 begin
				msec1 = 6;
				msec2 = msec-60;
			 end
			 else if(msec>49)
			 begin
				msec1 = 5;
				msec2 = msec-50;
			 end
			 else if(msec>39)
			 begin
				msec1 = 4;
				msec2 = msec-40;
			 end
			 else if(msec>29)
			 begin
				msec1 = 3;
				msec2 = msec-30;
			 end
			 else if(msec>19)
			 begin
				msec1 = 2;
				msec2 = msec-20;
			 end
			 else if(msec>9)
			 begin
				msec1 = 1;
				msec2 = msec-10;
			 end
			 else // m is 1 digit
			 begin
				msec1 = 0;
				msec2 = msec;
			 end		 
		 //define msec1 msec2 end

	 // definition end
	 
	 
	 //display start
	 //d1 start
	 case(m1)
				 4'b0000: d1=7'b1111110;
				 4'b0001: d1=7'b0110000;
				 4'b0010: d1=7'b1101101;
				 4'b0011: d1=7'b1111001;
				 4'b0100: d1=7'b0110011;
				 4'b0101: d1=7'b1011011;
				 4'b0110: d1=7'b1011111;
				 4'b0111: d1=7'b1110000;
				 4'b1000: d1=7'b1111111;
				 4'b1001: d1=7'b1111011; 
				 default: d1=7'b0000000;
	 endcase
	 //d2start
	 case(m2)
				 4'b0000: d2=7'b1111110;
				 4'b0001: d2=7'b0110000;
				 4'b0010: d2=7'b1101101;
				 4'b0011: d2=7'b1111001;
				 4'b0100: d2=7'b0110011;
				 4'b0101: d2=7'b1011011;
				 4'b0110: d2=7'b1011111;
				 4'b0111: d2=7'b1110000;
				 4'b1000: d2=7'b1111111;
				 4'b1001: d2=7'b1111011; 
				 default: d2=7'b0000000;
	 endcase
	 //d3start
	 case(sec1)
				 4'b0000: d3=7'b1111110;
				 4'b0001: d3=7'b0110000;
				 4'b0010: d3=7'b1101101;
				 4'b0011: d3=7'b1111001;
				 4'b0100: d3=7'b0110011;
				 4'b0101: d3=7'b1011011;
				 4'b0110: d3=7'b1011111;
				 4'b0111: d3=7'b1110000;
				 4'b1000: d3=7'b1111111;
				 4'b1001: d3=7'b1111011; 
				 default: d3=7'b0000000;
	 endcase
	 //d4start
	 case(sec2)
				 4'b0000: d4=7'b1111110;
				 4'b0001: d4=7'b0110000;
				 4'b0010: d4=7'b1101101;
				 4'b0011: d4=7'b1111001;
				 4'b0100: d4=7'b0110011;
				 4'b0101: d4=7'b1011011;
				 4'b0110: d4=7'b1011111;
				 4'b0111: d4=7'b1110000;
				 4'b1000: d4=7'b1111111;
				 4'b1001: d4=7'b1111011; 
				 default: d4=7'b0000000;
	 endcase
	 //d5start
	 case(msec1)
				 4'b0000: d5=7'b1111110;
				 4'b0001: d5=7'b0110000;
				 4'b0010: d5=7'b1101101;
				 4'b0011: d5=7'b1111001;
				 4'b0100: d5=7'b0110011;
				 4'b0101: d5=7'b1011011;
				 4'b0110: d5=7'b1011111;
				 4'b0111: d5=7'b1110000;
				 4'b1000: d5=7'b1111111;
				 4'b1001: d5=7'b1111011; 
				 default: d5=7'b0000000;
	 endcase
	 //d6start
	 case(msec2)
				 4'b0000: d6=7'b1111110;
				 4'b0001: d6=7'b0110000;
				 4'b0010: d6=7'b1101101;
				 4'b0011: d6=7'b1111001;
				 4'b0100: d6=7'b0110011;
				 4'b0101: d6=7'b1011011;
				 4'b0110: d6=7'b1011111;
				 4'b0111: d6=7'b1110000;
				 4'b1000: d6=7'b1111111;
				 4'b1001: d6=7'b1111011; 
				 default: d6=7'b0000000;
	 endcase
	 
	 //ledstart
	 led1=0;
	 led2=0;
	 led3=0;
	 led4=0;
	 led5=0;
	 led6=0;	 	
	 //display end
	 
	 end // always end


endmodule
