#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 //배열 최대 크기를 101로

struct { //구조체 이렇게 정의할 경우, 다음에 새롭게 정의하진 못함 !
	float coef; //계수
	int expon; //차수
} terms[MAX_TERMS] = { {4,7},{8,6},{7,5} ,{1,1},{10,3},{-7,1},{1,0} }; //terms는 전역변수. 인자로 전달 안해도 어디서든 사용가능
int avail = 7; //현재 비어있는 위치의 index(임의로 저장)

void add_one(float coef, int expon) { //계수랑 차수 입력하면 새로운 항으로 terms에 추가
	if (avail > MAX_TERMS) { //최대크기 넘어갈 경우
		printf("저장 불가\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}
void print_poly(int s, int e) {
	for (int i = s; i < e; i++)
		printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%.1fx^%d", terms[e].coef, terms[e].expon);
}
void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) { // A+B = C
	// As(A start), Ae(A end)
	// Cs, Ce 주소값으로 받는 이유??? - 반환값이 두개일 수 없으므로 call by reference

	*Cs = avail; //결과 다항식의 시작 위치
	while (As <= Ae && Bs <= Be) { //start-end 지키도록
		if (terms[As].expon > terms[Bs].expon) { // A다항식의 차수가 더 큰 경우
			add_one(terms[As].coef, terms[As].expon);
			As++; //하나 더 이동
		}
		else if (terms[As].expon == terms[Bs].expon) { //같을 경우 --> 더한다
			if (terms[As].expon + terms[Bs].expon != 0) //합쳐서 계수가 0일 경우- 항 추가 x
				add_one(terms[As].expon + terms[Bs].expon, terms[As].coef);
			As++; Bs++;
		}
		else { //B 차수가 더 클 경우
			add_one(terms[Bs].expon, terms[Bs].coef);
			Bs++;
		}
	}
	for (; As <= Ae; As++) //B다항식이 다 처리되고 A만 남은 경우(조건: As<=Ae)--> 남은 A 다항식 복사
		add_one(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		add_one(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1; //항 추가 후 avail이 자동으로 증가되었으므로 종료 위치는 avail-1
}

int main() {
	int As = 0, Ae = 3, Bs = 4, Be = 6; //다항식A는 0~3, B는 4~6 (인덱스 기준)
	int Cs, Ce;
	poly_add(As, Ae, Bs, Be, &Cs, &Ce); //결과값인 C는 주소로 보내기
	
	printf("\n< A >\n");
	print_poly(As, Ae);
	printf("\n< B >\n");
	print_poly(Bs, Be);

	printf("\n< C >\n");
	print_poly(Cs, Ce);

	return 0;
}