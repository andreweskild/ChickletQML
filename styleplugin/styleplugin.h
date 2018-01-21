#ifndef STYLEPLUGIN_H
#define STYLEPLUGIN_H

#include <QObject>

class StylePlugin : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(StylePlugin)

public:
    explicit StylePlugin(QObject *parent = nullptr);
    ~StylePlugin();

};

#endif // STYLEPLUGIN_H
