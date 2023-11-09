#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

const float SCALE = 50.0f;


class CuadradoEstatico {
public:
    CuadradoEstatico(b2World &world, float x, float y, float width, float height, float rotation, sf::Color color, float density) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        bodydef.type = b2_staticBody;
        body = world.CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox((width / 2) / SCALE, (height / 2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = density;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(width, height));
        box.setFillColor(color);
        box.setOrigin(width / 2, height / 2);
        body->SetTransform(body->GetPosition(), rotation * b2_pi / 180);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0, 0), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};

class CuadradoDinamico {
public:
    CuadradoDinamico(b2World &world, float x, float y, float width, float height, float rotation, sf::Color color, float density) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        bodydef.type = b2_dynamicBody;
        body = world.CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox((width / 2) / SCALE, (height / 2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = density;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(width, height));
        box.setFillColor(color);
        box.setOrigin(width / 2, height / 2);

        body->SetTransform(body->GetPosition(), rotation * b2_pi / 180);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void applyForce(b2Vec2 force) {
        body->ApplyForceToCenter(force, true);
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};

class CirculoDinamico {
public:
    CirculoDinamico(b2World &world, float x, float y, float radius, sf::Color color, float density) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        bodydef.type = b2_dynamicBody;
        body = world.CreateBody(&bodydef);

        b2CircleShape shape;
        shape.m_radius = radius / SCALE;

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = density;
        body->CreateFixture(&fixturedef);

        circle.setRadius(radius);
        circle.setFillColor(color);
        circle.setOrigin(radius, radius);
    }

    void update() {
        circle.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        circle.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(circle);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0, 0), body->GetAngle());
    }

    void applyForce(const b2Vec2& force) {
        body->ApplyForceToCenter(force, true);
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::CircleShape circle;
    b2Body *body;
};


