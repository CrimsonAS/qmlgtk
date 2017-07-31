#ifndef QGTKVBOX_H
#define QGTKVBOX_H

#include "qgtkwidget.h"

class QGtkVBox : public QGtkWidget
{
    Q_OBJECT

public:
    QGtkVBox(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() override;
    GtkBox *gtkBox() const { return GTK_BOX(gObject()); }
    void sync() override;

private:
    QString m_label;
};

#endif


