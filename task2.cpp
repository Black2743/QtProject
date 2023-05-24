#include "task2.h"

task2::task2()
{

}

void task2::insertQueue(QQueue<int> *q1, QQueue<int> *q2){
    int maxElement = q1->front();

    QQueue<int> tempQueue;


    while (!q1->empty()) {
        if (q1->front() > maxElement) {
            maxElement = q1->front();
        }
        else {
            tempQueue.enqueue(q1->front());
        }
        q1->dequeue();
    }

    q1->enqueue(maxElement);


    while (!q2->empty()) {
        q1->enqueue(q2->front());
        q2->dequeue();
    }


    while (!tempQueue.empty()) {
        q1->enqueue(tempQueue.front());
        tempQueue.dequeue();
    }
}
int task2::Main(QApplication *app){

    QWidget window;
    QTextEdit textEdit(&window);

    QQueue<int> queue1;
    QQueue<int> queue2;

    QRandomGenerator randomGenerator;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = randomGenerator.bounded(1, 101);
        queue1.enqueue(randomNumber);
        randomNumber = randomGenerator.bounded(1, 101);
        queue2.enqueue(randomNumber);
    }


    qDebug() << "Очередь 1:" << queue1;
    qDebug() << "Очередь 2:" << queue2;

    QString outputText = "Первая очередь:\n";
    for (const int& number : queue1) {
        outputText += QString::number(number) + "\n";
    }
    outputText += "Вторая очередь:\n";
    for (const int& number : queue2) {
        outputText += QString::number(number) + "\n";
    }
    insertQueue(&queue1, &queue2);

    outputText += "Итоговая очередь:\n";
    for (const int& number : queue1) {
        outputText += QString::number(number) + "\n";
    }

    textEdit.setPlainText(outputText);
    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();
}
