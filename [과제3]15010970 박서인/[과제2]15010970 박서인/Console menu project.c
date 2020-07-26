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
		case DIE_SIMULATION	: dieSimulation(); break;						//DIE_SIMULATION은 헤더파일에서 1의 값으로 선언 되었으므로 1일 때 dieSimulation()함수 적용
		case GAME_SHOW		: gameShow(); break;								//GAME_SHOW는 헤더파일에서 2의 값으로 선언 되었으므로 2일 때 gameShow()함수 적용
		case HIGH_LOW_GAME	: highLowGame(); break;							//HIGH_LOW_GAME은 헤더파일에서 3의 값으로 선언 되었으므로 3일 때 highLowGame() 함수적용
		case WORD_GAME		: wordGame(); break;									//MENU4는 헤더파일에서 4의 값으로 선언 되었으므로 4일 때 menu4()함수 적용
		case OX_GAME		: OXGame(); break;
		case STAR_GAME		: StarGame(); break;
		case ABOUT			: about(); break;	
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
	printf("  4.WORD GAME\n");
	printf("  5.OX GAME\n");
	printf("  6.STAR GAME\n");
	printf("  7.ABOUT\n");
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

void highLowGame() {																		//highLowGame
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

	}																							//while

}																								// highLowGame()

void wordGame()																					//WordGame()
{
	char strWords[10][80]																		//답으로 쓰일수 있는 단어들에 대한 2차원배열 선언-10개 단어, 80문자이내
	= {"clock", "sky", "boy", 
		"girl", "console", "computer", 
		"menu", "student", "chapter", "program"};

	char strAnswer[80];																			//맞춰야하는 정답 단어에 대한 배열 선언
	int nStrLength, nRandomIndex;																//정답 단어의 철자수 선언, nRandomIndex는 strWords[][]에서 임의로 strAnswer[] 정하는데 쓰임
	int i, cnt=0;																				//변수 선언, 카운트 값 초기화
	char chInput;																				//입력문자 선언
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz";										//마지막에 표시되는 a~z까지의 문자배열

	nRandomIndex = rand()%10;																	//strWords[10]안의 수는 0~9까지이므로 임의의 수를 10으로 나눈 나머지값을 이용해 nRandomIndex값 정한다.

	nStrLength = strlen(strWords[nRandomIndex]);												//strlen,즉 길이 구하는 함수를 이용하여 strWords[nRandomIndex](=strAnswer)의 철자 수를 구한다.

	for(i=0;i<nStrLength; i++)																	//0이상, nStrLength보다 적게 반복 
	{
		strAnswer[i] = '_';																		//strAnswer[i]에 '_'를 넣어 답 넣는 곳을 만든다.
	}
	strAnswer[nStrLength] = '\0';																//NULL문자를 입력해 80문자가 다 차지 않아도 됨을 표시

	while(TRUE)
	{
		//1.
		system("cls");																			//이전까지의 화면 지우기
		printf("\n");
		printf("===============================\n");
		printf("           WORD GAME\n");
		printf("------------------------------\n");
		printf("\n     ");
		for(i=0;i<nStrLength;i++)																//단어의 길이보다 적게 반복																
		{
			printf("%c ", strAnswer[i]);														//정답단어의 문자배열에서 맞춘 것을 출력
		}
		printf("\n\n");

		if(strcmp(strAnswer, strWords[nRandomIndex])==0)										//strAnswer와 strWords[nRandomIndex]가 0일 때

		{
			printf("     Congratulation!!\n\n");
			printf("     맞춘 횟수 : %d\n", cnt);
			break;																				//escape condition
		}																						//if

		printf("\n     ");
		for (i=0;i<strlen(strAlphabet);i++)														//strAlphabet의 길이만큼 반복
		{
			printf("%c ", strAlphabet[i]);
			if((i+1)%10==0) printf("\n     ");													//변수 i+1을 10으로 나눈 나머지가 0인경우 공백처리. i+1인 이유는 배열은 0부터 시작해서 10까지 끊으려면 i+1로 해야한다.
		}//for
		printf("\n\n");

		printf("   문자 하나를 입력하세요.>> ");
		fflush(stdin);																			//keyboard buffer clear
		scanf("%c", &chInput);																	//문자 입력
		cnt++;																					//카운트 up

		/*strAlphabet[chInput-'a']=' ';*/														//반복없이 공백얻을수있는 교수님solution

		for(i=0;i<nStrLength; i++)																//한 단어안에 같은 알파벳이 여러개 들어가있는 경우
		{
			if(chInput == strWords[nRandomIndex][i])											//입력한 문자가 strWords배열에서 골라진 정답인 단어의 문자 배열에 있을경우
			{
				strAnswer[i] = chInput;															//정답배열에 입력한 문자를 대입한다.
			}																					//if
		}																						//for

		for(i=0;i<strlen(strAlphabet);i++)														//알파벳의 나열에서 입력한 문자는 없애기
		{
			if(chInput == strAlphabet[i])														//입력한 문자가 알파벳 배열의 어떤 곳과 같은 경우 
				strAlphabet[i] = ' ';															//strAlphabet[i]의 자리에 공백표시한다.
		}
	}																							//while
}																								//wordGame()

