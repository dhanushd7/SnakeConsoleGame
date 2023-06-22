#include "snake.h"
#define WIDTH 50
#define HEIGHT 30
#include<vector>
using namespace std;

Snake::Snake(COORD pos){
	this->pos = pos; //same name of use this
	len=1;
	snakeBody.push_back(pos);//initial position
	//head
}

COORD Snake::getPos(){	return pos;}

void Snake::setDir(int d){
	direction=d;
}

void Snake::moveSnake(){
	switch(direction){
	case 'u' : pos.Y--; break;
	case 'd' : pos.Y++;break;
	case 'L' : pos.X--;break;
	case 'R' : pos.X++;break;
}

snakeBody.push_back(pos);
if(snakeBody.size()>len){
	snakeBody.erase(snakeBody.begin());
}
}

bool Snake::collided(){
	if(pos.X==0 || pos.X==WIDTH+1 ||
	pos.Y==0 || pos.Y==HEIGHT+1){
		return true;
	}
	return false;
}

bool Snake::eaten(Food food){ //food object as argument
	if(pos.X==food.getFoodPosition().X && 
	pos.Y==food.getFoodPosition().Y){
		return true;
	}
	return false;
}

void Snake::increaseBody(){
	len++;
}
vector<COORD> Snake::getSnakeBody(){
	return snakeBody;
}
