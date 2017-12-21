#ifndef DIMENSIONSPROVIDER_H
#define DIMENSIONSPROVIDER_H

#include <QObject>

class DimensionsProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal actionableHeight MEMBER m_ACTIONABLE_HEIGHT NOTIFY actionableHeightChanged)
    Q_PROPERTY(qreal actionableMiniWidth MEMBER m_ACTIONABLE_MINI_WIDTH NOTIFY actionableMiniWidthChanged)
    Q_PROPERTY(qreal actionableNormalWidth MEMBER m_ACTIONABLE_NORMAL_WIDTH NOTIFY actionableNormalWidthChanged)
    Q_PROPERTY(qreal actionableWideWidth MEMBER m_ACTIONABLE_WIDE_WIDTH NOTIFY actionableWideWidthChanged)
    Q_PROPERTY(qreal actionableRadius MEMBER m_ACTIONABLE_RADIUS NOTIFY actionableRadiusChanged)
    Q_PROPERTY(qreal checkableHeightWidth MEMBER m_CHECKABLE_HEIGHTWIDTH NOTIFY checkableHeightWidthChanged)
    Q_PROPERTY(qreal sliderHandleWidth MEMBER m_SLIDER_HANDLE_WIDTH NOTIFY sliderHandleWidthChanged)
    Q_PROPERTY(qreal progressBarWidth MEMBER m_PROGRESS_BAR_WIDTH NOTIFY progressBarWidthChanged)
    Q_PROPERTY(qreal progressBarIndeterminateWidth MEMBER m_PROGRESS_IND_WIDTH NOTIFY progressBarIndeterminateWidthChanged)
    Q_PROPERTY(qreal borderWidth MEMBER m_BORDER_WIDTH NOTIFY borderWidthChanged)
public:
    explicit DimensionsProvider(QObject *parent = nullptr);

signals:
    void actionableHeightChanged();
    void actionableMiniWidthChanged();
    void actionableNormalWidthChanged();
    void actionableWideWidthChanged();
    void actionableRadiusChanged();
    void checkableHeightWidthChanged();
    void sliderHandleWidthChanged();
    void progressBarWidthChanged();
    void progressBarIndeterminateWidthChanged();
    void borderWidthChanged();

public slots:

private:
    qreal m_ACTIONABLE_HEIGHT = 24;
    qreal m_ACTIONABLE_MINI_WIDTH = 72;
    qreal m_ACTIONABLE_NORMAL_WIDTH = 96;
    qreal m_ACTIONABLE_WIDE_WIDTH = 120;
    qreal m_ACTIONABLE_RADIUS = 4;
    qreal m_PROGRESS_IND_WIDTH = 24;
    qreal m_CHECKABLE_HEIGHTWIDTH = 16;
    qreal m_SLIDER_HANDLE_WIDTH = 32;
    qreal m_PROGRESS_BAR_WIDTH = 6;
    int m_BORDER_WIDTH = 1;
};

#endif // DIMENSIONSPROVIDER_H
