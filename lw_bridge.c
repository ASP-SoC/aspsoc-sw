#include <stdio.h>
#include <stdlib.h>

#include "physical.h"
#include "lw_bridge.h"

int write_lw(unsigned int *data,int offset, int len){
	void * LW_virtual; // physical addresses for LW bridge
    int fd = -1;       // file handle for /dev/mem
	volatile int * ptr;
	
	// Create virtual memory access to the FPGA LW bridge
    if ((fd = open_physical(fd)) == -1) {
        return -1;
    }
    if ((LW_virtual = map_physical(fd, LW_BRIDGE_BASE, LW_BRIDGE_SPAN)) == NULL) {
        return -1;
    }
	
	// Set virtual address pointer to I/O port
    ptr = (unsigned int *)(LW_virtual + offset);
	
	int i = 0;
  
	while(i < len){
		*ptr = data[i];
		i++;
		ptr++;
	}
	
	unmap_physical(LW_virtual, LW_BRIDGE_SPAN);
    close_physical(fd);
	
	return 0;
}