/*
 * Copyright (c) 2017 Crimson AS <info@crimson.no>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <QQmlEngine>
#include <QQmlComponent>
#include <QCoreApplication>
#include <QtQml>

#include "qgtkobject.h"
#include "qgtkapplication.h"
#include "qgtkwindow.h"
#include "qgtkbutton.h"
#include "qgtkbox.h"

static void activate_cb(GtkApplication *that, gpointer)
{
    qDebug() << "activate " << that;
    emit QGtkApplication::instance->activated();
}

static void startup_cb(GtkApplication *that, gpointer)
{
    qDebug() << "startup " << that;
    emit QGtkApplication::instance->startup();
}

int main(int argc, char **argv)
{
    QGtkApplication::appInstance = gtk_application_new("org.me.foobar", G_APPLICATION_FLAGS_NONE);
    g_application_hold(G_APPLICATION(QGtkApplication::appInstance));
    g_signal_connect(QGtkApplication::appInstance, "startup", G_CALLBACK(startup_cb), 0);
    g_signal_connect(QGtkApplication::appInstance, "activate", G_CALLBACK(activate_cb), 0);

    QCoreApplication a(argc, argv);

    qmlRegisterType<QGtkApplication>("Gtk", 4, 0, "Application");
    qmlRegisterType<QGtkWindow>("Gtk", 4, 0, "Window");
    qmlRegisterType<QGtkButton>("Gtk", 4, 0, "Button");
    qmlRegisterType<QGtkBox>("Gtk", 4, 0, "Box");

    QQmlApplicationEngine e(QUrl::fromLocalFile("test.qml"));

    // ### assert root is QGtkApplication

    return g_application_run(G_APPLICATION(QGtkApplication::appInstance), argc, argv);
}
