#ifndef QGTKSPINNER_H
#define QGTKSPINNER_H

#include "qgtkwidget.h"

class QGtkSpinner : public QGtkWidget
{
    Q_OBJECT

    Q_PROPERTY(bool active READ isActive WRITE setActive NOTIFY activeChanged)

public:
    QGtkSpinner(QGtkObject *parent = 0);

    bool isActive() const;
    void setActive(bool a);

signals:
    void activeChanged();

protected:
    GObject *acquireObject() const override;
    GtkSpinner *gtkSpinner() const { return GTK_SPINNER(gObject()); }
    void sync() override;

private:
    bool m_active;
};

#endif



