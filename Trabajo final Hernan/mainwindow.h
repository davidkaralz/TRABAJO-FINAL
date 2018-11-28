#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include "particle.h"

#define WIDTH 1000
#define HEIGHT 500
#define DT 0.1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);//Funcion que genera el grafico
    ~MainWindow();

private slots:
    void on_pushButton_clicked();//Funcion para cuando se da clic en botos Simular
    void update_scene();//Funcion que actualiza lo mostrado en pantalla

private:
    Ui::MainWindow *ui;
    QTimer *timer = nullptr;
    QGraphicsScene *scene = nullptr;
    Particle *particle = nullptr;

};

#endif // MAINWINDOW_H
