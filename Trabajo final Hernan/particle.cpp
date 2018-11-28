#include "particle.h"
#include <cmath>
Particle::Particle()
{

}


void Particle::move(float t, float vert_limit,float m)
{

    float c=0.47,g=9.8,e=2.78;
    float exp=(-c*(t))/m;

    x+=((m/c)*vx)*(1-pow(e,exp));
    vx=getVx(t);
    y+=((-m*g/c)*(t))+((m/c)*(vy+((m*g)/c))*(1-pow(e,exp)));
    vy=getVy(t);


    setPos(getX(), (vert_limit - getY()));      //Consequence of the coordinates system
}

void Particle::collide(float hor_limit, float vert_limit,float t)
{

    if (getX() < getRadius() || getX()>(hor_limit - getRadius())){
        setVelocity(-0.7*getVx(t), getVy(t));
    }
    if (getY() < getRadius() || getY()>(vert_limit - getRadius())){
        setVelocity(getVx(t), -0.7*getVy(t));
    }
}

QRectF Particle::boundingRect() const
{
    float r = radius;
    return QRectF(-1.0*r, -1.0*r, 2.0*r, 2.0*r);
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);           //Paint particle
    painter->drawEllipse(boundingRect());       //Draw ellipse within bounding

}
