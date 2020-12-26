#include "As3_Math.h"

int as3_round(double x) {
    if(x >= 0)
        return round(x);
    else 
        return round(x + 0.1) - 0.1;
}