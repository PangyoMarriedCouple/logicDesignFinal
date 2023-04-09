`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:31:29 12/16/2022 
// Design Name: 
// Module Name:    calendar 
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
module calendar(
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
	 
	 reg [5:0] led6bit;
	 
	 // real value
	 reg[6:0] y;
	 reg[3:0] m;
	 reg[5:0] day;
	 reg[3:0] yoil;
	 
	 reg[30:0] counter1; // half freq. snuBoard 2000000 / 2. xilinx 50000000 / 2
	 
	 parameter secfreq = 2000000;	// freq. snuBoard 2000000 xilinx 50000000 
	 parameter buttonfreq = 40000;
	 
	 // calendar isUsing : 1
	 reg [3:0] y1;
	 reg [3:0] y2;
	 reg m1;
	 reg [3:0] m2;
	 reg [3:0] day1;
	 reg [3:0] day2;
	 
	 reg [2:0] setStatus; // 1 : year change 2 : month change 3 : day change 4 : yoil change 
	 
	 initial 
	 begin 
	 counter1=0;
	 y=0;
	 m=1;
	 day=1;
	 yoil=0; // 0:sunday 1:monday ...
	 end
	 
	 always @ (posedge clkBoard)
	 begin
	 
		 if(reset)
		 begin
			y = 0;
			m=1;
			day=1;
			yoil=0;
		 end
		 else begin end
		 
		 case(setStatus)
		 0:	// calendar display mode
		 begin
			if(set) // set button pushed
			begin
				if(isUsing==1)
				begin
					counter1 = 0;
					setStatus = 1;
				end
				else begin end
			end
			else
			begin
			end
			
			if( counter1 < secfreq ) // half freq. snuBoard 2000000 / 2. xilinx 50000000 / 2
				counter1 = counter1 + 1;
			else // second up
			begin
				counter1 = 0;
			end	
			
		end // case 0 end
		
		1: // year change
		begin
		
			 if(set) // set button pushed
			 begin
					if(isUsing==1)
					begin
						setStatus = 2;
					end
					else begin end
			 end
			 else
			 begin
			 end
			 
			 if(	counter1 < buttonfreq ) 
			 begin // different clock speed when setting - 4 Hz
				counter1 = counter1 + 1;
			 end
			 else
			 begin
				counter1 = 0;
				
				if(up)
				begin
					y=y+1;
				end
				else begin end
				
				if(down)
				begin
					if(y==0)
					begin
						y=99;
					end
					else
					begin
						y=y-1;
					end
				end
				else begin end
	
			 end
			
		end // case 1 end
		
		2: // month change
		begin
		
			 if(set) // set button pushed
			 begin
					if(isUsing==1)
					begin
						setStatus = 3;
					end
					else begin end
			 end
			 else
			 begin
			 end
			 
			 if(	counter1 < buttonfreq ) 
			 begin // different clock speed when setting - 4 Hz
				counter1 = counter1 + 1;
			 end
			 else
			 begin
				counter1 = 0;
				if(up)
				begin
					m=m+1;
				end
				else begin end
				
				if(down)
				begin
					m=m-1;
				end
				else begin end
			 end
		end // case 2 end
		
		3: // day change
		begin
		
			 if(set) // set button pushed
			 begin
					if(isUsing==1)
					begin
						setStatus = 4;
					end
					else begin end
			 end
			 else
			 begin
			 end
			 
			 if(	counter1 < buttonfreq ) 
			 begin // different clock speed when setting - 4 Hz
				counter1 = counter1 + 1;
			 end
			 else
			 begin
				counter1 = 0;
				if(up)
				begin
					day=day+1;
				end
				else begin end
				
				if(down)
				begin
					day=day-1;
				end
				else begin end
			 end
		end // case 3 end
		
		4: // yoil change
		begin
		
			 if(set) // set button pushed
			 begin
					if(isUsing==1)
					begin
						setStatus = 0;
					end
					else begin end
			 end
			 else
			 begin
			 end
			 
			 if(	counter1 < buttonfreq ) 
			 begin // different clock speed when setting - 4 Hz
				counter1 = counter1 + 1;
			 end
			 else
			 begin
				counter1 = 0;
				if(up)
				begin
					yoil=yoil+1;
				end
				else begin end
				
				if(down)
				begin
					yoil=yoil-1;
				end
				else begin end
			 end
		end // case 4 end
			
		endcase
		
		//calendar logic start
		
		//year logic start
		if( y > 99 )
		begin
			y = 0;
		end
		else begin end
		
		if( y < 0 )
		begin
			y = 99;
		end
		else begin end
		// year logic end
		
		//month logic start
		if(m>12)
		begin
			m=1;
		end
		else begin end
		
		if(m<1)
		begin 
			m=12;
		end
		else begin end		
		//month logic end
		
		//day logic start
		if( m==1 || m==3 || m==5 ||
			 m==7 || m==8 || m==10 ||
			 m==12 ) //31days
		begin 
			if(day>31)
			begin
				day=1;
			end
			else begin end
			if(day<1)
			begin
				day=31;
			end
			else begin end
		end
		else begin end
		
		if( m==4 || m==6 || m==9 || 
			 m==11 ) //30days	
		begin
			if(day>30)
			begin
				day=1;
			end
			else begin end
			if(day<1)
			begin
				day=30;
			end
			else begin end
		end
		else begin end
		
		
		if(m==2) //28days
		begin
			if(day>28)
			begin
				day=1;
			end
			else begin end
			if(day<1)
			begin
				day=28;
			end
			else begin end
		end
		else begin end
		
		//day logic end 
		
		if(yoil>6)
		begin
			yoil=0;
		end
		else begin end
		
		if(yoil<0)
		begin
			yoil=6;
		end
		else begin end
		
		//calendar logic end
		 
		//define y1 y2 m1 m2 d1 d2
		
		//define y1 y2
		if(y>89)
		begin
			y1=9;
			y2=y-90;
		end
		else if(y>79)
		begin
			y1=8;
			y2=y-80;
		end
		else if(y>69)
		begin
			y1=7;
			y2=y-70;
		end
		else if(y>59)
		begin
			y1=6;
			y2=y-60;
		end
		else if(y>49)
		begin
			y1=5;
			y2=y-50;
		end
		else if(y>39)
		begin
			y1=4;
			y2=y-40;
		end
		else if(y>29)
		begin
			y1=3;
			y2=y-30;
		end
		else if(y>19)
		begin
			y1=2;
			y2=y-20;
		end
		else if(y>9)
		begin
			y1=1;
			y2=y-10;
		end
		else  // y 1 digit 
		begin
			y1=0;
			y2=y;
		end
		// y1 y2 definition end
		
		// m1 m2 definition
		if(m>9)
		begin
			m1=1;
			m2=m-10;
		end
		else // m is 1 digit
		begin
			m1=0;
			m2=m;
		end
		
		// d1 d2 definition
		if(day>29)
		begin
			day1=3;
			day2=day-30;
		end
		else if(day>19)
		begin
			day1=2;
			day2=day-20;		
		end
		else if(day>9)
		begin
			day1=1;
			day2=day-10;
		end
		else // d is 1 digit
		begin
			day1=0;
			day2=day;
		end
		// day definition end
				
		// definition end
		
		// display start
		case(y1)
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
		 case(y2)
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
		case(m1)
          4'b0000: d3=7'b1111110;
          4'b0001: d3=7'b0110000;
			 default: d3=7'b0000000;
      endcase
      case(m2)
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
      case(day1)
          4'b0000: d5=7'b1111110;
          4'b0001: d5=7'b0110000;
          4'b0010: d5=7'b1101101;
          4'b0011: d5=7'b1111001;
			 default: d5=7'b0000000;
      endcase
      case(day2)
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
		 
		 case(yoil)
			 0: led6bit=6'b111111; //sunday
			 1: led6bit=6'b100000; //monday
			 2: led6bit=6'b010000; 
			 3: led6bit=6'b001000; 
			 4: led6bit=6'b000100; 
			 5: led6bit=6'b000010; 
			 6: led6bit=6'b000001; 
		 endcase
		 
		 led1=led6bit[5];
		 led2=led6bit[4];
		 led3=led6bit[3];
		 led4=led6bit[2];
		 led5=led6bit[1];
		 led6=led6bit[0];
		
		// display end			
	 end	// always end
	 

endmodule
