#include<iostream>
#include<Windows.h>
using namespace std;

// X IS VERTICAL; Y IS HORIZONTAL; //

struct Position{
	int x = 0;
	int y = 0;
};

struct Entity{
	int hp;
	Position position;
};

Entity a,b;
Entity* player = &a;
Entity* enemy = &b;

void HandleMovement()
{
	bool isPressed;
	
	if(GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
	{
		isPressed = true;
			
		if(isPressed = true)
		{
			player->position.x++;
			isPressed = false;	
		}
	}	
		
	if(GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
	{
		isPressed = true;
		
		if(isPressed = true)
		{
			player->position.y++;
			isPressed = false;
		}
	}
		
	if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
	{
		isPressed = true;
			
		if(isPressed = true)
		{
			player->position.y--;
			isPressed = false;
		}
	}
		
	if(GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
	{
		isPressed = true;
		
		if(isPressed = true)
		{
			player->position.x--;
			isPressed = false;
		}
	}		
	
	//Handles Player Movement
}



int main()
{	
	player->position.x = 5;
	player->position.y = 5;
	
	while(true)
	{
		HandleMovement();
		
		//use matrix
		
		for(int i = 0; i < 11; i++)
		{
			for(int j = 0; j < 11; j++)
			{
				if(player->position.x == i && player->position.y == j)
				{
					cout<<" & ";
				}
				else if(enemy->position.x == i && enemy->position.y == j)
				{
					cout<<" % ";
				}
				/*else
				{
					cout<<" o ";
				}*/
			}
			
			cout<<"\n";
		}
			
		Sleep(150);	
		system("CLS");
	}
}
