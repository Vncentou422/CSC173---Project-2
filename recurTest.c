#include <stdio.h>
#include <stdlib.h>
#include "ParseTree.h"

int main(int argc, char **argv) {
  Tree* pTree = newTree(argv);
  pTree = Pls();
  printPT();
}
