#include "gridwidget.h"

#include <QPainter>

GridWidget::GridWidget(QWidget *parent) : QWidget(parent) {
  m_currentFrame.fill(Qt::black);

  for (int row = 0; row < m_currentFrame.height() + 1; ++row) {
    m_gridLines << QLine(0, row, m_currentFrame.width(), row);
  }

  for (int col = 0; col < m_currentFrame.width() + 1; ++col) {
    m_gridLines << QLine(col, 0, col, m_currentFrame.height());
  }
}

QSize GridWidget::minimumSizeHint() const {
  return QSize(m_currentFrame.width() * m_scale + 1,
               m_currentFrame.height() * m_scale + 1);
}

QSize GridWidget::sizeHint() const {
  return QSize(m_currentFrame.width() * m_scale + 1,
               m_currentFrame.height() * m_scale + 1);
}

void GridWidget::updateFrame(QImage frame) {
  m_currentFrame = frame;
  update();
}

void GridWidget::paintEvent(QPaintEvent *event) {
  QPainter painter{this};

  painter.scale(m_scale, m_scale);
  painter.drawImage(0, 0, m_currentFrame);

  painter.setPen(QPen(Qt::black, 0));
  painter.drawLines(m_gridLines);
}