void OXGame()
{
	char strArray[11] = "0123456789";															//O와X가 들어갈 자리 1~9까지의 배열
	char user = 'O';																			//OX나타내는 변수 user는 O로 초기화
	char chWin = '\0';																			//chWin값 NULL문자처리
	int nCount = 0;																				//입력횟수인 카운트값은 0으로 초기화한다.

	while(TRUE) {
		displayOX(strArray);																	//배열요소가 아닌 배열을 보낸 것
		if (chWin=='O' || chWin=='X') break;													//누군가 이겼을때 break를 건다(비겼을 경우엔 걸리지않음)->비겼을때도 탈출해야함.
																								//카운팅해서 o와 x를 합해서 총 9번 입력하여도 이긴사람이 없을경우엔 비김! break걸어야한다.
																								//하지만 현재는 중복입력이 가능하므로 카운팅의 의미가 없다!->중복의 경우를 없애야한다.->는 없앴다!!
		if (nCount >=9) break;																	//입력횟수가 9번 이상이면 while문 탈출
		playOX(strArray, user);																	//playOX
																								/*if (user=='O')	user = 'X');
																								else			user = 'O');
																								를 조건연산자로 정리하면*/
		user = (user=='O')?'X':'O';																//OX변수가 O라면 다음 변수는 X, 아니라면 O
		chWin = winCheck(strArray);																//chWin 함수
																								//nCount는 헤더에서 선언한 counting함수 이용한다.
	}																							//while
	if (chWin=='O' || chWin=='X')																//chWin이 O이거나 X라면 밑의 printf를 출력한다.
	{
		printf("	=============================================\n");
		printf("	     player %c Win!!\n", chWin);
		printf("	=============================================\n");
	}
	else{																						//그외(이기는 것이 없다)라면 밑의 printf를 출력한다.
																								//	printf("%c\n",chWin);
		printf("	=============================================\n");
		printf("	     players draw!!\n");
		printf("	=============================================\n");
	}
}
																								//OXGame()
