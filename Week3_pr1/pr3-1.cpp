/**/
#include <stdio.h>
#define MAX_DEGREE 101 //다항식의 최대 차수는 100으로 정함. 배열 크기 정하기 위함

// 함수 선언 area -------------------------------------------
typedef struct  {
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
	int this_degree = s.degree; //최고 차수 몇인지
	for (int i = this_degree; i > 0 ; i--) {
		printf("%.1fx^%d +", s.coef[this_degree-i], i);
	} //아직 차수 0은 출력 안 함!!
	printf("%.1f\n", s.coef[this_degree]); // 상수항 출력
}

polynomial poly_add1(polynomial s1, polynomial s2) {
	polynomial big, small; // 더 차수가 큰 걸 구분 //교수님은 매크로로 정의하심
	if (s1.degree >= s2.degree) {
		big = s1;
		small = s2;
	}	else {
		big = s2;
		small = s1; //타입이 같으므로 대입 ok
	}
	//float this_coef[MAX_DEGREE] = {}; //꼭 정의하지 않아도 됐을 부분
	polynomial result; // = { big.degree,this_coef[MAX_DEGREE - 1] }; //원래 인자로 갖고 있을 부분 따로 정의하려 고민할 필요 X
	result.degree = big.degree;
	int i = 0;
	int bb = big.degree;
	while (1) { //반복문. 뭐 무한반복까진 필요 없겠지만...
		if (bb == small.degree)
			break;
		//같지 않다면,
		result.coef[i] = s1.coef[i]; //큰 차수의 계수 그대로 처리
		i++;
		bb--; //small과 같아질 때까지
	}
	for (int d = i+1; d <= big.degree; d++) { //겹치는 항(i+1)부터 시작. 상수항까지.
		result.coef[d] = big.coef[d] + small.coef[d]; //더해주기
	}
	return result;
}

