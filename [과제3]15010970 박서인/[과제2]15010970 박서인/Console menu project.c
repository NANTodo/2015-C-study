#include "Console menu project.h"											//header���� �߰�


int main()
{
	int nSelectedMainMenu;													//mainmenu�� ���õ� ���� �����ϱ� ���� ���� ����
	int bIterationFlag = TRUE;												//IterationFlag �տ� b, �� �ο︰(true or false) ǥ�ø��Ѵ�.TRUE�� 1, FALSE�� 0�� ���� ��Ÿ����.
																			/* #define MAX(����) 100 �� ���ڷ� ������ ���� ����� �����Ѵ�.
																			����� �����Ҷ��� ������ �빮�� : ���� �ٲܼ� ���� ���, ������ ������Ͽ���*/

	srand(time(NULL));														//�����Լ��� seed����


	while(bIterationFlag) {													//blterationFlag�� TRUE�϶� while�� ������ ���� �� �ݺ��ϱ�
		system("cls");														//ȭ�������
		nSelectedMainMenu = displayMainMenu();								// �Լ����(ȣ��)

																			/*if (nSelectedMainMenu==0) break; //���ѹݺ� while���� Ż������)*/

		/*switch���� if������ ��Ÿ�� ���
		if (nSelectedMainMenu == DIE_SIMULATION) { dieSimulation(); }
		else if (nSelectedMainMenu == GAME_SHOW) { gameShow(); }
		else if (nSelectedMainMenu == HIGH_LOW_GAME) { highLowGame(); }
		else if (nSelectedMainMenu == MENU4) { menu4(); }
		else if (nSelectedMainMenu == EXIT) { blterationFlag=FALSE() ; printf("See ya!\n); }

		else {printf("�߸������̽��ϴ�\n");} */

		system("cls");														//ȭ�������
		switch (nSelectedMainMenu) {										//mainmenu���� ���õ� ���� ���Ͽ�
		case DIE_SIMULATION	: dieSimulation(); break;						//DIE_SIMULATION�� ������Ͽ��� 1�� ������ ���� �Ǿ����Ƿ� 1�� �� dieSimulation()�Լ� ����
		case GAME_SHOW		: gameShow(); break;								//GAME_SHOW�� ������Ͽ��� 2�� ������ ���� �Ǿ����Ƿ� 2�� �� gameShow()�Լ� ����
		case HIGH_LOW_GAME	: highLowGame(); break;							//HIGH_LOW_GAME�� ������Ͽ��� 3�� ������ ���� �Ǿ����Ƿ� 3�� �� highLowGame() �Լ�����
		case WORD_GAME		: wordGame(); break;									//MENU4�� ������Ͽ��� 4�� ������ ���� �Ǿ����Ƿ� 4�� �� menu4()�Լ� ����
		case OX_GAME		: OXGame(); break;
		case STAR_GAME		: StarGame(); break;
		case ABOUT			: about(); break;	
		case EXIT: bIterationFlag=FALSE;									//escape condition
			printf("See ya!\n"); break;
			/*case 0: break; break; //while Ż�������� if���� �ƴ϶� switch������, ���⼭�� break���� switch�� Ż�⸸����*/

			/*<switch case���� �ݺ��� Ż���� : ������ �������� �����>
			int nSelectedMainMenu;
			int iterationFlag = 1;
			while(iterationFlag) {
			�� ���� �Ǹ� case�� 0�� �ɶ� 1�� ���ǵ� iterationFlag���� �ٲ� ������ �������� ����� �ȴ�.
			case 0: iterationFlag=0; break;�� escape condition. */


		default : printf("�߸������̽��ϴ�\n");								//�Է¹��� ���� 0~4 �ܿ� �ٸ� ������ ���
		}																	//switch
		system("pause");													//���ߴ� �͵� while�� �ȿ� �� �־� ���߱⸦ ��� �ݺ��Ѵ�
	}																		//while																
	return 0;

}																			// main()

																			//�Լ� ������
int displayMainMenu() {				

	int nMainMenu;															//int Ÿ���̶� �տ� n �Ǵ� i�� ���δ� ���θ޴����� ������ �޴����� ����

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


	return nMainMenu;														//mainmenu ���� ����Ѵ�.

}																			// displayMainMenu()

