#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

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
	Vect2 operator+(const Vect2& s) const;
	Vect2 operator*(const int& s) const;
	Vect2 operator-(const Vect2& s) const;
	Vect2 operator/(const int& s) const;

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
	virtual string TellMyName() = 0;

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
	~StandardObject() {}
	void Update(float deltaTime) override;
	void SetPosition(float x, float y) override;
	bool IsIndestructible() override { return false; }
	bool IsSlowing() override { return false; }
	bool IsFalling() override { return false; }
	virtual string TellMyName() override { return "Standard Object"; }
};

class WeirdObject : public GameObject
{
	WeirdObject(const map<Vect2, wchar_t>& ffields) : GameObject(ffields) {};
	void Update(float deltaTime) override;
	void SetPosition(float x, float y) override;
	bool IsIndestructible() override { return true; }
	bool IsSlowing() override { return true; }
	bool IsFalling() override { return true; }
	string TellMyName() override { return "Weird Object"; }
};
class FallingObject : public StandardObject
{
public:
	FallingObject(const map<Vect2, wchar_t>& ffields) : StandardObject(ffields) {};
	bool IsFalling() { return true; }
	string TellMyName() override  { return "Falling Object"; }
};

class IndestructibleObject : public StandardObject
{
public:
	IndestructibleObject(const map<Vect2, wchar_t>& ffields) : StandardObject(ffields) {};
	bool IsIndestructible() { return true; }
	string TellMyName() override { return "Indestructible Object"; }
};

class SlowingObject : public StandardObject
{
public:
	SlowingObject(const map<Vect2, wchar_t>& ffields) : StandardObject(ffields) {};
	bool IsSlowing() { return true; }
	string TellMyName()override { return "Slowing Object"; }
};

class Collection
{
public:
	vector<GameObject*> objects;

	void add(GameObject* o);
	bool remove(GameObject* o);
	friend ostream& operator<< (ostream& os, const Collection& f);
	friend istream& operator>> (istream& is, Collection& f);
	void write_to_file(const string& file, char mode = 'w') const;
	void read_from_file(const string& file);
	struct Iterator
	{
		using value_type = GameObject*;
		using pointer = value_type*;
		using reference = value_type&;

		Iterator(const pointer& ptr) : m_ptr(ptr) {}
		

		GameObject* operator*() const { return *m_ptr; }
		reference operator->() { return *m_ptr; }
		Iterator& operator++()
		{
			m_ptr++;
			return *this;
		}
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
	private:
		pointer m_ptr;
	};
public:
	Iterator begin() { return Iterator(&objects[0]); }
	Iterator end() { return Iterator(&objects[objects.size() - 1] + 1); }

};

