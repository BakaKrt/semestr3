#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(0, "");
    cout << "";
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qt/qml/qt_turing_machine/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;



    return app.exec();
}
