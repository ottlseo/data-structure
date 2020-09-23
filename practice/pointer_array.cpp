/* week3 배열과 포인터 예제 1 */

#include <stdio.h>
#define SIZE 6
void get_integers(int list[]) {
	printf("6개의 정수를 입력하세요: \n");
	for (int i = 0; i < SIZE; i++)
		scanf_s("%d", &list[i]);
}
int cal_sum(int * list) { // int cal_sum(int list[])와 같은 의미
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += *(list + i); //i만큼 방 이동한 곳의 '값'을 계속 더해주기
	}
	return sum;
}
int main(void) {
	int list[SIZE];
	get_integers(list); //배열 이름은 포인터임
	printf("sum = %d\n",cal_sum(list));
	
	return 0;
}
