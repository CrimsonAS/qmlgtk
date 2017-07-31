#include "qgtkspinner.h"

QGtkSpinner::QGtkSpinner(QGtkObject *parent)
    : QGtkWidget(parent)
    , m_active(false)
{
}

GObject *QGtkSpinner::acquireObject()
{
    return G_OBJECT(gtk_spinner_new());
}

void QGtkSpinner::sync()
{
    if (!gtkSpinner())
        return;

    if (m_active) {
        gtk_spinner_start(gtkSpinner());
    } else {
        gtk_spinner_stop(gtkSpinner());
    }
    QGtkWidget::sync();
}

