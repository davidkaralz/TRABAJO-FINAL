#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>
#include <cmath>

using namespace std;

class Particle : public QGraphicsItem //Se crea la clase particle
{
public:
    Particle();

private:
    float x;
    float y;
    float radius;
    float vx, vy;

public:
    Particle(float ix, float iy, float ir,float VX,float VY):
        x(ix), y(iy), radius(ir){ vx = VX; vy = VY; }     //Se construye particula con posiciones iniciales, radio y velocidades

    void move(float t, float vert_limit,float m);       //Funcion que posiciona la particula
    void collide(float hor_limit, float vert_limit,float t);//Funcion que decide la velocidad cuando hay colisiones
    void setVelocity(float ivx, float ivy){vx = ivx; vy = ivy;}     //Funcion para cargar la velocidad
    void setPosition(float ix, float iy){ x = ix; y = iy;} //Funcion que dice la posicion


    float getRadius(){return radius;}            //Funciones que obtienen valores
    float getX(){return x;}
    float getY(){return y;}
    float getVx(float t){//Funcion que retorna la velocidad en X cuando se considera el coeficiente de amortiguamiento del aire
        float c=0.47,m=7,g=9.8,e=2.78;
        float exp=(-c*(t))/m;
        vx=vx*pow(e,exp);
        return vx;}
    float getVy(float t){//Funcion que retorna la velocidad en Y cuando se considera el coeficiente de amortiguamiento del aire
        float c=0.47,m=7,g=9.8,e=2.78;
        float exp=(-c*(t))/m;
        vy=((-m*g/c)+(vy+(m*g/c))*(pow(e,exp)));
        return vy;}

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PARTICLE_H
