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

    if (ok) {
        this->model->setCVal(_cVal);

        double kelvin = Util::roundTo((_cVal + 273.15), 2);
        model->setFVal(kelvin);
        qDebug() << "kelvin: " << kelvin;

        double fahrenheit = Util::roundTo((_cVal * 9 / 5 + 32), 2);
        model->setFVal(fahrenheit);
        qDebug() << "fahrenheit: " << fahrenheit;

        return true;
    }

    return false;
};

bool TCalcController::fValChanged(QString fVal)
{
    bool ok = false;
    double _fVal = fVal.toDouble(&ok);

    if (ok) {
        this->model->setCVal(_fVal);

        double celsius = Util::roundTo(((_fVal - 32) * 5 / 9), 2);
        model->setFVal(celsius);
        qDebug() << "celsius: " << celsius;

        double kelvin = Util::roundTo((((_fVal - 32) * 5 / 9) + 273.15), 2);
        model->setFVal(kelvin);
        qDebug() << "kelvin: " << kelvin;

        return true;
    }
    return false;
};

bool TCalcController::kValChanged(QString kVal)
{
    bool ok = false;
    double _kVal = kVal.toDouble(&ok);

    if (ok) {
        this->model->setCVal(_kVal);

        double celsius = Util::roundTo((_kVal - 273.15), 2);
        model->setFVal(celsius);
        qDebug() << "celsius: " << celsius;

        double fahrenheit = Util::roundTo(((_kVal - 273.15) * 9 / 5 + 32), 2);
        model->setFVal(fahrenheit);
        qDebug() << "fahrenheit: " << fahrenheit;

        return true;
    }
    return false;
};

//     // double fahrenheit = (_cVal * 9 / 5 + 32);
//     // double kelvin = (_cVal + 273.15);

//     // double celsius = ((_fVal - 32) * 5/9);
//     // double kelvin = (((_fVal - 32) * 5/9) + 273.15);

//     // double celsius = (_kVal - 273.15);
//     // double fahrenheit = ((_kVal - 273.15) * 9/5 + 32);
