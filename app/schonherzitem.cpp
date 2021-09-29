#include "schonherzitem.hpp"

#include <QPainter>

#include "schcoords.h"

SchonherzItem::SchonherzItem(QQuickItem *parent) : QQuickPaintedItem(parent) {
  m_currentFrame = libmueb::MuebReceiver::Instance().frame();
  setSize(m_background.size());
}

void SchonherzItem::paint(QPainter *painter) {
  libmueb::MuebReceiver &receiver = libmueb::MuebReceiver::Instance();
  painter->drawImage(boundingRect(), m_background);

  int windowIdx = 0;
  for (auto point : schCoords) {
    auto row = (windowIdx / 16) * receiver.vertical_pixel_unit();
    auto col = (windowIdx % 16) * receiver.horizontal_pixel_unit();

    for (int y = 0; y < receiver.vertical_pixel_unit(); ++y) {
      for (int x = 0; x < receiver.horizontal_pixel_unit(); ++x) {
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
