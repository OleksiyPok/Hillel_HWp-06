#include "tcalcmodel.h"

TCalcModel::TCalcModel(double cVal, double fVal, double kVal, QObject *parent)
    : _cVal(cVal)
    , _fVal(fVal)
    , _kVal(kVal)
    , QObject{parent}
{}

void TCalcModel::setCVal(double cVal)
{
    this->_cVal = cVal;
};
void TCalcModel::setFVal(double fVal)
{
    this->_fVal = fVal;
};
void TCalcModel::setKVal(double kVal)
{
    this->_kVal = kVal;
};

double TCalcModel::getCVal()
{
    return this->_cVal;
};
double TCalcModel::getFVal()
{
    return this->_fVal;
};
double TCalcModel::getKVal()
{
    return this->_kVal;
};
