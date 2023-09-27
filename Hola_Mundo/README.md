## Hola_Mundo
En este código se explica la caída de un cubo en la gravedad de la tierra

## ¿Qué es la gravedad?
La gravedad es un fenómeno natural por el cual los objetos con masa son
atraídos entre sí, efecto mayormente observable en la interacción entre los
planetas, galaxias y demás objetos del universo. Es una de las cuatro
interacciones fundamentales que origina la aceleración que experimenta un
cuerpo físico en las cercanías de un objeto astronómico. También se denomina
interacción gravitatoria o gravitación
## ¿Qué es la densidad?
La densidad es una magnitud referida a la cantidad de masa contenida en un determinado volumen, y puede utilizarse en términos absolutos o relativos.
## ¿Qué es la Friccion?
La fricción, fuerza de roce o fuerza de rozamiento es una fuerza existente entre dos superficies que se encuentren en contacto, y que se opone al movimiento, o sea, tiene dirección contraria al movimiento.
## ¿De cuanto es la gravedad en la tierra?
La aceleración de los objetos debido a la gravedad en la Tierra es de alrededor de **9,807 m/s²** . Pero si redondeamos los decimales, quedara **9,81 m/s²**.

## Código

``` c
#include <iostream>
#include <box2d/box2d.h>

int main() {
    //Creacion del mundo y de la gravedad
    b2Vec2 gravity(0.0f, -9.81f);
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
    fixtureDef.friction = 0.3f;

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
## Explicación de Código
Se agrega primero la librería Box2D: 
``` c
#include <iostream>
#include <box2d/box2d.h>
``` 
Después vamos a empezar a crear el mundo(Tierra), donde definimos la gravedad que es -9.81, se pone en negativo porque la gravedad nos jala hacia abajo,
``` c
int main() {
    //Creacion del mundo y de la gravedad
    b2Vec2 gravity(0.0f, -9.81f);
    b2World world(gravity);
```
Ahora las características del cuerpo en el suelo con su posición inicial.
``` c
//Caracteristicas del cuerpo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
```
Se crea un cuerpo rígido con las características del cuerpo.
``` c
  //Creamos el cuerpo
    b2Body *groundBody = world.CreateBody(&groundBodyDef);
```
Podemos crear la forma del suelo, la densidad del suelo y se crea el cubo para poder hacer la simulación de una caída, donde definimos la densidad del cubo , también su fricción y tambien su altura.
``` c
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
    fixtureDef.friction = 0.3f;
```
Solo falta la parte de velocidad de caída para poder hacer la simulación, donde es cada 60 interacciones , para poder saber la posición del cubo.
``` c
for (int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
     }
}
```
Resultado!!!!!! Ya esta la simulación de un cubo en la tierra
``` c
E:\Sim_Fisicas_DAHS\Hola_Mundo\cmake-build-debug-visual-studio\Hola_Mundo.exe
0.00 20.00 0.00
0.00 19.99 0.00
0.00 19.98 0.00
0.00 19.97 0.00
0.00 19.96 0.00
0.00 19.94 0.00
0.00 19.92 0.00
0.00 19.90 0.00
0.00 19.88 0.00
0.00 19.85 0.00
0.00 19.82 0.00
0.00 19.79 0.00
0.00 19.75 0.00
0.00 19.71 0.00
0.00 19.67 0.00
0.00 19.63 0.00
0.00 19.58 0.00
0.00 19.53 0.00
0.00 19.48 0.00
0.00 19.43 0.00
0.00 19.37 0.00
0.00 19.31 0.00
0.00 19.25 0.00
0.00 19.18 0.00
0.00 19.11 0.00
0.00 19.04 0.00
0.00 18.97 0.00
0.00 18.89 0.00
0.00 18.81 0.00
0.00 18.73 0.00
0.00 18.65 0.00
0.00 18.56 0.00
0.00 18.47 0.00
0.00 18.38 0.00
0.00 18.28 0.00
0.00 18.19 0.00
0.00 18.08 0.00
0.00 17.98 0.00
0.00 17.87 0.00
0.00 17.77 0.00
0.00 17.65 0.00
0.00 17.54 0.00
0.00 17.42 0.00
0.00 17.30 0.00
0.00 17.18 0.00
0.00 17.05 0.00
0.00 16.93 0.00
0.00 16.80 0.00
0.00 16.66 0.00
0.00 16.53 0.00
0.00 16.39 0.00
0.00 16.24 0.00
0.00 16.10 0.00
0.00 15.95 0.00
0.00 15.80 0.00
0.00 15.65 0.00
0.00 15.50 0.00
0.00 15.34 0.00
0.00 15.18 0.00
0.00 15.01 0.00

Process finished with exit code 0
```




