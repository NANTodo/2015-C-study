#include <stdio.h>											//ǥ������� �Լ�(fflush(), printf(), scanf(), gets(), puts()��)
#include <stdlib.h>											//for system()/ �⺻���̺귯���Լ�(rand(), srand(), NULL) ��
#include <time.h>											//for time()/ �ð��� ��¥�� ��ų� �����ϴ� �Լ�
#include <string.h>											//�޸� ����̳� ���ڿ��� �ٷ� �� �ִ� �Լ�(strcmp(), strlen() ��)
#include <conio.h>											//�ܼ�������Լ�(getch(), putch())
#include <Windows.h>										

//��� �����
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
#define STAR		"��"
#define INTERVAL	300
#define MIN			1
#define MAX			10


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
void wordGame();
void about();


////////////////////////////////////////////////////
//OXGame()�� ���õ� �Լ���
/////////////////////////////////////////////////
void OXGame();												//OXGame�Լ�
void displayOX(char strNumber[]);							//OXGame�� ������ �� ǥ���� ȭ��. 
void playOX(char strNumber[], char player);					//ĳ����(����)�� �Է��ϴ� �Լ�
char winCheck(char strNumber[]);							//ĳ���� �˻��ϴ� �Լ�(� ���ڰ� ���� ���������)
void gotoxy(int, int);										//��ǥ�� Ŀ�� �����϶� ����>>StarGame()������ ���̴� �Լ�
int inputOX(char strNumber[], char player, int index);		//strNumber[]�迭�� index�� player�ֱ�


////////////////////////////////////////////////////
//StarGame()�� ���õ� �Լ���
////////////////////////////////////////////////////
void StarGame();											//StarGame()
void draw_rectangle(int, int, int, int);					//StarGame �����Ҷ� ���̴� �簢���� �׸������� �Լ