void dieSimulation() {														//DieSimulation
	int nFaceValue, nSum=0, nCount=0;
	double lfAvgCount;														//��� Ƚ��
	int i;																	//for������ �ʿ��� ���� i
	int nIteration;															//�ݺ��� Ƚ��

	system("cls");															//ȭ�� �����
	printf("========================================\n");
	printf("             DIE SIMULATION\n");
	printf("----------------------------------------\n");
	printf("��� �ݺ��Ͻðڽ��ϱ�? >>");
	scanf("%d",&nIteration);
	printf("========================================\n");

	for (i=0; i<nIteration; i++){											//i�� 0���� �����Ͽ� nIteration������ �۰� ��� �����Ѵ�
		while(nSum<100) {													//while�� ���� : nSum�� 100���� ���� ��
			nFaceValue = rand()%6+1;										// 1 - 6������ ���� ���� ���´�
			nSum += nFaceValue;												// nSum ���� ����	
			nCount++;														//��������� �� �� ������
		}																	// while
		nSum = 0;															//sum �� �ʱ�ȭ: i�� 1�̾����� sum�� 100�� �Ѿ� ���̻� ������� �ʴ´�
	}																		// for



	lfAvgCount = nCount / nIteration;										
	printf("avg = %.2lf\n", lfAvgCount);

	system("cls");															//ȭ�������
	printf("========================================\n");
	printf("           DIE SIMULATION RESULT\n");
	printf("----------------------------------------\n");
	printf("  %d�� ���ǽ����� ���,\n ��� %.2lfȸ�� �ݺ��ϸ�\n �������� 100�� �Ѱ� �˴ϴ�.\n", nIteration, lfAvgCount);
	printf("========================================\n");

}																			// dieSimulation();

void gameShow() {
	int nPrizeDoor, nChoiceDoor, nRevealDoor, nSwitchDoor;									//������ ��, �� ��, ������ ��, �ٲ� �� �� ���� ������ �����ϴ�.
	int nChoiceCount=0, nSwitchCount=0, i;													//��Ƚ���� �ٲ� Ƚ���� 0���� �ʱ�ȭ, for���� ���� ����i�� �����Ѵ�.
	double lfChoiceAvg, lfSwitchAvg;														//��� ���� ������ ��� �ٲ� ������ �����Ѵ�.

	printf("\n\n");
	printf("========================================================\n\n");
	printf("        The Money Hall Game Show\n");
	printf("--------------------------------------------------------\n\n");

	//�� ���� ������ ���

	for(i=0; i<MAX; i++) {																	//i�� 0���� �����ϰ� �ִ�MAX���� �۰� ���� Ŀ���µ���
		nPrizeDoor = rand()%3;																// ������ ���� �����Լ��� �̿��� �����Ѵ�.
		nChoiceDoor = rand()%3;																//�� ���� �����Լ��� �̿��� �����Ѵ�. 3���� ���� ������ �̹Ƿ� ���� 0-2 ���� ��
		if (nPrizeDoor == nChoiceDoor) { nChoiceCount++; }									//������ ���� ������ ���� �� ��Ƚ���� ���� ī��Ʈ�� ���Ѵ�.
	}																						//for
	lfChoiceAvg = (double)nChoiceCount/MAX * 100;											//��� ���� ������ ��Ƚ���� �ִ����� ������ 100�� ���Ѵ�. �̶� ��Ƚ���� nChoiceCount�� double, �� �Ǽ� �� ǥ��� ��ȯ���־���Ѵ�.
	printf("        ������ ���� ��ǰ���� Ȯ���� %.2lf �Դϴ�.\n\n", lfChoiceAvg);

	//���� �ٲ��� ���
	for (i=0; i<MAX; i++) {																	//i�� 0���� �����ϰ� �ִ�MAX���� �۰� ���� Ŀ���µ���
		nPrizeDoor = rand()%3;																//������ ���� �����Լ��� �̿��� �����Ѵ�. 3���� ���� ������ �̹Ƿ� ���� 0-2 ���� ��
		nChoiceDoor = rand()%3;																//�� ���� �����Լ��� �̿��� �����Ѵ�. 3���� ���� ������ �̹Ƿ� ���� 0-2 ���� ��

		nRevealDoor = 0;																	//������ ���� ���� ���� 0���� �ʱ�ȭ
		while(nRevealDoor==nPrizeDoor || nRevealDoor==nChoiceDoor) { nRevealDoor++; }		//������ ���� ������ ���� ���ų� ������ ���� �� ���� ���� �� ������ ���� ���� ī��Ʈ ���� �����ȴ�

		nSwitchDoor = 0;																	//�ٲ� ���� ���� ���� 0���� �ʱ�ȭ
		while(nSwitchDoor==nRevealDoor || nSwitchDoor==nChoiceDoor) { nSwitchDoor++; }		//�ٲ� ���� ������ ���� ���ų� �ٲ� ���� ������ ���� �� �ٲ۹��� ���� ī��Ʈ ���� �����ȴ�

		if (nSwitchDoor==nPrizeDoor) { nSwitchCount++;}										//�ٲ۹��� ������ ���� ���� �� ���� �ٲ� Ƚ���� ���� ī��Ʈ�� �����ȴ�
	}																						//for
	lfSwitchAvg = (double)nSwitchCount/MAX * 100;											//���� �ٲ� ���� ���� ����� �ٲ�Ƚ���� �ִ����� ���� 100���� ���� ���� ����.
	printf("        ������ ���� ��ǰ���� Ȯ���� %.2lf%%�Դϴ�.\n\n", lfSwitchAvg);
	printf("========================================================\n\n");

}																							// gameShow()

