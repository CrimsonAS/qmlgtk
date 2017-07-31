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

    for (QObject *c : m_childs) {
        if (QGtkObject *co = qobject_cast<QGtkObject*>(c)) {
            // acquire, sync props
            co->create();

            // handle it further (e.g. adding it, if we are a container).
            childCreated(co);
        }
    }
}

void QGtkObject::childCreated(QGtkObject *o)
{
    // ### ref_sink (& unref in dtor)
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

