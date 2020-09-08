#include "schonherzitem.hpp"

#include <QPainter>

#include "schcoords.h"

SchonherzItem::SchonherzItem(QQuickItem *parent) : QQuickPaintedItem(parent) {
  setSize(m_background.size());
  m_currentFrame.fill(Qt::black);
}

void SchonherzItem::paint(QPainter *painter) {
  using namespace libmueb::defaults;

  painter->drawImage(boundingRect(), m_background);

  int windowIdx = 0;
  for (auto point : schCoords) {
    auto row = (windowIdx / windowPerRow) * verticalPixelUnit;
    auto col = (windowIdx % windowPerRow) * horizontalPixelUnit;

    for (int y = 0; y < verticalPixelUnit; ++y) {
      for (int x = 0; x < horizontalPixelUnit; ++x) {
        painter->fillRect(point.x() + x * 8, point.y() + y * 8, 8, 8,
                          m_currentFrame.pixelColor(col + x, row + y));
      }
    }

    windowIdx++;
  }
}

QImage SchonherzItem::currentFrame() const { return m_currentFrame; }

void SchonherzItem::setCurrentFrame(const QImage &currentFrame) {
  m_currentFrame = currentFrame;
  update();
}
