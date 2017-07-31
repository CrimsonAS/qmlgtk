import Gtk 3.0

Application {
    Window {
        id: win
        visible: true

        VBox {
            Button {
                label: "Hi"
            }
            Button {
                label: "Hi also"
            }
        }
    }

    onStartup: {
    }
}
