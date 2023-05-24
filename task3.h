#include <QApplication>
#include <QTextEdit>
#include <QWidget>
#include <QDebug>
#include <QRandomGenerator>

#ifndef TASK3_H
#define TASK3_H


class task3
{
public:
    task3();
    int Main(QApplication *app);

    void removeBetweenMinMax(QList<int>& queue);
    int getRandomNumber(int min, int max);

};

#endif // TASK3_H
