#include "tcalcmodel.h"

TCalcModel::TCalcModel(double cVal, double fVal, double kVal, QObject *parent)
    : _cVal(cVal)
    , _fVal(fVal)
    , _kVal(kVal)
    , QObject{parent}
{}

// void TCalcModel::setCelsiusValue(double celsiusValue)
// {
//     this->_celsiusValue = celsiusValue;
// };

void TCalcModel::setCVal(double cVal)
{
    if (this->_cVal != cVal) {
        this->_cVal = cVal;
        emit this->cValChanged(this->_cVal);
    };
}
void TCalcModel::setFVal(double fVal)
{
    if (this->_fVal != fVal) {
        this->_fVal = fVal;
        emit this->fValChanged(this->_fVal);
    }
};
void TCalcModel::setKVal(double kVal)
{
    if (this->_kVal != kVal) {
        this->_kVal = kVal;
        emit this->kValChanged(this->_kVal);
    }
};

// double TCalcModel::getCelsiusValue()
// {
//     return this->_celsiusValue;
// };

double TCalcModel::getCVal() const
{
    return this->_cVal;
};
double TCalcModel::getFVal() const
{
    return this->_fVal;
};
double TCalcModel::getKVal() const
{
    return this->_kVal;
};
