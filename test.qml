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
                    label: "Click to turn me " + (spinner.active ? "off" : "on")
                    onClicked: {
                        spinner.active = !spinner.active
                    }
                }
                Spinner {
                    id: spinner
                }
            }
        }
    }

    onStartup: {
    }
}
