#include "task3.h"

task3::task3()
{

}

int task3::getRandomNumber(int min, int max) {
    return  QRandomGenerator::global()->bounded(min, max + 1);
}


void task3::removeBetweenMinMax(QList<int>& queue) {
    if (queue.isEmpty()) {
        return;
    }

    int minValue = queue.first();
    int maxValue = queue.first();
    for (const auto& element : queue) {
        if (element < minValue) {
            minValue = element;
        }
        if (element > maxValue) {
            maxValue = element;
        }
    }

    bool remove = false;
    QList<int>::iterator it = queue.begin();
    while (it != queue.end()) {
        if (*it == minValue) {
            remove = true;
        }
        if (remove) {
            it = queue.erase(it);
        } else {
            ++it;
        }
        if (*it == maxValue) {
            break;
        }
    }
}

int task3::Main(QApplication *app)
{
    QWidget window;
    QTextEdit textEdit(&window);
    QList<int> myQueue;

    for (int i = 0; i < 10; ++i) {
        int randomNumber = getRandomNumber(1, 100);
        myQueue.append(randomNumber);
    }

    QString outputText = "Исходная очередь:\n";
    for (const int& number : myQueue) {
        outputText += QString::number(number) + "\n";
    }

    removeBetweenMinMax(myQueue);

    outputText += "Итоговая очередь:\n";
    for (const int& number : myQueue) {
        outputText += QString::number(number) + "\n";
    }
    textEdit.setPlainText(outputText);
    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();

}
