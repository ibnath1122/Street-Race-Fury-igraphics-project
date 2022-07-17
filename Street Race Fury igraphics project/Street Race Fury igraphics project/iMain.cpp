#include<iostream>
#include "iGraphics.h"
#include "bitmap_loader.h"

using namespace std;

int ScreenWidth = 900;
int ScreenHight = 500;
int w;
int h;
int m = 420;
int n = 0;
#define CarNumber 10

int win_x = 900, win_y = 500;
char img[30][50] = { "images\\s9.bmp", "images\\s8.bmp", "images\\s7.bmp", "images\\s6.bmp", "images\\s5.bmp", "images\\s4.bmp", "images\\s3.bmp", "images\\s2.bmp", "images\\s1.bmp", "images\\s.bmp" };
int height = 50;


int score = 0;

struct imgposition
{
	int x;
	int y;
};
imgposition pos[10];

void imgpos(){
	int dy = 0;
	for (int i = 0; i<10; i++)
	{
		pos[i].x = 0;
		pos[i].y = dy;
		dy += height;
	}

}
void change(){
	for (int i = 0; i<10; i++){
		pos[i].y -= height;
		if (pos[i].y<0){
			pos[i].y = win_y - height;
		}
	}
}


int enemy_x0 = 175;
int enemy_x1 = 300;
int enemy_x2 = 420;
int enemy_x3 = 550;
int enemy_x4 = 675;

int enemy_y0 = 450;
int enemy_y1 = 550;
int enemy_y2 = 550;
int enemy_y3 = 550;
int enemy_y4 = 550;

char car[40] = { "car7.bmp" };
char car1[40] = { "car8.bmp" };
char car2[40] = { "car9.bmp" };
char car3[40] = { "car6.bmp" };
char car4[40] = { "car10.bmp" };

int userNameInputIndex;
bool name = false;

char userNameInput[100];
bool temp;


struct buttonPosition
{
	int x;
	int y;
}bPosition[4];

char button[4][70] = { "playgame6.bmp", "credits6.bmp", "highscore6.bmp", "instruction7.bmp" };
char homemenu[30] = { "carpage4.bmp" };
char play[30] = { "playgame33.bmp" };
char aboutus[40] = { "credits4.bmp" };
char highscore[40] = { "highscore4.bmp" };
char instruction[40] = { "instruction4.bmp" };
char loading[40] = { "carbody6.bmp" };

char NameInput[25] = "nameInput1.bmp";
char GameOver[40] = "gameover2.bmp";


int gamepage = -2;
bool soundOn = false;
char soundPath[100] = "music4.wav";
void Sound();
int rec_x = 20;
int rec_y = 20;

void loading2()
{
	if (rec_x < 300)
	{
		rec_x += 10;
		if (rec_x >= 300)
		{
			gamepage = -1;
		}
	}
}


void MainCar()
{

	iShowBMP2(m, n, "carr.bmp", 0);
}


