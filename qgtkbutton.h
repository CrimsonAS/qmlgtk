#ifndef QGTKBUTTON_H
#define QGTKBUTTON_H

#include "qgtkwidget.h"

class QGtkButton : public QGtkWidget
{
    Q_OBJECT

    QGTKOBJECT_PROPERTY(QString, label, label, setLabel, const QString &, labelChanged, m_label, QString())

public:
    QGtkButton(QGtkObject *parent = 0);

signals:
    // ### consider an event wrapper
    void pressed();
    void released();
    void clicked();

protected:
    GObject *acquireObject() override;
    GtkButton *gtkButton() const { return GTK_BUTTON(gObject()); }
    void sync() override;

    static void onPressed(QGtkButton *that);
    static void onReleased(QGtkButton *that);
    static void onClicked(QGtkButton *that);
};

#endif

