#include "task8.h"

task8::task8()
{

}

int task8::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);

    QList<int> queue;
    const int queueSize = 10;
    QRandomGenerator randomGenerator;
    for (int i = 0; i < queueSize; ++i) {
        int randomNumber = randomGenerator.bounded(-100, 100);
        queue.append(randomNumber);
    }
    QString outputText = "Начальная очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }
    QList<int> negativeQueue;
    QList<int> positiveQueue;
    for (const int& number : queue) {
        if (number < 0) {
            negativeQueue.append(number);
        } else {
            positiveQueue.append(number);
        }
    }


    outputText += "Отрицательные числа:\n";
    for (const int& number : negativeQueue) {
        outputText += QString::number(number) + "\n";
    }
    outputText += "\nПоложительные числа:\n";
    for (const int& number : positiveQueue) {
        outputText += QString::number(number) + "\n";
    }


    textEdit.setPlainText(outputText);

    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();

}
