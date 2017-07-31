#include "qgtkvbox.h"

QGtkVBox::QGtkVBox(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkVBox::acquireObject() const
{
    return G_OBJECT(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
}

void QGtkVBox::sync()
{
    if (!gtkBox())
        return;

    QGtkWidget::sync();
}

