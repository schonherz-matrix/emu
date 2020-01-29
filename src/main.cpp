#include <QApplication>
#include "matrixemulator.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MatrixEmulator w;
  w.show();

  return a.exec();
}
