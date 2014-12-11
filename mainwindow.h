#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common.h"

#include <string>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();
    void on_searchButton_clicked();

private:
    void refreshTableWidget();

private:
    Ui::MainWindow *ui;

    matrix_type letterMatrix;
    std::wstring pattern;
};

#endif // MAINWINDOW_H
