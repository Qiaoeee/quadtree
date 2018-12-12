#include "stdio.h"
#include "stdlib.h"
#include "buildTree.h"
#include "writeTree.h"
#include "treeStructure.h"
// main


int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  makeChildren( head );
  makeChildren( head->child[1] );
  makeChildren( head->child[3] );
  makeChildren( head->child[2] );
  makeChildren( head->child[3]->child[3]);
  makeChildren( head->child[3]->child[3]->child[2]);
  makeChildren( head->child[2]->child[1]);
  makeChildren( head->child[2]->child[1]->child[0]);
  makeChildren( head->child[2]->child[1]->child[0]->child[3]);

  // grow tree
  growTree( head );
  growTree( head );
  // print the tree for Gnuplot
  writeTree( head );

  return 0;
}
