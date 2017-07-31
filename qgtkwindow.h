#ifndef QGTKWINDOW_H
#define QGTKWINDOW_H

#include "qgtkwidget.h"

class QGtkWindow : public QGtkWidget
{
    Q_OBJECT

    QGTKOBJECT_PROPERTY(QString, title, title, setTitle, const QString &, titleChanged, m_title, QString())

public:
    QGtkWindow(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() override;
    GtkWindow *gtkWindow() const { return GTK_WINDOW(gObject()); }
    void sync() override;
};

#endif
