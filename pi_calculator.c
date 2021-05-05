/* Program to compute Pi using Monte Carlo methods */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

main(int argc, char* argv)
{
   int iterations_number = 1000;
   double x_value,y_value;
   int counter = 0;
   double distance;
   double pi;

   srand(time(NULL));
   for (int i=0; i<iterations_number; i++) {
      x_value = rand() / ((double) RAND_MAX);
      y_value = rand() / ((double) RAND_MAX);
      distance = x_value*x_value+y_value*y_value;
      if (distance<=1) {
	counter++;
	}
      }
   pi=(double)counter/iterations_number*4;
   printf("iterations= %d ,pi= %g \n",iterations_number,pi);
}
