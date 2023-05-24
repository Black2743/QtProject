#include "task14.h"

task14::task14()
{

}
int task14::Main(QApplication *app){
    QWidget window;
    window.setWindowTitle("Circular Queue");
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QPushButton *prevButton = new QPushButton("Previous", &window);
    QPushButton *nextButton = new QPushButton("Next", &window);
    layout->addWidget(prevButton);
    layout->addWidget(nextButton);

    QDial *gauge = new QDial(&window);
    QLabel *label = new QLabel(&window);
    layout->addWidget(gauge);
    layout->addWidget(label);

    QQueue<int> queue;
    QRandomGenerator randomGenerator;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = randomGenerator.bounded(1, 100);
        queue.enqueue(randomNumber);
    }

    int currentIndex = 0;
    int queueSize = queue.size();
    queue.enqueue(queue.dequeue());


    gauge->setMinimum(0);
    gauge->setMaximum(queueSize - 1);
    gauge->setValue(currentIndex);
    label->setText(QString::number(queue.at(currentIndex)));

    QObject::connect(prevButton, &QPushButton::clicked, [&]() {
        currentIndex = (currentIndex - 1 + queueSize) % queueSize;
        gauge->setValue(currentIndex);
        label->setText(QString::number(queue.at(currentIndex)));
    });

    QObject::connect(nextButton, &QPushButton::clicked, [&]() {
        currentIndex = (currentIndex + 1) % queueSize;
        gauge->setValue(currentIndex);
        label->setText(QString::number(queue.at(currentIndex)));
    });

    window.show();
    return app->exec();
}
