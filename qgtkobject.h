#ifndef QGTKOBJECT_H
#define QGTKOBJECT_H

#include <QObject>
#include <QQmlListProperty>
#include <QVector>
#include <QDebug>

#undef signals
#include <gtk/gtk.h>
#define signals protected

class QGtkObject : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("DefaultProperty", "gtkChildren")

    Q_PROPERTY(QQmlListProperty<QObject> gtkChildren READ gtkChildren)
public:
    QGtkObject(QObject *parent = 0);

    QQmlListProperty<QObject> gtkChildren();

protected:
    GObject *gObject() const;
    virtual GObject *acquireObject() = 0;
    virtual void sync() = 0;
    void create();

    QVector<QObject*> m_childs;
    GObject *m_me;

private:
    static void appendGtkChild(QQmlListProperty<QObject> *prop, QObject *child);
    static int gtkChildCount(QQmlListProperty<QObject> *prop);
    static QObject* gtkChildrenAt(QQmlListProperty<QObject> *prop, int idx);
    static void clearGtkChilds(QQmlListProperty<QObject> *prop);
};

#endif // QGTKOBJECT_H
