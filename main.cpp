////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int W = 640;
int H = 480;
int x = 100;
double x1 = 0;
double speed = 0;
using namespace sf;
int main()
{
    std::cin >> x;
    
    RenderWindow window(VideoMode(640, 480), "Triangle");
    CircleShape triangle(x, 3); // x -> 100.f
    triangle.setFillColor(Color::Green);
    triangle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    triangle.setOrigin(x, x);
    while (window.isOpen())
    {
        
            sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                triangle.scale(0.5f, 0.5f);
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {

                triangle.scale(1.5f, 1.5f);
               
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            speed += 0.000001;
            //triangle.rotate(1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            speed -= 0.000001;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            speed = 0;
        triangle.rotate(speed);
       
        window.clear();
        window.draw(triangle);
        window.display();
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
