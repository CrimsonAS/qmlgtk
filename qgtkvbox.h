#ifndef QGTKVBOX_H
#define QGTKVBOX_H

#include "qgtkbox.h"

class QGtkVBox : public QGtkBox
{
    Q_OBJECT

public:
    QGtkVBox(QGtkObject *parent = 0);

    static QGtkBoxPackAttached *qmlAttachedProperties(QObject *object);

protected:
    GObject *acquireObject() override;
    GtkBox *gtkBox() const { return GTK_BOX(gObject()); }
    void sync() override;

private:
    QString m_label;
};

QML_DECLARE_TYPEINFO(QGtkVBox, QML_HAS_ATTACHED_PROPERTIES)

#endif

