#include "task4.h"

task4::task4()
{

}
void task4::printQueue(const QList<int> &queue)
{
    qDebug() << "Отсартированная очередь:";
    for (int num : queue) {
        qDebug() << num;
    }
}

void task4::sortQueue(QList<int> &list)
{
    int n = list.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}


int task4::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);

    QList<int> queue;

    for (int i = 0; i < 10; ++i) {
        queue.append(QRandomGenerator::global()->bounded(101));
    }

    QString outputText = "Начальная очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }

    sortQueue(queue);
    outputText += "Итоговая очередь:\n";
    for (const int& number : queue) {
        outputText += QString::number(number) + "\n";
    }
    textEdit.setPlainText(outputText);
    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();

}
