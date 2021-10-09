import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.12
import "components" as Components

Window {
    id: mainWindow

    property var radiusGeneral: 10
    property var margin: 40
    property var minimumLength: 540
    property color backgroundColor: "#282A35"
    property color green: "#03A96B"
    property color pressedGreen: "#3CB280"
    property color pink: "#FFC0C7"


    width: 600
    height: 600
    minimumHeight: minimumLength
    minimumWidth: minimumLength
    visible: true
    color: green

    Text {
        id: gameResult
        anchors { top: parent.top; horizontalCenter: parent.horizontalCenter; topMargin: margin }
        color: pink
        font { pixelSize: 40; bold: true }
        text: ""
    }

    Components.Board {
        id: gamingField
        anchors.centerIn: parent
    }

    Components.ButtonTicTac {
        id: button
        text: "play again!"
        implicitWidth: 100
        implicitHeight: 40
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: margin }
        onClicked: {
            gameResult.text = ""
            gamingField.clear()
        }
    }
}
