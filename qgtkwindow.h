#ifndef QGTKWINDOW_H
#define QGTKWINDOW_H

#include "qgtkwidget.h"

class QGtkWindow : public QGtkWidget
{
    Q_OBJECT
public:
    QGtkWindow(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() override;
    void sync() override;
};

#endif
