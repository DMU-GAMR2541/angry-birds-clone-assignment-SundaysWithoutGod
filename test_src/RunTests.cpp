#include <gtest/gtest.h>
#include "Enemy.h"
#include "Slingshot.h"
#include "Pig.h"

/// <summary>
///Taken from the GoogleTest primer. 
/// </summary>

// The fixture for testing class Foo.
class EnemyTest : public testing::Test {
public:
    std::unique_ptr<Enemy> enemy;
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    EnemyTest() {
        // You can do set-up work for each test here.
                    
    }

    ~EnemyTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        enemy = std::make_unique<Enemy>(50); // All enemnies in this test suite start with 50 HP.
                    
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }


};

class SlingshotTest : public testing::Test {
public:
    std::unique_ptr<Slingshot> slingshot;
    Slingshot Base;

protected:
    SlingshotTest() {
        // You can do set-up work for each test here.
        
    }

    ~SlingshotTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        
        Base.setTention(50);

    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }



};

//A single test, not a fixture. No setup is called.
TEST(Enemy, First_test) {
    
    //Test to see if the health is >100
    Enemy e(90);
    ASSERT_GT(e.getHealth(), 100);//Assesrt stops the muliple tests in the same unit from running if one test is wrong
    EXPECT_GT(e.getHealth(), 100);
  //SUCCEED() << "Test test passed";
    //FAIL() << "Test didn't pass";
}

TEST_F(EnemyTest, LethalDamagePopsPig) {
   
    //Test to see if the enemy is dead after taking damage
    enemy->takeDamage(60);
    EXPECT_TRUE(enemy->checkIfPopped());
}

TEST(Pig, posTest) 
{
  //Setting up a sprite, getting the position of the sprite and setting the position then running a test to see if the position equals what I set it to.
   Pig medPig("../assets/Ang_Birds/SinglePig.png", sf::Vector2f(500.0f, 500.0f), sf::Vector2f(1.0f, 1.0f));
   EXPECT_EQ(medPig.getSprite().getPosition().x, 500.0f);
   

}


//Testing to see if  the enemy pig has taken enough damage to die
TEST(DeathTest, SecondTest) {

    //Test to see if the Pig is dead

    Enemy Pig(100); //Creating an instance of the enemy setting health to 100
    Pig.takeDamage(110); //Setting damage
    EXPECT_TRUE(Pig.checkIfPopped());

}

TEST(Slighshot, TentionTest) {

    //Test to see if the set tention is >40
    Slingshot Tention;
    Tention.setTention(50);
    EXPECT_GT(Tention.getTension(), 40);


}

//A ficture is having the ablity yo use the class
TEST_F(SlingshotTest, Pullback) { //Test_Fixture means I can use anything in the slingshottest class 

    //Test to see if the pullback and tention will be =<80
    EXPECT_GE(Base.checkMax(30), 80);


}


TEST(LoadBird, Bird) {
    
//I want to know if the red bird is there
//Test to see if bird type will load
    
    Slingshot Bird;

    //Converting strings to char 
    std::string birdType = Bird.getBirdType();
    const char* charBird = birdType.c_str();
    

    EXPECT_STREQ(charBird, "Red");

}
//Test PosX
TEST(Position, PosX) {

    Enemy Pos;
    Pos.setPos(6.f, 2.f);
    EXPECT_FLOAT_EQ(Pos.getPosX(), 6.f);


}

//Testing the bird type
TEST(BirdType, BlackBird) {

    Slingshot Black;
    Black.setBirdType("Black");
    std::string typeB = Black.getBirdType();
    const char* birdChar = typeB.c_str();

    EXPECT_STREQ(birdChar, "Yellow");
    

}

//Test--
class ParamTest : public::testing::TestWithParam<int> {
protected:
    ParamTest() = default;
    ~ParamTest() = default;

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).

    }

    void TearDown() override {

    }
};

TEST_P(ParamTest, SimpleTest) {
    int i_test = GetParam();
    std::cout << "Param value:: " << i_test << std::endl;
    ASSERT_GT(i_test, 1);
}

INSTANTIATE_TEST_SUITE_P(
    Simple,//Name of testing suite
    ParamTest, ::testing::Values(1, 2, 3, 4, 5) //point the suit to the class thats called ParamTest--
);

//Param test setting the posX to 20 and giving 4 boundary values 
//--pos and neg numbers, middle nums, end vlaue ramges
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}