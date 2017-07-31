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
    virtual void childCreated(QGtkObject *o);

    QVector<QObject*> m_childs;
    GObject *m_me;

private:
    static void appendGtkChild(QQmlListProperty<QObject> *prop, QObject *child);
    static int gtkChildCount(QQmlListProperty<QObject> *prop);
    static QObject* gtkChildrenAt(QQmlListProperty<QObject> *prop, int idx);
    static void clearGtkChilds(QQmlListProperty<QObject> *prop);
};

// Simple helper to prevent massive repetition
#define QGTKOBJECT_PROPERTY(type, propName, readerName, writerName, writerType, signalName, memberName, memberValue) \
    Q_PROPERTY(type propName READ readerName WRITE writerName NOTIFY signalName) \
    public: \
    type readerName() const \
    { \
        qDebug() << this << "reading " #propName << memberName; \
        return memberName; \
    } \
    void writerName(writerType var) \
    { \
        if (memberName == var) \
        return; \
        qDebug() << this << "writing " #propName << " (was" << memberName << "now" << var << ")"; \
        memberName = var; \
        emit signalName(); \
        sync(); \
    } \
    signals: \
    Q_SIGNAL /* make moc happy with the macro magic */ void signalName(); \
    private: \
    type memberName = memberValue;


#endif // QGTKOBJECT_H