int main() {
    sf::RenderWindow window(sf::VideoMode(1400, 900), "Rube Golberg");

    b2Vec2 gravity(0.0f, 0.04f);
    b2World world(gravity);

    //Estatico

    CuadradoEstatico BarraLarga(world, 400, 310, 950, 10, 8, sf::Color::Cyan, 1);
    CuadradoEstatico BarraSuelo(world, 800, 800, 1400, 10, 0, sf::Color::Cyan, 1);
    CuadradoEstatico BarraPeque(world, 1300, 550, 200, 20, 120, sf::Color::Cyan, 1);
    CuadradoEstatico PrimsaEstatica(world, 900, 100, 60, 10, 0, sf::Color::Cyan, 1);
    CuadradoEstatico AspaEstatica(world, 1200, 350, 10, 10, 0, sf::Color::Red, 1);
    CuadradoEstatico PoleaEstatica(world, 450, 100, 10, 10, 0, sf::Color::Red, 1);
    CuadradoEstatico Polea1Estatica(world, 1200, 100, 10, 10, 0, sf::Color::Red, 1);


// Dinamico
    CuadradoDinamico BarraPrisma(world, 900, 500, 60, 10, 0, sf::Color::Cyan,3);
    CuadradoDinamico BarraMovimineto(world, 1100, 350, 110, 15, 0, sf::Color::Blue, 2);
    CuadradoDinamico Barra1Movimineto(world, 1255, 350, 110, 15, 0, sf::Color::Blue,2);
    CuadradoDinamico Barra2Movimineto(world, 1185, 430, 110, 15, 90, sf::Color::Blue,2);
    CuadradoDinamico Barra3Movimineto(world, 1185, 270, 110, 15, 90, sf::Color::Blue,2);
    CuadradoDinamico BarraPolea(world, 700, 590, 110, 10, 0, sf::Color::Cyan,1);
    CuadradoDinamico Barra1Polea(world, 1200, 590, 110, 10, 0, sf::Color::Cyan,1);
    CirculoDinamico Bola(world, 100, 100, 10, sf::Color::Green, 1);
    CirculoDinamico Bola1(world, 100, 300, 10, sf::Color::Green,1);
    CirculoDinamico Bola2(world, 700, 400, 15, sf::Color::Green,1);
    CirculoDinamico Bola3(world, 50, -15000, 15, sf::Color::Green,1);
    CirculoDinamico Bola4(world, 200, 300, 15, sf::Color::Green,1);






// Cuerpos

    b2Body* CuerpoPrismaE = PrimsaEstatica.getBody();
    b2Body* CuerpoAnclaE = AspaEstatica.getBody();
    b2Body* CuerpoPoleaE = PoleaEstatica.getBody();
    b2Body* CuerpoPolea1E = Polea1Estatica.getBody();

    b2Body* CuerpoBarraPrisma = BarraPrisma.getBody();
    b2Body* CuerpoBarraM = BarraMovimineto.getBody();
    b2Body* CuerpoBarra1M = Barra1Movimineto.getBody();
    b2Body* CuerpoBarra2M = Barra2Movimineto.getBody();
    b2Body* CuerpoBarra3M = Barra3Movimineto.getBody();
    b2Body* CuerpoBarraPolea = BarraPolea.getBody();
    b2Body* CuerpoBarra1Polea = Barra1Polea.getBody();




    // Joint de Distancia
    b2DistanceJointDef DistanciajointDef;
    DistanciajointDef.Initialize(Bola.getBody(), Bola1.getBody(), Bola.getBody()->GetWorldCenter(), Bola1.getBody()->GetWorldCenter());
    DistanciajointDef.collideConnected = true;
    b2DistanceJoint* joint = static_cast<b2DistanceJoint*>(world.CreateJoint(&DistanciajointDef));

    //Joint de Revolucion
    b2RevoluteJointDef RevolucionjointDef;
    RevolucionjointDef.Initialize(CuerpoBarraM,CuerpoAnclaE , CuerpoAnclaE->GetWorldCenter());
    RevolucionjointDef.enableMotor = true;
    RevolucionjointDef.maxMotorTorque = 100.0f;
    RevolucionjointDef.motorSpeed = -0.05f;
    b2RevoluteJoint* revoluteJoint = static_cast<b2RevoluteJoint*>(world.CreateJoint(&RevolucionjointDef));

    b2RevoluteJointDef RevolucionjointDef1;
    RevolucionjointDef.Initialize(CuerpoBarra1M,CuerpoAnclaE , CuerpoAnclaE->GetWorldCenter());
    RevolucionjointDef1.enableMotor = true;
    RevolucionjointDef1.maxMotorTorque = 100.0f;
    RevolucionjointDef1.motorSpeed = -0.05f;
    b2RevoluteJoint* revoluteJoint2 = static_cast<b2RevoluteJoint*>(world.CreateJoint(&RevolucionjointDef));

    b2RevoluteJointDef RevolucionjointDef2;
    RevolucionjointDef.Initialize(CuerpoBarra2M,CuerpoAnclaE , CuerpoAnclaE->GetWorldCenter());
    RevolucionjointDef2.enableMotor = true;
    RevolucionjointDef2.maxMotorTorque = 100.0f;
    RevolucionjointDef2.motorSpeed = -0.05f;
    b2RevoluteJoint* revoluteJoint3 = static_cast<b2RevoluteJoint*>(world.CreateJoint(&RevolucionjointDef));

    b2RevoluteJointDef RevolucionjointDef3;
    RevolucionjointDef.Initialize(CuerpoBarra3M,CuerpoAnclaE , CuerpoAnclaE->GetWorldCenter());
    RevolucionjointDef3.enableMotor = true;
    RevolucionjointDef3.maxMotorTorque = 100.0f;
    RevolucionjointDef3.motorSpeed = -0.05f;
    b2RevoluteJoint* revoluteJoint4 = static_cast<b2RevoluteJoint*>(world.CreateJoint(&RevolucionjointDef));

    //joint Polea
    b2Vec2 ancho1 = CuerpoBarraPolea->GetWorldCenter();
    b2Vec2 ancho2 = CuerpoBarra1Polea->GetWorldCenter();

    b2Vec2 groundAnchor1(CuerpoPoleaE->GetWorldCenter().x, CuerpoPoleaE->GetWorldCenter().y);
    b2Vec2 groundAnchor2(CuerpoPolea1E->GetWorldCenter().x, CuerpoPolea1E->GetWorldCenter().y);

    float ratio = 1.0f;

    b2PulleyJointDef jointDef;
    jointDef.Initialize(CuerpoBarraPolea, CuerpoBarra1Polea, groundAnchor1, groundAnchor2, ancho1, ancho2, ratio);

    b2PulleyJoint* pulleyJoint = static_cast<b2PulleyJoint*>(world.CreateJoint(&jointDef));



    //Joint Prismatico
    b2PrismaticJointDef PrismaticajointDef;
    b2Vec2 worldAxis(0.0f, 1.0f);
    PrismaticajointDef.Initialize(CuerpoBarraPrisma, CuerpoPrismaE, CuerpoBarraPrisma->GetWorldCenter(), worldAxis);
    PrismaticajointDef.lowerTranslation = 2.0f;
    PrismaticajointDef.upperTranslation = 5.0f;
    PrismaticajointDef.enableLimit = true;

    PrismaticajointDef.maxMotorForce = 0.5f;
    PrismaticajointDef.motorSpeed = 0.05f;
    PrismaticajointDef.enableMotor = true;

    b2PrismaticJoint* prismaticJoint = static_cast<b2PrismaticJoint*>(world.CreateJoint(&PrismaticajointDef));




    //Ciclo inical
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Cerrar ventana con z
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                window.close();
                return 0;
            }
        }


        world.Step(1 / 60.f, 8, 3);

        PrimsaEstatica.update();
        AspaEstatica.update();
        PoleaEstatica.update();
        Polea1Estatica.update();

        BarraLarga.update();
        BarraPeque.update();
        BarraSuelo.update();
        BarraPrisma.update();
        BarraMovimineto.update();
        Barra1Movimineto.update();
        Barra2Movimineto.update();
        Barra3Movimineto.update();
        BarraPolea.update();
        Barra1Polea.update();
        Bola.update();
        Bola1.update();
        Bola2.update();
        Bola3.update();
        Bola4.update();

        window.clear();

        PrimsaEstatica.draw(window);
        AspaEstatica.draw(window);
        PoleaEstatica.draw(window);
        Polea1Estatica.draw(window);

        BarraLarga.draw(window);
        BarraPeque.draw(window);
        BarraSuelo.draw(window);
        BarraPrisma.draw(window);
        BarraMovimineto.draw(window);
        Barra1Movimineto.draw(window);
        Barra2Movimineto.draw(window);
        Barra3Movimineto.draw(window);
        BarraPolea.draw(window);
        Barra1Polea.draw(window);
        Bola.draw(window);
        Bola1.draw(window);
        Bola2.draw(window);
        Bola3.draw(window);
        Bola4.draw(window);

        window.display();
    }
    return 0;
}