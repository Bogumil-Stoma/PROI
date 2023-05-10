// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameObject.h"
#include <map>
#include <vector>



using namespace std;

int main(int argc, char* argv[])
{
    
    if (argc > 1)
    {

        string arg = (argv[1]);
        if ((arg == "-h") || (arg == "--help"))
        {
            cout << "--help prints help\n";
            cout << "(-s) --save [file.txt] aks user for input and saves to specified file\n";
            cout << "(-r) --read [file.txt] reads from file.txt and displays info about recipe";
        }
        else if ((arg == "-w" || arg == "--write") && argc > 2)
        {
            string fileName;
            cout << "Input file name> ";
            cin >> fileName;
            Collection game;
            cin >> game;
            game.write_to_file(fileName);
        }
        else if ((arg == "-r" || arg == "--read") && argc > 2)
        {
            Collection game;
            game.read_from_file(string(argv[2]));
            cout << game;
        }
        else {
            cout << "-h for help";
        }
        return 0;
    }
    else {
        Collection objects;
        GameObject* st = new StandardObject({ { Vect2(0, 0), 'a' },{ Vect2(0, 1), 'a' },{ Vect2(0, 2), 'a' } });
        GameObject* i = new IndestructibleObject({ { Vect2(1, 1), 'v' } });
        GameObject* s = new SlowingObject({ { Vect2(2, 2), 'c' } });
        GameObject* f = new FallingObject({ { Vect2(3, 3), 'd' } });

        objects.add(st);
        objects.add(i);
        objects.add(s);
        objects.add(f);
       
        for (auto j : objects)
        {

            cout << j->TellMyName() << '\n';
        }
    }
}
