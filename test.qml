import Gtk 3.0
import QtQml 2.0

Application {
    useDarkTheme: true

    Window {
        id: win
        visible: true
        title: "A native Gtk window!"

        VBox {
            HBox {
                Label {
                    text: "Some plain text <b>here</b>"
                }
                Label {
                    markup: "Some marked up text <b>here</b>"
                }
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
                    id: pb
                    fraction: 0.5

                    Timer {
                        interval: 100
                        running: true
                        repeat: true
                        onTriggered: {
                            pb.fraction += 0.05
                            if (pb.fraction > 1.0) {
                                pb.fraction = 0.0
                            }
                        }
                    }
                }
            }
        }
    }

    onStartup: {
    }
}
