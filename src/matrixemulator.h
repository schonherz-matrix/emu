#ifndef MATRIXEMULATOR_H
#define MATRIXEMULATOR_H

#include <QWidget>
#include "muebreceiver.h"

namespace Ui {
class MatrixEmulator;
}

class MatrixEmulator : public QWidget {
  Q_OBJECT

 public:
  explicit MatrixEmulator(QWidget *parent = nullptr);
  ~MatrixEmulator();

 private:
  MuebReceiver m_receiver{this};
  Ui::MatrixEmulator *ui;
};

#endif  // MATRIXEMULATOR_H
