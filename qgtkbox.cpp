#include "qgtkbox.h"

QGtkBox::QGtkBox(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkBox::acquireObject() const
{
    return G_OBJECT(gtk_box_new(GTK_ORIENTATION_VERTICAL, 1));
}

void QGtkBox::sync()
{
    if (!gtkBox())
        return;

    QGtkWidget::sync();
}

