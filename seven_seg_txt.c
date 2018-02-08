#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep

#include "ARM_A9_HPS_bridges.h" // block addresses
#include "lw_bridge.h"

#define SLEEP 800000

void rotate_display_hex(unsigned char *text, int len);

int main(){
	unsigned char text_led[10] = {0x77,0x6D,0x73,0x40,0x6D,0x5C,0x39,0x00,0x00,0x00};
	unsigned int seven_seg1 = 0x39 | (0x5C<<7) | (0x6D<<14);
	unsigned int seven_seg2 = (0x73) | (0x6D<<7) | (0x77<<14);
	
	unsigned int led_data = 0xAAA;
  
	printf("run...\n");
	
	write_lw(&seven_seg1,PIO_HEX0_2_BASE,1);
	write_lw(&seven_seg2,PIO_HEX3_5_BASE,1);
	
	while(1){ // infinite loop
    usleep(SLEEP);
	
	led_data = ~led_data;
    write_lW(&led_data,PIO_LEDS_BASE,1);

    rotate_display_hex(text_led,sizeof(text_led));
  }
	
	return 0;
}

void rotate_display_hex(unsigned char *text, int len){
  static int text_counter = 0;
  unsigned int seven_seg1, seven_seg2;

  seven_seg2 = (text[text_counter] << 14) | (text[(text_counter+1)%10] << 7) | (text[(text_counter+2)%10]);
  seven_seg1 = (text[(text_counter+3)%10] << 14) | (text[(text_counter+4)%10] << 7) | (text[(text_counter+5)%10]);

  write_lw(&seven_seg1,PIO_HEX0_2_BASE,1);
  write_lw(&seven_seg2,PIO_HEX3_5_BASE,1);

  
  if(text_counter == 9){
    text_counter = 0;
  }else{
    text_counter++;
  }

}
