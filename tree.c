#include "tree.h"

static tree t;

void treeInit() {
  t.root = NULL;
}

/* recursive adding value to tree */
/* call this function with node = t.root */
static void add(int value, treeNode *node) {
  if(node == NULL)
    return;
  if(node->value == value)
    return;
  else if(node->value < value)
    if(node->rightChild == NULL) {
      node->rightChild = nodeConstructor(value);
      return;
    } else
      add(value, node->rightChild);
  else  /* node->value > value */
    if(node->leftChild == NULL) {
      node->leftChild = nodeConstructor(value);
      return;
    } else
      add(value, node->leftChild);
  return;
}

void addValueToTree(int value) {
  if(t.root == NULL) {
    t.root = nodeConstructor(value);
    return;
  }
  add(value, t.root);
  return;
}

/* str is a sequence of numbers */
/* characters: '0' to '9' and ' ' (spaces) */
void strToTree(char *str) {
  int value;
  while(*str != '\0') {
    value = 0;
    while(*str != ' ' && *str != '\0') {
      value = value*10 + (*str-'0');
      ++str;
    }
    addValueToTree(value);
    if(*str == ' ')
      ++str;
  }
  return;
}

static void printTreeFromMinToMax(treeNode *node) {
  if(node == NULL)
    return;
  printTreeFromMinToMax(node->leftChild);
  printf("%d ", node->value);
  printTreeFromMinToMax(node->rightChild);
  return;
}

void printTreeAscending() {
  if(t.root == NULL)
    return;
  printTreeFromMinToMax(t.root);
  return;
}

static void deleteTreeNodes(treeNode *node) {
  if(node == NULL)
    return;
  deleteTreeNodes(node->leftChild);
  deleteTreeNodes(node->rightChild);
  deleteNode(node);
  return;
}

void deleteTree() {
  if(t.root == NULL)
    return;
  deleteTreeNodes(t.root);
  return;
}