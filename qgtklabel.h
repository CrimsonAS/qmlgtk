#ifndef QGTKLABEL_H
#define QGTKLABEL_H

#include "qgtkwidget.h"

class QGtkLabel : public QGtkWidget
{
    Q_OBJECT

    QGTKOBJECT_PROPERTY(QString, text, text, setText, const QString &, textChanged, m_text, QString())
    QGTKOBJECT_PROPERTY(QString, markup, markup, setMarkup, const QString &, markupChanged, m_markup, QString())

public:
    QGtkLabel(QGtkObject *parent = 0);

protected:
    GObject *acquireObject() override;
    GtkLabel *gtkLabel() const { return GTK_LABEL(gObject()); }
    void sync() override;
};

#endif