void highLowGame() {																		//highLowGame
	int nRandomNumber, nInputNumber;														//�������� ������ϴ� ������ �Է��ϴ� ������ �����Ѵ�.
	int cnt=0;																				//����Ƚ�� ����=ù������ 0���� �ʱ�ȭ
	int min=1, max=100;																		//nRandomNumber 1~100 ������ ��, nInputNumber�� min�� max������ ��

	nRandomNumber = rand()%100 + 1;															//1-100		//�����Լ��� �̿��Ͽ� ���߾�� �ϴ� ������ �����Ѵ�.

	while(TRUE) {
		system("cls");																		//ȭ�������
		printf("\n");
		printf("=========================================================\n");
		printf("		      HIGH-LOW GAME\n");
		printf("---------------------------------------------------------\n");


		printf("���� �ϳ�(1-100)�� �Է��ϼ���. >>");
		scanf("%d", &nInputNumber);

		printf("\n");


		if (nRandomNumber < nInputNumber) {														//���� �Է��� ���� ���߾�� �� ������ Ŭ��
			max = nInputNumber<max ? nInputNumber-1 : max;										//�� �� ���� ���ǵǾ��� max�� �Է¹��� ������ ũ�ٸ� ���� ���ǵ� max�� nInputNumber-1, �۴ٸ� max���� ��ȭ�� �����ʴ´�.
			min = min;																			//�ּ��� ���� min�� ���� �������ʴ´�.
			printf("�Է��� ���� %d��(��) �� �����ϴ�.\n", nInputNumber);						
			printf("%d-%d������ ���ڸ� �Է��ϼ���.\n",min, max);
			cnt++;																				//����ī��Ʈ

		} else if (nRandomNumber > nInputNumber) {												//���� �Է��� ���� ������� ������ ������
			max = max;																			//������ ���ǹ��� max���� ������ �ʴ´�
			min = nInputNumber>min ? nInputNumber+1 : min;										//�� �� ���� ���ǵǾ��� min�� �Է¹��� ������ �۴ٸ� ���� ���ǵ� min�� nInputNumber+1, ũ�ٸ� min���� ������ �ʴ´�.
			printf("�Է��� ���� %d��(��) �� �����ϴ�.\n", nInputNumber);						
			printf("%d-%d ������ ���ڸ� �Է��ϼ���.\n", min, max);
			cnt++;																				//����ī��Ʈ

		} else {																				// nRandomNuber == nInputNumber�϶�
			printf("�����մϴ�!!!\n");
			printf("�Է��� ���� %d��(��) �½��ϴ�.\n", nInputNumber);
			cnt++;																				//����ī��Ʈ
			printf("�õ� Ƚ�� : %d\n", cnt);													//���� ������ ī��Ʈ�� ����Ѵ�.
			printf("=========================================================\n");
			break;																				//escape condition
		}																						//if-elseif-else
		printf("=========================================================\n");
		system("pause");																		//pause�� �������� ������ ���ߴ� ������ ��°��� ������ �ʰ� cls�� �۵��� ��������.

	}																							//while

}																								// highLowGame()

