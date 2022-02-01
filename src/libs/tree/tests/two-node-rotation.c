#include <assert.h>
#include <stdlib.h>
#include "../tree.h"

const uint16_t address01 =  12;
const uint16_t address02 =  1211;

int main(int argc, char** argv)
{
  node_t *root = NULL;
  insertNode(&root, address01, NULL);

  node_t *firstRightChild = (node_t*)malloc(sizeof(node_t));
  memset(firstRightChild, 0, sizeof(node_t));
  firstRightChild->address = address02;
  firstRightChild->mountedComponent = NULL;

  root->right = firstRightChild;

  assert(root->right != NULL && "Right node should not be null after setup.");
  assert(root->right->address == address02 && "Right node is not configured correctly for test.");
  assert(root->right->color == NODE_RED && "Right node color is not configured correctly for test.");

  leftRotateNode(&root, &root);

  assert(root->address == address02 && "Root is not correct after left rotation.");
  assert(root->color == NODE_RED && "Root color is not correct after left rotation.");
  assert(root->right == NULL && "Right node should be null after left rotation.");
  assert(root->left != NULL && "Left node should not be null after left rotation.");
  assert(root->left->address == address01 && "Left node is not correct after left rotation.");
  assert(root->left->color == NODE_BLACK && "Left node color is not correct after left rotation.");

  rightRotateNode(&root, &root);

  assert(root->address == address01 && "Root is not correct after right rotation.");
  assert(root->color == NODE_BLACK && "Root color is not correct after right rotation.");
  assert(root->right != NULL && "Right node should not be null after right rotation.");
  assert(root->left == NULL && "Left node should be null after right rotation.");
  assert(root->right->address == address02 && "Right node is not correct after right rotation.");
  assert(root->right->color == NODE_RED && "Right node color is not correct after right rotation.");

  return 0;
}