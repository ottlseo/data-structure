/* 역삼각형 출력하기 응용 */
#include <stdio.h>

void triangle(int num); //일반 삼각형 출력
void upgrade_triangle(int num); //가운데 정렬한 삼각형 출력

int main() {
	int num; //숫자 입력받기
	/**/
	printf("한 변의 길이를 입력하세용: ");
	scanf_s("%d", &num);
	
	printf("\n< triangle >\n");
	triangle(num);

	printf("\n< upgrade triangle >\n");
	upgrade_triangle(num);
	
	return 0;
}
void triangle(int num) {
	for (int i = num; i > 0; i--) {
		for (int j = i; j > 0; j--)
			putchar('*');
		putchar('\n');
	}
}
void upgrade_triangle(int num) {
	for (int i = num; i > 0; i-=2) {
		for (int blank = 0; blank < (num - i)/2; blank++) {
			putchar(' ');
		}
		for (int star = 0; star < i; star++) {
			putchar('*');
		}
		putchar('\n');
	}
}

