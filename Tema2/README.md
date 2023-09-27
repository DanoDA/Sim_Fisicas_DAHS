# Tema2 (Hola_Bala)
En este código se vera el disparo de una bala de cañón(Densidad libre) a velocidad de 900km/h a un ángulo 60° 

## ¿Qué es una bala de cañón?
La bola de cañón es un proyectil simple sin carga explosiva que se dispara con un cañón. Como indica su nombre
## ¿Qué es la velocidad?
La velocidad es el cambio de posición de un objeto con respecto al tiempo.

## Código
```c
#include <Box2D/Box2D.h>
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    // Define the gravity vector
    b2Vec2 gravity(0.0f, -1.62f);

    // Construct a world object, which will hold and simulate the rigid bodies
    b2World world(gravity);

    // Create a dynamic body for the bullet
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    // Define another box shape for the bullet
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.1f, 0.1f);

    // Define the dynamic body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.01f;


    // Add the shape to the body
    body->CreateFixture(&fixtureDef);

    // Set the initial velocity of the bullet
    float angle = 60.0f; // Angle in degrees
    float speed = 250.0f; // Speed in m/s
    float vx = speed * std::cos(angle * M_PI / 180.0f);
    float vy = speed * std::sin(angle * M_PI / 180.0f);

    body->SetLinearVelocity(b2Vec2(vx, vy));

    // Simulate the world
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        std::cout << body->GetPosition().x << " " << body->GetPosition().y << std::endl;

    }

    // Remember to clean up
    world.DestroyBody(body);

    return 0;
}
```

## Explicación del código
En este código si hay varios cambios que voy a explicar a continuación


Se incluye una nueva librería que sirve para operaciones matemáticas.
```c
#include <cmath >
```
Después definimos PI(3.1415...).
```c
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
```

Se maneja la gravedad de la luna, ya visto en **Hola_Luna**
 ```c
 b2Vec2 gravity(0.0f, -1.62f);
```
Ahora definimos el tamaño de la bala
```c
  b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.1f, 0.1f);
```
Podemos cambiar la densidad o dejarla igual
```c
fixtureDef.density = 0.01f;
```
Ahora vamos a definir la velocidad de la bala y su ángulo, hacemos la conversión de 900km/h
```c
    // Set the initial velocity of the bullet
    float angle = 60.0f; // Angle in degrees
    float speed = 250.0f; // Speed in m/s
    float vx = speed * std::cos(angle * M_PI / 180.0f);
    float vy = speed * std::sin(angle * M_PI / 180.0f);
```
Y el ultimo cambio es a la hora de simular
```c
 world.Step(timeStep, velocityIterations, positionIterations);
        std::cout << body->GetPosition().x << " " << body->GetPosition().y << std::endl;
```
Se avanza la simulación, luego  se obtiene la posición del cuerpo de la bala y 
después se imprime la posición.


Resultado de la simulación!!!!!
```c
E:\Sim_Fisicas_DAHS\Tema2\cmake-build-debug-visual-studio\Tema2.exe
1.00009 1.732
2.00019 3.46354
3.00028 5.19464
4.00037 6.92529
5.00047 8.65548
6.00056 10.3852
7.00065 12.1145
8.00075 13.8434
9.00084 15.5718
10.0009 17.2997
11.001 19.0272
12.0011 20.7543
13.0012 22.4809
14.0013 24.207
15.0014 25.9327
16.0015 27.6579
17.0016 29.3827
18.0017 31.1071
19.0018 32.831
20.0019 34.5544
21.002 36.2774
22.0021 38
23.0021 39.7221
24.0022 41.4437
25.0023 43.1649
26.0024 44.8857
27.0025 46.6059
28.0026 48.3258
29.0027 50.0452
30.0028 51.7641
31.0029 53.4826
32.003 55.2007
33.0031 56.9183
34.0032 58.6354
35.0033 60.3521
36.0034 62.0684
37.0034 63.7842
38.0035 65.4995
39.0036 67.2144
40.0037 68.9289
41.0038 70.6429
42.0039 72.3564
43.004 74.0695
44.0041 75.7822
45.0042 77.4943
46.0043 79.2061
47.0044 80.9174
48.0045 82.6282
49.0045 84.3386
50.0046 86.0486
51.0047 87.7581
52.0048 89.4671
53.0049 91.1757
54.005 92.8839
55.0051 94.5916
56.0052 96.2988
57.0053 98.0056
58.0054 99.7119
59.0055 101.418
60.0056 103.123

Process finished with exit code 0
```

