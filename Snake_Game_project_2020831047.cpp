#include <conio.h>
#include <vector>
#include <graphics.h>
#include <dos.h>       // libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int length = 2;
int lengthmax = 2; // controls snake's length

int x1 = 30;
int y1 = 170; // snake's location

//char direc = '-';
//char last = '-'; // direction
int key_dir,p_dir=1;

bool playing = true; // if you are alive

int fruitx;
int fruity;
bool eaten = false; // fruit position

vector<int> snakex;
vector<int> snakey; // where your tail needs to go

int i = 1;
int imax = 0; // some basic for() things

char score[50];
int score1; // your score

void fruit();
void graphic();
void move();
void start();
void update(); // all voids

int main()
{
	start();


	while (playing == true)
	{
		update();

		if (x1 >= 615 || x1 < 10 || y1 >= 620 || y1 < 10) // check if you are inside the map
		{
			playing = false; // you die :P
		}

		if (lengthmax > 3 ||key_dir!=1 && key_dir!=2 && key_dir!=3 && key_dir!=4 && key_dir!=0);
		{
			for (length = lengthmax; length >= 0; length--)
			{
				if (x1 == snakex[i] && y1 == snakey[i])
				{
					playing = false; // check if you head hits your tail
				}

				i--;
			}

			i = imax;
		}
	}

	if (playing == false)
	{
		cleardevice();
		//delay(150);
		outtextxy(70, 170, "YOU LOST, YOUR ");
		outtextxy(188, 170, score);
		delay(500);
		getch();
		getch();
		return 0; // game over things
	}
}

void start() // execute at the start of the game
{
	sprintf(score, "SCORE : %d ", score1);

	srand(time(NULL));
	initwindow(630, 470, "SnakeGame");

	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	rectangle(0, 0, 630, 10);
	floodfill(5, 5, GREEN);

	setcolor(WHITE);
	outtextxy(10, 0, score);

	fruitx = rand() % 34;
	fruity = rand() % 34;
	fruity = fruity * 10;
	fruitx = fruitx * 10;

	if(fruity == 0){
		fruity = fruity+10;
	}


	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx, fruity, fruitx + 10, fruity + 10);
	floodfill(fruitx + 5, fruity + 5, RED);
}

void update() // execute every frame
{
	sprintf(score, "SCORE : %d ", score1);

	delay(150);

	snakex.push_back(x1);
	snakey.push_back(y1); // makes your tail know the way to your head

	fruit();

	move();

	graphic();

}

void move() // all move related things
{
	 if(GetAsyncKeyState(VK_RIGHT)){
            key_dir=1;
        }else if(GetAsyncKeyState(VK_LEFT)){
            key_dir=2;
        }else if(GetAsyncKeyState(VK_UP)){
            key_dir=3;
        }else if(GetAsyncKeyState(VK_DOWN)){
            key_dir=4;
        }else {
            key_dir=0;
        }

        switch(key_dir){
        case 0:
            if(p_dir==1) x1=x1+10;
            else if(p_dir==2) x1=x1-10;
            else if(p_dir==3) y1=y1-10;
            else if(p_dir==4) y1=y1+10;
            else key_dir=0;

            break;

        case 1:
             x1=x1+10;
             p_dir=1;
             break;
        case 2:
             x1=x1-10;
             p_dir=2;
             break;
        case 3:
             y1=y1-10;
             p_dir=3;
             break;
        case 4:
             y1=y1+10;
             p_dir=4;
             break;
        }

}

void graphic() // the graphic
{
	cleardevice();

	 setfillstyle(SOLID_FILL,LIGHTMAGENTA);
     bar(0,0,630,470);

	setcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	rectangle(0,0, 630, 10);			// green line
	floodfill(5, 5, LIGHTBLUE);
	bar(0,0,630,10);
     bar(0,0,10,470);
     bar(0,470,630,460);
     bar(620,10,630,470);


	setcolor(WHITE);

	outtextxy(10, 0, score); // score
   //setfillstyle(SOLID_FILL,LIGHTBLUE);

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx, fruity, fruitx + 10, fruity + 10); // fruit
	floodfill(fruitx + 5, fruity + 5, RED);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(x1, y1, x1 + 10, y1 + 10); // head
	floodfill(x1 + 5, y1 + 5, WHITE);


	for (int length = lengthmax; length > 0; length--)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		rectangle(snakex[i], snakey[i], snakex[i] + 10, snakey[i] + 10); // tail
		floodfill(snakex[i] + 5, snakey[i] + 5, WHITE);
		i--;
	}

	imax++;
	i = imax;

}

void fruit() // fruit things
{
	if (x1 == fruitx && y1 == fruity)
	{
		eaten = true;

	}

	if (eaten == true)
	{
		eaten = false;
		lengthmax++;
		score1++;
		length = lengthmax;
		fruitx = rand() % 34;
		fruity = rand() % 34;
		fruity = fruity * 10;
		fruitx = fruitx * 10; // random location

		for (length = lengthmax; length >= 0; length--)
		{
			if (fruitx == snakex[i] && fruity == snakey[i])
			{
				fruitx = rand() % 34;
				fruity = rand() % 34;
				fruity = fruity * 10;
				fruitx = fruitx * 10; // don't spawn the fruit on the snake
			}

			i--;
		}

		if (fruity == 0)
		{
			fruity = 10;
		}

		i = imax;

		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		rectangle(fruitx, fruity, fruitx + 10, fruity + 10); // makes fruit
		floodfill(fruitx + 5, fruitx + 5, RED);
	}
}
