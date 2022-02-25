#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <windows.h>
#include "macros_decl.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//template<class QString>
class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ParentLogCheck(const QString Log, const QString Pass, BOOL &isStud); //распределяет для проверки учитель или ученик
    void on_pushButton_clicked() noexcept; // слот(при нажатии на кнопку вызовет метод)
    void on_RegButton_clicked() noexcept; // аналогично
    void ParentRegInput(const QString Log, const QString Pass, BOOL &isStud); // распределяет для ввода учитель или ученик
    void LogCheckTheacher(const QString Log, const QString Pass); // Проверяет учителя в базе данных
    void LogCheckStudent(const QString Log, const QString Pass); // Проверяет студента в базе данных
    void RegInputTheacher(const QString Log, const QString Pass); // Вводит учителя в отдельную базу данных
    void RegInputStudent(const QString Log, const QString Pass); // Вводит студента в отдельную базу данных

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
