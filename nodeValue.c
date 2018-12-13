#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "buildTree.h"
#include "treeStructure.h"

int add = 0;
int rem = 0;
int maxLevel = 6;
// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}


int setFlag(Node *parent, double time) {
  if( parent->child[0] == NULL )
  {
  	if(nodeValue(parent, time) < -0.5) 
  	{
  	  parent->flat = -1;
  	  return -1;
	}
	else if(nodeValue(parent, time) > 0.5)
	{
	  parent->flat = 1;
	  return 1;
	}
	else
	{
	  parent->flat = 0;
	  return 0;
	}
  }
  else
  {
  	parent->flat = 0;
  	int i;
  	for(i = 0; i < 4; i++)
  	  setFlag( parent->child[i], time);
  	return 0;
  }
}

void manageTree(Node *parent)
{
  if( parent->flat == 1 &&  ((parent->level) < maxLevel))
  {
  	makeChildren(parent);
  	add += 4;
  }
  else if(parent->child[0] != NULL)
  {
  	int i, counter = 0;
  	for(i = 0; i < 4; i++)
  	{
  	  if(parent->child[i]->flat == -1 )	
  	    counter += 1;
    }
    if(counter == 4)
    {
      removeChildren(parent);
      rem += 4;
	}  
    // its children's value are not all -1
    else
      {
      	for(i = 0; i < 4; i++)
      	{
      	  manageTree(parent->child[i]);
		}
	  }
  }  
}


void adapt( Node *head )
{
  double time = 0.0;
  int i;
  while(add != 0 || rem != 0)
  {
  	add = 0;
  	rem = 0;
    setFlag(head, time);
    manageTree(head);
    printf("There are %d nodes added\n", add);
    printf("There are %d nodes removed\n", rem);
  }
}
