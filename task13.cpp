#include "task13.h"

task13::task13()
{

}
int task13::Main(QApplication *app){
    QQueue<QImage> imageQueue;

    //менять путь нужно вот тут
    imageQueue.enqueue(QImage("C:/Users/gadzi/OneDrive/Документы/QtProjects/images/img1.png"));
    imageQueue.enqueue(QImage("C:/Users/gadzi/OneDrive/Документы/QtProjects/images/img2.png"));
    imageQueue.enqueue(QImage("C:/Users/gadzi/OneDrive/Документы/QtProjects/images/img3.png"));
    imageQueue.enqueue(QImage("C:/Users/gadzi/OneDrive/Документы/QtProjects/images/img4.png"));

     imageQueue.enqueue(imageQueue.dequeue());
    QLabel label;
    label.setFixedSize(800, 600);
    label.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        QImage image = imageQueue.dequeue();
        label.setPixmap(QPixmap::fromImage(image));
        imageQueue.enqueue(image);
    });

    timer.start(1000);
    return app->exec();
}
