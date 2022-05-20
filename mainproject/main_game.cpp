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

class random_num{
public:
    int n1 = 0, n2 = 0 , row = 0,column = 0;

    int rand1(){
        srand(time(0));
        int number = rand()%5 + 1;
        return number;
    }

    void rand2(){
        int howmany = 0 ;
        bool random_check;
        bool square_33 = true;
        srand(time(0));

     howmany = rand1();

     int *check_repeat_row = new int [howmany];
     int *check_repeat_column = new int [howmany];
     for (int j =0 ;j<howmany;j++){
         check_repeat_row[j]=-1;
         check_repeat_column[j]=-1;
     }
     for (int i=0;i<howmany;i++){
         do {
             square_33 = true;
             while (square_33){
             row = rand()%9;
             column = rand1()%9;
             if (row /3 == n1 && column / 3 == n2){
                 square_33 = false;
                 n2++;
                 if (n2 == 3){
                     n1 ++;
                     n2 == 0;
                 }
             }
             }
             random_check = false;
             for (int j =0 ; j<howmany ; j++){

                 if (row == check_repeat_row[j] && column == check_repeat_column[j] ){

                     random_check = true;
                 }
             }

         }
         while (random_check);
         for (int z = 0 ; z<howmany; z++){
             if(check_repeat_row[z] == -1){
                 check_repeat_row [z]= row;
                 break;
             }

         }
         for (int z = 0 ; z<howmany; z++){
             if(check_repeat_column[z] == -1){
                 check_repeat_column [z]= column;
                 break;
             }

         }
         rand3 ();

     }
    delete []check_repeat_row;
     delete []check_repeat_column;
    }

    int rand3 (){
        srand(time(0));
        int number_of_cells;
        bool ch_row = true;
        bool ch_column  = true;
        bool ch_square33 = true;
        while (ch_row == true || ch_column == true || ch_square33 == true){

         number_of_cells= rand1()% 9 +1;
         QString s = QString::number(number_of_cells);
         cells[row][column] = s;
          ch_row =check.check_row(row , column);
          ch_column = check.check_column(row , column);
          ch_square33 = check.check_square(row , column);
        }
       return -1 ;
    }

};
main_game::main_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_game)
{


    ui->setupUi(this);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cells [i][j]="-1" ;
        }

    }
    random_num random_rand;
    random_rand.rand2();
    for (int ij=0;ij<9;ij++){
        for (int ji =0;ji<9 ;ji++){
            if (cells[ij][ji] != "-1"){
              ui->tableWidget->item(ij,ji)->setText(cells[ij][ji]);
            }
        }
    }
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


















