#include "Console menu project.h"											//header파일 추가


int main()
{
	int nSelectedMainMenu;													//mainmenu에 선택된 값을 저장하기 위한 변수 선정
	int bIterationFlag = TRUE;												//IterationFlag 앞에 b, 즉 부울린(true or false) 표시를한다.TRUE는 1, FALSE는 0의 값을 나타낸다.
																			/* #define MAX(문자) 100 로 숫자로 정의한 값을 상수로 선언한다.
																			상수로 선언할때는 무조건 대문자 : 값을 바꿀수 없는 상수, 선언은 헤더파일에서*/

	srand(time(NULL));														//랜덤함수의 seed결정


	while(bIterationFlag) {													//blterationFlag가 TRUE일때 while의 과정을 무한 번 반복하기
		system("cls");														//화면지우기
		nSelectedMainMenu = displayMainMenu();								// 함수사용(호출)

																			/*if (nSelectedMainMenu==0) break; //무한반복 while에서 탈출조건)*/

																			/*switch문은 if문으로 나타낼 경우
																			if (nSelectedMainMenu == DIE_SIMULATION) { dieSimulation(); }
																			else if (nSelectedMainMenu == GAME_SHOW) { gameShow(); }
																			else if (nSelectedMainMenu == HIGH_LOW_GAME) { highLowGame(); }
																			else if (nSelectedMainMenu == MENU4) { menu4(); }
																			else if (nSelectedMainMenu == EXIT) { blterationFlag=FALSE() ; printf("See ya!\n); }

																			else {printf("잘못누르셨습니다\n");} */

		system("cls");														//화면지우기
		switch (nSelectedMainMenu) {										//mainmenu에서 선택된 값에 대하여
		case DIE_SIMULATION: dieSimulation(); break;						//DIE_SIMULATION은 헤더파일에서 1의 값으로 선언 되었으므로 1일 때 dieSimulation()함수 적용
		case GAME_SHOW	   : gameShow(); break;								//GAME_SHOW는 헤더파일에서 2의 값으로 선언 되었으므로 2일 때 gameShow()함수 적용
		case HIGH_LOW_GAME : highLowGame(); break;							//HIGH_LOW_GAME은 헤더파일에서 3의 값으로 선언 되었으므로 3일 때 highLowGame() 함수적용
		case MENU4: menu4(); break;											//MENU4는 헤더파일에서 4의 값으로 선언 되었으므로 4일 때 menu4()함수 적용
		case EXIT: bIterationFlag=FALSE;									//escape condition
			printf("See ya!\n"); break;
																			/*case 0: break; break; //while 탈출조건을 if문이 아니라 switch문으로, 여기서의 break문은 switch문 탈출만가능*/

																			/*<switch case에서 반복문 탈출방법 : 조건을 거짓으로 만들기>
																			int nSelectedMainMenu;
																			int iterationFlag = 1;
																			while(iterationFlag) {
																			의 꼴이 되면 case가 0이 될때 1로 정의된 iterationFlag값은 바꿔 조건을 거짓으로 만들면 된다.
																			case 0: iterationFlag=0; break;면 escape condition. */


		default : printf("잘못누르셨습니다\n");								//입력받은 수가 0~4 외에 다른 숫자일 경우
		}																	//switch
		system("pause");													//멈추는 것도 while문 안에 들어가 있어 멈추기를 계속 반복한다
	}																		//while																
	return 0;

}																			// main()

																			//함수 구현부
int displayMainMenu() {				

	int nMainMenu;															//int 타입이라 앞에 n 또는 i를 붙인다 메인메뉴에서 선택한 메뉴값을 저장

	printf("\n\n");
	printf("==================================\n");
	printf("            main menu\n");
	printf("----------------------------------\n");
	printf("  1.DIE SIMULATION\n");
	printf("  2.GAME SHOW\n");
	printf("  3.HIGH LOW GAME\n");
	printf("  4.MENU 4\n");
	printf("----------------------------------\n");
	printf("  0. EXIT \n");
	printf("==================================\n");
	printf("  >>");
	scanf("%d",&nMainMenu);


	return nMainMenu;														//mainmenu 값을 출력한다.

}																			// displayMainMenu()

