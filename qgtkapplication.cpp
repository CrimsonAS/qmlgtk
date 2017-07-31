#include "qgtkapplication.h"

#include <gio/gio.h>

QGtkApplication *QGtkApplication::instance = 0;
GtkApplication *QGtkApplication::appInstance = 0;

QGtkApplication::QGtkApplication(QObject *parent)
    : QGtkObject(parent)
{
    // ### assert singleton
    instance = this;
    connect(this, &QGtkApplication::startup, this, [=]() {
        create();
    });
}

GObject *QGtkApplication::acquireObject()
{
    return G_OBJECT(appInstance);
}

void QGtkApplication::sync()
{
}

