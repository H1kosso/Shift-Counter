import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts
import QtQuick.Controls 2.15
import appShiftCounter


Window {
    width: 1500
    height: 900
    visible: true
    title: qsTr("Liczenie godzin")
    color: "lightblue"
    id: mainWindow
    property int numberOfDays: 30
    property list<int> sundays: [2, 9, 16, 23]
    property list<int> saturdays: [1,8,15,22, 29]
    property list <string> allMonth: []


    // Indeksy
    Row {
        id: days
        spacing: 0
        width:  parent.width
        x: 0
        y: 160
        z: 1


        Repeater {
            model: numberOfDays
            Rectangle {
                width: parent.width / numberOfDays
                height: 30
                border.color: "black"
                border.width: 1
                color: saturdays.includes(index) ? "darkCyan" : ( sundays.includes(index) ? "red" : "lightgrey")

                Text {
                    text: (index + 1).toString()
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 25
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if( !saturdays.includes(index) && !sundays.includes(index)){
                            saturdays.push(index);
                        } else if( saturdays.includes(index)) {
                            saturdays.splice(saturdays.indexOf(index), 1);
                            sundays.push(index);
                        } else{
                            sundays.splice(sundays.indexOf(index), 1);
                        }
                    }
                }
            }
        }
    }

     //Miesiac
    GridLayout {
        id: month
        objectName: "month"
        height: mainWindow.height - 300
        width: parent.width
        rows: 16
        columns: numberOfDays
        columnSpacing: 0
        rowSpacing: 0
        x: 0
        y: 190
        z: 0

        Repeater {
            model: month.rows * month.columns
            id: monthR

            delegate: Rectangle {
                width: parent.width / month.columns
                height: month.height / month.rows

                border.color: "black"
                border.width: 1
                color: saturdays.includes(index % month.columns) ? "lightblue" : ( sundays.includes(index % month.columns) ? "pink" : (index >= month.columns * 8 && index < month.columns * 9 ? "lightgrey" : "white"))
                TextEdit {
                    anchors.fill: parent
                    text: index >= month.columns * 8 && index < month.columns * 9 ? "-" : ""// Math.floor(Math.random() * 10) + 1
                    readOnly: index >= month.columns * 8 && index < month.columns * 9
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 25

                }
            }
        }
    }




    Text {
        id: tekst
        x: 20
        y: 20
        font.pixelSize: 25
        text: "Dlugość miesiąca"
    }

    // Wybór miesiaca
    Item {
        width: 200
        height: 40
        x: 20
        y: 60


        ComboBox {
            id: comboBox
            width: parent.width
            height: parent.height
            font.pixelSize: 30

            model: ListModel {
                ListElement { text: "28"; days: 28 }
                ListElement { text: "29"; days: 29 }
                ListElement { text: "30"; days: 30 }
                ListElement { text: "31"; days: 31 }
            }

            delegate: Item {
                width: comboBox.width
                height: comboBox.height

                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: comboBox.highlightedIndex === index ? "lightblue" : "white"

                    Text {
                        anchors.centerIn: parent
                        text: comboBox.model.get(index).text
                        font.pixelSize: 30
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            comboBox.currentIndex = index;
                            month.columns = comboBox.model.get(index).days;
                            numberOfDays = month.columns

                        }
                    }
                }
            }

            onActivated: {
                month.columns = comboBox.currentData.days;
                numberOfDays = comboBox.currentData.days;
            }
        }
    }

    Counter{
        id: myCounter
    }

    Button {
        id: count
        text: qsTr("Policz")
        x: 500
        y: 50
        width: 150
        height: 50
        font.pixelSize: 30




        onClicked:{
            allMonth =[]
            // Iterate through the Repeater's delegate items
            for (var row = 0; row < month.rows; row++) {
                var rowData;
                for (var col = 0; col < month.columns; col++) {
                    var index = row * month.columns + col;
                    var cell = monthR.itemAt(index); // Get the Repeater item at the specified index

                    var textEdit = cell.children[0]; // Get the TextEdit element
                    allMonth.push(textEdit.text); // Add the text value to the row data
                }
            }
            myCounter.buttonClicked(numberOfDays, sundays, saturdays, allMonth)
        }



    }
}
