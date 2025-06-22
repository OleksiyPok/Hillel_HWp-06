#include "util.h"
#include <QtMath>

double Util::roundTo(double value, int decimals)
{
    double factor = qPow(10.0, decimals);
    return qRound64(value * factor) / factor;
}
