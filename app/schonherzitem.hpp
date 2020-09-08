#pragma once

#include <QImage>
#include <QQuickPaintedItem>

#include "libmuebconfig.h"

class SchonherzItem : public QQuickPaintedItem {
  Q_OBJECT
  QML_ELEMENT
  QML_ADDED_IN_MINOR_VERSION(0)
  Q_PROPERTY(QImage currentFrame READ currentFrame WRITE setCurrentFrame)

 public:
  explicit SchonherzItem(QQuickItem *parent = nullptr);

  // QQuickPaintedItem interface
  void paint(QPainter *painter) override;

  QImage currentFrame() const;
  void setCurrentFrame(const QImage &currentFrame);

 private:
  QImage m_currentFrame{libmueb::defaults::frame};
  QImage m_background{":/images/sch.jpg"};
};
