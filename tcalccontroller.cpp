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

    this->model->setCValid(ok);

    if (ok) {
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

    this->model->setFValid(ok);

    if (ok) {
        this->model->setCVal(_fVal);

        double celsius = Util::roundTo(((_fVal - 32) * 5 / 9), 2);
        model->setCVal(celsius);

        double kelvin = Util::roundTo((((_fVal - 32) * 5 / 9) + 273.15), 2);
        model->setKVal(kelvin);

        return true;
    }
    return false;
};

bool TCalcController::kValChanged(QString kVal)
{
    bool ok = false;
    double _kVal = kVal.toDouble(&ok);

    this->model->setKValid(ok);

    if (ok) {
        this->model->setCVal(_kVal);

        double celsius = Util::roundTo((_kVal - 273.15), 2);
        model->setCVal(celsius);

        double fahrenheit = Util::roundTo(((_kVal - 273.15) * 9 / 5 + 32), 2);
        model->setFVal(fahrenheit);

        return true;
    }
    return false;
};
