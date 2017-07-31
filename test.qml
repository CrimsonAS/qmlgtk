import Gtk 3.0

Application {
    useDarkTheme: true

    Window {
        id: win
        visible: true
        title: "A native Gtk window!"

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
                    HBox.expand: true
                    HBox.fill: true
                }
                Spinner {
                    id: spinner
                }
                ProgressBar {
                    fraction: 0.5
                }
            }
        }
    }

    onStartup: {
    }
}
