#ifndef QGTKHBOX_H
#define QGTKHBOX_H

#include "qgtkwidget.h"

class QGtkHBox : public QGtkWidget
{
    Q_OBJECT

public:
    QGtkHBox(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() const override;
    GtkBox *gtkBox() const { return GTK_BOX(gObject()); }
    void sync() override;

private:
    QString m_label;
};

#endif


