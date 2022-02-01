#include <stdlib.h>
#include <memory.h>
#include "tree.h"

void rightRotateNode(const node_t **root, const node_t **pivot)
{
  if((*pivot) != NULL && (*pivot)->left != NULL)
  {
    node_t *current = (*pivot);
    node_t *leftChild = (*pivot)->left;
    node_t *parent = (*pivot)->parent;

    current->left = leftChild->right;
    leftChild->right = current;
    current->parent = leftChild;
    leftChild->parent = parent;

    if(parent == NULL)
    {
      (*root) = leftChild;
    }
    else
    {
      if(parent->left == (*pivot))
      {
        parent->left = leftChild;
      }
      else
      {
        parent->right = leftChild;
      }
    }
  }
}

void leftRotateNode(const node_t **root, const node_t **pivot)
{
  if((*pivot) != NULL && (*pivot)->right != NULL)
  {
    node_t *current = (*pivot);
    node_t *rightChild = (*pivot)->right;
    node_t *parent = (*pivot)->parent;

    current->right = rightChild->left;
    rightChild->left = current;
    current->parent = rightChild;
    rightChild->parent = parent;

    if(parent == NULL)
    {
      (*root) = rightChild;
    }
    else
    {
      if(parent->left == (*pivot))
      {
        parent->left = rightChild;
      }
      else
      {
        parent->right = rightChild;
      }
    }
  }
}

void insertNode(const node_t **root, const uint16_t address, const struct component *componentToMount)
{
  node_t *new = (node_t*)malloc(sizeof(node_t));
  memset(new, 0, sizeof(node_t));
  new->address = address;
  new->mountedComponent = componentToMount;


  if((*root) == NULL)
  {
    new->color = NODE_BLACK;
    (*root) = new;
    return;
  }
  else
  {
    node_t *parent = NULL;
    node_t *current = (*root);
    do
    {
      parent = current;
      current = new->address < current->address ? current->left : current->right;
    } while (current != NULL);
    
  }

  return;
}

void removeNode(const node_t **root, const uint16_t address)
{
  node_t* node = findNode(root, address);

  if(node != NULL)
  {
    /* run throught node deletion cases here. */
    free(node->mountedComponent);
    free(node);
  }
}

node_t* findNode(const node_t **root, const uint16_t address)
{
  node_t *current = (*root);

  while (current != NULL)
  {
    if(current->address == address)
    {
        break;
    }
    current = address < current->address ? current->left : current->right;
  }

  return current;
}