void displayOX(char strNumber[]){																//displayOX함수

	int i;																						//for문에 쓰인 변수 i 선언

	system("cls");																				//화면지우기
	printf("\n");
	printf("=============================================\n");
	printf("                OX GAME\n");
	printf("---------------------------------------------\n");
	printf("\n\t");
	for(i=1/*0은 받지 않는다*/;i<10;i++) {												//숫자는 1~9까지지만 배열의 첫번째 칸의 0은 받지않는다.
		printf("%c\t",strNumber[i]);													//123456789 배열 출력, \t로 간격만들기
		if (i==9) { printf("\n\t");}													//만약 배열 마지막인 9라면 줄띄우기, 칸띄우기
		else if (i%3==0) {printf("\n\n\t");}											//3의 배수인 변수i인 경우 줄 두번띄우고 칸띄우기
																						//123456789 배열 3개씩 3줄 만들기
	}																					//for
	printf("\n");
	printf("---------------------------------------------\n");


}																						//displayOX()
void playOX(char strNumber[], char player)												//playOX 함수(배열요소와 입력문자)
{
	static int nIndex=1;																//문자(O또는X)가 들어갈 자리(숫자)
	static int x=MIN_X,y=MIN_Y;															//(x,y)좌표의 시작점
	char chInput;																		//입력문자
	int flag = TRUE;																	//flag를 TRUE(1)로 초기화

	printf("\tPlayer : %c",player);														//\t로 여백을 주고 player의 순서임을 표시

	//x = MIN_X;
	//y = MIN_Y;
	gotoxy(x,y);																		//gotoxy()함수로 커서이동

	//nIndex = 1;

	while(flag){																		//flag의 초기값은 1
		chInput = getch();																//getch()이용하여 문자입력받기 

		switch(chInput) {																
		case ENTER:																		//ENTER를입력할 경우
			if(inputOX(strNumber,player,nIndex)==TRUE)									//inputOX()가 TRUE라면
				flag = FALSE;															//flag는 FALSE로 escape condition
			break;
		case LEFT:																		//LEFT를 입력할 경우
			x = x - TAB_X;																//x좌표는 이전의 x좌표에서 왼쪽으로 TAB_X(8)만큼 이동
			if (x<MIN_X)	x = MIN_X;													//만약 x좌표가 시작점의 x좌표보다 작다면 x는 시작점의 x좌표인것으로 하자
			else			nIndex--;													//그 외라면 문자가 들어갈 자리 감소
			break;																		//escape condition
		case RIGHT:																		//RIGHT를 입력할 경우
			x = x + TAB_X;																//x좌표는 이전의 x좌표에서 오른쪽으로 TAB_X만큼 이동
			if (x>MAX_X)	x = MAX_X;													//만약 x좌표가 최댓값인 MAX_X보다 크다면 x좌표값은 MAX_X
			else			nIndex++;													//그 외라면 문자가 들어갈 자리 증가
			break;																		//escape condition
		case UP:																		//UP을 입력할 경우
			y = y  - TAB_Y;																//y좌표는 이전의 y좌표에서 위로 TAB_Y만큼 이동
			if (y<MIN_Y)	y = MIN_Y;													//만약 y좌표가 시작점의 y좌표보다 작다면 y는 시작점의 y좌표인것으로 하자 
			else			nIndex -= 3;												//그 외라면 문자가 들어갈 자리는 이전에서 3만큼 감소
			break;																		//escape condition
		case DOWN:																		//DOWN을 입력할 경우
			y = y + TAB_Y;																//y좌표는 이전의 y좌표에서 아래로 TAB_Y만큼 이동
			if (y>MAX_Y)	y = MAX_Y;													//만약 y좌표가 최대의 y좌표값인 MAX_Y보다 크다면 MAX_Y로 하자
			else			nIndex += 3;												//그 외라면 문자가 들어갈 자리는 이전에서 3 증가
			break;																		//escape condition
		}																				//switch	
		gotoxy(x,y);

	}																					//while
	/*	
	printf("\t");																		//여백만들기
	printf("%c's turn >>", player);														//....의 차례임을 표시하는 printf
	scanf("%d", &nIndex);																//player가 들어갈 자리 입력하는 scanf

	while(strNumber[nIndex]=='O' || strNumber[nIndex]=='X') {
	printf("\t");
	printf("(re-input) %c's trun >>",player);
	scanf("%d", &nIndex);
	}//while

	while(TRUE) {
	if(nIndex>=1 && nIndex<=9) {
	if(strNumber[nIndex]=='O' || strNumber[nIndex]=='X') break;
	{printf("\t");
	printf("(re-input) %c's trun >>",player);
	scanf("%d", &nIndex);
	}//if
	}//if
	}//while*/
}//playOX()
char winCheck(char strNumber[])															//winCheck() ->이기는경우의수
{
	char chReturn;																		//리턴값


	if (strNumber[1]==strNumber[2] &&													//만약 1과 2에 들어가는 문자가 같고 
		strNumber[2]==strNumber[3]) {													//2와 3에들어가는 문자가 같다면 (가로 첫째줄)
			chReturn = strNumber[1];													//리턴값는 1에 들어가는 문자.
	} else if (strNumber[4]==strNumber[5]&&												//만약 4와 5에 들어가는 문자가 같고
		strNumber[5]==strNumber[6]) {													//5와 6에 들어가는 문자가 같다면 (가로 둘째줄)
			chReturn = strNumber[4];													//리턴값은 4에 들어가는 문자
	} else if (strNumber[7]==strNumber[8]&&												//만약 7과 8에 들어가는 문자가 같고
		strNumber[8]==strNumber[9]) {													//8과 9에 들어가는 문자가 같다면(가로 셋째줄)
			chReturn = strNumber[7];													//리턴값은 7에 들어가는 문자
	} else if (strNumber[1]==strNumber[4]&&												//만약 1과 4에 들어가는 문자가 같고
		strNumber[4]==strNumber[7]) {													//4와 7에 들어가는 문자가 같다면(세로 첫째줄)
			chReturn = strNumber[1];													//리턴값은 1에 들어가는 문자
	} else if (strNumber[2]==strNumber[5]&&												//만약 2와 5에 들어가는 문자가 같고
		strNumber[5]==strNumber[8]) {													//5와 8에 들어가는 문자가 같다면(세로 둘째줄)
			chReturn = strNumber[2];													//리턴값은 2에 들어가는 문자
	} else if (strNumber[3]==strNumber[6]&&												//만약 3과 6에 들어가는 문자가 같고
		strNumber[6]==strNumber[9]) {													//6과 9에 들어가는 문자가 같다면 (세로 셋째줄)
			chReturn = strNumber[3];													//리턴값은 3에 들어가는 문자
	} else if (strNumber[1]==strNumber[5]&&												//만약 1과 5에 들어가는 문자가 같고
		strNumber[5]==strNumber[9]) {													//5와 9에 들어가는 문자가 같다면 (대각선 오>왼)
			chReturn = strNumber[1];													//리턴값은 1에 들어가는 문자
	} else if (strNumber[3]==strNumber[5]&&												//만약 3과 5에 들어가는 문자가 같고
		strNumber[5]==strNumber[7]) {													//5와 7에 들어가는 문자가 같다면 (대각선 왼>오)
			chReturn = strNumber[3];													//리턴값은 3에 들어가는 문자
	}else {																				//그 외에는
		chReturn = '\0';																//리턴값은 NULL문자 처리
	}
	return chReturn;																	//리턴값을 보인다.
}//winCheck

