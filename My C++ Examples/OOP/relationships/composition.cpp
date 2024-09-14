/*
    Composition is a type of association, and defines a "has-a" relationship between two classes.
    In this example, the Player class has a Point2D object as a member variable, which represents the player's position.
    The Player class uses the Point2D object to store and access the player's position.

    It wouldn't make sense to inherit from Point2D, because the player is not a point, but has a point.

    This example uses a location and a player class, where the player has a position in the game world.
    Composition makes the most sense here, since the position is only useful if a player exists.

*/

#include <iostream>
using namespace std;

class Point2D
{
private:
    int x;
    int y;

public:
    Point2D() = default;
    Point2D(int x, int y) : x(x), y(y) {}
    // this is accessible to the Player class through the position object member variable
    void setPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX() const { return x; }
    int getY() const { return y; }
};

class Player
{
private:
    Point2D position;

public:
    Player() = default;
    Player(Point2D &pos) : position(pos) {}

    void setPosition(int x, int y)
    {
        position.setPoint(x, y); // this calls the setPoint method of the Point2D object
    }

    void viewPlayerPosition() const
    {
        cout << "Player position: (" << position.getX() << ", " << position.getY() << ")" << endl;
    }
};

int main()
{
    Point2D position(10, 20);
    // this sends a copy of the Point2D object to the Player constructor
    Player player(position);

    player.viewPlayerPosition();
    // when the player object is destroyed, the Point2D object it contains is also destroyed
    // this is an example of composition, and shows a strong relationship between the two classes

    return 0;
}