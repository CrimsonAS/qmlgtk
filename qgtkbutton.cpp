#include "qgtkbutton.h"

QGtkButton::QGtkButton(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkButton::acquireObject() const
{
    return G_OBJECT(gtk_button_new_with_label("hi"));
}

void QGtkButton::sync()
{
    qDebug() << "sync " << gtkButton() << m_label;
    if (!gtkButton())
        return;

    gtk_button_set_label(gtkButton(), m_label.isEmpty() ? NULL : m_label.toUtf8().constData());
    QGtkWidget::sync();
}

QString QGtkButton::label() const
{
    return m_label;
}

void QGtkButton::setLabel(const QString &l)
{
    m_label = l;
    emit labelChanged();
    sync();
}

