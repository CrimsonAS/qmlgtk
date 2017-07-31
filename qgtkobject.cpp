#include "qgtkobject.h"
#include "qgtkwidget.h"

QGtkObject::QGtkObject(QObject *parent)
    : QObject(parent)
    , m_me(0)
{
}

QQmlListProperty<QObject> QGtkObject::gtkChildren()
{
    return QQmlListProperty<QObject>(this, this,
                                     &QGtkObject::appendGtkChild,
                                     &QGtkObject::gtkChildCount,
                                     &QGtkObject::gtkChildrenAt,
                                     &QGtkObject::clearGtkChilds);
}

GObject *QGtkObject::gObject() const
{
    return m_me;
}

void QGtkObject::create()
{
    m_me = acquireObject();
    sync();

    GObject *ours = gObject();
    GtkContainer *ourContainer = 0;
    if (GTK_IS_CONTAINER(ours))
        ourContainer = GTK_CONTAINER(ours);

    for (QObject *c : m_childs) {
        if (QGtkObject *co = qobject_cast<QGtkObject*>(c)) {
            // acquire, sync props
            co->create();

            if (QGtkWidget *cw = qobject_cast<QGtkWidget*>(c)) {
                if (ourContainer) {
                    GtkWidget *childWidget = cw->gtkWidget();
                    qDebug() << "container" << this << co;
                    gtk_container_add(ourContainer, childWidget);
                }
            }
        }
    }
}

void QGtkObject::appendGtkChild(QQmlListProperty<QObject> *prop, QObject *child)
{
    QGtkObject *that = static_cast<QGtkObject*>(prop->object);
    that->m_childs.append(child);
}

int QGtkObject::gtkChildCount(QQmlListProperty<QObject> *prop)
{
    QGtkObject *that = static_cast<QGtkObject*>(prop->object);
    return that->m_childs.count();
}

QObject* QGtkObject::gtkChildrenAt(QQmlListProperty<QObject> *prop, int idx)
{
    QGtkObject *that = static_cast<QGtkObject*>(prop->object);
    return that->m_childs.at(idx);
}

void QGtkObject::clearGtkChilds(QQmlListProperty<QObject> *prop)
{
    QGtkObject *that = static_cast<QGtkObject*>(prop->object);
    return that->m_childs.clear();
}