void wordGame()																					//WordGame()
{
	char strWords[10][80]																		//������ ���ϼ� �ִ� �ܾ�鿡 ���� 2�����迭 ����-10�� �ܾ�, 80�����̳�
	= {"clock", "sky", "boy", 
		"girl", "console", "computer", 
		"menu", "student", "chapter", "program"};

	char strAnswer[80];																			//������ϴ� ���� �ܾ ���� �迭 ����
	int nStrLength, nRandomIndex;																//���� �ܾ��� ö�ڼ� ����, nRandomIndex�� strWords[][]���� ���Ƿ� strAnswer[] ���ϴµ� ����
	int i, cnt=0;																				//���� ����, ī��Ʈ �� �ʱ�ȭ
	char chInput;																				//�Է¹��� ����
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz";										//�������� ǥ�õǴ� a~z������ ���ڹ迭

	nRandomIndex = rand()%10;																	//strWords[10]���� ���� 0~9�����̹Ƿ� ������ ���� 10���� ���� ���������� �̿��� nRandomIndex�� ���Ѵ�.

	nStrLength = strlen(strWords[nRandomIndex]);												//strlen,�� ���� ���ϴ� �Լ��� �̿��Ͽ� strWords[nRandomIndex](=strAnswer)�� ö�� ���� ���Ѵ�.

	for(i=0;i<nStrLength; i++)																	//0�̻�, nStrLength���� ���� �ݺ� 
	{
		strAnswer[i] = '_';																		//strAnswer[i]�� '_'�� �־� �� �ִ� ���� �����.
	}
	strAnswer[nStrLength] = '\0';																//NULL���ڸ� �Է��� 80���ڰ� �� ���� �ʾƵ� ���� ǥ��

	while(TRUE)
	{
		//1.
		system("cls");																			//���������� ȭ�� �����
		printf("\n");
		printf("===============================\n");
		printf("           WORD GAME\n");
		printf("------------------------------\n");
		printf("\n     ");
		for(i=0;i<nStrLength;i++)																//�ܾ��� ���̺��� ���� �ݺ�																
		{
			printf("%c ", strAnswer[i]);														//����ܾ��� ���ڹ迭���� ���� ���� ���
		}
		printf("\n\n");

		if(strcmp(strAnswer, strWords[nRandomIndex])==0)										//strAnswer�� strWords[nRandomIndex]�� 0�� ��

		{
			printf("     Congratulation!!\n\n");
			printf("     ���� Ƚ�� : %d\n", cnt);
			break;																				//escape condition
		}																						//if

		printf("\n     ");
		for (i=0;i<strlen(strAlphabet);i++)														//strAlphabet�� ���̸�ŭ �ݺ�
		{
			printf("%c ", strAlphabet[i]);
			if((i+1)%10==0) printf("\n     ");													//���� i+1�� 10���� ���� �������� 0�ΰ�� ����ó��. i+1�� ������ �迭�� 0���� �����ؼ� 10���� �������� i+1�� �ؾ��Ѵ�.
		}//for
		printf("\n\n");

		printf("   ���� �ϳ��� �Է��ϼ���.>> ");
		fflush(stdin);																			//keyboard buffer clear
		scanf("%c", &chInput);																	//���� �Է�
		cnt++;																					//ī��Ʈ up

		/*strAlphabet[chInput-'a']=' ';*/														//�ݺ����� ����������ִ� ������solution

		for(i=0;i<nStrLength; i++)																//�� �ܾ�ȿ� ���� ���ĺ��� ������ ���ִ� ���
		{
			if(chInput == strWords[nRandomIndex][i])											//�Է��� ���ڰ� strWords�迭���� ����� ������ �ܾ��� ���� �迭�� �������
			{
				strAnswer[i] = chInput;															//����迭�� �Է��� ���ڸ� �����Ѵ�.
			}																					//if
		}																						//for

		for(i=0;i<strlen(strAlphabet);i++)														//���ĺ��� �������� �Է��� ���ڴ� ���ֱ�
		{
			if(chInput == strAlphabet[i])														//�Է��� ���ڰ� ���ĺ� �迭�� � ���� ���� ��� 
				strAlphabet[i] = ' ';															//strAlphabet[i]�� �ڸ��� ����ǥ���Ѵ�.
		}
	}																							//while
}																								//wordGame()

