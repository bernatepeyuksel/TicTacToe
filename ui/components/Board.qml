import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12



//RECTANGLE CONTAINING BOARD
Rectangle {
    id: container

    property var lineLength: minimumLength*0.6
    property alias area: area

    function humanPlay(index)
    {
        var x = Math.floor(index / 3)
        var y = index%3
        human.play(board, x, y);
    }

    function clear()
    {
        board.clear()

        for(var index = 0; index< area.model ; index++)
        {
            area.currentIndex = index;
            area.currentItem.tictext = "";
            area.currentItem.cellArea.enabled = true
        }
    }

    width: minimumLength*0.72
    height: minimumLength*0.72
    color: backgroundColor
    radius: radiusGeneral

    GridView {
        id: area
        anchors.fill: parent
        cellWidth: (parent.width / 3)
        cellHeight: (parent.height / 3)
        model: 9
        clip: true
        interactive: false
        delegate: Item {
                    property alias tictext: ticField.text
                    property alias cellArea: cellArea
                    id: cell
                    width: area.cellWidth - radiusGeneral
                    height: area.cellHeight - radiusGeneral
                    Text {
                        id: ticField
                        anchors.centerIn: parent
                        color: green
                        font { pixelSize: 70; bold: true }
                        text: ""

                    }

                    MouseArea {
                      id: cellArea
                      anchors.fill: parent
                      onClicked: {
                          if(""==ticField.text)
                          {
                              ticField.text = "X"
                              humanPlay(index)
                          }
                      }
                    }
                    Connections {
                        target: computer
                        onComputerPlayed:
                        {
                            var index = x*3 +y;
                            area.currentIndex = index;
                            area.currentItem.tictext = "O";
                        }
                        onGameOver:
                        {
                            cellArea.enabled = false
                            gameResult.text = result
                        }
                    }
                    Connections {
                        target: human
                        onGameOver:
                        {
                            cellArea.enabled = false
                            gameResult.text = result
                        }
                    }
        }
    }

    Rectangle { id: vLine; color: green; width: radiusGeneral; height: lineLength; anchors{ right: area.right; rightMargin: area.cellWidth; verticalCenter: parent.verticalCenter} }
    Rectangle { id: hLine; color: green; width: lineLength; height: radiusGeneral; anchors{ bottom: area.bottom; bottomMargin: area.cellHeight; horizontalCenter: parent.horizontalCenter} }
    Rectangle { id: vLine1; color: green; width: radiusGeneral; height: lineLength ; anchors{ right: vLine.right; rightMargin: area.cellWidth; verticalCenter: parent.verticalCenter} }
    Rectangle { id: hLine1; color: green; width: lineLength; height: radiusGeneral; anchors{ bottom: hLine.bottom; bottomMargin: area.cellHeight; horizontalCenter: parent.horizontalCenter} }

}

