/**/
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b)) // 더 큰 값 골라주는 macro
#define MAX_DEGREE 101

// 함수 선언 area -------------------------------------------
typedef struct {
	int degree; //정의에서 초기화 불가능
	float coef[MAX_DEGREE];
}polynomial; //polynomial 이라고 부르겠다

void print_poly(polynomial s);
polynomial poly_add1(polynomial s1, polynomial s2); // 두 다항식 덧셈

// (메인) 함수 호출 area ------------------------------------
int main(void) {
	polynomial b = { 6, {2,3,6,0,0,0,10} }; // 구조체 변수 선언!!
	polynomial a = { 4, {7,0,5,0,1} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b); //a와 b 더해서 c에 저장
	printf("----------------------------------\n");
	print_poly(c);
	return 0;
}

// 함수 정의 area --------------------------------------------
void print_poly(polynomial s) {
	for (int i = s.degree; i > 0; i--)
		printf("%3.1fx^%d +", s.coef[s.degree - i], i);
	printf("%3.1f\n", s.coef[s.degree]); // 상수항
}
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C; //결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수(차수 큰 것의 계수가 인덱스 0부터 시작하므로...)
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); //결과 다항식 차수(더 큰 값으로)

	while (Apos <= A.degree && Bpos <= B.degree) { //배열크기가 차수값이 되도록
		if (degree_a > degree_b) { // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++]; //클 때는 계속 그냥 대입
			degree_a--;
		}
		else if (degree_a == degree_b) { //A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else
		{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	} //end of While
	return C;

}
