#include "create_account.h"
#include "ui_create_account.h"
#include <QMessageBox>
#include <iostream>
FILE *Information;

create_account::create_account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::create_account)
{
    ui->setupUi(this);
}

create_account::~create_account()
{
    delete ui;
}

class userpass{
public:
    QString name;
    QString username;
    QString password;
};
void create_account::on_pushButton_clicked()
{userpass information;
    information.name = ui->lineEdit->text();
    information.username =ui->lineEdit_2->text();
    information.password = ui ->lineEdit_3->text();

    //write new members in file
    fopen_s(&Information, "Information.dat", "ab");

    fwrite(&information, sizeof(information), 1, Information);

    fclose(Information);
    maingame = new main_game();
    hide();
    maingame->show();



}
