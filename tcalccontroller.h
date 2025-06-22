#ifndef TCALCCONTROLLER_H
#define TCALCCONTROLLER_H

#include <QObject>
#include "tcalcmodel.h"

class TCalcController : public QObject {
  Q_OBJECT

  public:
  explicit TCalcController(TCalcModel *model, QObject *parent = nullptr);

  Q_INVOKABLE bool cValChanged(QString cVal);
  Q_INVOKABLE bool kValChanged(QString kVal);
  Q_INVOKABLE bool fValChanged(QString fVal);

  private:
  TCalcModel *model;

  double roundTo(double value, int digits);

  signals:
};

#endif // TCALCCONTROLLER_H
