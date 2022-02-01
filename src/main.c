#include <stdio.h>
#include <stdint.h>
#include "libs/component/component.h"
#include "libs/probe/probe.h"
#include "libs/tree/tree.h"

/*
* To whom ever is reading this, i have no idea what i'm doing, this was a weird idea that i.... well i dont know.
*/


int main(int argc, char** argv)
{
  int *d = (int*)NULL;
  const int **x = &d;
  int *a = (*x);
  if(a == NULL)
  {
    printf("This works.\r\n");
  }

  printf("probe:%lu component:%lu node:%lu", sizeof(probe_t), sizeof(component_t), sizeof(node_t));
  return 0;
}