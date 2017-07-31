#include "qgtklabel.h"

QGtkLabel::QGtkLabel(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkLabel::acquireObject()
{
    GtkWidget *label = gtk_label_new(NULL);
    return G_OBJECT(label);
}

void QGtkLabel::sync()
{
    if (!gtkLabel())
        return;

    if (!m_text.isNull())
        gtk_label_set_text(gtkLabel(), m_text.isEmpty() ? NULL : m_text.toUtf8().constData());
    if (!m_markup.isNull())
        gtk_label_set_markup(gtkLabel(), m_markup.isEmpty() ? NULL : m_markup.toUtf8().constData());
    QGtkWidget::sync();
}

