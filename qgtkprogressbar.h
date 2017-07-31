#ifndef QGTKPROGRESSBAR_H
#define QGTKPROGRESSBAR_H

#include "qgtkwidget.h"

class QGtkProgressBar : public QGtkWidget
{
    Q_OBJECT

    Q_PROPERTY(double fraction READ fraction WRITE setFraction NOTIFY fractionChanged);
    Q_PROPERTY(bool inverted READ isInverted WRITE setInverted NOTIFY invertedChanged);
    Q_PROPERTY(bool textVisible READ isTextVisible WRITE setTextVisible NOTIFY textVisibleChanged);
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged);

public:
    QGtkProgressBar(QGtkObject *parent = 0);

    double fraction() const;
    void setFraction(double f);

    bool isInverted() const;
    void setInverted(bool i);

    bool isTextVisible() const;
    void setTextVisible(bool v);

    QString text() const;
    void setText(const QString &t);

    // ### ellipsize, pulse_step, pulse

signals:
    void fractionChanged();
    void invertedChanged();
    void textVisibleChanged();
    void textChanged();

protected:
    GObject *acquireObject() override;
    GtkProgressBar *gtkProgressBar() const { return GTK_PROGRESS_BAR(gObject()); }
    void sync() override;

private:
    bool m_fraction;
    bool m_inverted;
    bool m_textVisible;
    QString m_text;
};

#endif

