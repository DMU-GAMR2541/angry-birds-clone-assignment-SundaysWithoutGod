#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include"ContactListener.h"
#include "Bird.h"
#include "Pig.h"
#include"UI.h"
#include"StaticObject.h"
#include <list>


int main() {
    // --- 1. WINDOW SETUP ---
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Annoyed_Flocks");
    window.setFramerateLimit(60);

    //Box2D works in meters. SFML works in pixels.
    const float SCALE = 30.0f;

    //Can set a definition for PI.
    const float PI = 3.1415927;

    //setup world.
    b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
    b2World world(b2_gravity);

    bool deleteCurrentBird = false;
    float birdLaunchTimer = 0.0f;
    
    // Create the listener instance.
    ContactListener hit;

    // Register it with the world
    world.SetContactListener(&hit);
    // Create a graphical text to display

    //Text
    UI T(30, "Press space to fire!!", sf::Vector2f(50.0f, 70.0f));
    std::unique_ptr<UI> ui = std::make_unique<UI>(T);

    std::list<std::unique_ptr<Pig>>piggieTypes; //Shared pointers of the type bird
    for (int i = 1; i < 4; i++) {

        piggieTypes.push_back(std::make_unique<Pig>(world, "../assets/Ang_Birds/Pig.png", sf::Vector2f(700.0f, 100.0f), sf::Vector2f(1.0f, 1.0f), 10.0f, 0.8f, 0.0f));
        piggieTypes.front()->getBody()->GetUserData().pointer = i;

    }

    //UI text("The text is working", "../assests/fonts/angry-birds-1.ttf", 10, sf::Vector2f(10.0,10.0), &window);
     //UI text2("../assests/fonts/angry-birds.ttf", " Text is working ", 50, sf::Vector2f(100.0f, 100.0f));

    // UI basic(&window);
    // UI test;
    // test.gettxt_Text();

    //Bird birdie(world, ("../assets/Ang_Birds/birdTest.png"), sf::Vector2f(150.f, 367.f), sf::Vector2f(1.0f, 1.0f), 40.0f, 0.5f, 0.3f);
    /* Bird bigBird(world, ("../assets/Ang_Birds/BigBird.png"), sf::Vector2f(130.f, 367.f), sf::Vector2f(1.5f, 1.5f), 70.0f, 0.2f, 0.2f);
     Bird fastBird(world, ("../assets/Ang_Birds/YellowBird.png"), sf::Vector2f(120.f, 367.f), sf::Vector2f(1.0f, 1.0f), 20.0f, 0.7f, 0.5f);*/
     //Bird containers 
    bool birdLaunched = false; //bird is waiting to be fired

    //Container to store the needed bird information
    struct BirdData {
        std::string location;
        float den;
        float fric;
        float rest;
    };

    std::vector<BirdData> birdData;//Putting the bords into a vector
    std::vector<std::unique_ptr<Bird>> flock;//creating a pointer to the bird data
    //creating the different bird types
    birdData.push_back({ "../assets/Ang_Birds/YellowBird.png", 0.5f, 0.6f, 0.3f });
    birdData.push_back({ "../assets/Ang_Birds/BigBird.png",    2.0f, 0.8f, 0.1f });
    birdData.push_back({ "../assets/Ang_Birds/birdTest.png",   1.0f, 0.3f, 0.6f });
    
    for (const auto& birds : birdData) {
        flock.push_back(std::make_unique<Bird>(world, birds.location, sf::Vector2f(150.0f, 450.0f), sf::Vector2f(1.0f, 1.0f), birds.den, birds.fric, birds.rest));
    }
    /*for (std::string s : location) {

        flock.push_back(std::make_unique<Bird>(world, s, sf::Vector2f(150.0f, 450.0f), sf::Vector2f(1.0f, 1.0f), 1.0f, 0.8f, 0.3f));

    }*/



     //Setup ground for the circle to move / bounce on.
     //Needs to have a body definition and a body. We use a raw pointer for the b2Body as Box2d does the management itself.
     //A body can be defined as having a position, velocity, and mass. 
    b2BodyDef b2_groundBodyDef;
    b2_groundBodyDef.position.Set(400.0f / SCALE, 590.0f / SCALE);
    b2Body* b2_groundBody = world.CreateBody(&b2_groundBodyDef);

    //Define a fixture shape that relates to the collision for the ground.
    b2PolygonShape b2_groundBox;
    b2_groundBox.SetAsBox(1000.0f / SCALE, 10.0f / SCALE);
    b2_groundBody->CreateFixture(&b2_groundBox, 0.0f);

    //Set up the ground visualisation.
    sf::RectangleShape sf_groundVisual(sf::Vector2f(1200.0f, 20.0f));
    sf_groundVisual.setOrigin(400.0f, 10.0f);
    sf_groundVisual.setFillColor(sf::Color(34, 139, 34)); // Forest Green

    //Setting up a wall for the ball to hit.
    b2BodyDef b2_wallDef;
    b2_wallDef.position.Set(750.0f / SCALE, 500.0f / SCALE);
    b2Body* b2_wallBody = world.CreateBody(&b2_wallDef);


    b2PolygonShape b2_wallBox;
    b2_wallBox.SetAsBox(-40.0f / SCALE, 1000.0f / SCALE);
    b2_wallBody->CreateFixture(&b2_wallBox, 0.0f);

    sf::RectangleShape sf_wallVisual(sf::Vector2f(30.0f, 560.0f));//width and height
    sf_wallVisual.setOrigin(-350.0f, 480.0f);//sets the position
    sf_wallVisual.setFillColor(sf::Color::Red);

    //Rather than having an immovable wall, we can use the dynamic body type to create one that can have velocity etc.
    b2BodyDef b2_plankDef;

    b2_plankDef.type = b2_dynamicBody;
    b2_plankDef.position.Set(550.0f / SCALE, 450.0f / SCALE);
    b2Body* b2_plankBody = world.CreateBody(&b2_plankDef);

    b2PolygonShape b2_plankBox;
    b2_plankBox.SetAsBox(10.0f / SCALE, 60.0f / SCALE);

    b2FixtureDef b2_plankFixture;
    b2_plankFixture.shape = &b2_plankBox;
    b2_plankFixture.density = 1.5f;   // Light wood
    b2_plankFixture.friction = 0.3f;
    b2_plankBody->CreateFixture(&b2_plankFixture);

    sf::RectangleShape sf_plankVisual(sf::Vector2f(20.0f, 120.0f));
    sf_plankVisual.setOrigin(10.0f, 60.0f);
    sf_plankVisual.setFillColor(sf::Color(139, 69, 19)); // Brown

    //Create a ball that is fired when space is pressed. We need to first have a dynamic ball to do it.
    b2BodyDef b2_ballDef;
    b2_ballDef.type = b2_dynamicBody;
    b2_ballDef.position.Set(100.0f / SCALE, 500.0f / SCALE);
    b2Body* b2_ballBody = world.CreateBody(&b2_ballDef);

    b2CircleShape b2_circleShape;
    b2_circleShape.m_radius = 15.0f / SCALE;

    b2FixtureDef b2_ballFixture;
    b2_ballFixture.shape = &b2_circleShape;
    b2_ballFixture.density = 1.0f;
    b2_ballFixture.restitution = 0.5f; // Bounciness
    b2_ballBody->CreateFixture(&b2_ballFixture);

    sf::CircleShape sf_ballVisual(15.0f);
    sf_ballVisual.setOrigin(15.0f, 15.0f);
    sf_ballVisual.setFillColor(sf::Color::Yellow);


    //Created floates with default values that can change the trajectory of the bird being launched 
    float impuleX = 100.0f;
    float impuleY = -70.0f;

    // --- 7. MAIN LOOP ---
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // INPUT HANDLING: Press SPACE to launch
            if (event.type == sf::Event::KeyPressed) {

                //Inputs to change the tragectory of the bird
                if (event.key.code == sf::Keyboard::H) {

                    impuleX = impuleX + 2.0;
                    std::cout << "X Value: " << impuleX << std::endl;
                }

                if (event.key.code == sf::Keyboard::J) {

                    impuleX = impuleX - 2.0;
                    std::cout << "X Value: " << impuleX << std::endl;

                }

                if (event.key.code == sf::Keyboard::K) {

                    impuleY = impuleY + 2.0;
                    std::cout << "Y Value: " << impuleY << std::endl;

                }

                if (event.key.code == sf::Keyboard::L) {

                    impuleY = impuleY - 2.0;
                    std::cout << "Y Value: " << impuleY << std::endl;

                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {

                    //if there are birds and they aren't flying
                    if (!flock.empty() && !birdLaunched) {
                        Bird* currentBird = flock.front().get();

                        currentBird->getBody()->SetAwake(true);
                        currentBird->getBody()->SetLinearVelocity(b2Vec2_zero);
                   
                        currentBird->getBody()->ApplyLinearImpulseToCenter(b2Vec2(impuleX, impuleY), true);
                       

                        birdLaunched = true;
                        birdLaunchTimer = 0.0f;
                        std::cout
                            << "MASS" << currentBird->getBody()->GetMass()
                            << std::endl;

                    }

                    //after bird is fires erase from the list, fires next in list but check if there is bird is in list
                }
            }

        }

        // Update Physics
        world.Step(1.0f / 60.0f, 8, 3);

        if (birdLaunched) {
            birdLaunchTimer += 1.0f / 60.0f;
        }
       
        //If the flock is not empty update the sprites and make sure it lines up with the physics
        if (!flock.empty()) {
            for (auto& bird : flock)
                bird->updateSprite();

            
        }

        //If the birds are still there get the first bird
        if (!flock.empty()) {

            Bird* currentBird = flock.front().get();
           
            if (currentBird && currentBird->getBody()) {

                b2Vec2 vel = currentBird->getBody()->GetLinearVelocity();
              
                if (birdLaunched && birdLaunchTimer> 1.0f && vel.Length() < 0.8f) {
                
                deleteCurrentBird = true;
               
                std::cout << "DELETING BIRD: " << std::endl;
                }

             }

        }
            

        if (deleteCurrentBird && !flock.empty())
        {
            world.DestroyBody(flock.front()->getBody());//remove the physics
            flock.erase(flock.begin());//remove the first bird in the vector so the second one is now first

            
            birdLaunched = false;
            deleteCurrentBird = false;
            birdLaunchTimer = 0.0f;

            if (!flock.empty())
            {
                flock.front()->getBody()->SetAwake(true);
                flock.front()->getBody()->SetLinearVelocity(b2Vec2_zero);
                flock.front()->getBody()->SetAngularVelocity(0);
            }
       
        }



        std::set<uintptr_t> s_p = hit.getPointer(); //Set of pointers to the pig ID's
        for (auto pigIt = piggieTypes.begin(); pigIt != piggieTypes.end(); ) {

            uintptr_t currentPigID = (*pigIt)->getBody()->GetUserData().pointer; //Getting the current ID

            // Check if this pig's ID exists in the hit list
            if (s_p.find(currentPigID) != s_p.end()) { //Check through all of the container for specific Id's

                std::cout << currentPigID << " Destroyed" << std::endl;

                //Created a pointer to the pigIt body so I can go in there to destroy it.
                b2Body* bodyIdeal = (*pigIt)->getBody();
                world.DestroyBody(bodyIdeal);


                // Update the iterator by catching the return value of erase()
                pigIt = piggieTypes.erase(pigIt); //Erase the pig sprite from the set.


            }
            else {
                // Only increment if we didn't erase anything
                ++pigIt;
            }
        }




        //All of the visuals needs to be synced with the physics.

        sf_ballVisual.setPosition(b2_ballBody->GetPosition().x * SCALE, b2_ballBody->GetPosition().y * SCALE);
        sf_ballVisual.setRotation(b2_ballBody->GetAngle() * (180.0f / PI));

        //Static objects usually don't move, but we set the position once.
        sf_groundVisual.setPosition(b2_groundBody->GetPosition().x * SCALE, b2_groundBody->GetPosition().y * SCALE);
        sf_wallVisual.setPosition(b2_wallBody->GetPosition().x * SCALE, b2_wallBody->GetPosition().y * SCALE);

        // Dynamic wall.
        sf_plankVisual.setPosition(b2_plankBody->GetPosition().x * SCALE, b2_plankBody->GetPosition().y * SCALE);
        sf_plankVisual.setRotation(b2_plankBody->GetAngle() * (180.0f / PI));




        //Render all of the content at each frame. Remember you need to clear the screen each iteration or artefacts remain.
        window.clear(sf::Color(135, 206, 235)); // Sky Blue

        //Render the Pigs

        window.draw(sf_groundVisual);
        window.draw(sf_wallVisual);
        window.draw(sf_plankVisual);
     
        for (std::unique_ptr<Pig>& p : piggieTypes) {
            p->updateSprite();
            window.draw(p->getSprite());


        }

        //draw all the birds in flock on the screen
        for (auto& bird : flock)
        {
            window.draw(bird->getSprite());
        }
    
        window.draw(ui->getText());

     
        window.display();
    }

    return 0;
}