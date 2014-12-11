#include "mainwindow.h"
#include"wordfinder.h"
#include "common.h"
#include "inputparser.h"
#include <QApplication>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <locale>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    return 0;
}