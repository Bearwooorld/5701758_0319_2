#include <stdio.h>
#include <time.h>

double power_iter(double x, int n) { //순환함수
	double result = 1.0;
	for (int i = 0; i < n; i++)
		result = result * x;
	return(result);
}

double power_rec(double x, int n) { //재귀함수
	if (n == 0)
		return 1;
	else if ((n / 2) == 0)
		return power_rec(x * x, n / 2);
	else if ((n / 2) != 0)
		return x * power_rec(x * x, (n - 1) / 2);
}

int main() {

	clock_t start_iter, end_iter, start_rec, end_rec; // 시간 측정 변수
	start_iter = clock(); // 시간 측정 시작
	double result_iter = power_iter(13, 21); // 순환함수에서의 결과
	end_iter = clock(); // 시간 측정 끝
	long time_sum_iter = end_iter - start_iter; // 시간 측정 값 계산
	printf("Power Iterative Result: %f \n", result_iter); // 순환함수에 의한 결과 출력
	printf("Time: %f \n", (double)time_sum_iter / CLOCKS_PER_SEC); // 시간 측정 값 출력
	start_rec = clock(); // 시간 측정 시작
	double result_rec = power_rec(13, 21); // 재귀함수에서의 결과
	end_rec = clock(); // 시간 측정 끝
	double time_sum_rec = end_rec - start_rec;  // 시간 측정 값 계산
	printf("Power Iterative Result: %f \n", result_iter); // 재귀함수에 의한 결과
	printf("Time: %f \n", (double)time_sum_rec / CLOCKS_PER_SEC); // 시간 측정 값 출력
}