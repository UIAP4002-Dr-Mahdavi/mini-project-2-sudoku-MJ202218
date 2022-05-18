#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include <QDialog>

namespace Ui {
class main_game;
}

class main_game : public QDialog
{
    Q_OBJECT

public:
    explicit main_game(QWidget *parent = nullptr);
    ~main_game();

private:
    Ui::main_game *ui;
};

#endif // MAIN_GAME_H
