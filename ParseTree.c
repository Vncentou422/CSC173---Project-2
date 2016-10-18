#define FAILED NULL
typedef struct NODE *TREE;

struct NODE {
  char label;
  TREE leftmostChild, rightSibling;
};

TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode2(char x, TREE t1, TREE t2);
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3);
TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4);

TREE parseTree; /* holds the result of the parse */
char *nextTerminal; /* current position in input string */
void main()
{
  nextTerminal = "()()"; /* in practice, a string
                            of terminals would be read from input */
}
TREE makeNode0(char x)
{
  TREE root;
  root = (TREE) malloc(sizeof(struct NODE));
  root->label = x;
  root->leftmostChild = NULL;
  root->rightSibling = NULL;
  return root;
}
TREE makeNode1(char x, TREE t)
{
  TREE root;
  root = makeNode0(x);
  root->leftmostChild = t;
  return root;
}
TREE makeNode2(char x, TREE t1, TREE t2)
{
  TREE root;
  root = makeNode1(x, t1);
  t1->rightSibling = t2;
  return root;
}
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3)
{
  TREE root;
  root = makeNode1(x, t1);
  t1->rightSibling = t2;
  t2->rightSibling = t3;
  return root;
}
TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4)
{
  TREE root;
  root = makeNode1(x, t1);
  t1->rightSibling = t2;
  t2->rightSibling = t3;
  t3->rightSibling = t4;
  return root;
}
