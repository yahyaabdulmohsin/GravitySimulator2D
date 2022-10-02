# GravitySimulator2D

honors project for physics :)

You need:
- SFML

![alt text](https://yahyaabdulmohsin.com/GravitySimulator2D/initial.png)

![alt text](https://yahyaabdulmohsin.com/GravitySimulator2D/final.png)

Build with g++:

>g++ -c main.cpp CelestialBody.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC
>
>g++ main.o CelestialBody.o -o main -LC:\SFML-2.5.1\lib -static -static-libgcc -static-libstdc++ -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32