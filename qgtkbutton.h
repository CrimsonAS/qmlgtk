#ifndef QGTKBUTTON_H
#define QGTKBUTTON_H

#include "qgtkwidget.h"

class QGtkButton : public QGtkWidget
{
    Q_OBJECT

    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged);

public:
    QGtkButton(QGtkObject *parent = 0);

    QString label() const;
    void setLabel(const QString &l);

signals:
    void labelChanged();

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

private:
    QString m_label;
};

#endif

