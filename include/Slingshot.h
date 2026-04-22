#pragma once
#include <string>

/// <summary>
/// A simple class that you can use to begin the testing process using Googletest.
/// </summary>
class Slingshot {
private:
    /// <summary>
    /// Variables that define the slingshot.
    /// </summary>
    int i_tension;
    std::string str_birdType;
    const int MAX_TENSION = 100;

public:
    Slingshot() : i_tension(0), str_birdType("Red") {}

    //Functions to test.
    void loadBird(std::string str_type) { str_birdType = str_type; }

    bool pullBack(int amount) {
        if (amount < 0) return false;
        i_tension = (i_tension + amount > MAX_TENSION) ? MAX_TENSION : i_tension + amount; //If the tention and pull back is larger than the max tention set it to max tention else just add them togther
        return true;
    }

    int checkMax(int amount) {

        if (amount + i_tension > MAX_TENSION){
        
            return MAX_TENSION;
        }
        else {

            return amount + i_tension;
        }

    }


    void setTention(int amount) {

        i_tension = amount;

    }

    //Set enemy type
    void setBirdType(std::string birdTypein) {

        str_birdType = birdTypein;

    }

    int getTension() const { return i_tension; }
    std::string getBirdType() const { return str_birdType; }

    void release() { i_tension = 0; }
};