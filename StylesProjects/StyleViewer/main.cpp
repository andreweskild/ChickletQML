#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>
#include <QFontDatabase>
#include <QPalette>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQuickStyle::setStyle("../styleplugin");

    QFontDatabase::addApplicationFont("../fonts/IBMPlexSans-Text.ttf");

    app.setFont(QFont("IBM Plex Sans", 10));
    QQmlApplicationEngine engine;
    engine.addImportPath("../");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
