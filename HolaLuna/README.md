# Hola_Luna
En este código se explica la caída de un cubo en la gravedad de la la luna
## ¿Qué es la luna?
La Luna es uno de los cuerpos celestes del sistema solar. Es el único satélite de la Tierra y el quinto satélite natural más grande que existe.
## ¿Porque en la luna no hay fricción?
La respuesta es que en la luna no hay **Aire** lo que significa que no hay resistencia cuando caen, al no haber resistencia no hay fricción
## ¿De cuanto es la gravedad en la luna?
En la Luna, la gravedad es de **1,62 m/s**, que sería la velocidad a la que un objeto en caída libre se precipitaría contra su superficie.

## Código
```c
#include <iostream>  
#include <box2d/box2d.h>  
  
int main() {  
    //Creacion del mundo y de la gravedad  
    b2Vec2 gravity(0.0f, -1.62f);  
    b2World world(gravity);  
  
    //Caracteristicas del cuerpo  
    b2BodyDef groundBodyDef;  
    groundBodyDef.position.Set(0.0f, -10.0f);  
    //Creamos el cuerpo  
    b2Body *groundBody = world.CreateBody(&groundBodyDef);  
  
    //Crear la forma  
    b2PolygonShape groundBox;  
    groundBox.SetAsBox(50.0f,1.0f);  
  
    groundBody ->CreateFixture(&groundBox, 0.0f);  
  
    b2BodyDef bodyDef;  
    bodyDef.type = b2_dynamicBody;  
    bodyDef.position.Set(0.0f, 20.f);  
    b2Body* body = world.CreateBody(&bodyDef);  
    b2PolygonShape dynamicBox;  
    dynamicBox.SetAsBox(1.0f,1.0f);  
    b2FixtureDef fixtureDef;  
    fixtureDef.shape = &dynamicBox;  
    fixtureDef.density = 1.0f;  
  
    body ->CreateFixture(&fixtureDef);  
  
    float timeStep = 1.0f/60.0f;  
    int32 velocityIterations = 6;  
    int32 positionIterations = 2;  
  
    for (int32 i = 0; i < 60; ++i)  
    {  
        world.Step(timeStep, velocityIterations, positionIterations);  
        b2Vec2 position = body->GetPosition();  
        float angle = body->GetAngle();  
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);  
  
  
    }  
  
}
```

## Explicación del Código

Este código es muy parecido al de **Hola_Mundo**, solo que este tiene 2 diferencias que explicare a continuación.

Lo principal es que la gravedad cambia, ya que es otro cuerpo, donde la gravedad es de  **1,62 m/s**
```c
   b2Vec2 gravity(0.0f, -1.62f);
```
El otro cambio, es quitar la fricción ya que no existe resistencia en la luna.
```c
 fixtureDef.friction = 0.3f; //Se elimina o se deja en 0.0f
```
Resultado de la simulación!!!!!
```c
E:\Sim_Fisicas_DAHS\HolaLuna\cmake-build-debug-visual-studio\HolaLuna.exe
0.00 20.00 0.00
0.00 20.00 0.00
0.00 20.00 0.00
0.00 20.00 0.00
0.00 19.99 0.00
0.00 19.99 0.00
0.00 19.99 0.00
0.00 19.98 0.00
0.00 19.98 0.00
0.00 19.98 0.00
0.00 19.97 0.00
0.00 19.96 0.00
0.00 19.96 0.00
0.00 19.95 0.00
0.00 19.95 0.00
0.00 19.94 0.00
0.00 19.93 0.00
0.00 19.92 0.00
0.00 19.91 0.00
0.00 19.91 0.00
0.00 19.90 0.00
0.00 19.89 0.00
0.00 19.88 0.00
0.00 19.86 0.00
0.00 19.85 0.00
0.00 19.84 0.00
0.00 19.83 0.00
0.00 19.82 0.00
0.00 19.80 0.00
0.00 19.79 0.00
0.00 19.78 0.00
0.00 19.76 0.00
0.00 19.75 0.00
0.00 19.73 0.00
0.00 19.72 0.00
0.00 19.70 0.00
0.00 19.68 0.00
0.00 19.67 0.00
0.00 19.65 0.00
0.00 19.63 0.00
0.00 19.61 0.00
0.00 19.59 0.00
0.00 19.57 0.00
0.00 19.55 0.00
0.00 19.53 0.00
0.00 19.51 0.00
0.00 19.49 0.00
0.00 19.47 0.00
0.00 19.45 0.00
0.00 19.43 0.00
0.00 19.40 0.00
0.00 19.38 0.00
0.00 19.36 0.00
0.00 19.33 0.00
0.00 19.31 0.00
0.00 19.28 0.00
0.00 19.26 0.00
0.00 19.23 0.00
0.00 19.20 0.00
0.00 19.18 0.00

Process finished with exit code 0
```

