#ifndef SCHWIDGET_H
#define SCHWIDGET_H

#include <QWidget>
#include "libmueb_global.h"

class SchWidget : public QWidget {
  Q_OBJECT

 public:
  explicit SchWidget(QWidget *parent = nullptr);

  // QWidget interface
  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

 public slots:
  void updateFrame(QImage frame);

  // QWidget interface
 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  QImage m_currentFrame{libmueb::defaults::frame};
  QImage m_schImage{":/sch.jpg"};
};

#endif  // SCHWIDGET_H
