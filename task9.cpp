#include "task9.h"

task9::task9()
{

}
int task9::Main(QApplication *app){
    QWidget window;
    QTextEdit textEdit(&window);

    QList<QString> programQueue;
    programQueue.append("First");
    programQueue.append("Second");


    programQueue.append(programQueue.takeFirst());


    QString programText;
    for (const QString& line : programQueue) {
        programText += line + "\n";
    }
    textEdit.setPlainText(programText);


    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        programQueue.append(programQueue.takeFirst());
        QString updatedProgramText;
        for (const QString& line : programQueue) {
            updatedProgramText += line + "\n";
        }
        textEdit.setPlainText(updatedProgramText);
    });
    timer.start(2000);

    window.setGeometry(100, 100, 300, 200);
    window.show();
     return app->exec();
}
