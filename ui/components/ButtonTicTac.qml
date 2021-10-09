import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Button {
    id: button
    text: ""
    background: Rectangle {
        id: buttonStyle
        color: button.down ? pressedGreen : green
        border { width: 2; color: backgroundColor }
        radius: radiusGeneral
    }
}

