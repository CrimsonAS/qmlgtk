#include "qgtkvbox.h"

QGtkVBox::QGtkVBox(QGtkObject *parent)
    : QGtkBox(parent)
{
}

GObject *QGtkVBox::acquireObject()
{
    return G_OBJECT(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
}

void QGtkVBox::sync()
{
    if (!gtkBox())
        return;

    QGtkWidget::sync();
}

QGtkBoxPackAttached *QGtkVBox::qmlAttachedProperties(QObject *object)
{
    return new QGtkBoxPackAttached(object);
}

