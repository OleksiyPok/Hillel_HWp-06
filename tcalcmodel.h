#ifndef TCALCMODEL_H
#define TCALCMODEL_H

#include <QObject>

class TCalcModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(double cVal READ getCVal WRITE setCVal NOTIFY cValChanged)
    Q_PROPERTY(double fVal READ getFVal WRITE setFVal NOTIFY fValChanged)
    Q_PROPERTY(double kVal READ getKVal WRITE setKVal NOTIFY kValChanged)

public:
    explicit TCalcModel(double cVal, double fVal, double kVal, QObject *parent = nullptr);
    // void setCelsiusValue(double celsiusValue);
    void setCVal(double cVal);
    void setFVal(double fVal);
    void setKVal(double kVal);
    // double getCelsiusValue();
    double getCVal() const;
    double getFVal() const;
    double getKVal() const;

private:
    // double _celsiusValue;
    double _cVal;
    double _fVal;
    double _kVal;

signals:
    void cValChanged(double cVal);
    void fValChanged(double fVal);
    void kValChanged(double kVal);
};

#endif // TCALCMODEL_H
