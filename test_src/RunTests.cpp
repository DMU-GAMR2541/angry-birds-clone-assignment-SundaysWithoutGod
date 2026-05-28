
#include <gtest/gtest.h>
#include "Enemy.h"
#include "Slingshot.h"
#include"DynamicObject.h"
#include"StaticObject.h"
#include "Pig.h"
#include"box2d/box2d.h"
#include"Bird.h"
#include"UI.h"



TEST(Pig, posTest) 
{
  //Setting up a sprite, getting the position of the sprite and setting the position then running a test to see if the position equals what I set it to.
   Pig medPig("../assets/Ang_Birds/SinglePig.png", sf::Vector2f(550.0f, 500.0f), sf::Vector2f(1.0f, 1.0f));
   EXPECT_EQ(medPig.getSprite().getPosition().x, 550.0f);
   

}
TEST(Pig, scaleTest) 
{
    //Testing to see if the scale is equal 
    Pig smallPig("../assets/Ang_Birds/SinglePig.png", sf::Vector2f(300.0f, 250.0f), sf::Vector2f(0.5f, 0.5f));
    EXPECT_EQ(smallPig.getSprite().getScale().y, 0.5f);

}


TEST(Pig, Health_Pig)
{
    //Testing to see of the getters and setters for the health functions in pig is working 
    b2Vec2 gravity(0, 9.8f);
    b2World world(gravity);
    Pig largePig(world,"../assets/Ang_Birds/TesPig.png", sf::Vector2f(700.0f, 300.0f), sf::Vector2f(2.0f, 2.0f), 50.0f, 0.3f, 0.0f);
    largePig.setHealth(100);
    EXPECT_EQ(largePig.getHealth(), 100);
}



//create a bird, set the position, set parameters (list of position, ) 
//Test the correctness of the movement of a dynamic object across a suitable spread of values. ASK FOR MORE DETAILS
//PARAM TEST TEST_P
class birdMovementTest : public::testing::TestWithParam<b2Vec2> {
protected:
    birdMovementTest() = default;
    ~birdMovementTest() = default;

private:


public:

    std::shared_ptr<Bird>Test;
    const float SCALE = 30.0f;
    bool loadSprite = true;
  

    void SetUp() override { // things done before a test, setting the position to 0
        // Code here will be called immediately after the constructor (right
        // before each test).

        //Test->setPos(b2Vec2(0, 0));
        b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
        b2World world(b2_gravity);

        Test = std::make_shared<Bird>(world, "../assets/Ang_Birds/YellowBird.png", sf::Vector2f(700.0f / SCALE, 300.0f / SCALE), sf::Vector2f(2.0f, 2.0f), 0.5f, 0.6f, 0.3f);
        std::cout << "SetUp" << std::endl;
    }

    void TearDown() override { //things done after the test, 

        std::cout << "TearDown" << std::endl;
        
    }
};

INSTANTIATE_TEST_SUITE_P(
    MovementTest,//Name of testing suite
    birdMovementTest,::testing::Values(
        b2Vec2(700.0f,300.0f),
        b2Vec2(750.0f, 350.0f),
        b2Vec2(800.0f, 400.0f),
        b2Vec2(850.0f, 450.0f),
        b2Vec2(900.0f,500.0f)

    ) //point the suit to the class thats called ParamTest--
);
TEST_P(birdMovementTest, MovementTest) {
   b2Vec2 b2_movement = GetParam();
   std::cout << "Param value:: " << b2_movement.x << std::endl;
   Test->updateSprite(b2_movement);
   std::cout << "Sprite Param:  " << Test->getSprite().getPosition().y << " b2:  " << b2_movement.y * SCALE << std::endl;
   ASSERT_EQ(Test->getSprite().getPosition().y, b2_movement.y*SCALE);

}

////Param test setting the posX to 20 and giving 4 boundary values 
////--pos and neg numbers, middle nums, end vlaue ramges
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//Test a static object is correct in the game window

class UITest : public::testing::Test {

private:
protected:
    sf::Text txt_Text;//the text
    sf::Font f_font;//the font of the text
    std::unique_ptr<sf::RenderWindow>window; //reference to window
    std::unique_ptr<UI> ui;
    UITest() = default;
    ~UITest() = default;
public:
    UITest(int i, std::string texT, sf::Vector2f pos) {


       
    };

    sf::Text getText() {
        return txt_Text;
    }
      UITest(std::string location, std::string text, int textSize, sf::Vector2f position);
    //str text, str location, int textSize, vector2f position, &window

    sf::Font gettxt_Text() {
        return f_font;
        std::cout << "Text is called debug" << std::endl;
    }; //return the string
  
