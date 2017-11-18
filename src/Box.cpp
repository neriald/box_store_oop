#include "Box.h"
#include <iostream>
#include <math.h>

using namespace std;

int Box::counter=0;

double BrickBox::getVolume() const
{
    return len*wid*hei;
}

double TubeBox::getVolume() const
{
    return M_PI*pow(r,2)*h;
}

double BubbleBox::getVolume() const
{
    return 4/3.0 * M_PI * pow(r,3);
}

