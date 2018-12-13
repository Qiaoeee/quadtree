#ifndef NODEVALUE_H_INCLUDED
#define NODEVALUE_H_INCLUDED

extern double value( double x, double y, double time );
extern double nodeValue( Node *node, double time );
extern setFlag(Node *parent, double time);
extern void manageTree(Node *parent);
extern void adapt( Node *head );
#endif // NODEVALUE_H_INCLUDED
