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

void QGtkWidget::childCreated(QGtkObject *o)
{
    QGtkWidget *cw = qobject_cast<QGtkWidget*>(o);
    if (!cw)
        return;

    // If we're a container, we will want to put the child inside us.
    // ### this really belongs on a QGtkContainer
    GtkContainer *ourContainer = 0;
    GObject *ours = gObject();
    if (GTK_IS_CONTAINER(ours))
        ourContainer = GTK_CONTAINER(ours);
    else
        return;

    GtkWidget *childWidget = cw->gtkWidget();
    gtk_container_add(ourContainer, childWidget);
}