void iDraw()
{
	iClear();
	if (gamepage == -2)
	{
		//loading
		iShowBMP(0, 0, loading);
		//Rectangle draw for loading animation 
		iSetColor(255, 255, 255);
		iText(380, 150, "LOADING....", GLUT_BITMAP_HELVETICA_18);
		iSetColor(255, 255, 255);
		iRectangle(300, 100, 300, 20);
		iFilledRectangle(300, 100, rec_x, rec_y);
	}

	else if (gamepage == -1)
	{
		iShowBMP(0, 0, homemenu);
		for (int i = 0; i < 4; i++)
		{
			iShowBMP2(bPosition[i].x, bPosition[i].y, button[i], 0);
		}

	}
	else if (gamepage == 0)
	{
		if (name)
		{
			//temp = false;
			for (int i = 0; i < 10; i++)
			{
				iShowBMP(pos[i].x, pos[i].y, img[i]);
			}
			iSetColor(0, 0, 0);
			iText(100, 250, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
			iShowBMP2(enemy_x0, enemy_y0, car, 0);
			iShowBMP2(enemy_x1, enemy_y1, car1, 0);
			iShowBMP2(enemy_x2, enemy_y2, car2, 0);
			iShowBMP2(enemy_x3, enemy_y3, car3, 0);
			iShowBMP2(enemy_x4, enemy_y4, car4, 0);

			MainCar();
		}
		else
		{
			iShowBMP(0, 0, NameInput);
			iSetColor(255, 255, 255);
			iFilledRectangle(300, 200, 300, 30);
			iSetColor(255, 255, 255);
			iText(350, 250, "Enter Your Name", GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255, 255, 255);
			iRectangle(300, 200, 300, 30);
			iSetColor(0, 0, 0);
			iText(400, 210, userNameInput, GLUT_BITMAP_TIMES_ROMAN_24);
		}


	}
	else if (gamepage == 1)
	{
		iShowBMP(0, 0, aboutus);
	}
	else if (gamepage == 2)
	{
		iShowBMP(0, 0, highscore);
	}
	else if (gamepage == 3)
	{
		iShowBMP(0, 0, instruction);
	}
	else if (gamepage == 4)
	{
		iShowBMP(0, 0, GameOver);
	}
	else
	{
	}
}



void enemy_cordinate_change1()
{

	if (enemy_y0 >= 0)
	{
		enemy_y0 -= 10;
		if (enemy_y0  < 0)
		{
			enemy_y0 = 450;

		}
		else if (enemy_y0 = 0)
		{
			score = score + 10;
		}
	}
	if (enemy_y1 >= 0)
	{
		enemy_y1 -= 7;
		if (enemy_y1  < 0)
		{
			enemy_y1 = 550;
		}
		else if (enemy_y1 = 0)
		{
			score = score + 10;
		}
	}
	if (enemy_y2 >= 0)
	{
		enemy_y2 -= 7;
		if (enemy_y2  < 0)
		{
			enemy_y2 = 550;

		}
		else if (enemy_y2 = 0)
		{
			score = score + 10;
		}
	}
	if (enemy_y3 >= 0)
	{
		enemy_y3 -= 8;
		if (enemy_y3   < 0)
		{
			enemy_y3 = 550;

		}
		else if (enemy_y3 = 0)
		{
			score = score + 10;
		}
	}
	if (enemy_y4 >= 0)
	{
		enemy_y4 -= 9;
		if (enemy_y4   < 0)
		{
			enemy_y4 = 550;

		}
		else if (enemy_y4 = 0)
		{
			score = score + 10;
		}
	}
	else
	{

	}


}


void Collision()
{

	if ((m +65  >= enemy_x0) && m <= (enemy_x0 + 61) && ((n + 106>= enemy_y0) && (n <= enemy_y0 + 100)))
	{
		gamepage = 4;

	}
	if ((m + 60 >= enemy_x1) && m <= (enemy_x1 + 61) && ((n + 106 >= enemy_y1) && (n <= enemy_y1 + 106)))
	{
		gamepage = 4;

	}
	if ((m + 60 >= enemy_x2) && m <= (enemy_x2 + 60) && ((n + 102 >= enemy_y2) && (n <= enemy_y2 + 102)))
	{
		gamepage = 4;

	}
	if ((m + 70 >= enemy_x3) && m <= (enemy_x3 + 70) && ((n + 102 >= enemy_y3) && (n <= enemy_y3 + 102)))
	{
		gamepage = 4;

	}
	if ((m + 60 >= enemy_x4) && m <= (enemy_x4 + 60) && ((n + 108 >= enemy_y4) && (n <= enemy_y4 + 108)))
	{
		gamepage = 4;
	}
	else
	{

	}

}



//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://



//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://



/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		for (int i = 0; i < 4; i++)
		{
			if (mx >= bPosition[i].x && mx <= bPosition[i].x + 250 && my >= bPosition[i].y && my <= bPosition[i].y + 55)
			{
				gamepage = i;
			}

		}

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//printf("%d %d\n", mx, my);
	}

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{

	if (key == 's')
	{
		Sound();
	}
	if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
	{

		userNameInput[userNameInputIndex++] = key;
	}
	if (key == '\b')
	{
		userNameInputIndex--;

		if (userNameInputIndex < 0)
		{
			userNameInputIndex = 0;
		}

		userNameInput[userNameInputIndex] = '\0';
	}
	if (key == '\r')
	{
		gamepage = 0;
		name = true;
	}
	if (key == 'p')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_HOME)
	{
		gamepage = -1;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		if (m >= 170)
			m = m - 10;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		if (m <= 670)
			m = m + 10;
	}
	else if (key == GLUT_KEY_UP)
	{
		if (n<390)
			n = n + 10;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		if (n>0)
			n = n - 10;
	}
	else if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	else
	{

	}

}

void Sound()
{
	if (soundOn)
	{
		soundOn = false;
		PlaySound(0, 0, 0);
	}
	else
	{
		soundOn = true;
		PlaySound(soundPath, NULL, SND_ASYNC);
	}
}


int main()
{
	///srand((unsigned)time(NULL));
	int sum = 30;
	for (int i = 3; i >= 0; i--)
	{
		bPosition[i].x = 60;
		bPosition[i].y = sum;
		sum += 60;

	}
	Sound();
	imgpos();
	iSetTimer(300, change);
	iSetTimer(100, loading2);
	enemy_cordinate_change1();
	iSetTimer(250, enemy_cordinate_change1);
	Collision();
	iSetTimer(20, Collision);
	iInitialize(ScreenWidth, ScreenHight, "Street Race Fury");
	///updated see the documentations

	iStart();
	return 0;
}
