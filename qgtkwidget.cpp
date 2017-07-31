#include "qgtkwidget.h"

QGtkWidget::QGtkWidget(QGtkObject *parent)
    : QGtkObject(parent)
    , m_visible(true)
{
}

void QGtkWidget::sync()
{
    if (!gtkWidget()) {
        return;
    }

qDebug() << "widget sync" << this << m_visible;
    if (m_visible) {
        gtk_widget_show_all(gtkWidget());
    } else {
        gtk_widget_hide(gtkWidget());
    }
}

GtkWidget *QGtkWidget::gtkWidget() const
{
    return GTK_WIDGET(m_me);
}

bool QGtkWidget::isVisible() const
{
    return m_visible;
}

void QGtkWidget::setVisible(bool v)
{
    if (v == m_visible)
        return;

    m_visible = v;
    sync();
}

