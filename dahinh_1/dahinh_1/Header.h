#pragma once

class Animal
{
public:
	virtual void call();
};

class Cat: public Animal
{
public:
	void call();
};

class Dog: public Animal
{
public:
	void call();
};

