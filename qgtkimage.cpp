#include "qgtkimage.h"

QGtkImage::QGtkImage(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkImage::acquireObject()
{
    GtkImage *image = GTK_IMAGE(gtk_image_new());
    return G_OBJECT(image);
}

void QGtkImage::sync()
{
    if (!gtkImage())
        return;

    if (!m_fileName.isNull())
        gtk_image_set_from_file(gtkImage(), m_fileName.isEmpty() ? NULL : m_fileName.toUtf8().constData());
    else
        gtk_image_clear(gtkImage());

    QGtkWidget::sync();
}

