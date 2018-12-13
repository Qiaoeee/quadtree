
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
// make a node at given location (x,y) and level
// and let it has no child
// struct qnode *makeNode (double x, double y, int level)


Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  // the height of each child
  double hChild = pow(2.0,-(level+1));

  // the point representing the square is at the left bottom.
  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

void growTree( Node *parent ) {
  if( parent->child[0] == NULL )
    makeChildren( parent );
  else
  {
      growTree( parent->child[0]);
      growTree( parent->child[1]);
      growTree( parent->child[2]);
      growTree( parent->child[3]);
  }
}

void destroyTree( Node *parent ) {
  if( parent->child[0] == NULL )
  {
      free(parent);
      parent = NULL;
  }
  else
  {
      destroyTree(parent->child[0]);
      destroyTree(parent->child[1]);
      destroyTree(parent->child[2]);
      destroyTree(parent->child[3]);
  }

}

void removeChildren( Node *parent ){
  int i = 0;
  for(i = 0; i < 4; i++)
  {
      free(parent->child[i]);
      parent->child[i] = NULL;
  }
  parent = NULL;
}

void addChildren( Node *parent )
{
  
}
