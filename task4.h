#include <QApplication>
#include <QDebug>
#include <QTextEdit>
#include <QWidget>
#include <QRandomGenerator>
#ifndef TASK4_H
#define TASK4_H


class task4
{
public:
    task4();
    void sortQueue(QList<int> &queue);
    void printQueue(const QList<int> &queue);
    int Main(QApplication *app);
};

#endif // TASK4_H
