#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Vect2
{
public:
	int x = 0;
	int y = 0;

	Vect2(int xx, int yy) : x(xx), y(yy) {}
	bool operator==(const Vect2& s) const;
	bool operator<(const Vect2& s) const;
	bool operator>(const Vect2& s) const;
	bool operator!=(const Vect2& s) const;

};

class GameObject
{
public:
	GameObject(const map<Vect2, wchar_t>& ffields) { fields = ffields; };
	virtual ~GameObject()=0 {};
	virtual void Update(float deltaTime) = 0;
	virtual void SetPosition(float x, float y) = 0;
	virtual bool IsIndestructible() = 0;
	virtual bool IsSlowing() = 0;
	virtual bool IsFalling() = 0;

	const map<Vect2, wchar_t>& Fields() const { return fields; }
	const float& PositionX() const { return positionX; }
	const float& PositionY() const { return positionY; }
	const void add(int a, int b, char c);
	bool operator==(const GameObject& s) const;

protected:
	map<Vect2, wchar_t> fields;
	float positionX = 0;
	float positionY = 0;
};

class StandardObject : public GameObject
{
public:
	StandardObject(const map<Vect2, wchar_t>& ffields) : GameObject(ffields) {};
	void Update(float deltaTime) override;
	void SetPosition(float x, float y) override;
	bool IsIndestructible() override { return false; }
	bool IsSlowing() override { return false; }
	bool IsFalling() override { return false; }
};

class WeirdObject : public GameObject
{
	WeirdObject(const map<Vect2, wchar_t>& ffields) : GameObject(ffields) {};
	void Update(float deltaTime) override;
	void SetPosition(float x, float y) override;
	bool IsIndestructible() override { return true; }
	bool IsSlowing() override { return true; }
	bool IsFalling() override { return true; }
};
class FallingObject : public StandardObject
{
public:
	FallingObject(const map<Vect2, wchar_t>& ffields) : StandardObject(ffields) {};
	bool IsFalling() { return true; }
};

class IndestructibleObject : public StandardObject
{
public:
	IndestructibleObject(const map<Vect2, wchar_t>& ffields) : StandardObject(ffields) {};
	bool IsIndestructible() { return true; }
};

class SlowingObject : public StandardObject
{
public:
	SlowingObject(const map<Vect2, wchar_t>& ffields) : StandardObject(ffields) {};
	bool IsSlowing() { return true; }
};

class Collection
{
	vector<GameObject*> objects;
public:
	void add(GameObject* o);
	bool remove(GameObject* o);
	friend ostream& operator<< (ostream& os, const Collection& f);
	friend istream& operator>> (istream& is, Collection& f);
	void write_to_file(const string& file, char mode = 'w') const;
	void read_from_file(const string& file);
};

