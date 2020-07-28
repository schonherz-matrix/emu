#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QWidget>

#include "libmuebconfig.h"

class GridWidget : public QWidget {
  Q_OBJECT

 public:
  explicit GridWidget(QWidget *parent = nullptr);

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
  QVector<QLine> m_gridLines;
  int m_scale{20};
};

#endif  // GRIDWIDGET_H
