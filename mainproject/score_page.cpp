#include "score_page.h"
#include <iostream>
#include "ui_score_page.h"
#include <QString>
#include <QFile>
#include <string>
#include <QTextStream>
#include <QMessageBox>
FILE *info1;
FILE *info2;
class username{
public:
    QString name;
    int score;
 };
QString convert_to_string(int number){
    QString s = QString::number(number);
    return s;
};
int sort_function(int number_of_playes , username players[]){
    username temp;
    for (int i =0; i <number_of_playes - 1;i++){

        for (int j=0;j<number_of_playes-1-j;j++){
            if (players[j].score < players[j+1].score){
                temp = players[j];
                players[j] =players[j+1];
                players[j+1] = temp;
            }
        }
    }
    return 0;

};
score_page::score_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::score_page)
{
    ui->setupUi(this);

    username information;
    int number_of_players = 0;
    fopen_s(&info1, "shomaresh.txt", "r");

    if (!info1) {
        exit(0);

    }

     fread(&number_of_players, sizeof(int), 1, info1);

   while (!feof(info1)) {

      fread(&number_of_players, sizeof(int), 1, info1);


  }
  fclose(info1);


    username *players = new username [number_of_players];
    int i =0 ;
//    fopen_s(&info1, "Information.txt", "r");

//    if (!info1) {
//        exit(0);

//    }

//    fread(&information, sizeof(username), 1, info1);
//    players[i]=information;
//    i++;
//    while (!feof(info1)) {

//        fread(&information, sizeof(username), 1, info1);
//        players[i]=information;
//        i++;


//    }
//    fclose(info1);

   sort_function(number_of_players,players);
//    i = 0;
//    fopen_s(&info2, "Information_2.txt", "a");
//    fclose(info2);
//    fopen_s(&info2, "Information_2.txt", "r+");
//      for (int j = 0;j <number_of_players;j++){
//          information = players[j];

//    fwrite(&information, sizeof(username), 1, info2);
//}
//    fclose(info2);
    QFile file ("file.txt");

    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file);

    ui->textBrowser->setText(in.readAll());
    file.close();

}

score_page::~score_page()
{
    delete ui;
}
