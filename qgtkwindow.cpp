#include "qgtkwindow.h"

QGtkWindow::QGtkWindow(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkWindow::acquireObject()
{
    GtkWidget *w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(w), 100, 100);
    return G_OBJECT(w);
}

void QGtkWindow::sync()
{
    if (!gtkWindow())
        return;

    gtk_window_set_title(gtkWindow(), m_title.isEmpty() ? NULL : m_title.toUtf8().constData());
    QGtkWidget::sync();
}

QString QGtkWindow::title() const
{
    return m_title;
}

void QGtkWindow::setTitle(const QString &t)
{
    if (m_title == t)
        return;

    m_title = t;
    emit titleChanged();
    sync();
}