/*int counting(char strNumber[])													//입력횟수(중복제외)세는 함수
{
int i;																				//for문에 쓰일 변수 i
int nCount=0;																		//입력횟수 셀 변수 nCount를 0으로 초기화

for(i=1;i<10;i++)																	//for문(문자가 입력가능한 배열요소가 1~9)
{ if(strNumber[i]=='O'||strNumber[i]=='X')											//어떤 배열요소에 'O'나 'X'가 있다면
{ nCount++;}}																		//nCount값 증가

return nCount;																		//리턴값은 nCount
}*/

void gotoxy(int x, int y)															//커서를 (x,y)로 움직이는 함수 gotoxy()
{
	COORD Cur;																		

	Cur.X = x;
	Cur.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);

}																					//gotoxy

int inputOX(char strNumber[], char player, int index)								//inputOX()함수(중복입력이 안되게 하기)
{
	if (strNumber[index]=='O' || strNumber[index]=='X') return FALSE;				//만약 입력하려는 곳에 이미 O나 X가 있다면 리턴값은 FALSE로 실행불가
	else {																			//그외라면 입력하려는 곳에 player의 이름을 넣는다. 리턴값 TRUE로 실행
		strNumber[index] = player;													
		return TRUE;
	}
}//inputOX()

void StarGame()
{
	int input;																				//사용자가 입력한 별 반짝임 횟수에 대한 변수
	int stars;																				//실제 반짝이는 별의 갯수에 대한 변수
	int start_x = 10, start_y = 3;															//사각형 영역 왼쪽 상단 x와 y 좌표에 대한 변수와 초기값
	int width = 50, height = 10;															//별이 나타날 사각형 영역의 가로폭과 세로 높이에 대한 변수와 초기값
	int x, y, i;																			//현재 별이 나타날 좌표에 대한 변수

																							//게임 시작전 안내문 출력
	printf("반짝이는 별의 갯수를 맞추는 게임입니다. 아무키나 누르면 시작합니다.");
	getch();																				//아무 키나 누르면 게임을 시작하도록 기다린다.

	system("cls");																			//화면 지우기
	Sleep(1000);																			//앞에서의 getch()에서 아무 키나 누르자마자 갑자기 실행되지않도록 프로그램 실행을 1000밀리초(1초)동안 중지
	srand(time(NULL));																		//rand함수의 seed를 현재시간으로 설정

	stars = rand()%(MAX - MIN + 1) + MIN;													//별반짝임 횟수를 최소 MIN번에서 최대 MAX번 중 임의의 값으로 설정하기.

	draw_rectangle(start_x, start_y, width, height);										//별이 나타날 사각형 영역 바깥으로 테두리 그리기
	Sleep(1000);																			//프로그램 실행을 1000밀리초(1초)동안 중기

	for (i=1; i<=stars; i++)																//별이 나타날 영역 안에서 임의의 (x,y)좌표에 INTERVAL 간격으로 별을 repeats번 반짝이기
	{
		x = start_x + rand()%(width - 2);													//rand함수를 이용해서 별이 나타날 x좌표 구하기(-2는 "★"이 두 칸을 차지하므로 일반문자 출력시보다 최대 x좌표가 1 더 작아야함
		y = start_y + rand()%(height - 1);													//rand함수를 이용해서 별이 나타날 y좌표 구하기

		gotoxy(x,y);																		
		printf("%s",STAR);																	//별을 (x,y)좌표에 표시
	}
		Sleep(1000);																	//INTERVAL 밀리초동안 중지

	system("cls");
	draw_rectangle(start_x, start_y, width, height);	

	gotoxy(!0, 21);																			//출력위치
	printf("별은 몇 개가 (%d ~ %d개) 반짝 거렸을까요?", MIN, MAX);								//사용자에게 별 반짝임 횟수 묻기
	scanf("%d", &input);																	//입력받기

	gotoxy(!0, 22);																			//출력위치
	if(input == stars)																	//사용자가 답한 횟수와 실제 횟수가 같다면
		printf("맞았습니다!\n");
	else																					//다르다면
		printf("틀렸습니다. 답은 %d개입니다!\n", stars);

}

