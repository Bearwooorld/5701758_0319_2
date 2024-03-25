#include <stdio.h>
#include <time.h>

double power_iter(double x, int n) { //��ȯ�Լ�
	double result = 1.0;
	for (int i = 0; i < n; i++)
		result = result * x;
	return(result);
}

double power_rec(double x, int n) { //����Լ�
	if (n == 0)
		return 1;
	else if ((n / 2) == 0)
		return power_rec(x * x, n / 2);
	else if ((n / 2) != 0)
		return x * power_rec(x * x, (n - 1) / 2);
}

int main() {

	clock_t start_iter, end_iter, start_rec, end_rec; // �ð� ���� ����
	start_iter = clock(); // �ð� ���� ����
	double result_iter = power_iter(13, 21); // ��ȯ�Լ������� ���
	end_iter = clock(); // �ð� ���� ��
	long time_sum_iter = end_iter - start_iter; // �ð� ���� �� ���
	printf("Power Iterative Result: %f \n", result_iter); // ��ȯ�Լ��� ���� ��� ���
	printf("Time: %f \n", (double)time_sum_iter / CLOCKS_PER_SEC); // �ð� ���� �� ���
	start_rec = clock(); // �ð� ���� ����
	double result_rec = power_rec(13, 21); // ����Լ������� ���
	end_rec = clock(); // �ð� ���� ��
	double time_sum_rec = end_rec - start_rec;  // �ð� ���� �� ���
	printf("Power Iterative Result: %f \n", result_iter); // ����Լ��� ���� ���
	printf("Time: %f \n", (double)time_sum_rec / CLOCKS_PER_SEC); // �ð� ���� �� ���
}