#include "tcalccontroller.h"

TCalcController::TCalcController(TCalcModel *model, QObject *parent)
    : model(model)
    , QObject{parent}
{}

double TCalcController::cCalc()
{
    return this->model->getCVal();
}

double TCalcController::kCalc()
{
    return this->model->getKVal();
}

double TCalcController::fCalc()
{
    return this->model->getFVal();
}

void TCalcController::setCVal(QString cVal)
{
    bool ok = false;
    double _cVal = cVal.toDouble(&ok);

    if (ok) {
        this->model->setCVal(_cVal);
    }
};

void TCalcController::setKVal(QString kVal)
{
    bool ok = false;
    double _kVal = kVal.toDouble(&ok);

    if (ok) {
        this->model->setCVal(_kVal);
    }
};

void TCalcController::setFVal(QString fVal)
{
    bool ok = false;
    double _fVal = fVal.toDouble(&ok);

    if (ok) {
        this->model->setCVal(_fVal);
    }
};
