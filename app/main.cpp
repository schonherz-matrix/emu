#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "muebreceiver.h"
#include "schonherzitem.hpp"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);

  // Remove in Qt6
  qmlRegisterType<SchonherzItem>("hu.bme.kszk.SchonherzItem", 1, 0,
                                 "SchonherzItem");
  //

  decltype(auto) receiver{MuebReceiver::getInstance()};
  engine.rootContext()->setContextProperty("MuebReceiver", &receiver);
  engine.load(url);

  return app.exec();
}
