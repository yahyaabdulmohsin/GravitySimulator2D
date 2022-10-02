#include <iostream>
#include <SFML/Graphics.hpp>
#include "CelestialBody.h"
#include <cmath>

int main()
{
    // welcoming the user
    std::cout << "Welcome to GravitySimulator2D. Use the command \"/help\" to get more information.\n";
    // creating the list for the objects in the simulation
    std::vector<CelestialBody> objects;
    // creating an empty string to handle input from the user
    std::string command = "";
    // creating the necessary variables to handle input from the user
    float xPos = 0.f, yPos = 0.f, radius = 0.f, mass = 0.f, initialVelocity = 0.f, direction = 0.f;
    char color;
    char temp;
    // Big G constant that is needed to calculate force according to Newton's law of universal gravitation
    const float G = 0.000000000066743;
    // looping to get input from the user in the form of commands
    while (true)
    {
        std::cout << ">";
        std::cin >> command;
        if (command == "/help")
        {
            // showing the available commands to the user
            std::cout << "Use \"/add\" to add an object.\n";
            std::cout << "Use \"/start\" to start the simulation.\n";
            std::cout << "Use \"/clear\" to clear the console window.\n";
            std::cout << "Use \"/exit\" to exit the program.\n";
        }
        else if (command == "/add")
        {
            // allowing the user to add a specific object with specific parameters
            std::cout << "Please enter the x-position of the object (0-1000): ";
            std::cin >> xPos;
            std::cout << "Please enter the y-position of the object (0-1000): ";
            std::cin >> yPos;
            std::cout << "Please enter the radius of the object (pixels): ";
            std::cin >> radius;
            std::cout << "Please enter the mass of the object (kg): ";
            std::cin >> mass;
            std::cout << "Please enter the color of the object (r, g, b): ";
            std::cin >> color;
            std::cout << "Is there an initial velocity for the object (y,n)?";
            std::cin >> temp;
            if (temp == 'y')
            {
                // allowing the user to add initial velocity
                std::cout << "Please enter the initial velocity for the object (km/s): ";
                std::cin >> initialVelocity;
                std::cout << "Please enter the direction for the object: ";
                std::cin >> direction;
            }
            else
            {
                initialVelocity = 0.f;
                direction = 0.f;
            }
            // adding the object to the objects list
            CelestialBody object(xPos, yPos, radius, mass, color, initialVelocity, direction);
            objects.push_back(object);
        }
        else if (command == "/start")
        {
            break;
        }
        else if (command == "/clear")
        {
            system("cls");
        }
        else if (command == "/exit")
        {
            exit(0);
        }
        command == "";
    }

    // creating the window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GravitySimulator2D", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        // looping through all the objects
        for (int i = 0; i < objects.size(); i++)
        {
            // looping through all the available pairs in the objects list
            for (int j = i + 1; j < objects.size(); j++)
            {
                float obj1x = objects[i].get_pos().x;
                float obj1y = objects[i].get_pos().y;
                float obj2x = objects[j].get_pos().x;
                float obj2y = objects[j].get_pos().y;
                float fx;
                float fy;
                float distanceInPixels = std::sqrt((obj2x - obj1x) * (obj2x - obj1x) + (obj2y - obj1y) * (obj2y - obj1y));
                float distanceInKilometers = distanceInPixels * 1000;
                float f = (G * objects[i].get_mass() * objects[j].get_mass()) / (distanceInKilometers * distanceInKilometers);
                //______________________________________//
                if (obj1x < obj2x && obj2y < obj1y)
                {
                    fx = (f * (obj2x - obj1x)) / distanceInPixels;
                    fy = (f * (obj2y - obj1y)) / distanceInPixels;
                    objects[i].accelerate(fx, -1 * fy);
                    objects[j].accelerate(-1 * fx, fy);
                }
                else if (obj1x < obj2x && obj2y > obj1y)
                {
                    fx = (f * (obj2x - obj1x)) / distanceInPixels;
                    fy = (f * (obj2y - obj1y)) / distanceInPixels;
                    objects[i].accelerate(fx, -1 * fy);
                    objects[j].accelerate(-1 * fx, fy);
                }
                else if (obj1x > obj2x && obj2y < obj1y)
                {
                    fx = (f * (obj2x - obj1x)) / distanceInPixels;
                    fy = (f * (obj2y - obj1y)) / distanceInPixels;
                    objects[i].accelerate(fx, -1 * fy);
                    objects[j].accelerate(-1 * fx, fy);
                }
                else if (obj1x > obj2x && obj2y > obj1y)
                {
                    fx = (f * (obj2x - obj1x)) / distanceInPixels;
                    fy = (f * (obj2y - obj1y)) / distanceInPixels;
                    objects[i].accelerate(fx, -1 * fy);
                    objects[j].accelerate(-1 * fx, fy);
                }
            }
        }

        // moving the objects
        for (int i = 0; i < objects.size(); i++)
        {
            objects[i].move();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // rendering the objects
        for (int i = 0; i < objects.size(); i++)
        {
            objects[i].render(window);
        }
        window.display();
    }

    return 0;
}