void OXGame()
{
	char strArray[11] = "0123456789";															//O��X�� �� �ڸ� 1~9������ �迭
	char user = 'O';																			//OX��Ÿ���� ���� user�� O�� �ʱ�ȭ
	char chWin = '\0';																			//chWin�� NULL����ó��
	int nCount = 0;																				//�Է�Ƚ���� ī��Ʈ���� 0���� �ʱ�ȭ�Ѵ�.

	while(TRUE) {
		displayOX(strArray);																	//�迭��Ұ� �ƴ� �迭�� ���� ��
		if (chWin=='O' || chWin=='X') break;													//������ �̰����� break�� �Ǵ�(����� ��쿣 �ɸ�������)->��������� Ż���ؾ���.
																								//ī�����ؼ� o�� x�� ���ؼ� �� 9�� �Է��Ͽ��� �̱����� ������쿣 ���! break�ɾ���Ѵ�.
																								//������ ����� �ߺ��Է��� �����ϹǷ� ī������ �ǹ̰� ����!->�ߺ��� ��츦 ���־��Ѵ�.->�� ���ݴ�!!
		if (nCount >=9) break;																	//�Է�Ƚ���� 9�� �̻��̸� while�� Ż��
		playOX(strArray, user);																	//playOX
																								/*if (user=='O')	user = 'X');
																								else			user = 'O');
																								�� ���ǿ����ڷ� �����ϸ�*/
		user = (user=='O')?'X':'O';																//OX������ O��� ���� ������ X, �ƴ϶�� O
		chWin = winCheck(strArray);																//chWin �Լ�
																								//nCount�� ������� ������ counting�Լ� �̿��Ѵ�.
	}																							//while
	if (chWin=='O' || chWin=='X')																//chWin�� O�̰ų� X��� ���� printf�� ����Ѵ�.
	{
		printf("	=============================================\n");
		printf("	     player %c Win!!\n", chWin);
		printf("	=============================================\n");
	}
	else{																						//�׿�(�̱�� ���� ����)��� ���� printf�� ����Ѵ�.
																								//	printf("%c\n",chWin);
		printf("	=============================================\n");
		printf("	     players draw!!\n");
		printf("	=============================================\n");
	}
}
																								//OXGame()
