#ifndef QGTKHBOX_H
#define QGTKHBOX_H

#include "qgtkbox.h"

class QGtkHBox : public QGtkBox
{
    Q_OBJECT

public:
    QGtkHBox(QGtkObject *parent = 0);

    static QGtkBoxPackAttached *qmlAttachedProperties(QObject *object);

protected:
    GObject *acquireObject() override;
    GtkBox *gtkBox() const { return GTK_BOX(gObject()); }
    void sync() override;

private:
    QString m_label;
};

QML_DECLARE_TYPEINFO(QGtkHBox, QML_HAS_ATTACHED_PROPERTIES)

#endif

