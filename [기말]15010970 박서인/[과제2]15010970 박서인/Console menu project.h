#include <stdio.h>											//표준입출력 함수(fflush(), printf(), scanf(), gets(), puts()등)
#include <stdlib.h>											//for system()/ 기본라이브러리함수(rand(), srand(), NULL) 등
#include <time.h>											//for time()/ 시간과 날짜를 얻거나 조작하는 함수
#include <string.h>											//메모리 블록이나 문자열을 다룰 수 있는 함수(strcmp(), strlen() 등)
#include <conio.h>											//콘솔입출력함수(getch(), putch())
#include <Windows.h>										

//상수 선언부
#define DIE_SIMULATION	1									
#define GAME_SHOW		2
#define HIGH_LOW_GAME	3
#define WORD_GAME		4
#define OX_GAME			5
#define STAR_GAME		6
#define ABOUT			7
#define EXIT	0

#define MAX		10000

#define TRUE	1
#define FALSE	0

//OX_GAME
#define LEFT	75
#define RIGHT	77
#define UP		72
#define DOWN	80
#define ENTER	13

#define MIN_X	8
#define MIN_Y	5
#define MAX_X	24
#define MAX_Y	9
#define TAB_X	8											
#define TAB_Y	2

//STAR GAME
#define STAR		"★"
#define INTERVAL	300
#define MIN			1
#define MAX			10


// 함수선언부
															/***********************************************
															displayMainMenu() 함수는 메인메뉴를
															화면에 출력하고, 입력한 메인 메뉴값을 리턴한다.
															************************************************/

int displayMainMenu();

															/***********************************************
																	각 메뉴별 함수들
															***********************************************/
void dieSimulation();
void gameShow();
void highLowGame();
void wordGame();
void about();


////////////////////////////////////////////////////
//OXGame()과 관련된 함수들
/////////////////////////////////////////////////
void OXGame();												//OXGame함수
void displayOX(char strNumber[]);							//OXGame을 시작할 때 표시할 화면. 
void playOX(char strNumber[], char player);					//캐릭터(문자)를 입력하는 함수
char winCheck(char strNumber[]);							//캐릭터 검사하는 함수(어떤 문자가 빙고를 만들었는지)
void gotoxy(int, int);										//좌표로 커서 움직일때 쓰임>>StarGame()에서도 쓰이는 함수
int inputOX(char strNumber[], char player, int index);		//strNumber[]배열의 index에 player넣기


////////////////////////////////////////////////////
//StarGame()과 관련된 함수들
////////////////////////////////////////////////////
void StarGame();											//StarGame()
void draw_rectangle(int, int, int, int);					//StarGame 시작할때 보이는 사각형을 그리기위한 함수