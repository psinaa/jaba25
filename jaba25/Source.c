#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define A 1
#define B 4

int rand10(int mmax);
double rand_double(double dmin, double dmax);
int* rand20(int n, int mmax);
double* rand_double2(int n, double dm);
int showGist(int* counterArray, int arrayLenght);
void sortArr(int* num, int size, int step);

void main() {
	// 1
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int m = 1 + rand() % 10;
	int k;
	puts("Введите число: ");
	scanf("%d", &k);
	if (k == m) {
		printf("Вы отгадали число! Ваш ответ: %d. Загаданное число: %d", k, m);
	}
	else {
		printf("Вы не отгадали число! Ваш ответ: %d. Загаданное число: %d", k, m);
	}

	// 1.4
	m = A + rand() % (B - A);
	puts("\nВведите число для выбора предмета(1 - камень, 2 - ножницы, 3 - бумага): ");
	scanf("%d", &k);
	if (k == m) {
		printf("Ничья! Оба игрока выбрали один и тот же предмет.");
	}
	else if (k == 1 && m == 2) {
		printf("Вы выйграли! У вас был камень, а противник выбрал ножницы");
	}
	else if (k == 2 && m == 3) {
		printf("Вы выйграли! У вас были ножницы, а противник выбрал бумагу");
	}
	else if (k == 3 && m == 1) {
		printf("Вы выйграли! У вас была бумага, а противник выбрал камень");
	}
	else {
		printf("Вы проиграли!");
	}

	// 2
	int randNum = rand10(20);
	double randNum2 = rand_double(12.3, 100.5);
	int* randNums = rand20(20, 600);
	double* randNums2 = rand_double2(20, 300);
	printf("\n\n\nРандомное число из первой функции равно: %d", randNum);
	printf("\nРандомное число из второй функции равно: %d", randNum2);
	printf("\nРандомные числа из третьей функции равны: ");
	for (int i = 0; i < 20; i++) {
		printf("\n randNums[%d] = %d", i, randNums[i]);
	}
	printf("\n\nРандомные числа из четвёртой функции равны: ");
	for (int i = 0; i < 20; i++) {
		printf("\n randNums[%d] = %lf", i, randNums2[i]);
	}

	// 3
	int arraySize, maxNum;
	puts("\n\n\nВведите длину массива рандомных чисел: ");
	scanf("%d", &arraySize);
	puts("\nВведите максимальное рандомное число: ");
	scanf("%d", &maxNum);
	int* counter;
	counter = (int*)calloc(maxNum, sizeof(int));
	int* randomArray = rand20(arraySize, maxNum);

	for (int i = 0; i < arraySize; i++) {
		counter[randomArray[i]]++;
	}
	for (int i = 0; i < maxNum; i++) {
		printf("\ncounter[%d] = %d", i, counter[i]);
	}
	puts("\n\n\n");
	for (int i = 0; i < arraySize; i++) {
		printf("\nandomArray[%d] = %d", i, randomArray[i]);
	}
	puts("\n\n\n");
	showGist(counter, maxNum);

	int nums[] = { 0, 5, 4, 2, 57, 6, 12, 42, 43, 784 };

	puts("\n\n\n");

	sortArr(nums, 10, 2);
	for (int i = 0; i < 10; i++) {
		printf("\n%d", nums[i]);
		;
	}
}

int rand10(int mmax) {
	int res = A + rand() % (mmax - A);
	return res;
}

double rand_double(double dmin, double dmax) {
	double res = dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
	return res;
}

int* rand20(int n, int mmax) {
	int* res = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		res[i] = A + rand() % (mmax - A);
	}
	return res;
}

double* rand_double2(int n, double dm) {
	double* res = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		res[i] = (-1 * dm) + 1.f * (dm - (-1 * dm)) * rand() / RAND_MAX;
	}
	return res;
}

int showGist(int* counterArray, int arrayLenght) {
	int maxNum = -10000000;
	for (int i = 0; i < arrayLenght; i++) {
		if (counterArray[i] > maxNum) {
			maxNum = counterArray[i];
		}
	}
	for (int i = maxNum; i > 0; i--) {
		for (int j = 0; j < arrayLenght; j++) {
			if ((counterArray[j] >= i)) {
				printf("**");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}

void sortArr(int* num, int size, int step)
{
	for (int i = 0; i < size - 1; i += step)
	{
		for (int j = (size - 1); j > i; j -= step)
		{
			if (num[j - 1] > num[j])
			{
				int temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}

	}
}