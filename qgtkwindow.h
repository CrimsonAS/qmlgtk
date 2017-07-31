#ifndef QGTKWINDOW_H
#define QGTKWINDOW_H

#include "qgtkwidget.h"

class QGtkWindow : public QGtkWidget
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

public:
    QGtkWindow(QGtkObject *parent = 0);

    QString title() const;
    void setTitle(const QString &t);

signals:
    void titleChanged();

protected:
    GObject *acquireObject() override;
    GtkWindow *gtkWindow() const { return GTK_WINDOW(gObject()); }
    void sync() override;

private:
    QString m_title;
};

#endif
