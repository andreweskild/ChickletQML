#ifndef BASICANIMATOR_H
#define BASICANIMATOR_H

#include <QObject>
#include <QVariantAnimation>

class BasicAnimator : public QVariantAnimation
{
    Q_OBJECT
public:
    explicit BasicAnimator(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BASICANIMATOR_H
