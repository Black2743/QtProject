#include <QApplication>
#include <QDebug>
#include <QQueue>
#include <QTextEdit>
#include <QWidget>
#include <QRandomGenerator>
#ifndef TASK12_H
#define TASK12_H


class task12
{
public:
    task12();
    void swapMinMax(QQueue<int>& queue);
    int Main(QApplication *app);
};

#endif // TASK12_H
