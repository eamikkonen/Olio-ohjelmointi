#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameInfoLabel = ui->infoText;
    pTimer = new QTimer(this);
    gameTime = 0;

    connect (pTimer, &QTimer::timeout, this, &MainWindow::timeout);
    connect(ui->gameStartButton, &QPushButton::clicked, this, &MainWindow::startGameButton);
    connect(ui->gameStopButton, &QPushButton::clicked, this, &MainWindow::stopGameButton);
    connect(ui->gameTime2min, &QPushButton::clicked, this, &MainWindow::peliaika2min);
    connect(ui->gameTime5min, &QPushButton::clicked, this, &MainWindow::peliaika5min);
    connect(ui->player1SwitchButton, &QPushButton::clicked, this, &MainWindow::switchTurns);
    connect(ui->player2SwitchButton, &QPushButton::clicked, this, &MainWindow::switchTurns);
    connect(ui->player1progressBar, &QProgressBar::valueChanged, this, &MainWindow::updateProgressBar);
    connect(ui->player2progressBar, &QProgressBar::valueChanged, this, &MainWindow::updateProgressBar);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGameInfoText(QString text, short fontSize) {
    ui->infoText->setText(text);
}

void MainWindow::switchTurns() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if ((currentPlayer == 1 && sender() != ui->player1SwitchButton) ||
        (currentPlayer == 2 && sender() != ui->player2SwitchButton)) {
        return;
    }

    currentPlayer = (currentPlayer == 1) ? 2 : 1;

    updateProgressBar();
}

void MainWindow::timeout(){
    if (currentPlayer == 1) {
        player1Time--;
    } else {
        player2Time--;
    }

    updateProgressBar();

    if (player1Time <= 0 || player2Time <= 0){
        pTimer->stop();

        if (player1Time <= 0) {
            setGameInfoText("Pelaaja kakkonen epic victory royale!", 12);
        } else {
            setGameInfoText("Pelaaja ygy epic win moment!", 12);
        }
    }
}





void MainWindow::updateProgressBar() {
    ui->player1progressBar->setValue(player1Time);
    ui->player2progressBar->setValue(player2Time);
}


void MainWindow::startGameButton() {

    currentPlayer = 1;
    short gameDuration = gameTime;

    if (gameDuration <= 0){
        setGameInfoText("Valitse pelille aika", 30);
        qDebug() << "peliaika <= 0";
        return;
    }

    player1Time = player2Time = gameDuration;

    ui->player1progressBar->setMaximum(gameDuration);
    ui->player2progressBar->setMaximum(gameDuration);
    ui->player1progressBar->setValue(gameDuration);
    ui->player2progressBar->setValue(gameDuration);

    pTimer->start(1000);

    setGameInfoText("Peli alkanut! gaming time", 30);
}

void MainWindow::stopGameButton(){

    pTimer->stop();

    player1Time = player2Time = 0;

    ui->player1progressBar->setValue(ui->player1progressBar->maximum());
    ui->player2progressBar->setValue(ui->player2progressBar->maximum());

    updateProgressBar();

    setGameInfoText("Select playtime and press start game!", 12);
}



void MainWindow::peliaika2min()
{
    qDebug() << "2min painettu";
    gameTime = 120;
}


void MainWindow::peliaika5min()
{
    qDebug() << "5min painettu";
    gameTime = 300;
}

