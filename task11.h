#include <QApplication>
#include <QDebug>
#include <QQueue>
#include <QTextEdit>
#include <QWidget>
#include <QRandomGenerator>
#ifndef TASK11_H
#define TASK11_H


class task11
{
public:
    task11();
    int Main(QApplication *app);
    void removeDuplicates(QQueue<int>& queue);
};

#endif // TASK11_H