void displayOX(char strNumber[]){																//displayOX�Լ�

	int i;																						//for���� ���� ���� i ����

	system("cls");																				//ȭ�������
	printf("\n");
	printf("=============================================\n");
	printf("                OX GAME\n");
	printf("---------------------------------------------\n");
	printf("\n\t");
	for(i=1/*0�� ���� �ʴ´�*/;i<10;i++) {												//���ڴ� 1~9�������� �迭�� ù��° ĭ�� 0�� �����ʴ´�.
		printf("%c\t",strNumber[i]);													//123456789 �迭 ���, \t�� ���ݸ����
		if (i==9) { printf("\n\t");}													//���� �迭 �������� 9��� �ٶ���, ĭ����
		else if (i%3==0) {printf("\n\n\t");}											//3�� ����� ����i�� ��� �� �ι����� ĭ����
																						//123456789 �迭 3���� 3�� �����
	}																					//for
	printf("\n");
	printf("---------------------------------------------\n");


}																						//displayOX()
void playOX(char strNumber[], char player)												//playOX �Լ�(�迭��ҿ� �Է¹���)
{
	static int nIndex=1;																//����(O�Ǵ�X)�� �� �ڸ�(����)
	static int x=MIN_X,y=MIN_Y;															//(x,y)��ǥ�� ������
	char chInput;																		//�Է¹���
	int flag = TRUE;																	//flag�� TRUE(1)�� �ʱ�ȭ

	printf("\tPlayer : %c",player);														//\t�� ������ �ְ� player�� �������� ǥ��

	//x = MIN_X;
	//y = MIN_Y;
	gotoxy(x,y);																		//gotoxy()�Լ��� Ŀ���̵�

	//nIndex = 1;

	while(flag){																		//flag�� �ʱⰪ�� 1
		chInput = getch();																//getch()�̿��Ͽ� �����Է¹ޱ� 

		switch(chInput) {																
		case ENTER:																		//ENTER���Է��� ���
			if(inputOX(strNumber,player,nIndex)==TRUE)									//inputOX()�� TRUE���
				flag = FALSE;															//flag�� FALSE�� escape condition
			break;
		case LEFT:																		//LEFT�� �Է��� ���
			x = x - TAB_X;																//x��ǥ�� ������ x��ǥ���� �������� TAB_X(8)��ŭ �̵�
			if (x<MIN_X)	x = MIN_X;													//���� x��ǥ�� �������� x��ǥ���� �۴ٸ� x�� �������� x��ǥ�ΰ����� ����
			else			nIndex--;													//�� �ܶ�� ���ڰ� �� �ڸ� ����
			break;																		//escape condition
		case RIGHT:																		//RIGHT�� �Է��� ���
			x = x + TAB_X;																//x��ǥ�� ������ x��ǥ���� ���������� TAB_X��ŭ �̵�
			if (x>MAX_X)	x = MAX_X;													//���� x��ǥ�� �ִ��� MAX_X���� ũ�ٸ� x��ǥ���� MAX_X
			else			nIndex++;													//�� �ܶ�� ���ڰ� �� �ڸ� ����
			break;																		//escape condition
		case UP:																		//UP�� �Է��� ���
			y = y  - TAB_Y;																//y��ǥ�� ������ y��ǥ���� ���� TAB_Y��ŭ �̵�
			if (y<MIN_Y)	y = MIN_Y;													//���� y��ǥ�� �������� y��ǥ���� �۴ٸ� y�� �������� y��ǥ�ΰ����� ���� 
			else			nIndex -= 3;												//�� �ܶ�� ���ڰ� �� �ڸ��� �������� 3��ŭ ����
			break;																		//escape condition
		case DOWN:																		//DOWN�� �Է��� ���
			y = y + TAB_Y;																//y��ǥ�� ������ y��ǥ���� �Ʒ��� TAB_Y��ŭ �̵�
			if (y>MAX_Y)	y = MAX_Y;													//���� y��ǥ�� �ִ��� y��ǥ���� MAX_Y���� ũ�ٸ� MAX_Y�� ����
			else			nIndex += 3;												//�� �ܶ�� ���ڰ� �� �ڸ��� �������� 3 ����
			break;																		//escape condition
		}																				//switch	
		gotoxy(x,y);

	}																					//while
	/*	
	printf("\t");																		//���鸸���
	printf("%c's turn >>", player);														//....�� �������� ǥ���ϴ� printf
	scanf("%d", &nIndex);																//player�� �� �ڸ� �Է��ϴ� scanf

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
char winCheck(char strNumber[])															//winCheck() ->�̱�°���Ǽ�
{
	char chReturn;																		//���ϰ�


	if (strNumber[1]==strNumber[2] &&													//���� 1�� 2�� ���� ���ڰ� ���� 
		strNumber[2]==strNumber[3]) {													//2�� 3������ ���ڰ� ���ٸ� (���� ù°��)
			chReturn = strNumber[1];													//���ϰ��� 1�� ���� ����.
	} else if (strNumber[4]==strNumber[5]&&												//���� 4�� 5�� ���� ���ڰ� ����
		strNumber[5]==strNumber[6]) {													//5�� 6�� ���� ���ڰ� ���ٸ� (���� ��°��)
			chReturn = strNumber[4];													//���ϰ��� 4�� ���� ����
	} else if (strNumber[7]==strNumber[8]&&												//���� 7�� 8�� ���� ���ڰ� ����
		strNumber[8]==strNumber[9]) {													//8�� 9�� ���� ���ڰ� ���ٸ�(���� ��°��)
			chReturn = strNumber[7];													//���ϰ��� 7�� ���� ����
	} else if (strNumber[1]==strNumber[4]&&												//���� 1�� 4�� ���� ���ڰ� ����
		strNumber[4]==strNumber[7]) {													//4�� 7�� ���� ���ڰ� ���ٸ�(���� ù°��)
			chReturn = strNumber[1];													//���ϰ��� 1�� ���� ����
	} else if (strNumber[2]==strNumber[5]&&												//���� 2�� 5�� ���� ���ڰ� ����
		strNumber[5]==strNumber[8]) {													//5�� 8�� ���� ���ڰ� ���ٸ�(���� ��°��)
			chReturn = strNumber[2];													//���ϰ��� 2�� ���� ����
	} else if (strNumber[3]==strNumber[6]&&												//���� 3�� 6�� ���� ���ڰ� ����
		strNumber[6]==strNumber[9]) {													//6�� 9�� ���� ���ڰ� ���ٸ� (���� ��°��)
			chReturn = strNumber[3];													//���ϰ��� 3�� ���� ����
	} else if (strNumber[1]==strNumber[5]&&												//���� 1�� 5�� ���� ���ڰ� ����
		strNumber[5]==strNumber[9]) {													//5�� 9�� ���� ���ڰ� ���ٸ� (�밢�� ��>��)
			chReturn = strNumber[1];													//���ϰ��� 1�� ���� ����
	} else if (strNumber[3]==strNumber[5]&&												//���� 3�� 5�� ���� ���ڰ� ����
		strNumber[5]==strNumber[7]) {													//5�� 7�� ���� ���ڰ� ���ٸ� (�밢�� ��>��)
			chReturn = strNumber[3];													//���ϰ��� 3�� ���� ����
	}else {																				//�� �ܿ���
		chReturn = '\0';																//���ϰ��� NULL���� ó��
	}
	return chReturn;																	//���ϰ��� ���δ�.
}//winCheck

/*int counting(char strNumber[])													//�Է�Ƚ��(�ߺ�����)���� �Լ�
{
int i;																				//for���� ���� ���� i
int nCount=0;																		//�Է�Ƚ�� �� ���� nCount�� 0���� �ʱ�ȭ

for(i=1;i<10;i++)																	//for��(���ڰ� �Է°����� �迭��Ұ� 1~9)
{ if(strNumber[i]=='O'||strNumber[i]=='X')											//� �迭��ҿ� 'O'�� 'X'�� �ִٸ�
{ nCount++;}}																		//nCount�� ����

return nCount;																		//���ϰ��� nCount
}*/

void gotoxy(int x, int y)															//Ŀ���� (x,y)�� �����̴� �Լ� gotoxy()
{
	COORD Cur;																		

	Cur.X = x;
	Cur.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);

}																					//gotoxy

