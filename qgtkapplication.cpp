#include "qgtkapplication.h"

#include <gio/gio.h>

QGtkApplication *QGtkApplication::instance = 0;
GtkApplication *QGtkApplication::appInstance = 0;

QGtkApplication::QGtkApplication(QObject *parent)
    : QGtkObject(parent)
    , m_darkTheme(0)
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
    // ### this is crashy
    //g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", m_darkTheme ? TRUE : FALSE, NULL);
}

// ### this should probably be in a GtkSettings instead
bool QGtkApplication::useDarkTheme() const
{
    return m_darkTheme;
}

void QGtkApplication::setUseDarkTheme(bool d)
{
    if (m_darkTheme == d)
        return;

    m_darkTheme = d;
    emit useDarkThemeChanged();
    sync();
}
