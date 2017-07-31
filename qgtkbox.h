#ifndef QGTKBOX_H
#define QGTKBOX_H

#include "qgtkwidget.h"

#include <QtQml/qqml.h>

class QGtkBoxPackAttached;

class QGtkBox : public QGtkWidget
{
    Q_OBJECT

public:
    QGtkBox(QGtkObject *parent = 0);

protected:
    void childCreated(QGtkObject *w);
    GtkBox *gtkBox() const { return GTK_BOX(gObject()); }
};

class QGtkBoxPackAttached : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool expand READ expand WRITE setExpand NOTIFY expandChanged)
    Q_PROPERTY(bool fill READ fill WRITE setFill NOTIFY fillChanged)
    Q_PROPERTY(int padding READ padding WRITE setPadding NOTIFY paddingChanged)

public:
    QGtkBoxPackAttached(QObject *parent);

    bool expand() const;
    void setExpand(bool e);

    bool fill() const;
    void setFill(bool f);

    int padding() const;
    void setPadding(int p);

signals:
    void expandChanged();
    void fillChanged();
    void paddingChanged();

private:
    bool m_expand = 0;
    bool m_fill = false;
    int m_padding = 0;
};

#endif

