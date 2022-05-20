#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class main_game;
}

class main_game : public QDialog
{

    Q_OBJECT

public:
    explicit main_game(QWidget *parent = nullptr);
    ~main_game();

private slots:


    void on_tableWidget_cellChanged(int row, int column);
    void on_pushButton_clicked();

public slots:
    void myfunction();
private:
    Ui::main_game *ui;
    QTimer* timer;
};

#endif // MAIN_GAME_H
