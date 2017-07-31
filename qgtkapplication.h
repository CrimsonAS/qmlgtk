#ifndef QGTKAPPLICATION_H
#define QGTKAPPLICATION_H

#include "qgtkobject.h"

class QGtkApplication : public QGtkObject
{
    Q_OBJECT

    Q_PROPERTY(bool useDarkTheme READ useDarkTheme WRITE setUseDarkTheme NOTIFY useDarkThemeChanged)

public:
    QGtkApplication(QObject *parent = 0);

    static QGtkApplication *instance;
    static GtkApplication *appInstance;

    bool useDarkTheme() const;
    void setUseDarkTheme(bool d);

Q_SIGNALS:
    void activated();
    void startup();
    void useDarkThemeChanged();

protected:
    GObject *acquireObject() override;
    void sync() override;

private:
    bool m_darkTheme;
};

#endif // QGTKAPPLICATION_H
