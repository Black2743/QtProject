#include "task6.h"

task6::task6()
{

}

int task6::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);


    QQueue<int> queue;
    const int queueSize = 10;
    QRandomGenerator randomGenerator;
    for (int i = 0; i < queueSize; ++i) {
        int randomNumber = randomGenerator.bounded(-10, 10);
        queue.enqueue(randomNumber);
    }


    QString initialQueueText = "Первоначальная очередь:\n";
    for (const int& number : queue) {
        initialQueueText += QString::number(number) + "\n";
    }


    int queueSizeBeforeDeletion = queue.size();
    for (int i = 0; i < queueSizeBeforeDeletion; ++i) {
        int number = queue.dequeue();
        if (number >= 0) {
            queue.enqueue(number);
        }
    }


    QString finalQueueText = "Итоговая очередь:\n";
    for (const int& number : queue) {
        finalQueueText += QString::number(number) + "\n";
    }

    textEdit.setPlainText(initialQueueText + "\n" + finalQueueText);

    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();
}
