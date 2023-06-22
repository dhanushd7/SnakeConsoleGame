#include "Food.h";
#include<ctime>
#include<stdlib.h>
#define WIDTH 50
#define HEIGHT 30

Food::Food(){
	srand(time(NULL)); //seed
	foodPlotter();
}

void Food::foodPlotter(){
	foodPos.X = rand()%WIDTH+1;
	foodPos.Y = rand()%HEIGHT+1;
}

COORD Food::getFoodPosition(){
	return foodPos;
}
