#ifndef QGTKWIDGET
#define QGTKWIDGET

#include "qgtkobject.h"

class QGtkWidget : public QGtkObject
{
    Q_OBJECT

    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)

public:
    QGtkWidget(QGtkObject *parent = 0);

    bool isVisible() const;
    void setVisible(bool v);

signals:
    void visibleChanged();

protected:
    void sync() override;

    GtkWidget *gtkWidget() const;

private:
    bool m_visible;

    friend class QGtkObject;
};

#endif

