#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Model/Game.h"
#include "Model/Direction.h"
#include "Model/Rotation.h"
#include <QPropertyAnimation>
#include <QPainter>
#include <QMovie>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::Tetris), timer(new QTimer)
{
    this->setWindowIcon(QIcon(":/menumusic/Resources/images/Logo.ico"));
    this->setFixedSize(950, 550);
    ui->setupUi(this);

    ui->Box_Niveau->setValue(1);   ui->Box_Niveau->setRange(1,20);
    ui->Box_Hauteur->setValue(20); ui->Box_Hauteur->setRange(10,30);
    ui->Box_Largeur->setValue(10); ui->Box_Largeur->setRange(10,30);

    connect(ui->Start, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->Exit, &QPushButton::clicked, this, &QApplication::quit);
    connect(ui->end_exit, &QPushButton::clicked, this, &QApplication::quit);
    connect(ui->Option, &QPushButton::clicked,this,&MainWindow::optionMenu);
    connect(ui->BackMenu, &QPushButton::clicked,this,&MainWindow::optionMenu);


    ui->widget->setVisible(false);
    ui->TetrisScreen->setVisible(false);
    ui->TetrisGameOver->setVisible(false);
    movie = new QMovie(":/menumusic/Resources/images/bg2.gif");
    ui->backGround->setMovie(movie);
    ui->backGround->setScaledContents(true);
    movie->start();


}

void MainWindow::auto_increment() {
    if(!game->is_game_over()){
        game->move_shape_down();
    } else {
        timer->stop();
        QString score = QString::fromStdString(std::to_string(game->get_score()));
        ui->end_score_output->setText(score);
        ui->TetrisScreen->deleteLater();
        ui->TetrisGameOver->setVisible(true);
    }
}

void MainWindow::startGame() {
    int level = ui->Box_Niveau->value();
    int heigth = ui->Box_Hauteur->value();
    int width = ui->Box_Largeur->value();
    bool random_board = ui->random_board->isChecked();

    static model::Game tmp(level, heigth, width);
    game = &tmp;

    timerSave = game->get_tick();
    timer->start(timerSave*1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::auto_increment);

    // Supprime un écran (frame)
    ui->MenuSCreen->deleteLater();

    // Affichage l'écran (frame) visible
    ui->TetrisScreen->setVisible(true);

    ui->board->setSpacing(0);
    ui->board->setContentsMargins(0, 0, 0, 0);
    ui->board->setSizeConstraint(QLayout::SetFixedSize);

    for (int i = 0; i < game->get_board_row(); ++i) {
        for (int j = 0; j < game->get_board_col(); ++j) {
            QLabel *label = new QLabel(" ");
            label->setAlignment(Qt::AlignCenter);
            label->setFixedSize(15, 15);
            ui->board->addWidget(label, i, j);
        }
    }

    ui->next_shape_board->setSpacing(0);
    ui->next_shape_board->setContentsMargins(0, 0, 0, 0);
    ui->next_shape_board->setSizeConstraint(QLayout::SetFixedSize);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QLabel *label = new QLabel(" ");
            label->setAlignment(Qt::AlignCenter);
            label->setFixedSize(15, 15);
            ui->next_shape_board->addWidget(label, i, j);
        }
    }
    if(random_board) game->generateRandomBoard();
    game->Register(this);
    update();
}

void MainWindow::update() {
    QString level = QString::fromStdString(std::to_string(game->get_level()));
    QString score = QString::fromStdString(std::to_string(game->get_score()));
    ui->level_output->setText(level);
    ui->score_output->setText(score);
    display_board();
    display_next_shape();
    if(timerSave != game->get_tick()){
        timerSave = game->get_tick();
        timer->setInterval(timerSave*1000);
    }
}

void MainWindow::display_next_shape() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QWidget* widget = ui->next_shape_board->itemAtPosition(i, j)->widget();
            if (widget) {
                QLabel* label = qobject_cast<QLabel*>(widget);
                if (label) {
                    model::shape::Position pos(i, j+(game->get_board_col()/2)-2);
                    QString styleSheet;
                    if(pos == game->get_next_shape()) {
                        std::string color = get_shape_color(game->get_next_shape().get_id());
                        styleSheet = QString::fromStdString("QLabel { image: url(:/menumusic/Resources/images/" + color + ".png); }");
                    } else {
                        styleSheet = QString::fromStdString("QLabel { background-color: none; }");
                    }
                    label->setStyleSheet(styleSheet);
                }
            }
        }
    }
}

void MainWindow::display_board() {
    for (int i = 0; i < game->get_board_row(); ++i) {
        for (int j = 0; j < game->get_board_col(); ++j) {
            QWidget* widget = ui->board->itemAtPosition(i, j)->widget();
            if (widget) {
                QLabel* label = qobject_cast<QLabel*>(widget);
                if (label) {
                    model::shape::Position pos(i, j);
                    QString styleSheet;
                    if(pos == game->get_curr_shape()) {
                        std::string color = get_shape_color(game->get_curr_shape().get_id());
                        styleSheet = QString::fromStdString("QLabel { image: url(:/menumusic/Resources/images/" + color + ".png); }");
                    } else {
                        if(game->get_board()[i][j] == 0) {
                            styleSheet = "QLabel { background-color: gray; opacity: 0.5; border: 1px solid white; }";
                        } else {
                            std::string color = get_shape_color(game->get_board()[i][j]);
                            styleSheet = QString::fromStdString("QLabel { image: url(:/menumusic/Resources/images/" + color + ".png); }");
                        }
                    }
                    if (label->styleSheet() != styleSheet) {
                        label->setStyleSheet(styleSheet);
                    }
                }
            }
        }
    }
}


void MainWindow::optionMenu(){
    if(ui->MenuSCreen->isVisible()){
        ui->MenuSCreen->setVisible(false);
        ui->widget->setVisible(true);
    } else {
        ui->MenuSCreen->setVisible(true);
        ui->widget->setVisible(false);
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!game->is_game_over()) {
        switch (event->key()) {
            case Qt::Key_Q:
                game->move_shape_l_r(model::Direction::LEFT);
                break;
            case Qt::Key_D:
                game->move_shape_l_r(model::Direction::RIGHT);
                break;
            case Qt::Key_S:
                game->move_shape_down();
                break;
            case Qt::Key_E:
                game->rotate_shape(model::ROTATE_RIGHT);
                break;
            case Qt::Key_A:
                game->rotate_shape(model::ROTATE_RIGHT);
                break;
            case Qt::Key_Space:
                game->drop_shape();
        }
    }
}

/**
 *
 * Name            FG  BG
 * Red             31  41
 * Green           32  42
 * Yellow          33  43
 * Blue            34  44
 * Magenta         35  45
 * Cyan            36  46
 * White           37  47
 *
**/
std::string MainWindow::get_shape_color(int id) const {
    switch(id) {
        case 1 : return "red";
            break;
        case 2 : return "green";
            break;
        case 3 : return "yellow";
            break;
        case 4 : return "blue";
            break;
        case 5 : return "purple";
            break;
        case 6 : return "cyan";
            break;
        case 7 : return "orange";
            break;
        default : return "red";
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
