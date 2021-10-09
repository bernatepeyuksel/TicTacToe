import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick 2.14
import QtQuick.Controls 2.14
import QtGraphicalEffects 1.14
import QtQuick.Layouts 1.14
import QtQuick.Dialogs 1.3

Window {
    id: window
    width: 800
    height: 600
    visible: true
    color: yellow

    property var popUpWidth: 640
    property var popUpHeight: 480
    property var pixelSize: 12
    property color backgroundColor: "#FF5733"
    property color textColors: "#900C3F"
    property color red: "#C70039"
    property color yellow: "#FFC300"
    property color canvasColor: "#DAF7A6"

        //RECTANGLE CONTAINING CANVAS, HEADER, FOOTER
    Rectangle {
        id: container
        width: popUpWidth
        height: popUpHeight
        anchors.centerIn: parent
        radius: 20
        color: "#DAF7A6"

        // HEADER of PAGE
        Rectangle
        {
            id: pageHeader
            color: backgroundColor
            width: popUpWidth
            height: 50
            radius: 20
            anchors { top: parent.top; right: parent.right}

            Rectangle{ id:noRound; color: backgroundColor; anchors.bottom: parent.bottom; width: popUpWidth; height: 30 }

            //Closes pop up
            ToolButton {
                id: closeButton
                height: pageHeader.height
                width: height
                anchors { left: parent.left; leftMargin: 20 }
                background: Rectangle{ color: backgroundColor; radius: 20 }

                Text {
                   text: "cancel"
                   color: textColors
                   verticalAlignment: Text.AlignVCenter
                   horizontalAlignment: Text.AlignHCenter
                   font.pixelSize: pixelSize
                   anchors.fill: parent
                }

//                onClicked: {
//                    canceled()
//                    canvas.setContentImage(entrance.accounts.current.signature)
//                    if(!canvas.hasContent)
//                    {
//                        canvas.reset()
//                    }
//                    canvas.resize() // After saved image is loaded keeps ratio of pen
//                    canvas.update()
//                    popup.close()
//               }

           }

            //Saves signature
            ToolButton {
                id: okButton
                height: pageHeader.height
                width: height
                anchors { right: parent.right; rightMargin: 20 }
                background: Rectangle{ color: backgroundColor; radius: 20 }
                Text {
                    id: saveText
                    text: "save"
                    color: textColors
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: pixelSize
                    anchors.fill: parent
                }

            }

            Text {
                text: "Draw Here"
                color: textColors
                anchors.centerIn: parent
                font.pixelSize: pixelSize
            }
        }

/*
        // CANVAS
        Rectangle {
            id: canvasField
            width: popUpWidth
            height: 300
            anchors { centerIn: parent; top: pageHeader.bottom}

//            StackLayout {
//                id: signatureFieldStack
//                anchors.fill: parent

//                Item {
//                    id: drawTab
//                    Canvas {
//                        objectName: "SignaturePopUp_canvas"
//                        id: canvas
//                        anchors.fill: parent
//                        contentSize: Qt.size(width, height)
//                        brushWidth: 3
//                        brushSoftness: 0.8
//                        brushColor: radioBlue.checked? '#00589C' : 'black'

//                        PointHandler {
//                            acceptedButtons: Qt.LeftButton
//                            acceptedPointerTypes: PointerDevice.GenericPointer
//                                                  | PointerDevice.Cursor
//                                                  | PointerDevice.Finger | PointerDevice.Pen

//                            acceptedDevices: PointerDevice.AllDevices
//                            onActiveChanged: canvas.finishStroke()
//                            onPointChanged:  canvas.stroke(point.position, point.pressure)

//                        }

//                        Component.onCompleted: {
//                            canvas.finishStroke()
//                            //canvas.stroke(point.position, point.pressure)
//                        }
//                    }
//                }

//                ImagePainter {
//                    id: imageTab
//                    TextButton {
//                        id: openImageButton
//                        text: qsTrId("ks_signdoc_005_signdoc_view_infotab_setsignature")
//                    }
//                }
//            }
//            Component.onCompleted: {    //Retrieves signature while page loading
//                canvas.setContentImage(entrance.accounts.current.signature)
//                if(!canvas.hasContent)
//                {
//                    canvas.reset()
//                }
//                canvas.resize() // After saved image is loaded keeps ratio of pen
//                canvas.update()
//            }
        }
*/
        // FOOTER of PAGE
        Rectangle
        {
            id: pageFooter
            width: popUpWidth
            height: 50
            color: backgroundColor
            anchors { bottom: parent.bottom; right: parent.right }
            radius: 20

            Rectangle{ id:noRound2; width: popUpWidth; height: 30; color: backgroundColor; anchors.top: parent.top }

            Text {
                id: colorText
                text: "color"
                color: textColors
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: pixelSize
                anchors { left: parent.left; leftMargin: 20 }
            }

            RadioButton {       //Blue RadioButton
                objectName: "SignaturePopUp_radioBlue"
                id: radioBlue
                checked: true
                text: "yellow"
                anchors { left: colorText.right; leftMargin: 20; verticalCenter: colorText.verticalCenter }
                indicator: Rectangle{       //colors button when checked
                    id: outer
                    y: (radioBlue.height / 2) - (implicitHeight / 2)
                    implicitWidth: 21
                    implicitHeight: 21

                    color: textColors
                    radius: Math.min(width, height) / 2

                    Rectangle {
                        id: inner
                        radius: outer.radius - 1
                        width: 2 * radius
                        height: width
                        color: radioBlue.checked? yellow : canvasColor
                        anchors { verticalCenter: outer.verticalCenter; horizontalCenter: outer.horizontalCenter }
                    }

                }
                onClicked: {
                    canvas.brushColor = yellow
                    canvas.reColor(canvas.brushColor)
                }
            }

            RadioButton {       //Black RadioButton
                id: radioBlack
                text: "red"
                anchors {left: radioBlue.right; leftMargin: 10; verticalCenter: colorText.verticalCenter}

                indicator: Rectangle{       //colors button when checked
                    id: outerB
                    y: (radioBlack.height / 2) - (implicitHeight / 2)
                    implicitWidth: 21
                    implicitHeight: 21

                    color: textColors
                    radius: Math.min(width, height) / 2

                    Rectangle {
                        id: innerB
                        radius: outerB.radius - 1
                        width: 2 * radius
                        height: width
                        color: radioBlack.checked? red : canvasColor
                        anchors { verticalCenter: outerB.verticalCenter; horizontalCenter: outerB.horizontalCenter }
                    }

                }
                onClicked:{
                    canvas.brushColor = red
                    canvas.reColor(canvas.brushColor)
                }
            }

            Text {
                id: textButton_Clean
                text: "clear"
                color: textColors
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: pixelSize
                anchors { right: parent.right; rightMargin: 20}

                MouseArea {
                    anchors.fill: parent
                    onClicked: canvas.reset()
                }
            }
            Text {

                id: textButton_Load
                //% "Load"
                text: "Load Image"
                color: textColors
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: pixelSize
                anchors.right: textButton_Clean.left
                anchors.rightMargin: 30

                MouseArea{
                    anchors.fill: parent
                    onClicked:fileDialog.open()
                    }
                }

            FileDialog {
                 id: fileDialog
                 title: "Choose a png file" // TODO: Add qsTrId for translation
                 selectMultiple: false
                 folder: shortcuts.desktop
                 nameFilters: [
                             "Image files (*.png )",
                         ]
                 onAccepted: {
                     canvas.setContentImage(canvas.readFromFile(fileDialog.fileUrl))
                     canvas.resize()
                 }
                 onRejected:  console.log("Cancelled File Dialog")
                 Component.onCompleted: visible = false
            }
          }
      }
}