void dieSimulation() {														//DieSimulation
	int nFaceValue, nSum=0, nCount=0;
	double lfAvgCount;														//평균 횟수
	int i;																	//for문에서 필요한 변수 i
	int nIteration;															//반복할 횟수

	system("cls");															//화면 지우기
	printf("========================================\n");
	printf("             DIE SIMULATION\n");
	printf("----------------------------------------\n");
	printf("몇번 반복하시겠습니까? >>");
	scanf("%d",&nIteration);
	printf("========================================\n");

	for (i=0; i<nIteration; i++){											//i는 0부터 시작하여 nIteration값보다 작고 계속 증가한다
		while(nSum<100) {													//while의 조건 : nSum이 100보다 작을 때
			nFaceValue = rand()%6+1;										// 1 - 6까지의 눈의 수가 나온다
			nSum += nFaceValue;												// nSum 값의 누적	
			nCount++;														//여기까지가 한 번 굴린값
		}																	// while
		nSum = 0;															//sum 값 초기화: i가 1이었을때 sum이 100을 넘어 더이상 수행되지 않는다
	}																		// for



	lfAvgCount = nCount / nIteration;										
	printf("avg = %.2lf\n", lfAvgCount);

	system("cls");															//화면지우기
	printf("========================================\n");
	printf("           DIE SIMULATION RESULT\n");
	printf("----------------------------------------\n");
	printf("  %d번 모의실험한 결과,\n 평균 %.2lf회를 반복하면\n 누적합이 100을 넘게 됩니다.\n", nIteration, lfAvgCount);
	printf("========================================\n");

}																			// dieSimulation();

void gameShow() {
	int nPrizeDoor, nChoiceDoor, nRevealDoor, nSwitchDoor;									//정답인 문, 고른 문, 보여준 문, 바꾼 문 에 대한 변수를 선언하다.
	int nChoiceCount=0, nSwitchCount=0, i;													//고른횟수와 바꾼 횟수는 0으로 초기화, for문에 쓰일 변수i도 선언한다.
	double lfChoiceAvg, lfSwitchAvg;														//평균 구할 변수와 평균 바꾼 변수를 선언한다.

	printf("\n\n");
	printf("========================================================\n\n");
	printf("        The Money Hall Game Show\n");
	printf("--------------------------------------------------------\n\n");

	//고른 문이 정답일 경우

	for(i=0; i<MAX; i++) {																	//i가 0에서 시작하고 최댓값MAX보다 작고 점점 커지는동안
		nPrizeDoor = rand()%3;																// 정답인 문은 랜덤함수를 이용해 정의한다.
		nChoiceDoor = rand()%3;																//고른 문은 랜덤함수를 이용해 정의한다. 3으로 나눈 나머지 이므로 값은 0-2 중의 값
		if (nPrizeDoor == nChoiceDoor) { nChoiceCount++; }									//정답인 문과 고른문이 같을 때 고른횟수에 대한 카운트를 더한다.
	}																						//for
	lfChoiceAvg = (double)nChoiceCount/MAX * 100;											//평균 구할 변수는 고른횟수를 최댓값으로 나눈후 100을 곱한다. 이때 고른횟수인 nChoiceCount를 double, 즉 실수 값 표기로 변환해주어야한다.
	printf("        선택한 문이 상품문일 확률은 %.2lf 입니다.\n\n", lfChoiceAvg);

																							//문을 바꿨을 경우
	for (i=0; i<MAX; i++) {																	//i가 0에서 시작하고 최댓값MAX보다 작고 점점 커지는동안
		nPrizeDoor = rand()%3;																//정답인 문은 랜덤함수를 이용해 정의한다. 3으로 나눈 나머지 이므로 값은 0-2 중의 값
		nChoiceDoor = rand()%3;																//고른 문은 랜덤함수를 이용해 정의한다. 3으로 나눈 나머지 이므로 값은 0-2 중의 값

		nRevealDoor = 0;																	//보여준 문에 대한 값은 0으로 초기화
		while(nRevealDoor==nPrizeDoor || nRevealDoor==nChoiceDoor) { nRevealDoor++; }		//보여준 문이 정답인 문과 같거나 보여준 문이 고른 문과 같을 때 보여준 문에 대한 카운트 값은 누적된다

		nSwitchDoor = 0;																	//바꾼 문에 대한 값은 0으로 초기화
		while(nSwitchDoor==nRevealDoor || nSwitchDoor==nChoiceDoor) { nSwitchDoor++; }		//바꾼 문이 보여준 문과 같거나 바꾼 문이 고른문과 같을 때 바꾼문에 대한 카운트 값은 누적된다

		if (nSwitchDoor==nPrizeDoor) { nSwitchCount++;}										//바꾼문과 정답인 문이 같을 때 문을 바꾼 횟수에 대한 카운트도 누적된다
	}																						//for
	lfSwitchAvg = (double)nSwitchCount/MAX * 100;											//문을 바꾼 것이 맞을 평균은 바꾼횟수를 최댓값으로 나눠 100으로 곱한 값과 같다.
	printf("        변경한 문이 상품문일 확률은 %.2lf%%입니다.\n\n", lfSwitchAvg);
	printf("========================================================\n\n");

}																							// gameShow()

