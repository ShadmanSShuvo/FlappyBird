#include "iGraphics.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
int speed = 20;
void gameover();
void drawPipes();
void resetPipes();
void drawHomepage();
void drawSettingsPage();
void drawInstructionPage();
void drawScorePage();
void drawGamePage();
void back();
void info();
void scores();
void settings();
void Game();
void scoreUpdate();
int hiscore = 0;
int homepage = 1;
int settingsPage = 0;
int InstructionPage = 0;
int scorePage = 0;
int gamePage = 0;
int bx=30, by=280;
int score = 0;
int Bird = 1;
int Bird2 = 0;
int game_over = 0;
void resetStates() {
    homepage = 0;
    settingsPage = 0;
    InstructionPage = 0;
    scorePage = 0;
    gamePage = 0;
    game_over = 0;
}
void back() {
	resetStates();
	homepage = 1;
}
void info() {
	resetStates();
	InstructionPage = 1;
}
void scores() {
	resetStates();
	scorePage = 1;
}
void settings() {
	resetStates();
	settingsPage = 1;
}
void Game() {
	resetStates();
	gamePage = 1;
}
int pipeX[6];
int pipeY[6];
void resetPipes(){
	bx = 30;
	by = 280;
	pipeX[0] = 700;
	pipeX[1] = 800;
	pipeX[2] = pipeX[0] + 300 + rand()%100;
	pipeX[3] = pipeX[1] + 300 + rand()%100;
	pipeX[4] = pipeX[2] + 300 + rand()%100;
	pipeX[5] = pipeX[3] + 300 + rand()%100;
	pipeY[0] = 320;
	pipeY[1] = 0;
	pipeY[2] = 320 + rand()%40;
	pipeY[3] = 10;
	pipeY[4] = 320 + rand()%40;
	pipeY[5] = 5;
}
int coinX = 1500, coinY = 320;
int flag[6]={0};
bool Music=0;
void iDraw()
{
	iClear();
	if(Music){
		PlaySound(TEXT("music.wav"), NULL, SND_SYNC);
	}
	if (homepage == 1)
	{
		drawHomepage();
	}
	else if (InstructionPage == 1)
	{
		drawInstructionPage();
	}
	else if (scorePage == 1)
	{
		drawScorePage();
	}
	else if (settingsPage == 1)
	{
		drawSettingsPage();
	}
	else if (gamePage == 1)
	{
		drawGamePage();
	}
}
void drawHomepage() {
	iFilledRectangle(0,0,1000,562);
	iShowBMP(0,0,"images\\bground2.bmp");
	iShowBMP2(150, 100, "images\\play.bmp", 0);
	iShowBMP2(350, 100, "images\\settings.bmp", 0);
	iShowBMP2(550, 100, "images\\leaderboard.bmp", 0);
	iShowBMP2(750, 100, "images\\info2.bmp", 0);
}
void drawSettingsPage() {
	iFilledRectangle(0,0,1000,562);
	iSetColor(255, 0, 0);
	iShowBMP(0,0,"images\\bground2.bmp");
	iShowBMP2(300,400,"images\\easy.bmp",0);
	iShowBMP2(300,300,"images\\medium.bmp",0);
	iShowBMP2(300,200,"images\\hard.bmp",0);
	iShowBMP2(500, 400, "images\\bird.bmp", 0);
	iShowBMP2(500, 300, "images\\bird2.bmp", 0);
	iShowBMP2(600, 400, "images\\musicon.bmp", 0);
	iShowBMP2(600, 300, "images\\musicoff.bmp", 0);
	iShowBMP2(0, 500, "images\\back.bmp", 0);
}
void drawInstructionPage() {
	iFilledRectangle(0,0,1000,562);
	iShowBMP(0,0,"images\\bground2.bmp");
	iSetColor(0, 0, 0);
	iText(500, 400, "Here are some Instruction for the Game:\n", GLUT_BITMAP_HELVETICA_18);
	iText(500, 350, "Use the Arrow keys for avoiding the gravity effect.\n", GLUT_BITMAP_HELVETICA_18);
	iText(500, 300, "Go through the gap between the pipes.\n", GLUT_BITMAP_HELVETICA_18);
	iText(500, 250, "Don't collide with the pipes or fall in the ground.\n", GLUT_BITMAP_HELVETICA_18);
	iShowBMP2(0, 500, "images\\back.bmp", 0);
}
void drawScorePage() {
	iFilledRectangle(0,0,1000,562);
	iShowBMP(0,0,"images\\bground2.bmp");
	char strscr[50];
	sprintf(strscr, "%d", hiscore);
	iSetColor(0, 0, 0);
	iText(500, 400, "HighScore:\n", GLUT_BITMAP_HELVETICA_18);
	iText(600, 400, strscr, GLUT_BITMAP_HELVETICA_18);
	iShowBMP2(0, 500, "images\\back.bmp", 0);
}
void drawPipes()
{
	iShowBMP2(pipeX[0], pipeY[0], "images\\pipe1.bmp", 0);
	iShowBMP2(pipeX[1], pipeY[1], "images\\pipe2.bmp", 0);
	iShowBMP2(pipeX[2], pipeY[2], "images\\pipe1.bmp", 0);
	iShowBMP2(pipeX[3], pipeY[3], "images\\pipe2.bmp", 0);
	iShowBMP2(pipeX[4], pipeY[4], "images\\pipe1.bmp", 0);
	iShowBMP2(pipeX[5], pipeY[5], "images\\pipe2.bmp", 0);
	iShowBMP2(coinX, coinY, "images\\coin.bmp", 0);
}
void drawGamePage()
{
	iClear();
	iFilledRectangle(0,0,1000,562);
	iShowBMP(0, 0, "images\\bground2.bmp");
	iShowBMP2(0, 500, "images\\back.bmp", 0);
	if (Bird == 1)
	{
		iShowBMP2(bx, by, "images\\bird.bmp", 0);
	}
	else if (Bird2 == 1)
	{
		iShowBMP2(bx, by, "images\\bird2.bmp", 0);
	}
	drawPipes();
	iSetColor(0, 0, 0);
	char scoreStr[20];
	sprintf(scoreStr, "Score: %d", score);
	iText(10, 450, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	if(Bird){
		if ((by <= 0 || by >= (562 - 45)) || (((bx + 45) >= pipeX[0] && bx <= (pipeX[0] + 93)) && !((by + 30) < pipeY[0] || by > (pipeY[0] + 250)))|| (((bx + 45) >= pipeX[1] && bx <= (pipeX[1] + 93)) && !((by + 30) < pipeY[1] || by > (pipeY[1] + 250))) || (((bx + 45) >= pipeX[2] && bx <= (pipeX[2] + 93)) && !((by + 30) < pipeY[2] || bx > (pipeY[2] + 250))) || (((bx + 45) >= pipeX[3] && bx <= (pipeX[3] + 93)) && !((by + 30) < pipeY[3] || by > (pipeY[3] + 250)))|| (((bx + 45) >= pipeX[4] && bx <= (pipeX[4] + 93)) && !((by + 30) < pipeY[4] || by > (pipeY[4] + 250))) || (((bx + 45) >= pipeX[5] && bx <= (pipeX[5] + 93)) && !((by + 30) < pipeY[5] || by > (pipeY[5] + 250))))
		{
			gameover();
		}
	}
	if(Bird2){
		if ((by <= 0 || by >= (562 - 35)) || (((bx + 35) >= pipeX[0] && bx <= (pipeX[0] + 93)) && !((by + 20) < pipeY[0] || by > (pipeY[0] + 250)))|| (((bx + 35) >= pipeX[1] && bx <= (pipeX[1] + 93)) && !((by + 20) < pipeY[1] || by > (pipeY[1] + 250))) || (((bx + 35) >= pipeX[2] && bx <= (pipeX[2] + 93)) && !((by + 20) < pipeY[2] || bx > (pipeY[2] + 250))) || (((bx + 35) >= pipeX[3] && bx <= (pipeX[3] + 93)) && !((by + 20) < pipeY[3] || by > (pipeY[3] + 250)))|| (((bx + 35) >= pipeX[4] && bx <= (pipeX[4] + 93)) && !((by + 20) < pipeY[4] || by > (pipeY[4] + 250))) || (((bx + 35) >= pipeX[5] && bx <= (pipeX[5] + 93)) && !((by + 20) < pipeY[5] || by > (pipeY[5] + 250))))
		{
			gameover();
		}
	}
	if (!game_over)
	{
		scoreUpdate();
		pipeX[0] -= speed;
		pipeX[1] -= speed;
		pipeX[2] -= speed;
		pipeX[3] -= speed;
		pipeX[4] -= speed;
		pipeX[5] -= speed;
		coinX -= speed;
		if (coinX <= 0)
		{
			coinX += 2000;
			srand(time(NULL));
			coinY = 320 + rand() % 25;
		}
		if (pipeX[0] <= 0)
		{
			pipeX[0] += 1000;
			srand(time(NULL));
			pipeY[0] = 320 + rand() % 100;
		}
		if (pipeX[1] <= 0)
		{
			pipeX[1] += 1000;
			pipeY[1] = 0;
		}
		if (pipeX[2] <= 0)
		{
			pipeX[2] += 1000;
			srand(time(NULL));
			pipeY[2] = 320 + rand() % 100;
		}
		if (pipeX[3] <= 0)
		{
			pipeX[3] += 1000;
			srand(time(NULL));
			pipeY[3] = rand()%10;
		}
		if (pipeX[4] <= 0)
		{
			pipeX[4] += 1000;
			srand(time(NULL));
			pipeY[4] = 320 + rand() % 100;
		}
		if (pipeX[5] <= 0)
		{
			pipeX[5] += 1000;
			srand(time(NULL));
			pipeY[5] = rand()%10;
		}
		by -= 2;
	}
}
void gameover(){
	game_over = 1;
	if(game_over){
		PlaySound(TEXT("game_over.wav"), NULL, SND_ASYNC);
	}
	resetPipes();
	if (hiscore < score)
		{
			hiscore = score;
			FILE *fp;
			fp = fopen("hiscore.txt", "w");
			fprintf(fp, "%d\n", hiscore);
			fclose(fp);
		}
	bx = 30;
	by = 280;
	coinX = 1500;
	coinY = 320;
	iClear();
	iFilledRectangle(0,0,1000,562);
	iShowBMP(0,0,"images\\go2.bmp");
	iShowBMP2(0, 500, "images\\back.bmp", 0);
	gamePage = 0;
	homepage = 1; 
	score = 0;
	game_over = 0;
}
void scoreUpdate(){
	if(!flag[0] && bx>(pipeX[0]+93)) flag[0]=1, score++;
	else if(flag[0] && bx < pipeX[0]) flag[0] = 0;
	if(!flag[1] && bx>(pipeX[1]+93)) flag[1]=1, score++;
	else if(flag[1] && bx < pipeX[1]) flag[1] = 0;
	if(!flag[2] && bx>(pipeX[2]+93)) flag[2]=1, score++;
	else if(flag[2] && bx < pipeX[2]) flag[2] = 0;
	if(!flag[3] && bx>(pipeX[3]+93)) flag[3]=1, score++;
	else if(flag[3] && bx < pipeX[3]) flag[3] = 0;
	if(!flag[4] && bx>(pipeX[4]+93)) flag[4]=1, score++;
	else if(flag[4] && bx < pipeX[4]) flag[4] = 0;
	if(!flag[5] && bx>(pipeX[5]+93)) flag[5]=1, score++;
	else if(flag[5] && bx < pipeX[5]) flag[5] = 0;
	if((((bx + 45) >= coinX && bx <= (coinX + 25)) && !((by + 30) < coinY || by > (coinY + 25)))){
		score += 10;
		coinX = 1500;
		coinY = 320;
	}
}
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n", mx, my);
}
void iPassiveMouseMove(int mx, int my) {
}
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x = %d, y= %d\n", mx, my);
		if (homepage == 1 && (mx >= 150 && mx <= 250) && (my >= 100 && my <= 200))
		{
			Game();
		}
		else if (homepage == 1 && (mx >= 350 && mx <= 450) && (my >= 100 && my <= 200))
		{
			settings();
		}
		else if (homepage == 1 && (mx >= 550 && mx <= 650) && (my >= 100 && my <= 200))
		{
			scores();
		}
		else if (homepage == 1 && (mx >= 750 && mx <= 850) && (my >= 100 && my <= 200))
		{
			info();
		}
		else if ((gamePage == 1) && (mx >= 0 && mx <= 50) && (my >= 500 && my <= 550))
		{
			back();
		}
		else if ((settingsPage == 1) && (mx >= 0 && mx <= 50) && (my >= 500 && my <= 550))
		{
			back();
		}
		else if ((scorePage == 1) && (mx >= 0 && mx <= 50) && (my >= 500 && my <= 550))
		{
			back();
		}
		else if ((InstructionPage == 1) && (mx >= 0 && mx <= 50) && (my >= 500 && my <= 550))
		{
			back();
		}
		else if ((game_over == 1) && (mx >= 0 && mx <= 50) && (my >= 500 && my <= 550))
		{
			back();
		}
		else if ((settingsPage == 1) && (mx >= 300 && mx <= 400) && (my >= 400 && my <= 460))
		{
			speed = 20;
			resetPipes();
		}
		else if ((settingsPage == 1) && (mx >= 300 && mx <= 400) && (my >= 300 && my <= 360))
		{
			speed = 25;
			resetPipes();
		}
		else if ((settingsPage == 1) && (mx >= 300 && mx <= 400) && (my >= 200 && my <= 260))
		{
			speed = 30;
			resetPipes();
		}
		else if ((settingsPage == 1) && (mx >= 500 && mx <= 550) && (my >= 400 && my <= 450))
		{
			Bird = 1;
			Bird2 = 0;
			resetPipes();
		}
		else if ((settingsPage == 1) && (mx >= 500 && mx <= 550) && (my >= 300 && my <= 350))
		{
			Bird = 0;
			Bird2 = 1;
			resetPipes();
		}
		else if ((settingsPage == 1) && (mx >= 600 && mx <= 675) && (my >= 400 && my <= 475))
		{
			Music = 1;
		}
		else if ((settingsPage == 1) && (mx >= 600 && mx <= 675) && (my >= 300 && my <= 375))
		{
			Music = 0;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}
void iKeyboard(unsigned char key) {
	if (key == 'q')
	{
		exit(0);
	}
	if (key == '\b')
	{
		resetStates();
		homepage = 1;
	}
	if (game_over && ( key == '\n' || key == '\r'))
	{
		resetPipes();
		score = 0;
		game_over = 0;
	}
}
void iSpecialKeyboard(unsigned char key) {
	if (key == GLUT_KEY_UP)
	{
		by += 20;
	}
	if (key == GLUT_KEY_DOWN)
	{
		by -= 20;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		bx += 30;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		bx -= 30;
	}
}
int main() {
	resetPipes();
	FILE *fp;
	fp = fopen("hiscore.txt", "r");
	fscanf(fp, "%d", &hiscore);
	fclose(fp);
	iInitialize(1000, 562, "Flappy Bird Clone");
	return 0;
}
