/* week3. 배열 이용한 다항식 표현 #1 */

#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b)) //macro
#define MAX_DEGREE 101

typedef struct {
	int degree; //다항식 차수
	float coef[MAX_DEGREE]; // 각 항별 계수
} polynomial;

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}
polynomial poly_add(polynomial A, polynomial B) {
	polynomial C; //결과식
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수(coef)
	int degree_A = A.degree;
	int degree_B = B.degree;
	C.degree = MAX(A.degree, B.degree); //C의 차수는 A,B중 더 큰 차수로 결정
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_A > degree_B) { // A항>B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_A--; //다음항으로 이동
		}
		else if (degree_A == degree_B) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_A--; degree_B--;
		}
		else { // A항 < B항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_B--; //다음항으로 이동
		}
	} //end of while
	return C;
}
int main() {
	polynomial b = { 6,{2,3,6,0,0,0,10} }; //모든 항의 계수를 다 입력해주어야함
	polynomial a = { 4,{7,0,5,0,1} };
	polynomial c;

	printf("<< Poly A >>\n");
	print_poly(a);
	printf("\n<< Poly B >>\n");
	print_poly(b);
	c = poly_add(a, b);
	printf("\n----------------------\n<< Poly C >>\n");
	print_poly(c);

	return 0;
}
