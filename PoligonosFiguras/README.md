# Polígonos Figuras
En este código se crean polígonos que son las figuras triangulo, rectángulo, cuadrado, octágono, hexágono y pentágono


## Código
```c
#include <iostream>  
#include <box2d/box2d.h>  
  
int main() {  
    // Crear un mundo de física  
    b2Vec2 gravity(0.0f, 0.0f);  
    b2World world(gravity);  
  
    // Definir un cuerpo estático en el suelo  
    b2BodyDef groundBodyDef;  
    groundBodyDef.position.Set(0.0f, -15.0f);  
    b2Body* groundBody = world.CreateBody(&groundBodyDef);  
  
    // Crear formas geométricas para las figuras  
    b2PolygonShape TrianguloShape;  
    b2PolygonShape RectanguloShape;  
    b2PolygonShape CuadradoShape;  
    b2PolygonShape OctagonoShape;  
    b2PolygonShape HexagonoShape;  
    b2PolygonShape PentagonoShape;  
  
  
    // Triángulo  
    b2Vec2 TrianguloVertices[3];  
    TrianguloVertices[0].Set(0.0f, 0.0f);  
    TrianguloVertices[1].Set(1.0f, 0.0f);  
    TrianguloVertices[2].Set(0.5f, 1.0f);  
    TrianguloShape.Set(TrianguloVertices, 3);  
  
    // Rectángulo  
    RectanguloShape.SetAsBox(1.0f, 0.5f);  
  
    // Cuadrado  
    CuadradoShape.SetAsBox(0.5f, 0.5f);  
  
    // Octagono  
    b2Vec2 OctagonoVertices[8];  
    OctagonoVertices[0].Set(0.0f, 0.0f);  
    OctagonoVertices[1].Set(1.0f, 0.0f);  
    OctagonoVertices[2].Set(1.5f, 0.5f);  
    OctagonoVertices[3].Set(1.5f, 1.5f);  
    OctagonoVertices[4].Set(1.0f, 2.0f);  
    OctagonoVertices[5].Set(0.0f, 2.0f);  
    OctagonoVertices[6].Set(-0.5f, 1.5f);  
    OctagonoVertices[7].Set(-0.5f, 0.5f);  
    OctagonoShape.Set(OctagonoVertices, 8);  
  
    // Hexagono  
    b2Vec2 HexagonoVertices[6];  
    HexagonoVertices[0].Set(0.0f, 0.0f);  
    HexagonoVertices[1].Set(1.0f, 0.0f);  
    HexagonoVertices[2].Set(1.5f, 1.0f);  
    HexagonoVertices[3].Set(1.0f, 1.5f);  
    HexagonoVertices[4].Set(0.0f, 1.5f);  
    HexagonoVertices[5].Set(-0.5f, 1.0f);  
    HexagonoShape.Set(HexagonoVertices, 6);  
  
    // Pentagono  
    b2Vec2 PentagonoVertices[5];  
    PentagonoVertices[0].Set(0.0f, 0.0f);  
    PentagonoVertices[1].Set(1.0f, 0.0f);  
    PentagonoVertices[2].Set(1.5f, 1.0f);  
    PentagonoVertices[3].Set(0.5f, 1.5f);  
    PentagonoVertices[4].Set(-0.5f, 1.0f);  
    PentagonoShape.Set(PentagonoVertices, 5);  
  
  
    // Crear cuerpos  
    b2BodyDef bodyDef;  
    bodyDef.type = b2_dynamicBody;  
  
    b2Body* TrianguloBody = world.CreateBody(&bodyDef);  
    TrianguloBody->CreateFixture(&TrianguloShape, 1.0f);  
  
    b2Body* RectanguloBody = world.CreateBody(&bodyDef);  
    RectanguloBody->CreateFixture(&RectanguloShape, 1.0f);  
  
    b2Body* CuadradoBody = world.CreateBody(&bodyDef);  
    CuadradoBody->CreateFixture(&CuadradoShape, 1.0f);  
  
    b2Body* OctagonoBody = world.CreateBody(&bodyDef);  
    OctagonoBody->CreateFixture(&OctagonoShape, 1.0f);  
  
    b2Body* HexagonoBody = world.CreateBody(&bodyDef);  
    HexagonoBody->CreateFixture(&HexagonoShape, 1.0f);  
  
    b2Body* PentagonoBody = world.CreateBody(&bodyDef);  
    PentagonoBody->CreateFixture(&PentagonoShape, 1.0f);  
  
  
  
  
  
    // Definir el tiempo y las iteraciones  
    float timeStep = 1.0f / 60.0f;  
    int32 velocityIterations = 6;  
    int32 positionIterations = 2;  
  
    for (int i = 0; i < 60; ++i)  
    {  
        world.Step(timeStep, velocityIterations, positionIterations);  
    }  
  
    // Imprimir la posición de cada cuerpo después de la simulación  
    std::cout << "Triangulo: " << TrianguloBody->GetPosition().x << " " << TrianguloBody->GetPosition().y << std::endl;  
  
    std::cout << "Rectangulo: " << RectanguloBody->GetPosition().x << " " << RectanguloBody->GetPosition().y << std::endl;  
  
    std::cout << "Cuadrado: " << CuadradoBody->GetPosition().x << " " << CuadradoBody->GetPosition().y << std::endl;  
  
    std::cout << "Octagono: " << OctagonoBody->GetPosition().x << " " << OctagonoBody->GetPosition().y << std::endl;  
  
    std::cout << "Hexagono: " << HexagonoBody->GetPosition().x << " " << HexagonoBody->GetPosition().y << std::endl;  
  
    std::cout << "Pentagono: " << PentagonoBody->GetPosition().x << " " << PentagonoBody->GetPosition().y << std::endl;  
  
  
  
  
    world.DestroyBody(TrianguloBody);  
  
    world.DestroyBody(RectanguloBody);  
  
    world.DestroyBody(CuadradoBody);  
  
    world.DestroyBody(OctagonoBody);  
  
    world.DestroyBody(HexagonoBody);  
  
    world.DestroyBody(PentagonoBody);  
  
  
  
    return 0;  
}
```

