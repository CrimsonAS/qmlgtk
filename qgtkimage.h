#ifndef QGTKIMAGE_H
#define QGTKIMAGE_H

#include "qgtkwidget.h"

class QGtkImage : public QGtkWidget
{
    Q_OBJECT

    QGTKOBJECT_PROPERTY(QString, fileName, fileName, setFileName, const QString &, fileNameChanged, m_fileName, QString())

public:
    QGtkImage(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() override;
    GtkImage *gtkImage() const { return GTK_IMAGE(gObject()); }
    void sync() override;
};

#endif

