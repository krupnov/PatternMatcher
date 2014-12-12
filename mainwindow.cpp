#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputparser.h"
#include "letterpoint.h"
#include "wordfinder.h"

#include <QMessageBox>
#include <QFileDialog>
#include <stdexcept>
#include <stack>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл с данными", "~");
    if (fileName == NULL || fileName.size() == 0)
    {
        return;
    }
    try
    {
        letterMatrix = inputparser::parseInputFile(fileName.toStdString());
        ui->tableWidget->setRowCount(letterMatrix.size());
        ui->tableWidget->setColumnCount(letterMatrix.at(0).size());
        for (size_t i = 0 ; i < letterMatrix.size() ; ++i)
        {
            for (size_t j = 0 ; j < letterMatrix.at(i).size() ; ++j)
            {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromWCharArray(&letterMatrix.at(i).at(j), 1)));
            }
        }
    }
    catch (std::invalid_argument& )
    {
        QMessageBox::information(this, "Предупреждание", "Невозможно загрузить файл", QMessageBox::Ok);
    }
}

void MainWindow::on_searchButton_clicked()
{
    refreshTableWidget();
    std::wstring pattern = ui->patternEdit->text().toStdWString();
    if (pattern.empty() || letterMatrix.empty()) {
        QMessageBox::information(this, "Предупреждание", "Не заполнены все необходимые поля", QMessageBox::Ok);
        return;
    }
    std::stack<LetterPoint> path;
    if (WordFinder::findPattern(letterMatrix, pattern, path))
    {
        while (!path.empty())
        {
            const LetterPoint& point = path.top();
            ui->tableWidget->item(point.getX(), point.getY())->setBackgroundColor(Qt::red);
            path.pop();
        };
    }
    else
    {
        QMessageBox::information(this, "Сообщение", "Невозможно найти вхождение строки в матрицу", QMessageBox::Ok);
    }
}

void MainWindow::refreshTableWidget()
{
    for (int i = 0 ; i < ui->tableWidget->rowCount() ; ++i)
    {
        for (int j = 0 ; j < ui->tableWidget->columnCount() ; ++j)
        {
            ui->tableWidget->item(i, j)->setBackgroundColor(Qt::white);
        }
    }
}
