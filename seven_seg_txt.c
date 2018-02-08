#include <stdio.h>
#include <stdlib.h>

#include "ARM_A9_HPS_bridges.h" // block addresses
#include "lw_bridge.h"


int main(){
	unsigned char text_led[10] = {0x77,0x6D,0x73,0x40,0x6D,0x5C,0x39,0x00,0x00,0x00};
	unsigned int seven_seg1 = 0x39 | (0x5C<<7) | (0x6D<<14);
	unsigned int seven_seg2 = (0x73) | (0x6D<<7) | (0x77<<14);
  
	printf("run...\n");
	
	write_lw(&seven_seg1,PIO_HEX0_2_BASE,1);
	write_lw(&seven_seg2,PIO_HEX3_5_BASE,1);
	
	return 0;
}