int inputOX(char strNumber[], char player, int index)								//inputOX()�Լ�(�ߺ��Է��� �ȵǰ� �ϱ�)
{
	if (strNumber[index]=='O' || strNumber[index]=='X') return FALSE;				//���� �Է��Ϸ��� ���� �̹� O�� X�� �ִٸ� ���ϰ��� FALSE�� ����Ұ�
	else {																			//�׿ܶ�� �Է��Ϸ��� ���� player�� �̸��� �ִ´�. ���ϰ� TRUE�� ����
		strNumber[index] = player;													
		return TRUE;
	}
}//inputOX()

void StarGame()
{
	int input;																				//����ڰ� �Է��� �� ��¦�� Ƚ���� ���� ����
	int stars;																				//���� ��¦�̴� ���� ������ ���� ����
	int start_x = 10, start_y = 3;															//�簢�� ���� ���� ��� x�� y ��ǥ�� ���� ������ �ʱⰪ
	int width = 50, height = 10;															//���� ��Ÿ�� �簢�� ������ �������� ���� ���̿� ���� ������ �ʱⰪ
	int x, y, i;																			//���� ���� ��Ÿ�� ��ǥ�� ���� ����

																							//���� ������ �ȳ��� ���
	printf("��¦�̴� ���� ������ ���ߴ� �����Դϴ�. �ƹ�Ű�� ������ �����մϴ�.");
	getch();																				//�ƹ� Ű�� ������ ������ �����ϵ��� ��ٸ���.

	system("cls");																			//ȭ�� �����
	Sleep(1000);																			//�տ����� getch()���� �ƹ� Ű�� �����ڸ��� ���ڱ� ��������ʵ��� ���α׷� ������ 1000�и���(1��)���� ����
	srand(time(NULL));																		//rand�Լ��� seed�� ����ð����� ����

	stars = rand()%(MAX - MIN + 1) + MIN;													//����¦�� Ƚ���� �ּ� MIN������ �ִ� MAX�� �� ������ ������ �����ϱ�.

	draw_rectangle(start_x, start_y, width, height);										//���� ��Ÿ�� �簢�� ���� �ٱ����� �׵θ� �׸���
	Sleep(1000);																			//���α׷� ������ 1000�и���(1��)���� �߱�

	for (i=1; i<=stars; i++)																//���� ��Ÿ�� ���� �ȿ��� ������ (x,y)��ǥ�� INTERVAL �������� ���� repeats�� ��¦�̱�
	{
		x = start_x + rand()%(width - 2);													//rand�Լ��� �̿��ؼ� ���� ��Ÿ�� x��ǥ ���ϱ�(-2�� "��"�� �� ĭ�� �����ϹǷ� �Ϲݹ��� ��½ú��� �ִ� x��ǥ�� 1 �� �۾ƾ���
		y = start_y + rand()%(height - 1);													//rand�Լ��� �̿��ؼ� ���� ��Ÿ�� y��ǥ ���ϱ�

		gotoxy(x,y);																		
		printf("%s",STAR);																	//���� (x,y)��ǥ�� ǥ��
	}
		Sleep(1000);																	//INTERVAL �и��ʵ��� ����

	system("cls");
	draw_rectangle(start_x, start_y, width, height);	

	gotoxy(!0, 21);																			//�����ġ
	printf("���� �� ���� (%d ~ %d��) ��¦ �ŷ������?", MIN, MAX);								//����ڿ��� �� ��¦�� Ƚ�� ����
	scanf("%d", &input);																	//�Է¹ޱ�

	gotoxy(!0, 22);																			//�����ġ
	if(input == stars)																	//����ڰ� ���� Ƚ���� ���� Ƚ���� ���ٸ�
		printf("�¾ҽ��ϴ�!\n");
	else																					//�ٸ��ٸ�
		printf("Ʋ�Ƚ��ϴ�. ���� %d���Դϴ�!\n", stars);

}

