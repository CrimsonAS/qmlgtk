#ifndef QGTKSPINNER_H
#define QGTKSPINNER_H

#include "qgtkwidget.h"

class QGtkSpinner : public QGtkWidget
{
    Q_OBJECT

    QGTKOBJECT_PROPERTY(bool, active, isActive, setActive, bool, activeChanged, m_active, false)

public:
    QGtkSpinner(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() override;
    GtkSpinner *gtkSpinner() const { return GTK_SPINNER(gObject()); }
    void sync() override;
};

#endif



