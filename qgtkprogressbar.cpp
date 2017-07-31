#include "qgtkprogressbar.h"

QGtkProgressBar::QGtkProgressBar(QGtkObject *parent)
    : QGtkWidget(parent)
    , m_fraction(0)
    , m_inverted(false)
    , m_textVisible(false)
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

double QGtkProgressBar::fraction() const
{
    return m_fraction;
}

void QGtkProgressBar::setFraction(double f)
{
    if (m_fraction == f)
        return;

    m_fraction = f;
    emit fractionChanged();
    sync();
}

bool QGtkProgressBar::isInverted() const
{
    return m_inverted;
}

void QGtkProgressBar::setInverted(bool i)
{
    if (m_inverted == i)
        return;
    m_inverted = i;
    emit invertedChanged();
    sync();
}

bool QGtkProgressBar::isTextVisible() const
{
    return m_textVisible;
}

void QGtkProgressBar::setTextVisible(bool v)
{
    if (m_textVisible == v)
        return;
    m_textVisible = v;
    emit textVisibleChanged();
    sync();
}

QString QGtkProgressBar::text() const
{
    return m_text;
}

void QGtkProgressBar::setText(const QString &t)
{
    m_text = t;
    emit textChanged();
    sync();
}

