#ifndef _PROBE_H
#define _PROBE_H

#include <stdint.h>
#include "../shared.h"
#include "../tree/tree.h"



/*
* So this symbolizes a "spaceprobe" for the lack of a better word, it has a number of components that can perform operations.
*/
typedef struct probe
{
  // this is tree storing the components the probe has in a addressable space.
  node_t* component;
  
  // x,y,z represent the probes position inside a grid cell.
  float x;
  float y;
  float z;

  // vel_x,vel_y,vel_z represent the probes velocity.
  float vel_x;
  float vel_y;
  float vel_z;

  // grid_x,grid_y,grid_z represent the probes grid position.
  uint16_t grid_x;
  uint16_t grid_y;
  uint16_t grid_z;

  // the number of components in the tree.
  uint16_t componentCount;
  
} probe_t;



#endif //_PROBE_H
