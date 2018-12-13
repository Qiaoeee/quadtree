#ifndef BUILDTREE_H_INCLUDED
#define BUILDTREE_H_INCLUDED

#include "treeStructure.h"
extern Node *makeNode( double x, double y, int level );
extern void makeChildren( Node *parent );
extern void growTree( Node *parent );
extern void destroyTree( Node *parent );
extern void removeChildren( Node *parent );
#endif // BUILDTREE_H_INCLUDED

