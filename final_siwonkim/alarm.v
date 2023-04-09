`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    03:14:43 12/17/2022 
// Design Name: 
// Module Name:    alarm 
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
module alarm(
	 input alarmoff,
	 input [5:0] sec,
	 input [5:0] m,
	 input [5:0] h,
	 input is12,
	 input [2:0] isUsing,
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
	 output reg alarmonout
    );
	 
	 reg [26:0] setcounter;
	 
	 reg [30:0] blinkcounter;
	 reg blink;
	 
	 // for display ease
	 reg[2:0] sec1;
	 reg[3:0] sec2;
	 reg[2:0] m1;
	 reg[3:0] m2;
	 
	 reg[26:0] counter1; // half freq. snuBoard 2000000 / 2. xilinx 50000000 / 2
	 
	 parameter secfreq = 50000000;	// freq. snuBoard 2000000 xilinx 50000000 
	 parameter buttonfreq = 7000000;

	 reg [1:0] setStatus; // 0-> display 1 -> first two 
	 reg hasalarm; // 0-> no alarm
	 reg alarmon; // when alarm time == current time;
	 reg [5:0] ah; // alarm hour
	 reg [5:0] am; // alarm minute
	 reg [5:0] asec; // alarm second
	 
	 initial begin
		setcounter=0;
	   blinkcounter=0;
	   blink=0;
	   sec1=0;
	   sec2=0;
		m1=0;
		m2=0;
		counter1=0;	 
		setStatus = 0;
		hasalarm = 0;
		alarmon = 0;
		ah = 0;
		am = 0;
		asec = 0;
	 end
	 
	 always @ (posedge clkBoard)
	 begin
	 
		if( (hasalarm==1)&&(m==am)&&(h==ah) )
		begin
			alarmon=1;
		end
		else begin end
		
		if( alarmoff==1 )
		begin
			alarmon=0;
		end
		else begin end
		
		alarmonout = alarmon;
	 
		 if(reset)
		 begin
			counter1 = 0;
			setStatus = 0;
			hasalarm = 0;
			alarmon = 0;
			ah=0;
			am=0;
			asec=0;
		 end
		 else begin end
		 
		 case(setStatus)
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
						if(isUsing==2)
							begin
								counter1 = 0;
								hasalarm=1;
								setStatus = 1;
							end
						else begin end
						//my	
						// your code here
						end
					else begin end	
			 end

			
			if( counter1 < secfreq ) 
				counter1 = counter1 + 1;
			else // second up
			begin
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
						if(set)
							begin
							// your code here
							//my
							if(isUsing==2)
							begin
								hasalarm=1;
								setStatus = 2;
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
				 if(up)
				 begin
					if(is12==0) // 24 mode hr change
					begin
						if(ah<23)
							ah=ah+1;
						else
							ah=0;
					end
					else	// 12 mode am pm change
					begin 
						if( ah > 11)
						begin
							ah = ah-12;
						end
						else
						begin
							ah = ah+12;
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
						if (ah > 0) 
						begin
							ah = ah-1;
						end 
						else 
						begin
							ah = 23;
						end
					end	// 24 mode hr change end
					else	// 12 mode am pm change 
					begin
						if( ah > 11)
						begin
							ah = ah-12;
						end
						else
						begin
							ah = ah+12;
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
							//my
							if(isUsing==2)
							begin
									if(is12==0) // 24 mode go to clock display mode
									begin
										hasalarm = 1;
										setStatus = 0;
									end
									else begin
										setStatus = 3; // 12 mode go to min set mode
									end
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
				if(is12==0) // 24 mode min change
				begin
					if(am<59)
						am=am+1;
					else
						am=0;
				end
				else	// 12 mode hr change
				begin 
					if(ah<23)
						ah=ah+1;
					else
						ah=0;
				end
			 end // case2 up finished
			 else
			 begin
			 end
			 
			 if(down)
			 begin
				if(is12==0) // 24 mode min change
				begin
					if(am>0)
					begin
						am=am-1;
					end
					else
					begin
						am=59;
					end
				end	// 24 mode min change end
				else	// 12 mode hr change 
				begin
					if(ah>0)
					begin
						ah=ah-1;
					end
					else
					begin
						ah=23;
					end
				end	// 12 mode hr change end
			 end	// case2 down finished
			 else begin end
		 end 
		 // down end 		 
		 end
		 //case 2 finished
		 
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
						if(isUsing==2)
						begin
							hasalarm = 1;
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
				if( am<59 )
					am=am+1;
				else
					am=0;
			 end
			 else
			 begin
			 end	// min up finished
			 
			 if(down)	
			 begin
				if(am>0)
					am=am-1;
				else
					am=59;
			 end
			 else
			 begin
			 end	
			 
			 //down end
		end	 
		end // case 3 end
				 
		endcase
		
		//clock logic start
		 if (asec > 59) 
		 begin 
			 asec = 0;
		 end 
		 else begin end
		 if (am > 59) 
		 begin 
			 am = 0;			 
		 end
		 else begin end
		 if (ah > 23) 
		 begin 
			 ah = 0;
		 end
		 else begin end
	 //clock logic end
	 
	 // alarm deactivation
	 if( (setStatus==0)&&(up==1) )
	 begin
		hasalarm = 0;
	 end
	 else begin end
	 
	 
	 // define m1 m2 sec1 sec2 
	 if(am>49)
	 begin
		m1 = 5;
		m2 = am-50;
	 end
	 else if(am>39)
	 begin
		m1 = 4;
		m2 = am-40;
	 end
	 else if(am>29)
	 begin
		m1 = 3;
		m2 = am-30;
	 end
	 else if(am>19)
	 begin
		m1 = 2;
		m2 = am-20;
	 end
	 else if(am>9)
	 begin
		m1 = 1;
		m2 = am-10;
	 end
	 else // m is 1 digit
	 begin
		m1 = 0;
		m2 = am;
	 end
	 
	 
	 if(asec>49)
	 begin
		sec1 = 5;
		sec2 = asec-50;
	 end
	 else if(asec>39)
	 begin
		sec1 = 4;
		sec2 = asec-40;
	 end
	 else if(asec>29)
	 begin
		sec1 = 3;
		sec2 = asec-30;
	 end
	 else if(asec>19)
	 begin
		sec1 = 2;
		sec2 = asec-20;
	 end
	 else if(asec>9)
	 begin
		sec1 = 1;
		sec2 = asec-10;
	 end
	 else // m is 1 digit
	 begin
		sec1 = 0;
		sec2 = asec;
	 end
	 
	 // definition finished
	 
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
	 
	 //display start
	 if(hasalarm==1)
	 begin
	 //original logic start here
	 
		 if( (setStatus==1) && (isUsing==2) && (blink==1)	)
		 begin		
				d1=0;
		 end
		 else 
		 begin
		 //original d logic start here
			// d1 display start
		 if(is12==0) // d1 24 mode
		 begin
			  if(ah<10)
			  begin
					d1 = 7'b1111110;
			  end
			  else if(ah<20)
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
			 if(ah<12) // am
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
	 		 
	//original logic ends here
	end
	else
	begin
		d1=7'b0000001;
	end
	// alarm d1 over
	
	if(hasalarm==1)
	 begin
	 //original logic start here
	 
	 if( (setStatus==1) && (isUsing==2) && (blink==1)	)
	 begin		
			d2=0;
	 end
	 else 
	 begin
	 //original d logic start here
	 //d2 start
	 if(is12==0) // d2 24 mode 
	 begin
		  if(ah<10)
		  begin
			case(ah)
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
	  else if(ah<20)
	  begin
		case(ah-10)
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
	  case(ah-20)
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
	 
	 //original logic ends here
	end
	else
	begin
		d2=7'b0000001;
	end
	// alarm d2 over
	
	if(hasalarm==1)
	 begin
	 //original logic start here
	 
	 if( (setStatus==2) && (isUsing==2) && (blink==1)	)
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
		if(ah<12)
		begin
			if(ah<10)
				d3 = 7'b1111110;
			else
				d3 = 7'b0110000;
		end
		else // 12~23
		begin
			if(ah-12<10)
				d3 = 7'b1111110;
			else
				d3 = 7'b0110000;
		end
	 end
	 //d3 end
	 
		 
	 //original d logic end here	 
	 end
	 
	 
	 
	 
	 //original logic ends here
	end
	else
	begin
		d3=7'b0000001;
	end
	// alarm d3 over
	
	if(hasalarm==1)
	 begin
	 //original logic start here
	 
	 if( (setStatus==2) && (isUsing==2) && (blink==1)	)
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
	 if(ah<12)
	 begin
		 if(ah<10)
		  begin
			case(ah)
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
			case(ah-10)
				 4'b0000: d4=7'b1111110;
				 4'b0001: d4=7'b0110000; 
				 default: d4=7'b0000000;
			 endcase
		  end
	 end
	 else	// h 12~23
	 begin
		 if(ah-12<10) // h 12 ~ 21 
		  begin
			case(ah-12)
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
			case(ah-22)
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
	 
	 
	 
	 //original logic ends here
	end
	else
	begin
		d4=7'b0000001;
	end
	// alarm d4 over
	
	if(hasalarm==1)
	 begin
	 //original logic start here
	 
	 if( (setStatus==3) && (isUsing==2) && (blink==1)	)
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
	 
	 //original logic ends here
	end
	else
	begin
		d5=7'b0000001;
	end
	// alarm d5 over
	
	if(hasalarm==1)
	 begin
	 //original logic start here
	 
	 
	 if( (setStatus==3) && (isUsing==2) && (blink==1)	)
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
	 
	 
	 
	 //original logic ends here
	end
	else
	begin
		d6=7'b0000001;
	end
	// alarm d6 over
	 
	 //display end
	 
	 end // always end


endmodule
