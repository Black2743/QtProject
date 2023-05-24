#include "task12.h"

task12::task12()
{

}

void task12::swapMinMax(QQueue<int>& queue) {
    if (queue.isEmpty())
        return;

    int minIndex = 0;
    int maxIndex = 0;
    int minValue = queue.first();
    int maxValue = queue.first();

    for (int i = 0; i < queue.size(); ++i) {
        int value = queue.at(i);
        if (value < minValue) {
            minValue = value;
            minIndex = i;
        } else if (value > maxValue) {
            maxValue = value;
            maxIndex = i;
        }
    }

    int temp = queue.at(minIndex);
    queue.replace(minIndex, queue.at(maxIndex));
    queue.replace(maxIndex, temp);
}
int task12::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);

    QQueue<int> queue;
    QRandomGenerator randomGenerator;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = randomGenerator.bounded(1, 101);
        queue.enqueue(randomNumber);
    }
    QString outputText = "Начальная очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }

    swapMinMax(queue);

    outputText += "Итоговая очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }

    textEdit.setPlainText(outputText);
    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();
}
