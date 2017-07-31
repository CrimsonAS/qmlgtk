#ifndef QGTKAPPLICATION_H
#define QGTKAPPLICATION_H

#include "qgtkobject.h"

class QGtkApplication : public QGtkObject
{
    Q_OBJECT

public:
    QGtkApplication(QObject *parent = 0);

    static QGtkApplication *instance;
    static GtkApplication *appInstance;

Q_SIGNALS:
    void activated();
    void startup();

protected:
    GObject *acquireObject() override;
    void sync();
};

#endif // QGTKAPPLICATION_H
