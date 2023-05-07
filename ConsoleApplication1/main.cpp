// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameObject.h"
#include <map>
#include <vector>



using namespace std;

int main()
{
    Collection bruh;
    bruh.read_from_file("test.txt");
    /*GameObject* st = new StandardObject({ { Vect2(0, 0), 'a' },{ Vect2(0, 1), 'a' },{ Vect2(0, 2), 'a' } });
    GameObject* i = new IndestructibleObject({ { Vect2(1, 1), 'v' } });
    GameObject* s = new SlowingObject({ { Vect2(2, 2), 'c' } });
    GameObject* f = new FallingObject({ { Vect2(3, 3), 'd' } });
    
    bruh.add(st);
    bruh.add(i);
    bruh.add(s);
    bruh.add(f);
    bruh.write_to_file("test.txt");
    vector<GameObject*> y = { st, i, s, f };
    for (auto j : y)
    {
        cout << j->IsFalling() << j->IsIndestructible() << j->IsSlowing() << '\n';
    }*/

}
