#include "mainwindow.h"
#include "ui_mainwindow.h"

#define _READ_ALL_FILETEXT_ QTextStream
#define _FILE_STREAM_ QFile

BOOL isStudent = false;

//template<class QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//template<class QString>
MainWindow::~MainWindow()
{
    delete ui;
}


//если radioButton - Я учитель
//template<class QString>
void MainWindow::LogCheckTheacher(const QString Log, const QString Pass)
{
    QString Filelog, Filepass;
    bool check{};
    _FILE_STREAM_ stream ("LOGINANDREGtheacher.txt");
    stream.open(QIODevice::ReadOnly | QIODevice::Text);
     _READ_ALL_FILETEXT_ line(&stream);
        while (!line.atEnd()){
        Filelog = line.readLine();
        Filepass = line.readLine();
        if (Filelog == Log && Filepass == Pass){
            check = true;
            break;
        }
        else{
            check = false;
        }
}
        if (check == true){
            ui->WrongBar->hide();
            this->close();
            QMessageBox::information(this,"Window", "Open Theacher window");
            //открываем окно..
        }
        else
        {
            ui->WrongBar->setStyleSheet("background-color: rgb(250, 235, 234); border: rgb(238, 173, 169); color: 13px black");
            ui->WrongBar->setText("Неверный логин или пароль");
            ui->WrongBar->show();
        }
}
//если radiobutton -  Я ученик
//template<class QString>
void MainWindow::LogCheckStudent(const QString Log, const QString Pass)
{
    QString Filelog, Filepass;
    bool check{};
    _FILE_STREAM_ stream ("LOGINANDREGstudent.txt");
    stream.open(QIODevice::ReadOnly | QIODevice::Text);
     _READ_ALL_FILETEXT_ line(&stream);
        while (!line.atEnd()){
        Filelog = line.readLine();
        Filepass = line.readLine();

        if (Filelog == Log && Filepass == Pass){
            check = true;
            break;
        }
        else
            check = false;
}
        if (check == true){
            ui->WrongBar->hide();
            this->close();
            QMessageBox::information(this,"Window", "Open Student window");
            // открываем окно
        }
        else
        {
            ui->WrongBar->setStyleSheet("background-color: rgb(250, 235, 234); border: rgb(238, 173, 169); color: 13px black");
            ui->WrongBar->setText("Неверный логин или пароль");
            ui->WrongBar->show();
        }
}

//Передача параметров в зависимости от учителя или ученика
//template<class QString>
void MainWindow::ParentLogCheck(const QString Log, const QString Pass, BOOL &isStud)
{
        if (isStud == true)
            MainWindow::LogCheckStudent(Log, Pass);
        else if (isStud == false)
            MainWindow::LogCheckTheacher(Log, Pass);
}

//template<class QString>
void MainWindow::on_pushButton_clicked() noexcept
{
    QString Login = ui->LoginLine->text();
    QString Password = ui->PasswordLine->text();
    MainWindow::ParentLogCheck(Login, Password, isStudent);
}

//template<class QStringing>
void MainWindow::ParentRegInput(QString Log, QString Pass, BOOL &isStud)
{
    if (isStud == true)
        MainWindow::RegInputStudent(Log,Pass);
    else if (isStud == false)
        MainWindow::RegInputTheacher(Log, Pass);
}

//template<class QString>
void MainWindow::RegInputTheacher(QString Log, QString Pass)
{
    _FILE_STREAM_ stream("LOGINANDREGtheacher.txt");
    if (stream.open(QIODevice::Append | QIODevice::ReadWrite))
    {
            QTextStream file(&stream);
            file << Log << Pass;
    }
}

//template<class QString>
void MainWindow::RegInputStudent(QString Log, QString Pass)
{
    _FILE_STREAM_ stream ("LOGINANDREGstudent.txt");
    if (stream.open(QIODevice::Append | QIODevice::ReadWrite))
    {
            QTextStream file(&stream);
            file << Log << Pass;
    }
}

//template<class QString>
void MainWindow::on_RegButton_clicked() noexcept
{
    QString Login = ui->LoginLine->text();
    QString Password = ui->PasswordLine->text();
    if (Login.length() > 5 && Password.length() > 5){
           ui->WrongBar->hide();
           if (ui->radioTeacher->isChecked()) { isStudent = false; ParentRegInput(Login, Password, isStudent); }
           else if (ui->radioStudent->isChecked()) { isStudent = true; ParentRegInput(Login, Password, isStudent);}
       }
       else{
           ui->WrongBar->setStyleSheet("background-color: rgb(250, 235, 234); border: rgb(238, 173, 169); color: 13px black");
           ui->WrongBar->setText("More 5 characters!");
    }
}
