import Gtk 3.0

Application {
    Window {
        id: win
        visible: true

        Box {
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
