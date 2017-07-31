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
#include "qgtklabel.h"
#include "qgtkbutton.h"
#include "qgtkbox.h"
#include "qgtkhbox.h"
#include "qgtkvbox.h"
#include "qgtkspinner.h"
#include "qgtkprogressbar.h"

static void activate_cb(GtkApplication *that, gpointer)
{
    emit QGtkApplication::instance->activated();
}

static void startup_cb(GtkApplication *that, gpointer)
{
    emit QGtkApplication::instance->startup();
}

int main(int argc, char **argv)
{
    QGtkApplication::appInstance = gtk_application_new("org.me.foobar", G_APPLICATION_FLAGS_NONE);
    g_application_hold(G_APPLICATION(QGtkApplication::appInstance));
    g_signal_connect(QGtkApplication::appInstance, "startup", G_CALLBACK(startup_cb), 0);
    g_signal_connect(QGtkApplication::appInstance, "activate", G_CALLBACK(activate_cb), 0);

    QCoreApplication a(argc, argv);

    qmlRegisterType<QGtkApplication>("Gtk", 3, 0, "Application");
    qmlRegisterType<QGtkWindow>("Gtk", 3, 0, "Window");
    qmlRegisterType<QGtkLabel>("Gtk", 3, 0, "Label");
    qmlRegisterType<QGtkButton>("Gtk", 3, 0, "Button");
    qmlRegisterUncreatableType<QGtkBoxPackAttached>("Gtk", 3, 3, "Box", QGtkBoxPackAttached::tr("Box is only available via attached properties"));
    qmlRegisterType<QGtkHBox>("Gtk", 3, 0, "HBox");
    qmlRegisterType<QGtkVBox>("Gtk", 3, 0, "VBox");
    qmlRegisterType<QGtkSpinner>("Gtk", 3, 0, "Spinner");
    qmlRegisterType<QGtkProgressBar>("Gtk", 3, 0, "ProgressBar");



    QQmlApplicationEngine e(QUrl::fromLocalFile("test.qml"));

    // ### assert root is QGtkApplication

    return g_application_run(G_APPLICATION(QGtkApplication::appInstance), argc, argv);
}

