#include "task10.h"

task10::task10()
{

}

int task10::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);

    QList<int> queue1;
    QList<int> queue2;
    QRandomGenerator randomGenerator;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = randomGenerator.bounded(1, 101);
        queue1.append(randomNumber);
        randomNumber = randomGenerator.bounded(1, 101);
        queue2.append(randomNumber);
    }
    QString outputText = "Первая очередь:\n";
    for (const int& number : queue1) {
        outputText += QString::number(number) + "\n";
    }
    outputText += "Вторая очередь:\n";
    for (const int& number : queue2) {
        outputText += QString::number(number) + "\n";
    }

    int maxNum = queue1.first();
    int minNum = queue1.first();
    for (int num : queue1) {
        if (num > maxNum) {
            maxNum = num;
        }
        if (num < minNum) {
            minNum = num;
        }
    }


    int insertPosition = queue1.indexOf(minNum) + 1;
    for (int num : queue2) {
        queue1.insert(insertPosition++, num);
    }
    outputText += "Первая очередь после вставки:\n";
    for (const int& number : queue1) {
        outputText += QString::number(number) + "\n";
    }

    textEdit.setPlainText(outputText);

    window.setGeometry(100, 100, 300, 200);
    window.show();
    return app->exec();


}
