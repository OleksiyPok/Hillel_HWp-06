#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "tcalccontroller.h"
#include "tcalcmodel.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/icons/favicon.ico"));

    TCalcModel *model = new TCalcModel(0, 0, 0);
    TCalcController *controller = new TCalcController(model);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("model", model);
    engine.rootContext()->setContextProperty("controller", controller);
    engine.loadFromModule("TCalc", "Main");

    return app.exec();
}
