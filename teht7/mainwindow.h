#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout();

private slots:



    void peliaika2min();

    void peliaika5min();

private:
    Ui::MainWindow *ui;
    QLabel *gameInfoLabel;
    QTimer *pTimer;
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;

    void updateProgressBar();
    void setGameInfoText(QString text,short fontSize);
    void startGameButton();
    void stopGameButton();
    void switchTurns();

};
#endif // MAINWINDOW_H
