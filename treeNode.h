#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <stdlib.h>   /* malloc, rand */

typedef struct treeNode {
  int value;
  struct treeNode *leftChild;
  struct treeNode *rightChild;
} treeNode;

treeNode *nodeConstructor(int);
void deleteNode(treeNode *);

#endif