## Explicación del código
Primero se exportan las librerías 
```c
#include <iostream>  
#include <box2d/box2d.h> 
```
Después creamos el mundo con un cuerpo en el suelo
```c
int main() {  
    // Crear un mundo de física  
    b2Vec2 gravity(0.0f, 0.0f);  
    b2World world(gravity);  
  
    // Definir un cuerpo estático en el suelo  
    b2BodyDef groundBodyDef;  
    groundBodyDef.position.Set(0.0f, -15.0f);  
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
```
Después crean las formas de las figuras
```c
// Crear formas geométricas para las figuras  
b2PolygonShape TrianguloShape;  
b2PolygonShape RectanguloShape;  
b2PolygonShape CuadradoShape;  
b2PolygonShape OctagonoShape;  
b2PolygonShape HexagonoShape;  
b2PolygonShape PentagonoShape;  
  
  
// Triángulo  
b2Vec2 TrianguloVertices[3];  
TrianguloVertices[0].Set(0.0f, 0.0f);  
TrianguloVertices[1].Set(1.0f, 0.0f);  
TrianguloVertices[2].Set(0.5f, 1.0f);  
TrianguloShape.Set(TrianguloVertices, 3);  
  
// Rectángulo  
RectanguloShape.SetAsBox(1.0f, 0.5f);  
  
// Cuadrado  
CuadradoShape.SetAsBox(0.5f, 0.5f);  
  
// Octagono  
b2Vec2 OctagonoVertices[8];  
OctagonoVertices[0].Set(0.0f, 0.0f);  
OctagonoVertices[1].Set(1.0f, 0.0f);  
OctagonoVertices[2].Set(1.5f, 0.5f);  
OctagonoVertices[3].Set(1.5f, 1.5f);  
OctagonoVertices[4].Set(1.0f, 2.0f);  
OctagonoVertices[5].Set(0.0f, 2.0f);  
OctagonoVertices[6].Set(-0.5f, 1.5f);  
OctagonoVertices[7].Set(-0.5f, 0.5f);  
OctagonoShape.Set(OctagonoVertices, 8);  
  
// Hexagono  
b2Vec2 HexagonoVertices[6];  
HexagonoVertices[0].Set(0.0f, 0.0f);  
HexagonoVertices[1].Set(1.0f, 0.0f);  
HexagonoVertices[2].Set(1.5f, 1.0f);  
HexagonoVertices[3].Set(1.0f, 1.5f);  
HexagonoVertices[4].Set(0.0f, 1.5f);  
HexagonoVertices[5].Set(-0.5f, 1.0f);  
HexagonoShape.Set(HexagonoVertices, 6);  
  
// Pentagono  
b2Vec2 PentagonoVertices[5];  
PentagonoVertices[0].Set(0.0f, 0.0f);  
PentagonoVertices[1].Set(1.0f, 0.0f);  
PentagonoVertices[2].Set(1.5f, 1.0f);  
PentagonoVertices[3].Set(0.5f, 1.5f);  
PentagonoVertices[4].Set(-0.5f, 1.0f);  
PentagonoShape.Set(PentagonoVertices, 5);
```
Luego se crean los cuerpos con su densidad
``` c
// Crear cuerpos  
b2BodyDef bodyDef;  
bodyDef.type = b2_dynamicBody;  
  
b2Body* TrianguloBody = world.CreateBody(&bodyDef);  
TrianguloBody->CreateFixture(&TrianguloShape, 1.0f);  
  
b2Body* RectanguloBody = world.CreateBody(&bodyDef);  
RectanguloBody->CreateFixture(&RectanguloShape, 1.0f);  
  
b2Body* CuadradoBody = world.CreateBody(&bodyDef);  
CuadradoBody->CreateFixture(&CuadradoShape, 1.0f);  
  
b2Body* OctagonoBody = world.CreateBody(&bodyDef);  
OctagonoBody->CreateFixture(&OctagonoShape, 1.0f);  
  
b2Body* HexagonoBody = world.CreateBody(&bodyDef);  
HexagonoBody->CreateFixture(&HexagonoShape, 1.0f);  
  
b2Body* PentagonoBody = world.CreateBody(&bodyDef);  
PentagonoBody->CreateFixture(&PentagonoShape, 1.0f);
```
Después se define las iteraciones y las posiciones de los cuerpos
``` c
// Definir el tiempo y las iteraciones  
float timeStep = 1.0f / 60.0f;  
int32 velocityIterations = 6;  
int32 positionIterations = 2;  
  
for (int i = 0; i < 60; ++i)  
{  
    world.Step(timeStep, velocityIterations, positionIterations);  
}  
  
// Imprimir la posición de cada cuerpo después de la simulación  
std::cout << "Triangulo: " << TrianguloBody->GetPosition().x << " " << TrianguloBody->GetPosition().y << std::endl;  
  
std::cout << "Rectangulo: " << RectanguloBody->GetPosition().x << " " << RectanguloBody->GetPosition().y << std::endl;  
  
std::cout << "Cuadrado: " << CuadradoBody->GetPosition().x << " " << CuadradoBody->GetPosition().y << std::endl;  
  
std::cout << "Octagono: " << OctagonoBody->GetPosition().x << " " << OctagonoBody->GetPosition().y << std::endl;  
  
std::cout << "Hexagono: " << HexagonoBody->GetPosition().x << " " << HexagonoBody->GetPosition().y << std::endl;  
  
std::cout << "Pentagono: " << PentagonoBody->GetPosition().x << " " << PentagonoBody->GetPosition().y << std::endl;
```
Y para terminar se destruyen los cuerpos y se finaliza la simulación
``` c
 world.DestroyBody(TrianguloBody);  
  
    world.DestroyBody(RectanguloBody);  
  
    world.DestroyBody(CuadradoBody);  
  
    world.DestroyBody(OctagonoBody);  
  
    world.DestroyBody(HexagonoBody);  
  
    world.DestroyBody(PentagonoBody);  
  
  
  
    return 0;  
}
```
Resultados de la simulación!!!!!!!!:
``` c
E:\Sim_Fisicas_DAHS\PoligonosFiguras\cmake-build-debug-visual-studio\PoligonosFiguras.exe
Triangulo: -0.924737 0.429581
Rectangulo: -0.370964 -0.875446
Cuadrado: -0.877931 -1.84718
Octagono: 0.0331723 1.44651
Hexagono: 0.421609 -1.02033
Pentagono: 0.707894 0.465078

Process finished with exit code 0
```


