import Gtk 3.0

Application {
    Window {
        id: win
        visible: true

        VBox {
            Button {
                label: "Hi"
            }

            HBox {
                Button {
                    label: "Hi also"
                }
                Spinner {
                    active: true
                }
            }
        }
    }

    onStartup: {
    }
}
