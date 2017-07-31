#include "qgtkprogressbar.h"

QGtkProgressBar::QGtkProgressBar(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

GObject *QGtkProgressBar::acquireObject()
{
    GtkWidget *pbar = gtk_progress_bar_new();
    return G_OBJECT(pbar);
}

void QGtkProgressBar::sync()
{
    if (!gtkProgressBar())
        return;

    gtk_progress_bar_set_fraction(gtkProgressBar(), m_fraction);
    gtk_progress_bar_set_inverted(gtkProgressBar(), m_inverted);
    gtk_progress_bar_set_show_text(gtkProgressBar(), m_textVisible);
    gtk_progress_bar_set_text(gtkProgressBar(), m_text.toUtf8().constData());
    QGtkWidget::sync();
}

