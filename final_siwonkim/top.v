module top(
    input clk,
    input push_switch1,
    input push_switch2,
    input push_switch3,
    input push_switch4,
    input push_switch5,
    input push_switch6,

    output [6:0] segment1,
    output [6:0] segment2,
    output [6:0] segment3,
    output [6:0] segment4,
    output [6:0] segment5,
    output [6:0] segment6,
    
	 input dip_switch1,
    input dip_switch2,
    input dip_switch3,
    input dip_switch4,
    input dip_switch5,
    input dip_switch6,
    input dip_switch7,
    input dip_switch8,
    input dip_switch9,
    input dip_switch10,

    output led1_red,
    output led2_yellow,	
    output led3_green,
    output led4_red,
    output led5_yellow,
    output led6_green
);

// Instantiate your design module here
// Example) Your_module uut( .clk(clk), .XX(led1_red) .YY(led2_yellow) ....);

	 
	 modeControl m1(
	 .mode(push_switch1),
    .clkBoard(clk),
	 .reset(push_switch6),
    .set(push_switch2),
    .up(push_switch3),
    .down(push_switch4),
    .d1(segment1),
    .d2(segment2),
    .d3(segment3),
    .d4(segment4),
    .d5(segment5),
    .d6(segment6),
	 .led1(led1_red),
	 .led2(led2_yellow),
	 .led3(led3_green),
	 .led4(led4_red),
	 .led5(led5_yellow),
	 .led6(led6_green)
	 );
	 



endmodule
