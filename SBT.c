#include "tree.h"

static void treeAction();

int main(int argc, char *argv[]) {
  treeAction();
  return 0;
}

static void treeAction() {
  treeInit();
  strToTree("20 10 30 5 15 3 8 12 17");
  addValueToTree(7);
  addValueToTree(9);
  printTreeAscending();
  deleteTree();
  return;
}