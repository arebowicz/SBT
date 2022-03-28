#include "treeNode.h"

treeNode *nodeConstructor(int value) {
  treeNode *node = (treeNode *) malloc(sizeof(treeNode));
  if(node == NULL)
    return NULL;
  node->value = value;
  node->leftChild = NULL;
  node->rightChild = NULL;
  return node;
}

void deleteNode(treeNode *node) {
  free(node);
  return;
}