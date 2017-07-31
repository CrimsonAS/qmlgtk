#ifndef QGTKBOX_H
#define QGTKBOX_H

#include "qgtkwidget.h"

class QGtkBox : public QGtkWidget
{
    Q_OBJECT

public:
    QGtkBox(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() const override;
    GtkBox *gtkBox() const { return GTK_BOX(gObject()); }
    void sync() override;

private:
    QString m_label;
};

#endif


