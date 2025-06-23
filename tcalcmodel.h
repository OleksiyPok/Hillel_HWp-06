#ifndef TCALCMODEL_H
#define TCALCMODEL_H

#include <QObject>

class TCalcModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(double cVal READ getCVal WRITE setCVal NOTIFY cValChanged)
    Q_PROPERTY(double fVal READ getFVal WRITE setFVal NOTIFY fValChanged)
    Q_PROPERTY(double kVal READ getKVal WRITE setKVal NOTIFY kValChanged)
    Q_PROPERTY(bool cValid READ getCValid WRITE setCValid NOTIFY cValidChanged)
    Q_PROPERTY(bool fValid READ getFValid WRITE setFValid NOTIFY fValidChanged)
    Q_PROPERTY(bool kValid READ getKValid WRITE setKValid NOTIFY kValidChanged)

public:
    explicit TCalcModel(double cVal, double fVal, double kVal, QObject *parent = nullptr);

    void setCVal(double cVal);
    void setFVal(double fVal);
    void setKVal(double kVal);

    void setCValid(bool val);
    void setFValid(bool val);
    void setKValid(bool val);

    double getCVal() const;
    double getFVal() const;
    double getKVal() const;

    bool getCValid() const;
    bool getFValid() const;
    bool getKValid() const;

private:
    double _cVal;
    double _fVal;
    double _kVal;
    bool cValid;
    bool fValid;
    bool kValid;

signals:
    void cValChanged(double cVal);
    void fValChanged(double fVal);
    void kValChanged(double kVal);

    void cValidChanged(bool val);
    void fValidChanged(bool val);
    void kValidChanged(bool val);
};

#endif // TCALCMODEL_H
