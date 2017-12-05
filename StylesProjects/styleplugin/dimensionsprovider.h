#ifndef DIMENSIONSPROVIDER_H
#define DIMENSIONSPROVIDER_H

#include <QObject>

class DimensionsProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal actionableHeight MEMBER m_ACTIONABLE_HEIGHT)
    Q_PROPERTY(qreal actionableMiniWidth MEMBER m_ACTIONABLE_MINI_WIDTH)
    Q_PROPERTY(qreal actionableNormalWidth MEMBER m_ACTIONABLE_NORMAL_WIDTH)
    Q_PROPERTY(qreal actionableWideWidth MEMBER m_ACTIONABLE_WIDE_WIDTH)
    Q_PROPERTY(qreal actionableRadius MEMBER m_ACTIONABLE_RADIUS)
    Q_PROPERTY(qreal progressBarWidth MEMBER m_PROGRESS_BAR_WIDTH)
    Q_PROPERTY(qreal borderWidth MEMBER m_BORDER_WIDTH)
public:
    explicit DimensionsProvider(QObject *parent = nullptr);

signals:

public slots:

private:
    qreal m_ACTIONABLE_HEIGHT = 24;
    qreal m_ACTIONABLE_MINI_WIDTH = 72;
    qreal m_ACTIONABLE_NORMAL_WIDTH = 96;
    qreal m_ACTIONABLE_WIDE_WIDTH = 120;
    qreal m_ACTIONABLE_RADIUS = 4;
    qreal m_PROGRESS_BAR_WIDTH = 8;
    int m_BORDER_WIDTH = 1;
};

#endif // DIMENSIONSPROVIDER_H
