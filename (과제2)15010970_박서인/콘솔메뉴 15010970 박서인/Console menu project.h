#include <stdio.h>
#include <stdlib.h>											// for system()
#include <time.h>											//for time()

															//상수 선언부
#define DIE_SIMULATION	1									
#define GAME_SHOW		2
#define HIGH_LOW_GAME	3
#define MENU4	4
#define EXIT	0

#define MAX		10000

#define TRUE	1
#define FALSE	0

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
void menu4();