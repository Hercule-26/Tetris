#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Util/Observer.h"
#include "Model/Game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Tetris;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public util::Observer
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * @brief startGame
     * Start game, initialise game
     */
    void startGame();
    /**
     * @brief optionMenu
     * Display the menu option
     */
    void optionMenu();
    /**
     * @brief get_shape_color
     * @param id
     * @return color word for the id
     */
    std::string get_shape_color(int id) const;
    /**
     * @brief auto_increment
     * Connected to the QTimer, each time the shape down
     */
    void auto_increment();
    /**
     * @brief update
     */
    void update() override;
private:
    Ui::Tetris *ui;
    model::Game *game;
    QTimer *timer;
    QMovie *movie;

    /**
     * @brief display_board
     */
    void display_board();
    /**
     * @brief display_next_shape
     */
    void display_next_shape();

    /**
     * @brief timerSave
     * Save curent time for changed the next timer
     */
    double timerSave;
};
#endif // MAINWINDOW_H
