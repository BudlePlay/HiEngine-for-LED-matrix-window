#pragma once
#include "Canon.h"
#include "conio.h"
#include "Object.h"
#include "WorldOutliner.h"
#include "PushTrap.h"

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 


class Player : public Object {
private:

public:
	std::string w;
	Player();

	Player(FPosition p, std::string name, std::string shape, std::string Type);

	void Work() // 랜더 안에서 돌아가는 Work
	;

	void Control();

	void Move(std::string w, bool ifGo);

	void Shot(std::string D);

	virtual void OnCollision(Object* other);

	std::string getW();
};