void draw_rectangle(int start_x, int start_y, int width, int height)						//(start_x, start_y)좌표에서 시작하는 가로 width,세로 height인 사각형 바깥으로 테두리를 그리는 함수
{
	int col, row;																			//가로, 세로의 변수선언

																							//사각형 위 경계선 그리기
	gotoxy(start_x - 1, start_y - 1);														//사각형 바깥이므로 시작점보다 x,y 좌표 모두 1이 더 작다
	for (col=0;col<=width+1;col++)															//col은 0부터 시작해 사각형의 가로보다 한 칸 더 넓을 때 까지 반복
		putch('=');																			//그 만큼 '='붙인다.

																							//사각형 아래 경계선 그리기
	gotoxy(start_x - 1, start_y + height);													//사각형 바깥이므로 시작점의 x 좌표는 한칸 더 작게, y좌표는 사각형 높이의 길이만큼 더한다.
	for (col=0; col<=width+1; col++)														//col은 0부터 시작해 사각형의 가로보다 한 칸 더 넓을 때 까지 반복
		putch('=');

																							//사각형 왼쪽 끝에 '|' 그리기
	for (row=0;row<height;row++)															//row는 0부터 시작해 높이의 길이보다는 적게 증가
	{
		gotoxy(start_x - 1, start_y + row);													//시작점의 x좌표보다 1 작게, y좌표에는 row만큼 더한 좌표로 이동
		putch('|');																			//row만큼 | 출력
	}

																							//사각형 오른쪽 끝에 '|' 그리기
	for (row=0;row<height;row++)															//row는 0부터 시작해 높이의 길이보다는 적게 증가
	{
		gotoxy(start_x + width, start_y + row);												//시작점의 x좌표에 사각형 가로의 길이만큼 더하고, y좌표에는 row만큼 더한 좌표로 이동한다
		putch('|');																			//row만큼 | 출력
	}
}

void about()
{
	printf("========================================\n");
	printf("	Programmed by Park, Seoin\n");
	printf("	Copyright@Park\n");
	printf("========================================\n");
}