void highLowGame() {																		//highLowG/ame
	int nRandomNumber, nInputNumber;														//랜덤으로 맞춰야하는 정수와 입력하는 정수를 선언한다.
	int cnt=0;																				//누적횟수 선언=첫시작은 0으로 초기화
	int min=1, max=100;																		//nRandomNumber 1~100 사이의 수, nInputNumber는 min과 max사이의 수

	nRandomNumber = rand()%100 + 1;															//1-100		//랜덤함수를 이용하여 맞추어야 하는 정수를 설정한다.

	while(TRUE) {
		system("cls");																		//화면지우기
		printf("\n");
		printf("=========================================================\n");
		printf("		      HIGH-LOW GAME\n");
		printf("---------------------------------------------------------\n");


		printf("숫자 하나(1-100)를 입력하세요. >>");
		scanf("%d", &nInputNumber);

		printf("\n");


		if (nRandomNumber < nInputNumber) {														//만약 입력한 수가 맞추어야 할 수보다 클때
			max = nInputNumber<max ? nInputNumber-1 : max;										//이 식 전에 정의되었던 max가 입력받은 수보다 크다면 새로 정의될 max는 nInputNumber-1, 작다면 max값에 변화를 주지않는다.
			min = min;																			//최소의 정수 min의 값은 변하지않는다.
			printf("입력한 숫자 %d이(가) 더 높습니다.\n", nInputNumber);						
			printf("%d-%d사이의 숫자를 입력하세요.\n",min, max);
			cnt++;																				//누적카운트

		} else if (nRandomNumber > nInputNumber) {												//만약 입력한 수가 맞춰야할 수보다 작을때
			max = max;																			//직전에 정의받은 max값은 변하지 않는다
			min = nInputNumber>min ? nInputNumber+1 : min;										//이 식 전에 정의되었던 min가 입력받은 수보다 작다면 새로 정의될 min은 nInputNumber+1, 크다면 min값은 변하지 않는다.
			printf("입력한 숫자 %d이(가) 더 낮습니다.\n", nInputNumber);						
			printf("%d-%d 사이의 숫자를 입력하세요.\n", min, max);
			cnt++;																				//누적카운트

		} else {																				// nRandomNuber == nInputNumber일때
			printf("축하합니다!!!\n");
			printf("입력한 숫자 %d이(가) 맞습니다.\n", nInputNumber);
			cnt++;																				//누적카운트
			printf("시도 횟수 : %d\n", cnt);													//여태 누적된 카운트를 출력한다.
			printf("=========================================================\n");
			break;																				//escape condition
		}																						//if-elseif-else
		printf("=========================================================\n");
		system("pause");																		//pause로 멈춰주지 않으면 맞추는 과정중 출력값이 보이지 않고 cls가 작동해 지워진다.

	}																						//while

}																							// highLowGame()

void menu4() {
	//test 
	printf("4번 메뉴\n");
} // menu4