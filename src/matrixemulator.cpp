#include "matrixemulator.h"
#include "ui_matrixemulator.h"

MatrixEmulator::MatrixEmulator(QWidget *parent)
    : QWidget(parent), ui(new Ui::MatrixEmulator) {
  ui->setupUi(this);
  setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint |
                 Qt::MSWindowsFixedSizeDialogHint);

  setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint |
                 Qt::MSWindowsFixedSizeDialogHint);

  connect(&m_receiver, &MuebReceiver::frameChanged, ui->schWidget,
          &SchWidget::updateFrame);
  connect(&m_receiver, &MuebReceiver::frameChanged, ui->gridWidget,
          &GridWidget::updateFrame);
  connect(ui->tabWidget, &QTabWidget::currentChanged, this, [&]() {
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
      ui->tabWidget->widget(i)->setSizePolicy(QSizePolicy::Ignored,
                                              QSizePolicy::Ignored);
    }

    auto widget = ui->tabWidget->currentWidget();

    widget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    widget->resize(widget->minimumSizeHint());
    widget->adjustSize();
    ui->tabWidget->resize(ui->tabWidget->minimumSizeHint());
    ui->tabWidget->adjustSize();

    adjustSize();
  });
}

MatrixEmulator::~MatrixEmulator() { delete ui; }
