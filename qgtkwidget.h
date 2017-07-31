#ifndef QGTKWIDGET
#define QGTKWIDGET

#include "qgtkobject.h"

class QGtkWidget : public QGtkObject
{
    Q_OBJECT

    QGTKOBJECT_PROPERTY(bool, visible, isVisible, setVisible, bool, visibleChanged, m_visible, false)

public:
    QGtkWidget(QGtkObject *parent = 0);

protected:
    void sync() override;
    void childCreated(QGtkObject *o) override;

    GtkWidget *gtkWidget() const;

private:
    friend class QGtkBox;
};

#endif