    void SetUp() override {
    
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1200, 800), "Aggressive_Aviens");
        //Set up a window that I can acess
     
        ui = std::make_unique<UI>(30, "Text being rendered to the window", sf::Vector2f(1300.0f, 850.0f));
       
    };

    void TearDown() override
    {
        ui.release();
        window.release();
        };

};



//Get the width of window and check I the UI is correctly placed within the window same with height
//2 expects of width and height
TEST_F(UITest, Placement) {
   std::cout<<"UI Pos X : "<< ui->getText().getPosition().x << std::endl;
   std::cout<<"UI Pos Y : "<< ui->getText().getPosition().y << std::endl;
    EXPECT_LE(ui->getText().getPosition().x, window->getSize().x);
    EXPECT_LE(ui->getText().getPosition().y, window->getSize().y);
    

//Placeing withing the window in the correct fashion
    //testing if its greater than the widest part as well

}



//create a bird class which allows me not have to repeatedly make birds for individual test
class birdTest : public::testing::Test {

private:


public:
   
    std::unique_ptr<Bird>Test;
    std::unique_ptr<Pig>pigFunc;
    std::unique_ptr<Pig>pigTest;
    std::unique_ptr<Pig>pig;
    const float SCALE = 30.0f;
    bool loadSprite = true;
    birdTest() = default;
    ~birdTest() = default;

    void SetUp() override { // things done before a test, setting the position to 0
        // Code here will be called immediately after the constructor (right
        // before each test).
      
        //Test->setPos(b2Vec2(0, 0));
        b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
        b2World world(b2_gravity);
       
        std::cout << "SetUp" << std::endl;
        Test = std::make_unique<Bird>(world, "../assets/Ang_Birds/YellowBird.png", sf::Vector2f(700.0f, 300.0f), sf::Vector2f(2.0f, 2.0f), 0.5f, 0.6f, 0.3f);

        //Adding in a pig variable for relations testing
        pigFunc = std::make_unique<Pig>(world, "../assets/Ang_Birds/Pig.png", sf::Vector2f(700.0f, 300.0f), sf::Vector2f(1.0f, 1.0f), 10.0f, 0.8f, 0.0f);
        pigTest = std::make_unique<Pig>(world, "../assets/Ang_Birds/Pig.png", sf::Vector2f(720.0f, 100.0f), sf::Vector2f(1.0f, 1.0f), 10.0f, 0.8f, 0.0f);
        pig = std::make_unique<Pig>(world, "../assets/Ang_Birds/Pig.png", sf::Vector2f(740.0f, 100.0f), sf::Vector2f(1.0f, 1.0f), 10.0f, 0.8f, 0.0f);
    }

    void TearDown() override { //things done after the test, 

        std::cout << "TearDown" << std::endl;
        //Releasing the referemce to the poniters without deleting them
        pigFunc.release();
        pigTest.release();
        pig.release();
       
    }


};
//Data setup for multiple tests in the proceeding class including the setup and teardown functionality. ASK FOR MORE DETAIL

//Using the bird class to set up tests 
//test the fixtures of a bird
//Testing the position of the bird from the sprite and it's greater than 0
TEST_F(birdTest, getSprite) {
    
    EXPECT_GT(Test->getSprite().getPosition().x, 0);
}
TEST_F(birdTest, changingPos2) {

    //Testing to see of the sprite position will be the same as the value I set

    
    
    std::cout << "NEW POS: " << (550/SCALE) << std::endl;
    
    Test->getSprite().setPosition(550, 350.0f);
    std::cout << "Sprite POSITION: " << Test->getSprite().getPosition().x << std::endl;
    EXPECT_EQ(Test->getSprite().getPosition().x, (700.0f / SCALE));
   
}


//Test whether a sprite  texture can be loaded. 
//TRUE OR FALSE RETURN TEST
TEST_F(birdTest, loadSprite) {
    
    EXPECT_FALSE(Test->getLoadSprite());

}


//Take the bird game object and test to see if it's position is calculated correctly in relation to the pigs, floor and static plank
//Creating a bird and making it's position equal to the other 3 objects and seeing if that works
//Or if they are 10 pixels away
//
//Test the correctness of the sequence of destructor calls, for example from pig to gameobject. ASK FOR MORE DETAIL

TEST_F(birdTest, Relation) {

    ASSERT_EQ(Test->getSprite().getPosition(), pigFunc->getSprite().getPosition()); //compsring the position of one bird against a pig
    ASSERT_LE(Test->getSprite().getPosition().x, pigTest->getSprite().getPosition().x); //compsring the position of one bird against a pig
    ASSERT_LE(Test->getSprite().getPosition().x, pig->getSprite().getPosition().x); //compsring the position of one bird against a pig
    //Goes
    // Point of relations test-----Checking the position of the bird pixels the same or further awat than the pig--correct relationship with bird
    // using asserts 
   
    //Testing the position relationship--Does it work  with multiple pigs/Does for me 
}
