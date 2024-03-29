#include "qgtkbutton.h"

QGtkButton::QGtkButton(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkButton::acquireObject()
{
    GtkWidget *button = gtk_button_new_with_label(NULL);
    g_signal_connect_swapped(button, "button-press-event", G_CALLBACK(QGtkButton::onPressed), this);
    g_signal_connect_swapped(button, "button-release-event", G_CALLBACK(QGtkButton::onReleased), this);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(QGtkButton::onClicked), this);
    return G_OBJECT(button);
}

void QGtkButton::sync()
{
    if (!gtkButton())
        return;

    gtk_button_set_label(gtkButton(), m_label.isEmpty() ? NULL : m_label.toUtf8().constData());
    QGtkWidget::sync();
}

void QGtkButton::onPressed(QGtkButton *that)
{
    emit that->pressed();
}
void QGtkButton::onReleased(QGtkButton *that)
{
    emit that->released();
}
void QGtkButton::onClicked(QGtkButton *that)
{
    emit that->clicked();
}

