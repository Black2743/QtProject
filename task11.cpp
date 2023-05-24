#include "task11.h"

task11::task11()
{

}
void task11::removeDuplicates(QQueue<int>& queue) {
    QSet<int> uniqueSet;
    int size = queue.size();

    for (int i = 0; i < size; ++i) {
        int value = queue.dequeue();
        if (!uniqueSet.contains(value)) {
            queue.enqueue(value);
            uniqueSet.insert(value);
        }
    }
}
int task11::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);

    QQueue<int> queue;
    QRandomGenerator randomGenerator;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = randomGenerator.bounded(1, 5);
        queue.enqueue(randomNumber);
    }
    QString outputText = "Начальная очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }

    removeDuplicates(queue);

    outputText += "Итоговая очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }

    textEdit.setPlainText(outputText);
    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();
}
