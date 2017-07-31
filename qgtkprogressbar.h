#ifndef QGTKPROGRESSBAR_H
#define QGTKPROGRESSBAR_H

#include "qgtkwidget.h"

class QGtkProgressBar : public QGtkWidget
{
    Q_OBJECT

    QGTKOBJECT_PROPERTY(double, fraction, fraction, setFraction, double, fractionChanged, m_fraction, 0)
    QGTKOBJECT_PROPERTY(bool, inverted, isInverted, setInverted, bool, invertedChanged, m_inverted, false)
    QGTKOBJECT_PROPERTY(bool, textVisible, isTextVisible, setTextVisible, bool, textVisibleChanged, m_textVisible, false)
    QGTKOBJECT_PROPERTY(QString, text, text, setText, const QString &, textChanged, m_text, QString())

    // ### ellipsize, pulse_step, pulse

public:
    QGtkProgressBar(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() override;
    GtkProgressBar *gtkProgressBar() const { return GTK_PROGRESS_BAR(gObject()); }
    void sync() override;
};

#endif

