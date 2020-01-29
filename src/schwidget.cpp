#include "schwidget.h"

#include <QPainter>
#include "schcoords.h"

SchWidget::SchWidget(QWidget *parent) : QWidget(parent) {
  m_currentFrame.fill(Qt::black);
}

QSize SchWidget::minimumSizeHint() const { return m_schImage.size(); }

QSize SchWidget::sizeHint() const { return m_schImage.size(); }

void SchWidget::paintEvent(QPaintEvent * /*event*/) {
  using namespace libmueb::defaults;

  QPainter painter{this};
  painter.drawImage(0, 0, m_schImage);

  int windowIdx = 0;
  for (auto point : schCoords) {
    auto row = (windowIdx / windowPerRow) * verticalPixelUnit;
    auto col = (windowIdx % windowPerRow) * horizontalPixelUnit;

    for (int y = 0; y < verticalPixelUnit; ++y) {
      for (int x = 0; x < horizontalPixelUnit; ++x) {
        painter.fillRect(point.x() + x * 8, point.y() + y * 8, 8, 8,
                         m_currentFrame.pixelColor(col + x, row + y));
      }
    }

    windowIdx++;
  }
}

void SchWidget::updateFrame(QImage frame) {
  m_currentFrame = frame;
  update();
}
