#include "main_game.h"
#include "ui_main_game.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QtDebug>
#include <QDateTime>
FILE *info;
class userpass{
public:
    QString name;
    QString username;
    QString password;

};

QString cells[9][9];
class Check{
public:
    // return false if find repeatation, if not return true
    bool check_row(int row,int column)
    {
        for (int j = 0; j<9 ;j++){
            if (cells[row][j] != "-1"){
                if (j != column ){
                    if (cells[row][column] == cells[row][j] )return true;
                }
            }
        }
        return false;

    }
    // return false if find repeatation, if not return true
    bool check_column(int row, int column){

        for (int i = 0; i<9 ;i++){
            if (cells[i][column] != "-1"){
                if (i != row ){
                    if (cells[row][column] == cells[i][column] )return true;
                }
            }
        }
        return false;


    }
    bool check_square (int row, int column){


        if (column>=0 && column<3){
            if (row >=0 && row <3){

                for (int i = 0; i<3 ; i++){

                    for(int j=0; j<3; j++){
                        if (cells[i][j]== "-1" || (i == row && j == column))continue;
                       if (cells[row][column] == cells [i][j])return true;
                    }
                }
                return false;
            }

            if (row >=3 && row <6){
                for (int i=3 ;i <6;i++){
                    for (int j =0;j<3;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

            if (row >=6 && row <9){
                for (int i =6 ;i<9;i++){
                    for (int j=0 ;j<3;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

        }


        if (column>=3 && column<6){

            if (row >=0 && row <3){

                for (int i = 0; i<3 ; i++){

                    for(int j=3; j<6; j++){
                        if (cells[i][j]== "-1" || (i == row && j == column))continue;
                       if (cells[row][column] == cells [i][j])return true;
                    }
                }
                return false;

            }

            if (row >=3 && row <6){
                for (int i=3 ;i <6;i++){
                    for (int j =3;j<6;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

            if (row >=6 && row <9){
                for (int i =6 ;i<9;i++){
                    for (int j=3 ;j<6;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

        }

        if (column >= 6 && column <9){

            if (row >=0 && row <3){

                for (int i = 0; i<3 ; i++){

                    for(int j=6; j<9; j++){
                        if (cells[i][j]== "-1" || (i == row && j == column))continue;
                       if (cells[row][column] == cells [i][j])return true;
                    }
                }
                return false;

            }

            if (row >=3 && row <6){
                for (int i=3 ;i <6;i++){
                    for (int j =6;j<9;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

            if (row >=6 && row <9){
                for (int i =6 ;i<9;i++){
                    for (int j=6 ;j<9;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }


        }
    }
};
Check check;

main_game::main_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_game)
{


    ui->setupUi(this);
    ui->lineEdit->setText(" GUIDE");
   timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
   timer->start(1000);
    userpass information;
    int number_of_players = 0;
    fopen_s(&info, "Information.dat", "rb");

    if (!info) {
        exit(0);

    }

    fread(&information, sizeof(userpass), 1, info);
    while (!feof(info)) {

        number_of_players ++ ;
        fread(&information, sizeof(userpass), 1, info);


    }
    fclose(info);
    QString s =QString::number(number_of_players);
    fopen_s(&info, "Information.dat", "a+b");
    fseek(info,(number_of_players-1)*sizeof(userpass),-SEEK_SET);
    fread(&information, sizeof(userpass), 1, info);
    fclose(info);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cells [i][j]="-1" ;
        }

    }

}

//class check the table
// tekrari = return true no tekrari = return false



main_game::~main_game()
{
    delete ui;
}


void main_game::on_tableWidget_cellChanged(int row, int column)

{

    bool ckeck_row_t = true;
    bool check_column_t = true;
    bool check_square = true;
    cells[row][column] =  ui->tableWidget->item(row,column)->text();
    ckeck_row_t = check.check_row(row,column);
    check_column_t = check.check_column(row , column);
    check_square =check.check_square(row,column);
    if (ckeck_row_t == true || check_column_t == true || check_square == true){
        cells[row][column] =  ui->tableWidget->item(row,column)->text();
        ui->lineEdit->setText(" GUIDE : You Can't Choose This Number :(");
        ckeck_row_t = check.check_row(row,column);
        check_column_t = check.check_column(row , column);
        check_square =check.check_square(row,column);


    }
    else ui->lineEdit->setText(" GUIDE");


}

void main_game::myfunction()
{
       QTime time = QTime::currentTime();
       QString time_text = time.toString("hh : mm : ss");

       ui->Datetime->setText("                                                                                       "+time_text);

}



















