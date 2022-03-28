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
  if(t.root == NULL) {
    printf("empty tree...");
    return;
  }
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

/*
  yeah, I know... it's complicated...
  but it works well
  I'm sure that there is simpler way to implement deleting value from binary tree
  and maybe, later, I'll try again
*/
void deleteValue(int value) {
  treeNode *node = t.root;  /* this node will be deleted (if value in tree) */
  treeNode *parent = NULL;  /* parent of above node */
  /* searching for right node (which value == value from function parameter) */
  while(node != NULL) {
    if(node->value == value)
      break;
    parent = node;
    if(node->value > value)
      node = node->leftChild;
    else /* node->value < value */
      node = node->rightChild;
  }
  /* if value isn't in tree */
  if(node == NULL) {
    printf("value %d isn't in tree, nothing to delete...\n", value);
    return;
  }
  /* else if searching value is a leaf */
  else if (node->leftChild == NULL && node->rightChild == NULL) {
    if(parent == NULL) {
      deleteNode(t.root);
      t.root = NULL;
      printf("deleted value %d was a root...\n", value);
      return;
    }
    if(parent->leftChild == node)
      parent->leftChild = NULL;
    else
      parent->rightChild = NULL;
    deleteNode(node);
    printf("deleted value %d was a leaf...\n", value);
    return;
  /* we have to find a successor in our tree */
  } else if(node->rightChild != NULL) {
    treeNode *successor = node->rightChild;
    treeNode *parentOfSuccessor = node;
    /* searching for succesor and his parent */
    while(successor->leftChild != NULL) {
      parentOfSuccessor = successor;
      successor = successor->leftChild;
    }
    /* one smart trick: we can easily change value, there's no need to call deleteNode(node) */
    node->value = successor->value;
    if(parentOfSuccessor == node) {
      parentOfSuccessor->rightChild = successor->rightChild;
      deleteNode(successor);
      printf("successfully deleted value %d...\n", value);
      return;
    } else {
      parentOfSuccessor->leftChild = successor->rightChild;
      deleteNode(successor);
      printf("successfully deleted value %d...\n", value);
      return;
    }
  /* case as in condition in comment below */
  } else { /* node->leftChild != NULL && node->rightChild == NULL */
    if(parent == NULL) {
      t.root = t.root->leftChild;
      deleteNode(node);
      printf("successfully deleted value %d (which was root!)...\n", value);
      return;
    }
    parent->leftChild = node->leftChild;
    deleteNode(node);
    printf("successfully deleted value %d...\n", value);
    return;
  }
}