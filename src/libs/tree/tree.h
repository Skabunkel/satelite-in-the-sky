#ifndef TREE_H
#define TREE_H

#include <stdint.h>
#include "../shared.h"

#define NODE_RED 0x00
#define NODE_BLACK 0x01

// a simple redblack tree, the idea is that component should have a random "port" or address assigned and you should be able to insteract with it.
// sadness there is some padding bytes here but i will alwys have them it seems
typedef struct node
{ 
  struct node *right, *left, *parent;
  struct component *mountedComponent;
  uint16_t address;
  uint8_t color:1;
} node_t;

/* 
* Adds a components into the tree.
*/
void insertNode(const node_t **root, const uint16_t address, const struct component *componentToMount);

/*
* Removes a component from the tree.
* Removing the component from the tree will also free the component.
*/
void removeNode(const node_t **root, const uint16_t address);

/*
* Finds a component in the tree.
* Returns a NULL pointer if it was not found.
*/
node_t* findNode(const node_t **root, const uint16_t address);


/*
* Rotate nodes right.
* Its exposed for testing purpoeses and is not intended to be used.
*/
void rightRotateNode(const node_t **root, const node_t **pivot);

/*
* Rotate nodes left.
* Its exposed for testing purpoeses and is not intended to be used.
*/
void leftRotateNode(const node_t **root, const node_t **pivot);

#endif // TREE_H