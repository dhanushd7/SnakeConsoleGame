#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<vector>
#include "snake.h"
#include<conio.h>
#include"food.h"
#define WIDTH 50
#define HEIGHT 30
#define up_key 72
#define down_key 80
#define left_key 75
#define right_key 77
using namespace std;


Snake snake({WIDTH/2,HEIGHT/2}); //classname object(arguments)
Food food;
void board(){
	vector<COORD>snakeBody = snake.getSnakeBody();
	for(int i=0;i<=HEIGHT+1;i++){
		cout<<"\t\t";

		for(int j=0;j<=WIDTH+1;j++){
			if(i==0 || i==HEIGHT+1 || j==0 || j==WIDTH+1){
				cout<<"#";
			}
			else if(i==food.getFoodPosition().Y &&
			j==food.getFoodPosition().X)
			{
				cout<<"$";
			}
			else{
				bool snakePos = false;
				for(int k=0;k<snakeBody.size();k++){
					if(i==snakeBody[k].Y &&
					j==snakeBody[k].X){
						cout<<"o";
						snakePos=true;
						break;
					}
				}
				if(!snakePos){
					cout<<' ';
				}
			}
		}
		cout<<endl;
	}
}
int main(){
	//creating board
	while(true){
		Sleep(100);
		board();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
		if(kbhit()){ //keyboard hit
			switch(getch()){
				case up_key: //getch() knows the 
				snake.setDir('u');break;
				case down_key: 
				snake.setDir('d');break;
				case left_key: 
				snake.setDir('L');break;
				case right_key: 
				snake.setDir('R');break;
			}
		}
		snake.moveSnake();
		if(snake.collided()){
			cout<<endl;
			cout<<"\t\t\t\tGameOver";
			break;
		}
		
		if(snake.eaten(food)){
			snake.increaseBody();
			food.foodPlotter(); //place in new place
			
		}
	}

	return 0;
}
