#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <cmath>

float masa,vel,ang,h;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,WIDTH, HEIGHT);

    ui->graphicsView->setScene(scene);          //Link scene with GraphicsView

    scene->addRect(scene->sceneRect());         //Adds a rectangle to limit the scene

    ui->graphicsView->resize(scene->width(), scene->height());  //Adjust GraphicsView to scene dimensions

    this->resize(ui->graphicsView->width()+100, ui->graphicsView->width()+100);     //Resize the main window to be larger than the scene

    connect(timer, SIGNAL(timeout()), this, SLOT(update_scene()));      //Link timeout with update method
}

MainWindow::~MainWindow()
{
    delete ui;
    delete particle;
    delete timer;
    delete scene;

}

void MainWindow::on_pushButton_clicked()
{

    QString m=ui->PESO->text() ;//Se lee valor en casilla de masa
    masa=m.toFloat();//se convierte de Qstring a float
    QString v=ui->Vel->text() ;//Se lee valor en casilla de velocidad
    vel=v.toFloat();//se convierte de Qstring a float
    QString a=ui->ANGULO->text() ;//Se lee valor en casilla de angulo
    ang=a.toFloat();//se convierte de Qstring a float
    ang = (ang*3.1416) / 180;//conversion de angulos a radianes
    QString alt=ui->altura->text() ;//Se lee valor en casilla de altura
    h=alt.toFloat();//se convierte de Qstring a float

    scene->clear();
    particle = new Particle(10, h, 15,vel*cos(ang),vel*sin(ang));      //Se crea particula segun las variables
    scene->addItem(particle);       //Se crea la particula en el grafico
    particle->move(DT, HEIGHT,masa);
    timer->start(30);

}

void MainWindow::update_scene(){
    particle->move(DT, HEIGHT,masa);
    particle->collide(WIDTH, HEIGHT,DT);
}

