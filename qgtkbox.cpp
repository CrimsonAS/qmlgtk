#include "qgtkbox.h"
#include "qgtkvbox.h"
#include "qgtkhbox.h"

QGtkBox::QGtkBox(QGtkObject *parent)
    : QGtkWidget(parent)
{
}

void QGtkBox::childCreated(QGtkObject *w)
{
    QGtkWidget *cw = qobject_cast<QGtkWidget*>(w);
    if (!cw)
        return;

    QGtkBoxPackAttached *pack = qobject_cast<QGtkBoxPackAttached*>(qmlAttachedPropertiesObject<QGtkHBox>(w, false));
    if (!pack) {
        // ### c'mon, why do we have to do this
        pack = qobject_cast<QGtkBoxPackAttached*>(qmlAttachedPropertiesObject<QGtkVBox>(w, false));
    }

    qDebug() << "child added " << w << " with pack " << pack;
    if (!pack) {
        // let container handle it
        QGtkWidget::childCreated(w);
        return;
    }

    GtkBox *box = gtkBox();
    GtkWidget *childWidget = cw->gtkWidget();

    if (pack->packDirection() == QGtkBoxPackAttached::PackStart)
        gtk_box_pack_start(box, childWidget, pack->expand() ? TRUE : FALSE, pack->fill() ? TRUE : FALSE, pack->padding());
    else
        gtk_box_pack_end(box, childWidget, pack->expand() ? TRUE : FALSE, pack->fill() ? TRUE : FALSE, pack->padding());
}


QGtkBoxPackAttached::QGtkBoxPackAttached(QObject *parent)
    : QObject(parent)
{
}

bool QGtkBoxPackAttached::expand() const
{
    return m_expand;
}

void QGtkBoxPackAttached::setExpand(bool e)
{
    if (m_expand == e)
        return;
    m_expand = e;
    emit expandChanged();
}

bool QGtkBoxPackAttached::fill() const
{
    return m_fill;
}

void QGtkBoxPackAttached::setFill(bool f)
{
    if (m_fill == f)
        return;
    m_fill = f;
    emit fillChanged();
}

int QGtkBoxPackAttached::padding() const
{
    return m_padding;
}

void QGtkBoxPackAttached::setPadding(int p)
{
    if (m_padding == p)
        return;
    m_padding = p;
    emit paddingChanged();
}

QGtkBoxPackAttached::PackDirection QGtkBoxPackAttached::packDirection() const
{
    return m_packDirection;
}

void QGtkBoxPackAttached::setPackDirection(const QGtkBoxPackAttached::PackDirection &p)
{
    if (m_packDirection == p)
        return;
    m_packDirection = p;
    emit packDirectionChanged();
}

