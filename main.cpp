#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty>
#include <QObject>
#include <QQuickItem>
#include <QDebug>
#include <vector>

#include "counter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/ShiftCounter/Main.qml"_qs);

    qmlRegisterType<Counter>("appShiftCounter", 1, 0, "Counter");

    engine.load(url);


    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
