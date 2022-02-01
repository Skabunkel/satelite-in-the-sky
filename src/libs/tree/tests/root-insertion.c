#include <assert.h>
#include <stdio.h>
#include "../tree.h"

const uint16_t address01 =  12;

int main(int argc, char** argv)
{
  node_t *root = NULL;
  insertNode(&root, address01, NULL);

  assert(NODE_RED != NODE_BLACK && "NODE_RED and NODE_BLACK should have diffrent values.");
  assert(root->address == address01 && "Address is not assigned as it should be.");
  assert(root->color == NODE_BLACK && "Root note color is not assigned as it should.");
  assert(root->right == NULL && "Right child is not null after zero.");
  assert(root->left == NULL && "Left child is not null after zero.");
  assert(root->mountedComponent == NULL && "Component is not set as expected.");

  return 0;
}