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
		case DIE_SIMULATION: dieSimulation(); break;						//DIE_SIMULATION�� ������Ͽ��� 1�� ������ ���� �Ǿ����Ƿ� 1�� �� dieSimulation()�Լ� ����
		case GAME_SHOW	   : gameShow(); break;								//GAME_SHOW�� ������Ͽ��� 2�� ������ ���� �Ǿ����Ƿ� 2�� �� gameShow()�Լ� ����
		case HIGH_LOW_GAME : highLowGame(); break;							//HIGH_LOW_GAME�� ������Ͽ��� 3�� ������ ���� �Ǿ����Ƿ� 3�� �� highLowGame() �Լ�����
		case MENU4: menu4(); break;											//MENU4�� ������Ͽ��� 4�� ������ ���� �Ǿ����Ƿ� 4�� �� menu4()�Լ� ����
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
	printf("  4.MENU 4\n");
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

void highLowGame() {																		//highLowG/ame
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

	}																						//while

}																							// highLowGame()

void menu4() {
	//test 
	printf("4�� �޴�\n");
} // menu4