using namespace std;
/******************************************************************************
 Header file
 Class:        LinearParsimony
 Date created: 15/09/2008
 Written by:   Brian Pinto

 Applies parsimony pressure such that the size of the GP trees has a linear
 growth. All methods are pure virtual, subclasses must implement all methods.
******************************************************************************/
#include <float.h>
#include <math.h>
#include "LinearParsimony.h"

//Constructor
LinearParsimony::LinearParsimony( double kFactor): Parsimony(kFactor)
{
   initmean = -1.0;
}

LinearParsimony::~LinearParsimony()
{
}

double LinearParsimony::desiredFunc(int generation, Population *pop)
{
   if(initmean < 0)
   {
      initmean = pop->getAvgSize();
   }
   return (double) ((double)generation + initmean);
}
