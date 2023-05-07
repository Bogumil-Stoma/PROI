#include "GameObject.h"


using namespace std;

bool GameObject::operator==(const GameObject& s) const
{
    return this->positionX == s.positionX && this->positionY == s.positionY && this->fields == s.fields;
}

const void GameObject::add(int a, int b, char c)
{
    this->fields.insert_or_assign( Vect2(a,b),(wchar_t)c );
}

void StandardObject::Update(float deltaTime)
{
    cout << "standard";
}

void StandardObject::SetPosition(float x, float y)
{
    this->positionX = x;
    this->positionY = y;
}

void WeirdObject::Update(float deltaTime)
{
    cout << "weird";
}

void WeirdObject::SetPosition(float x, float y)
{
    this->positionX = y;
    this->positionY = x;
} 

void Collection::add(GameObject* o)
{
    objects.push_back(o);
}

bool Collection::remove(GameObject* o)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        if (objects[i] == o)
        {
            objects.erase(objects.begin() + i);
            return true;
        }
    }
    return false;

}

ostream& operator<<(ostream& os, const Collection& f)
{
    for (size_t i = 0; i < f.objects.size(); i++)
    {
        if (f.objects[i]->IsFalling() == 1)
        {
            os << "f"<<'\n';
        }
        else if (f.objects[i]->IsIndestructible() == 1)
        {
            os << "i" << '\n';
        }
        else if (f.objects[i]->IsSlowing() == 1)
        {
            os << "s" << '\n';
        }
        else
        {
            os << "t" << '\n';
        }
        os << f.objects[i]->Fields().size() << '\n';
        for (auto i : f.objects[i]->Fields())
        {
            os << i.first.x << '\n';
            os << i.first.y << '\n';
            os << (char)i.second << '\n';
        }
        os << '\n';
    }
    return os;
}

istream& operator>>(istream& is, Collection& f)
{
    char name[3];
    //is.getline(name, 100);
    while (!(is.eof()))
    {
        GameObject* x = new StandardObject({});
        is >> name;
        if (name[0] == 's')
        {
            GameObject* x = new SlowingObject({});
        }
        else if (name[0] == 'f')
        {
            GameObject* x = new FallingObject({});
        }
        else if (name[0] == 'i')
        {
            GameObject* x = new IndestructibleObject({});
        }
        else if (name[0] == 't')
        {
            GameObject* x = new StandardObject({});
        }
        int i;
        is >> i;
        int a, b;
        char c;
        while (i > 0)
        {
            is >> a;
            is >> b;
            is >> c;
            x->add(a, b, c);
            i--;
        }
        f.add(x);
    }
    return is;

}
bool Vect2::operator==(const Vect2& s) const
{
    return this->x == s.x && this->y == s.y;
}

bool Vect2::operator<(const Vect2& s) const
{
    return this->x < s.x || this->y < s.y;
}

bool Vect2::operator>(const Vect2& s) const
{
    return this->x > s.x || this->y > s.y;
}

bool Vect2::operator!=(const Vect2& s) const
{
    return not(this->x == s.x && this->y == s.y);
}

void Collection::write_to_file(const string& file, char mode) const
{
    ofstream myfile;
    if (mode == 'a') myfile.open(file, ios_base::app);
    else myfile.open(file);
    if (myfile.is_open())
    {
        myfile << *this << '\n';
        myfile.close();
    }
    else {
        cerr << "\nUnable to open the file\n";
    }
}

void Collection::read_from_file(const string& file)
{
    string line;
    ifstream myfile(file);
    if (myfile.is_open())
    {
        myfile >> *this;

        myfile.close();
    }

    else cout << "Unable to open file";
}
