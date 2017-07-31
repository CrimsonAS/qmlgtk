#include "qgtkhbox.h"

QGtkHBox::QGtkHBox(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkHBox::acquireObject() const
{
    return G_OBJECT(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0));
}

void QGtkHBox::sync()
{
    if (!gtkBox())
        return;

    QGtkWidget::sync();
}

