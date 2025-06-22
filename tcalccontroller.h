#ifndef TCALCCONTROLLER_H
#define TCALCCONTROLLER_H

#include <QObject>
#include "tcalcmodel.h"

class TCalcController : public QObject {
  Q_OBJECT

  public:
  explicit TCalcController(TCalcModel *model, QObject *parent = nullptr);
  Q_INVOKABLE void setCVal(QString cVal);
  Q_INVOKABLE void setKVal(QString kVal);
  Q_INVOKABLE void setFVal(QString fVal);

  double cCalc();
  double kCalc();
  double fCalc();

  private:
  TCalcModel *model;

  signals:
};

#endif // TCALCCONTROLLER_H
