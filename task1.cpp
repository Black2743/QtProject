#include "task1.h"
task1::task1()
{

}

int task1::Main(QApplication *app){

    QWidget window;
    QTextEdit textEdit(&window);


    QList<int> myQueue;
    const int queueSize = 10;
    for (int i = 0; i < queueSize; ++i) {
        int randomNumber = QRandomGenerator::global()->bounded(1, 101);
        myQueue.append(randomNumber);
    }

    QString outputText = "Начальная очередь:\n";
    for (const int& number : myQueue) {
        outputText += QString::number(number) + "\n";
    }


    int minElement = myQueue.at(0);
    for (int i = 1; i < queueSize; ++i) {
        int currentElement = myQueue.at(i);
        if (currentElement < minElement) {
            minElement = currentElement;
        }
    }

    myQueue.removeAll(minElement);
    myQueue.prepend(minElement);

    outputText += "Итоговая очередь:\n";
    for (const int& number : myQueue) {
        outputText += QString::number(number) + "\n";
    }



    textEdit.setPlainText(outputText);
    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();
}
