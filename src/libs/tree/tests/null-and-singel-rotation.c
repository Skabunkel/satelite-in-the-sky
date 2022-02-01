#include <assert.h>
#include <stdio.h>
#include "../tree.h"

const uint16_t address01 =  12;

int main(int argc, char** argv)
{
  node_t *root = NULL;

  leftRotateNode(&root, &root);

  assert(root == NULL && "Null root should not be left rotated.");

  rightRotateNode(&root, &root);

  assert(root == NULL && "Null root should not be right rotated.");


  insertNode(&root, address01, NULL);

  assert(root->address == address01 && "Root is not configured correctly for test.");
  assert(root->color == NODE_BLACK && "Root color is not configured correctly for test.");
  assert(root->right == NULL && "Right node should be null after setup.");
  assert(root->left == NULL && "Left node should be null after setup.");

  leftRotateNode(&root, &root);

  assert(root->address == address01 && "Single node tree should not be left rotated.");
  assert(root->color == NODE_BLACK && "Single node tree should not be left rotated.");
  assert(root->right == NULL && "Single node tree should not be left rotated.");
  assert(root->left == NULL && "Single node tree should not be left rotated.");

  rightRotateNode(&root, &root);

  assert(root->address == address01 && "Single node tree should not be right rotated.");
  assert(root->color == NODE_BLACK && "Single node tree should not be right rotated.");
  assert(root->right == NULL && "Single node tree should not be right rotated.");
  assert(root->left == NULL && "Single node tree should not be right rotated.");

  return 0;
}