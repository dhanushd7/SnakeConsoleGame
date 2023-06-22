#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include "food.h"
#include<vector>
using namespace std;

class Snake{
	private:
		COORD pos;
		int len;
		int direction;
		vector<COORD> snakeBody;
	public:
	    Snake(COORD pos);
            void board();
	    COORD getPos();
	    void setDir(int d);
	    void moveSnake();
	    bool collided();
	    bool eaten(Food food);
	    vector<COORD>getSnakeBody();
	    void increaseBody();
		
};
#endif //SNAKE_H