void draw_rectangle(int start_x, int start_y, int width, int height)						//(start_x, start_y)��ǥ���� �����ϴ� ���� width,���� height�� �簢�� �ٱ����� �׵θ��� �׸��� �Լ�
{
	int col, row;																			//����, ������ ��������

																							//�簢�� �� ��輱 �׸���
	gotoxy(start_x - 1, start_y - 1);														//�簢�� �ٱ��̹Ƿ� ���������� x,y ��ǥ ��� 1�� �� �۴�
	for (col=0;col<=width+1;col++)															//col�� 0���� ������ �簢���� ���κ��� �� ĭ �� ���� �� ���� �ݺ�
		putch('=');																			//�� ��ŭ '='���δ�.

																							//�簢�� �Ʒ� ��輱 �׸���
	gotoxy(start_x - 1, start_y + height);													//�簢�� �ٱ��̹Ƿ� �������� x ��ǥ�� ��ĭ �� �۰�, y��ǥ�� �簢�� ������ ���̸�ŭ ���Ѵ�.
	for (col=0; col<=width+1; col++)														//col�� 0���� ������ �簢���� ���κ��� �� ĭ �� ���� �� ���� �ݺ�
		putch('=');

																							//�簢�� ���� ���� '|' �׸���
	for (row=0;row<height;row++)															//row�� 0���� ������ ������ ���̺��ٴ� ���� ����
	{
		gotoxy(start_x - 1, start_y + row);													//�������� x��ǥ���� 1 �۰�, y��ǥ���� row��ŭ ���� ��ǥ�� �̵�
		putch('|');																			//row��ŭ | ���
	}

																							//�簢�� ������ ���� '|' �׸���
	for (row=0;row<height;row++)															//row�� 0���� ������ ������ ���̺��ٴ� ���� ����
	{
		gotoxy(start_x + width, start_y + row);												//�������� x��ǥ�� �簢�� ������ ���̸�ŭ ���ϰ�, y��ǥ���� row��ŭ ���� ��ǥ�� �̵��Ѵ�
		putch('|');																			//row��ŭ | ���
	}
}

void about()
{
	printf("========================================\n");
	printf("	Programmed by Park, Seoin\n");
	printf("	Copyright@Park\n");
	printf("========================================\n");
}