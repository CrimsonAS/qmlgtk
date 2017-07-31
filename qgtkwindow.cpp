#include "qgtkwindow.h"

QGtkWindow::QGtkWindow(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkWindow::acquireObject()
{
    GtkWidget *w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(w), "Hello, Gtk!");
    gtk_window_set_default_size(GTK_WINDOW(w), 100, 100);
    return G_OBJECT(w);
}

void QGtkWindow::sync()
{
    QGtkWidget::sync();
}

