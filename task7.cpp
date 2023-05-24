#include "task7.h"

task7::task7()
{

}

int task7::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);

    QList<int> queue;
    const int queueSize = 15;
    QRandomGenerator randomGenerator;
    for (int i = 0; i < queueSize; ++i) {
        int randomNumber = randomGenerator.bounded(1, 100);
        queue.append(randomNumber);
    }

    QString outputText = "Начальная очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }
    int maxElement = queue.first();
    int minElement = queue.first();
    for (const int& number : queue) {
        if (number > maxElement) {
            maxElement = number;
        }
        if (number < minElement) {
            minElement = number;
        }
    }
    int maxIndex = queue.indexOf(maxElement);
    int minIndex = queue.indexOf(minElement);
    int start = (maxIndex > minIndex) ? minIndex : maxIndex;
    int end = (maxIndex > minIndex) ? maxIndex : minIndex;

    QList<int> firstRing = queue.mid(start + 1, end - start - 1);

    QList<int> secondRing = queue;
    secondRing.remove(start + 1, end - start - 1);


    outputText += "Первое кольцо:\n";
    for (const int& number : firstRing) {
        outputText += QString::number(number) + "\n";
    }
    outputText += "\nВторое кольцо:\n";
    for (const int& number : secondRing) {
        outputText += QString::number(number) + "\n";
    }

    textEdit.setPlainText(outputText);

    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();
}
