#include <math.h>
#define Min(a,b) ((a) < (b) ? (a) : (b))
double angleClock(int hour, int minutes) {
    float mangle = minutes*6.0; 
    float hangle = (hour % 12) * 30.0 + minutes * 0.5;
    float diff = fabs(hangle - mangle); 
    return Min(diff, 360.0 - diff);
}
