# Hola_Jupiter
En este código veremos como calcular la caída de un cubo con una densidad de un carburo de tungsteno a una altura de 15 metros en Júpiter

## ¿Qué es Júpiter?
Júpiter es el planeta más grande del sistema solar y el quinto en orden de lejanía al Sol.​ Es un gigante gaseoso que forma parte de los denominados planetas exteriores. Recibe su nombre del dios romano Júpiter, este es su gravedad: 24.79 m/s².
## ¿Qué es altura?
La altura de un objeto o figura geométrica es una longitud o una distancia de una dimensión geométrica, usualmente vertical o en la dirección de la gravedad. Este término también se utiliza para designar la coordenada vertical de la parte más elevada de un objeto. 
## ¿Qué es carburo de tungsteno?
El carburo de tungsteno es un material muy versátil que se puede alear para obtener diversas propiedades. Su extraordinaria dureza es útil para moldear y cortar casi cualquier otro material y su alta resistencia a la temperatura le permite trabajar a altas velocidades maximizando su valor como herramienta de corte, su densidad es de **15600 kg/m^3** (kilogramos por metro cúbico), usaremos esta medida para la densidad.
## Código
``` c
#include <iostream>
#include <box2d/box2d.h>

int main() {
    //Creacion del mundo y de la gravedad
    b2Vec2 gravity(0.0f, -24.79f);
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
    bodyDef.position.Set(0.0f, 15.f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f,1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 15600.0f;
    fixtureDef.friction = 0.9f;

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
Este código es muy parecido al **Hola_Mundo y Hola_Luna**, con la diferencia de 4 variables

La primera que es la mas importante es la gravedad ya que es júpiter la densidad es mucho mayor que el de la luna y la tierra.
```c
b2Vec2 gravity(0.0f, -24.79f);
```
Después cambiamos la posición, ya que en este, se definió en 15 metros.
```c
    bodyDef.position.Set(0.0f, 15.f);
```
Modificamos la densidad del cubo por la de carburo de tungsteno.
```c
   fixtureDef.density = 15600.0f;
```
Por ultimo modificamos la fricción ya que como hay una atmosfera mayor, por ende la fricción será mayor.
```c
fixtureDef.friction = 0.9f;
```

Resultado de la simulación!!!!!!!!
```c
E:\Sim_Fisicas_DAHS\HolaJupiter\cmake-build-debug-visual-studio\HolaJupiter.exe
0.00 14.99 0.00
0.00 14.98 0.00
0.00 14.96 0.00
0.00 14.93 0.00
0.00 14.90 0.00
0.00 14.86 0.00
0.00 14.81 0.00
0.00 14.75 0.00
0.00 14.69 0.00
0.00 14.62 0.00
0.00 14.55 0.00
0.00 14.46 0.00
0.00 14.37 0.00
0.00 14.28 0.00
0.00 14.17 0.00
0.00 14.06 0.00
0.00 13.95 0.00
0.00 13.82 0.00
0.00 13.69 0.00
0.00 13.55 0.00
0.00 13.41 0.00
0.00 13.26 0.00
0.00 13.10 0.00
0.00 12.93 0.00
0.00 12.76 0.00
0.00 12.58 0.00
0.00 12.40 0.00
0.00 12.20 0.00
0.00 12.00 0.00
0.00 11.80 0.00
0.00 11.58 0.00
0.00 11.36 0.00
0.00 11.14 0.00
0.00 10.90 0.00
0.00 10.66 0.00
0.00 10.41 0.00
0.00 10.16 0.00
0.00 9.90 0.00
0.00 9.63 0.00
0.00 9.35 0.00
0.00 9.07 0.00
0.00 8.78 0.00
0.00 8.49 0.00
0.00 8.18 0.00
0.00 7.87 0.00
0.00 7.56 0.00
0.00 7.23 0.00
0.00 6.90 0.00
0.00 6.56 0.00
0.00 6.22 0.00
0.00 5.87 0.00
0.00 5.51 0.00
0.00 5.15 0.00
0.00 4.77 0.00
0.00 4.40 0.00
0.00 4.01 0.00
0.00 3.62 0.00
0.00 3.22 0.00
0.00 2.81 0.00
0.00 2.40 0.00

Process finished with exit code 0
```
