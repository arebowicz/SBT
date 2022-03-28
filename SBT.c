#include "tree.h"

/*
static void treeAction();
*/
static void treeTest();

int main(int argc, char *argv[]) {
  /*
  treeAction();
  */
  treeTest("20", 20);
  treeTest("20", 30);
  treeTest("20 10", 20);
  treeTest("20 30", 20);
  treeTest("20 10 30", 20);
  treeTest("20 30 21", 20);
  treeTest("20 30 21 22", 20);
  treeTest("20 30 21 22 23", 20);
  treeTest("20 30 40", 20);
  treeTest("20 10 30", 30);
  return 0;
}

/*
static void treeAction() {
  treeInit();
  strToTree("20 10 30 5 15 3 8 12 17");
  addValueToTree(7);
  addValueToTree(9);
  addValueToTree(11);
  addValueToTree(14);
  addValueToTree(13);
  printTreeAscending();
  deleteTree();
  return;
}
*/

static void treeTest(char *str, int value) {
  treeInit();
  strToTree(str);
  printTreeAscending();
  printf("\n");
  deleteValue(value);
  printTreeAscending();
  printf("\n\n");
  deleteTree();
  return;
}