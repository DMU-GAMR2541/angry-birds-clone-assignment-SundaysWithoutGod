#include <gtest/gtest.h>
#include "Enemy.h"
#include "Slingshot.h"

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
    Slingshot Constructor;

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
        
        Constructor.setTention(50);

    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }



};

//A single test, not a fixture. No setup is called.
TEST(Enemy, First_test) {
    Enemy e(110);
    EXPECT_GT(e.getHealth(), 100);
  //SUCCEED() << "Test test passed";
    //FAIL() << "Test didn't pass";
}

TEST_F(EnemyTest, LethalDamagePopsPig) {
    enemy->takeDamage(60);
    EXPECT_TRUE(enemy->checkIfPopped());
}


//Testing to see if  the enemy pig has taken enough damage to die
TEST(DeathTest, SecondTest) {
    Enemy Pig(100); //Creating an instance of the enemy setting health to 100
    Pig.takeDamage(110); //Setting damage
    EXPECT_TRUE(Pig.checkIfPopped());

}

TEST(Slighshot, TentionTest) {

    Slingshot Tention;
    Tention.setTention(50);
    EXPECT_GT(Tention.getTension(), 40);


}

//A ficture is having the ablity yo use the class
TEST_F(SlingshotTest, Pullback) {

    EXPECT_GE(Constructor.checkMax(30), 80);


}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}