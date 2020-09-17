/* 1~100 범위의 7의 배수 더하기 */
#include <stdio.h>

int main() {
	int n, sum = 0;
	// 100/7 = 14 ...2
	for (int i = 1; i <= 14; i++) {
		n = 7 * i;
		sum += n;
		printf("[%d] -> [%d]\n", n, sum);
	}
	printf("합계: %d", sum);
	return 0;
}