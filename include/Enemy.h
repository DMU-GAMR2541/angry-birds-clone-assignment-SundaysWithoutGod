#pragma once
class Enemy {
/// <summary>
/// Varaibles that define an enemy.
/// </summary>
private:
    int i_health;
    bool b_isDestroyed;
    float f_posX;
    float f_posY;

public:
    //Default constructor for an enemy. 
    Enemy() = default;
    Enemy(int i_initialHealth) : i_health(i_initialHealth), b_isDestroyed(false) {}
    Enemy(int i_initialHealth, bool b_isDestroyedin, float f_posXin, float f_posYin) {

        i_health = i_initialHealth;
        b_isDestroyed = b_isDestroyedin;
        f_posX = f_posXin;
        f_posY = f_posYin;
    
    }

    //Class functions to be tested.
    void takeDamage(int damage) {
        if (damage < 0) return;
            i_health -= damage;
        if (i_health <= 0) {
            i_health = 0;
            b_isDestroyed = true;
        }
    }

    //Setter for health 
    void setHealth(int health) {

        i_health = health;

    }
    
    //position of enemy objects
    //Enemy would have X,Y pos
    void setPos(float PosX, float PosY) {

        f_posX = PosX;
        f_posY = PosY;

    }
     
    
    float getPosX() const { return f_posX; }
    float getPosY() const { return f_posY; }
    int getHealth() const { return i_health; }
    bool checkIfPopped() const { return b_isDestroyed; }
};