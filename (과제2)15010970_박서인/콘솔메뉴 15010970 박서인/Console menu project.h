#include <stdio.h>
#include <stdlib.h>											// for system()
#include <time.h>											//for time()

															//��� �����
#define DIE_SIMULATION	1									
#define GAME_SHOW		2
#define HIGH_LOW_GAME	3
#define MENU4	4
#define EXIT	0

#define MAX		10000

#define TRUE	1
#define FALSE	0

															// �Լ������
															/***********************************************
															displayMainMenu() �Լ��� ���θ޴���
															ȭ�鿡 ����ϰ�, �Է��� ���� �޴����� �����Ѵ�.
															************************************************/

int displayMainMenu();

															/***********************************************
																	�� �޴��� �Լ���
															***********************************************/
void dieSimulation();
void gameShow();
void highLowGame();
void menu4();