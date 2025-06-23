#include "tcalccontroller.h"
#include "util.h"
#include <qdebug.h>

TCalcController::TCalcController(TCalcModel *model, QObject *parent)
    : model(model)
    , QObject{parent}
{}

bool TCalcController::cValChanged(QString cVal)
{
    bool ok = false;
    double _cVal = cVal.toDouble(&ok);
    bool isValid = ok && _cVal >= -273.15;

    this->model->setCValid(isValid);

    if (isValid) {
        this->model->setCVal(_cVal);

        double kelvin = Util::roundTo((_cVal + 273.15), 2);
        model->setKVal(kelvin);

        double fahrenheit = Util::roundTo((_cVal * 9 / 5 + 32), 2);
        model->setFVal(fahrenheit);

        return true;
    }

    return false;
}

bool TCalcController::fValChanged(QString fVal)
{
    bool ok = false;
    double _fVal = fVal.toDouble(&ok);
    bool isValid = ok && _fVal >= -459.67;

    this->model->setFValid(isValid);

    if (isValid) {
        double celsius = Util::roundTo(((_fVal - 32) * 5 / 9), 2);
        model->setCVal(celsius);

        double kelvin = Util::roundTo(celsius + 273.15, 2);
        model->setKVal(kelvin);

        model->setFVal(_fVal);

        return true;
    }

    return false;
}

bool TCalcController::kValChanged(QString kVal)
{
    bool ok = false;
    double _kVal = kVal.toDouble(&ok);
    bool isValid = ok && _kVal >= 0.0;

    this->model->setKValid(isValid);

    if (isValid) {
        double celsius = Util::roundTo((_kVal - 273.15), 2);
        model->setCVal(celsius);

        double fahrenheit = Util::roundTo(celsius * 9 / 5 + 32, 2);
        model->setFVal(fahrenheit);

        model->setKVal(_kVal);

        return true;
    }

    return false;
}
