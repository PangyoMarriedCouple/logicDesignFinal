`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    05:28:12 12/16/2022 
// Design Name: 
// Module Name:    clock 
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
module clock(
	 input alarmon,
	 input [2:0] isUsing,
    input clkBoard,
	 input reset,
    input set,
    input up,
    input down,
	 input is12in,
	 output reg is12out,
    output reg [6:0] d1,
    output reg [6:0] d2,
    output reg [6:0] d3,
    output reg [6:0] d4,
    output reg [6:0] d5,
    output reg [6:0] d6,
	 output reg [5:0] secout,
	 output reg [5:0] mout,
	 output reg [5:0] hout,
	 output reg alarmoff
    );
	 
	 reg [30:0] blinkcounter;
	 reg blink;
	 
	 /*
	 reg [30:0] blinkcounter;
	 reg blink;
	 
	 // blink logic front of display part
	 
	 if( blinkcounter < (secfreq/10) )
	 begin
			blinkcounter = blinkcounter+1;
	 end
	 else
	 begin
			blinkcounter = 0;
			blink = ~blink;
	 end
	 
	 // logic end
	 
	 
	 if( (setStatus==3) && (isUsing==2) && (blink==1)	)
	 begin		
			d6=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 
		 
	 //original d logic end here	 
	 end
	 	 
	 
	 */
	 
	 // for display ease
	 reg[2:0] sec1;
	 reg[3:0] sec2;
	 reg[2:0] m1;
	 reg[3:0] m2;
	 
	 // real value
	 reg[5:0] sec;
	 reg[5:0] m;
	 reg[5:0] h;
	 
	 reg [26:0] counter1; // half freq. snuBoard 2000000 / 2. xilinx 50000000 / 2
	 reg [26:0] setcounter;
	 
	 parameter secfreq = 50000000;	// freq. snuBoard 2000000 xilinx 50000000 
	 parameter buttonfreq = 7000000;
	 
	 //for setting
	 reg is12;
	 reg [1:0] setStatus; // 0-> not setting 1 -> first 2 display 
	 		 
	 initial 
	 begin 
	 setcounter=0;
	 
	 //reg list start
	 blinkcounter=0;
	 blink=0;	 
	 sec1=0;
	 sec2=0;
	 m1=0;
	 m2=0;	 
	 counter1=0;	 
	 //reg list end
	 h=0;
	 m=0;
	 sec=0;
	 setStatus=0;
	 end
	 
	 // new logic start
	 always @ (posedge clkBoard)
	 begin
	 
	 if((alarmon==1)&&(up==1))
	 begin
		alarmoff=1;
	 end
	 else
	 begin
		alarmoff=0;
	 end
	 
	 
	 // from , to other modules
	 is12 = is12in;
	 is12out = is12;
	 secout=sec;
	 mout=m;
	 hout=h;	 
	 
	 if(reset)
	 begin
		setcounter = 0;
		counter1 = 0;
		h=0;
		m=0;
		sec=0;
	 end
	 else begin end
	 
	 case(setStatus)
	 0:	// clock display mode
	 begin
	 
		if( setcounter < buttonfreq )
		begin
				setcounter = setcounter + 1;
		end		
		else 
		begin
				setcounter = 0;
				if( (set==1)&&(isUsing==0) )
				begin
						counter1 = 0;
						sec = 0;
						setStatus = 1;				
				end
				else begin end	
		end
		
		
		if( counter1 < secfreq ) // half freq. snuBoard 2000000 / 2. xilinx 50000000 / 2
		begin
			counter1 = counter1 + 1;
		end
		else // second up
		begin
			sec = sec+1;
			counter1 = 0;
		end
		
	 end // case 0 finished	 
	 1:   // 24 : hr change 12 : am pm change
	 begin
	 
	 	 if( setcounter < buttonfreq )
		 begin
					setcounter = setcounter + 1;
		 end		
		 else 
		 begin
				setcounter = 0;				
				if((set==1)&&(isUsing==0))
				begin
					setStatus = 2;
				end
				else begin end		
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
				if(is12==0) // 24 mode hr change
				begin
					if(h<23)
						h=h+1;
					else
						h=0;
				end
				else	// 12 mode am pm change
				begin 
					if( h > 11)
					begin
						h = h-12;
					end
					else
					begin
						h = h+12;
					end
				end
			 end 
			 else
			 begin
			 end	// case1 up finished
		 
			 if(down)
			 begin
				if(is12==0) // 24 mode hr change
				begin
					if (h > 0) 
					begin
						h = h-1;
					end 
					else 
					begin
						h = 23;
					end
				end	// 24 mode hr change end
				else	// 12 mode am pm change 
				begin
					if( h > 11)
					begin
						h = h-12;
					end
					else
					begin
						h = h+12;
					end		
				end	// 12 mode am pm change end
			 end	// case1 down finished
			 else begin end
		end
		 
	 end // case1 finished
	 
	 2:   // 24 : min change 12 : hr change
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
					//my code here
					if(isUsing==0)
					begin
							if(is12==0) // 24 mode go to clock display mode
								setStatus = 0;
							else
								setStatus = 3; // 12 mode go to min set mode
					end
					else begin end
					//my code here						
					// your code here
					end
				else begin end	
		 end			
		 
		 
		 if(	counter1 < buttonfreq ) 
		 begin // different clock speed when setting - 4 Hz
				counter1 = counter1 + 1;
		 end
		 else
		 begin
			 counter1 = 0;				
		 
			 // up start
			 if(up)
			 begin
				if(is12==0) // 24 mode min change
				begin
					if(m<59)
						m=m+1;
					else
						m=0;
				end
				else	// 12 mode hr change
				begin 
					if(h<23)
						h=h+1;
					else
						h=0;
				end
			 end // case2 up finished
			 else
			 begin
			 end
			 
			 if(down)
			 begin
				if(is12==0) // 24 mode min change
				begin
					if(m>0)
					begin
						m=m-1;
					end
					else
					begin
						m=59;
					end
				end	// 24 mode min change end
				else	// 12 mode hr change 
				begin
					if(h>0)
					begin
						h=h-1;
					end
					else
					begin
						h=23;
					end
				end	// 12 mode hr change end
			 end	// case2 down finished
			 else begin end
		 end 
		 // down end 		 
		 end
		 
	 // only 12 : min change
	 3:   
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
							if(isUsing==0)
							begin
								setStatus = 0;
							end
							else begin end
							//my								
							// your code here
							end
						else begin end	
				 end
		 
		 if(	counter1 < buttonfreq ) 
		 begin // different clock speed when setting - 4 Hz
				counter1 = counter1 + 1;
		 end
		 else
		 begin
			 counter1 = 0;				
		 
			 // up start
			 if(up)	
			 begin
				if( m<59 )
					m=m+1;
				else
					m=0;
			 end
			 else
			 begin
			 end	// min up finished
			 
			 if(down)	
			 begin
				if(m>0)
					m=m-1;
				else
					m=59;
			 end
			 else
			 begin
			 end	
			 
			 //down end
		end
	 
	 end // case 3 end
	 
	 endcase // end of setstatus case
	 
	 //clock logic start
	 if (sec > 59) 
	 begin 
       sec = 0;
       m = m + 1;
    end 
	 else begin end
    if (m > 59) 
	 begin 
       m = 0;
       h = h + 1;
    end
	 else begin end
    if (h > 23) 
	 begin 
       h = 0;
    end
	 else begin end
	 //clock logic end
	 
	 // define m1 m2 sec1 sec2 
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
	 
	 // definition finished
	 
	 // clock display start
	 
	 
	 //d1 start
	 
	 
	 // d1 blink condition
	 // 1. setStatus==1
	 // 2. isUsing==1
	 
	 //logic for blink start
	 if( blinkcounter < (secfreq/10) )
	 begin
			blinkcounter = blinkcounter+1;
	 end
	 else
	 begin
			blinkcounter = 0;
			blink = ~blink;
	 end
	 //logic for blink end
	 
	 if( ((setStatus==1) && (isUsing==0) && (blink==1))|| ((alarmon==1)&& (blink==1))	)
	 begin		
			d1=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 
		 if(is12==0) // d1 24 mode
		 begin
			  if(h<10)
			  begin
					d1 = 7'b1111110;
			  end
			  else if(h<20)
			  begin
					d1 = 7'b0110000;
			  end
			  else
			  begin
					d1 = 7'b1101101;
			  end
		 end
		 else // d1 12 mode
		 begin
			 if(h<12) // am
			 begin
				d1=7'b1110111;
			 end
			 else // pm
			 begin
			 d1=7'b1100111;
			 end 
		 end
		 //d1 end
		 
	 //original d logic end here	 
	 end
	 
	 if( ((setStatus==1) && (isUsing==0) && (blink==1))  ||  ((alarmon==1)&& (blink==1)) )
	 begin		
			d2=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 //d2 start
	 if(is12==0) // d2 24 mode 
	 begin
		  if(h<10)
		  begin
			case(h)
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
		  end
	  else if(h<20)
	  begin
		case(h-10)
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
	  end
	  else
	  begin
	  case(h-20)
          4'b0000: d2=7'b1111110;
          4'b0001: d2=7'b0110000;
          4'b0010: d2=7'b1101101;
          4'b0011: d2=7'b1111001;
			 default: d2=7'b0000000;
       endcase
	  end 
	 end // d2 24 mode end
	 else // d2 12 mode start
	 begin 
	 d2=0;
	 end 
	 //d2 end		 
	 //original d logic end here	 
	 end
	 
	 
	 if( ((setStatus==2) && (isUsing==0) && (blink==1))	|| ((alarmon==1)&& (blink==1))  )
	 begin		
			d3=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 //d3 start
	 if(is12==0) // d3 24 mode
	 begin
      case(m1)
          4'b0000: d3=7'b1111110;
          4'b0001: d3=7'b0110000;
          4'b0010: d3=7'b1101101;
          4'b0011: d3=7'b1111001;
          4'b0100: d3=7'b0110011;
          4'b0101: d3=7'b1011011; 
			 default: d3=7'b0000000;
        endcase
	 end
	 else // d3 12 mode
	 begin
		if(h<12)
		begin
			if(h<10)
				d3 = 7'b1111110;
			else
				d3 = 7'b0110000;
		end
		else // 12~23
		begin
			if(h-12<10)
				d3 = 7'b1111110;
			else
				d3 = 7'b0110000;
		end
	 end
	 //d3 end
	 
		 
	 //original d logic end here	 
	 end
	 

	 if( ((setStatus==2) && (isUsing==0) && (blink==1) )|| ((alarmon==1)&& (blink==1))	)
	 begin		
			d4=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 //d4 start
	 if(is12 ==0 ) // d4 24 mode
	 begin
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
	 end
	 else //d4 12 mode
	 begin
	 if(h<12)
	 begin
		 if(h<10)
		  begin
			case(h)
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
		  end
		  else // 10~11
		  begin
			case(h-10)
				 4'b0000: d4=7'b1111110;
				 4'b0001: d4=7'b0110000; 
				 default: d4=7'b0000000;
			 endcase
		  end
	 end
	 else	// h 12~23
	 begin
		 if(h-12<10) // h 12 ~ 21 
		  begin
			case(h-12)
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
		  end
		  else // 22~23
		  begin
			case(h-22)
				 4'b0000: d4=7'b1111110;
				 4'b0001: d4=7'b0110000; 
				 default: d4=7'b0000000;
			 endcase
		  end
			
	 end
	 
	 end
	 //d4 end
		 
	 //original d logic end here	 
	 end
	 
	 if( ((setStatus==3) && (isUsing==0) && (blink==1) )|| ((alarmon==1)&& (blink==1))	)
	 begin		
			d5=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 //d5 start
	 if(is12==0) //d5 24 mode
	 begin
      case(sec1)
          4'b0000: d5=7'b1111110;
          4'b0001: d5=7'b0110000;
          4'b0010: d5=7'b1101101;
          4'b0011: d5=7'b1111001;
          4'b0100: d5=7'b0110011;
          4'b0101: d5=7'b1011011;
			 default: d5=7'b0000000;
        endcase
	 end
	 else //d5 12 mode
	 begin
		 case(m1)
          4'b0000: d5=7'b1111110;
          4'b0001: d5=7'b0110000;
          4'b0010: d5=7'b1101101;
          4'b0011: d5=7'b1111001;
          4'b0100: d5=7'b0110011;
          4'b0101: d5=7'b1011011; 
			 default: d5=7'b0000000;
        endcase
	 end
	 //d5 end
	 
		 
	 //original d logic end here	 
	 end
	 
	 if( ((setStatus==3) && (isUsing==0) && (blink==1)	)||  ((alarmon==1)&& (blink==1)) )
	 begin		
			d6=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 
	 //d6 start
	 if(is12==0) //d6 24mode
    begin
      case(sec2)
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
    end
	 else //d6 12mode
	 begin
		 case(m2)
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
	 end
	 //d6 end
	 
		 
	 //original d logic end here	 
	 end
	 
		 
	 
	 
	 
	 
	 // clock display end
	 
	 end // end of always	 
	
endmodule
