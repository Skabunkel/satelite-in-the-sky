#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdint.h>
#include "../shared.h"

// asking for component 0 will list all probe components.
const uint16_t LIST_PROBE_COMPONENTS = 0x0;
const uint16_t DISSCONNECT_FROM_PROBE = 0xffff;

/*
* component functionpointer, it takes a callback function with signature
* (const struct probe*, const struct component*, const void*)
* void* is the raw data from the input buffer
*/
typedef void (*component_operator)(const struct probe*, const struct component*, const void*);



/*
* So this is a probe component, each component does diffrent things.
*/
typedef struct component
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
} component_t;


#endif //COMPONENT_H