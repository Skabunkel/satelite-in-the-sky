#include <stdio.h>
#include <stdint.h>
#include "probe.h"


int main(int argc, char** argv)
{

  printf("probe:%lu component:%lu", sizeof(probe_t), sizeof(probe_component_t));
  return 0;
}