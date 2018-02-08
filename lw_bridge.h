#ifndef LW_BRIDGE_H
#define LW_BRIDGE_H

#define LW_BRIDGE_BASE 0xFF200000
#define LW_BRIDGE_SPAN 0x00010000

int write_lw(unsigned int *data,int offset, int len);

#endif