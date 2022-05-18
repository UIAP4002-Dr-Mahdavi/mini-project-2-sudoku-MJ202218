#include "main_game.h"
#include "ui_main_game.h"

main_game::main_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_game)
{
    ui->setupUi(this);
}

main_game::~main_game()
{
    delete ui;
}
