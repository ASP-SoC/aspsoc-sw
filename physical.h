#ifndef PHYSICAL_H
#define PHYSICAL_H

int open_physical(int);
void * map_physical(int, unsigned int, unsigned int);
void close_physical(int);
int unmap_physical(void *, unsigned int);

#endif