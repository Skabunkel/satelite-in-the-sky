#ifndef _PROBE_H
#define _PROBE_H

#include <stdint.h>

struct probe;
struct probe_component;

// asking for component 0 will list all probe components.
const uint16_t LIST_PROBE_COMPONENTS = 0x0;
const uint16_t DISSCONNECT_FROM_PROBE = 0xffff;

typedef void (*component_operator)(struct probe*, struct probe_component*, void*);

/*
* To whom ever is reading this, i have no idea what i'm doing, this was a weird idea that i.... well i dont know.
*/

/*
* So this symbolizes a "spaceprobe" for the lack of a better word, it has a number of components that can perform operations.
*/
typedef struct probe
{
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

  // the number of components installed in the probe.
  uint16_t componentCount;

  // this is the list of components in the probe
  struct probe_component* component;
} probe_t;

/*
* So this is a probe component, each component does diffrent things.
*/
typedef struct probe_component
{
  // each component is mounted on a location, and so has an offset from the center of the probe.
  float xOffset;
  float yOffset;
  float zOffset;

  // each component has a type, camera, sensor, engine
  uint16_t componentType;
  // the manifacturers id, i may remove this later it is probably stupid.
  uint16_t manifacturer;

  // each component has some sort of operation.
  component_operator operator;
} probe_component_t;

#endif //_PROBE_H
