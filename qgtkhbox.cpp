#include "qgtkhbox.h"

QGtkHBox::QGtkHBox(QGtkObject *parent)
    : QGtkBox(parent)
{
}

GObject *QGtkHBox::acquireObject()
{
    return G_OBJECT(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0));
}

void QGtkHBox::sync()
{
    if (!gtkBox())
        return;

    QGtkWidget::sync();
}

QGtkBoxPackAttached *QGtkHBox::qmlAttachedProperties(QObject *object)
{
    return new QGtkBoxPackAttached(object);
}

