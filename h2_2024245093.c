#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int lotteryNumber[7], bonusNumber;
void RandomPick(int a) {
	int pickedNumber, redoRandomPick, i;
	redoRandomPick = 1;
	while (redoRandomPick) { //중복된 숫자가 뽑혔는지 검사
		pickedNumber = rand() % 45 + 1;
		redoRandomPick = 0;
		for (i = 0; i < 7; i++) {
			if (pickedNumber == lotteryNumber[i]) {
				redoRandomPick = 1;
				break;
			}
		}
	}
	lotteryNumber[a] = pickedNumber;
}
void initiateLotterySystem() {
	srand(time(NULL));
	int UserPick[6], usersInput;
	int doInputUserPick, i, j, k;
	int counter = 0;
	for (i = 0; i < 7; i++) {
		RandomPick(i);
	}
	for (i = 0; i < 6; i++) {
		doInputUserPick = 1;
		while (doInputUserPick) { //1~45인지, 중복된 숫자인지 확인
			doInputUserPick = 0;
			printf("로또 번호를 입력해주세요 (1 ~ 45): ");
			scanf("%d", &usersInput);
			while (usersInput < 1 || usersInput>45) {
				printf("1 ~ 45 사이의 숫자를 입력해주세요.\n");
				printf("로또 번호를 입력해주세요 (1 ~ 45): ");
				scanf("%d", &usersInput);
			}
			for (j = 0; j < i; j++) {
				if (usersInput == UserPick[j]) {
					doInputUserPick = 1;
					printf("중복된 숫자는 입력할 수 없습니다. 다른 숫자를 입력하세요.\n");
					break;
				}
			}
		}
		UserPick[i] = usersInput;
	}
		for (j = 0; j < 6; j++) {
			if (usersInput == lotteryNumber[j]) {
				counter++;
				break;
			}
		}
		int isBonus;
		bonusNumber = lotteryNumber[6]; //보너스 번호
		printf("로또 번호 : ");
		for (i = 0; i < 6; i++) {
			printf("%d ", lotteryNumber[i]);
		}
		printf("보너스 번호 : %d\n", bonusNumber);
		switch (counter) {
		case 6:
			printf("1등입니다! (6개 번호 일치)");
			break;
		case 5:
			for (i = 0; i < 6; i++) {
				if (bonusNumber == UserPick[i]) {
					isBonus = 1;
					break;
				}
			}
			if (isBonus) printf("2등입니다! ");
			else printf("3등입니다! (5개 번호 일치)");
			break;
		case 4:
			printf("4등입니다! (4개의 번호 일치)");
			break;
		case 3:
			printf("5등입니다! (3개의 번호 일치)");
			break;
		default:
			printf("꽝");
		}
		

	}

int main() {
	initiateLotterySystem();
	return 0;
}