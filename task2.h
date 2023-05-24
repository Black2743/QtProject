#include <QQueue>
#include <QApplication>
#include <QRandomGenerator>
#include <QDebug>
#include <QListWidgetItem>
#include <QTextEdit>
#ifndef TASK2_H
#define TASK2_H


class task2
{
public:
    void insertQueue(QQueue<int>* q1, QQueue<int>* q2);
    task2();
    int Main(QApplication *app);

};

#endif // TASK2_H
