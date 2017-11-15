/*
 * =====================================================================================
 *
 *       Filename:  tutorial.cxx
 *
 *    Description:  A CXX file for cmake tutorial
 *
 *        Version:  1.0
 *        Created:  11/15/2017 11:36:52 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Talha ahmed (), 
 *   Organization:  ICE Animations
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[])
{
    if ( argc < 2 )
    {
        fprintf(stdout, "%s Version %d.%d\n",
                argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number \n", argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
    double outputValue = mysqrt(inputValue);
#else
    double outputValue = sqrt(inputValue);
#endif

    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}
