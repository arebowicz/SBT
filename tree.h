#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include "treeNode.h"

typedef struct tree {
  treeNode *root;
} tree;

void treeInit();
void addValueToTree(int);
void strToTree(char *);
void printTreeAscending();
void deleteTree();
void deleteValue(int);
void printTreeHeight();

#endif