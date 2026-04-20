#include "Cmplx.h"

int main()
{
	Cmplx cmplxs[7];

	printf("Input complex number (rrr,iii,ddd) : ");
	cmplxs[0] = inputCmplx(cmplxs[0]);
	printf("Input complex number (rrr,iii,ddd) : ");
	cmplxs[1] = inputCmplx(cmplxs[1]);
	cmplxs[0].mgn = sqrt(pow(cmplxs[0].real, 2.0) + pow(cmplxs[0].imag, 2.0)); // 0번째 배열에 a+bi의 절댓값 저장
	cmplxs[1].mgn = sqrt(pow(cmplxs[1].real, 2.0) + pow(cmplxs[1].imag, 2.0)); // 1번째 배열의 c+di의 절댓값 저장
	cmplxs[2] = cmplxAdd(cmplxs[0], cmplxs[1]); // 복소수 덧셈
	cmplxs[3] = cmplxSub(cmplxs[0], cmplxs[1]); // 복소수 뺄셈
	cmplxs[4] = cmplxMul(cmplxs[0], cmplxs[1]); // 복소수 곱셈
	cmplxs[5] = cmplxDiv(cmplxs[0], cmplxs[1]); // 복소수 나눗셈

	printf("cmplxs[0] = ");
	printCmplx(cmplxs[0]);
	printf("\n");
	printf("cmplxs[1] = ");
	printCmplx(cmplxs[1]);
	printf("\n");
	cmplxs[2] = cmplxAdd(cmplxs[0], cmplxs[1]);
	printf("cmplxs[2] = cmplxs[0] + cmplxs[1] = \n ");
	printCmplx(cmplxs[0]); printf(" + "); printCmplx(cmplxs[1]); printf(" = "); printCmplx(cmplxs[2]); printf("\n");

	cmplxs[3] = cmplxSub(cmplxs[0], cmplxs[1]);
	printf("cmplxs[3] = cmplxs[0] - cmplxs[1] = \n ");
	printCmplx(cmplxs[0]); printf(" - "); printCmplx(cmplxs[1]); printf(" = "); printCmplx(cmplxs[3]); printf("\n");

	cmplxs[4] = cmplxMul(cmplxs[0], cmplxs[1]);
	printf("cmplxs[4] = cmplxs[0] * cmplxs[1] = \n ");
	printCmplx(cmplxs[0]); printf(" * "); printCmplx(cmplxs[1]); printf(" = "); printCmplx(cmplxs[4]); printf("\n");
	
	cmplxs[5] = cmplxDiv(cmplxs[0], cmplxs[1]);
	printf("cmplxs[5] = cmplxs[0] / cmplxs[1] = \n ");
	printCmplx(cmplxs[0]); printf(" / "); printCmplx(cmplxs[1]); printf(" = "); printCmplx(cmplxs[5]); printf("\n");
	
	cmplxs[6] = cmplxMul(cmplxs[1], cmplxs[5]);
	printf("cmplxs[6] = cmplxs[1] * cmplxs[5] = \n ");
	printCmplx(cmplxs[1]); printf(" * "); printCmplx(cmplxs[5]); printf(" = "); printCmplx(cmplxs[6]); printf("\n");
	printf("Before sorting complexs: \n");

	for (int i = 0; i < 7; i++)
	{
		printf("cmplxs[%d] = ", i); printCmplx(cmplxs[i]);
		printf("\n");
	}
	sortCmplx(cmplxs, 7);

	printf("Sorted complexs: \n");
	for (int i = 0; i < 7; i++)
	{
		printf("cmplxs[%d] = ", i); printCmplx(cmplxs[i]);
		printf("\n");
	}
}