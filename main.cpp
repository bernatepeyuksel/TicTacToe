#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Board.h"
#include "Computer.h"
#include "Human.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto context = engine.rootContext();

    auto board = std::make_unique<Board>();
    context->setContextProperty("board", board.get());

    auto human = std::make_unique<Human>();
    context->setContextProperty("human", human.get());

    auto computer = std::make_unique<Computer>();
    context->setContextProperty("computer", computer.get());

    QObject::connect(
        human.get(),
        &Human::humanPlayed,
        computer.get(),
        &Computer::play
    );

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
