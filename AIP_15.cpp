#include <iostream>
#include <string>
using namespace std;

void ex_1();
void ex_2();

int main() {
	ex_1();
	ex_2();
	return 0;
}

// ********************************************* Задание 1 ***************************************
int translation(int h, int m);
int translation(int m);

void ex_1() {
	int min, hours;

	cout << "Enter time" << endl;
	cout << "Minutes:";  cin >> min;
	if (min < 60) 
	{
		cout << "Hours:";
		cin >> hours;
		cout << hours << "h " << min << "m = " << translation(hours, min) << "m";
	}
	else cout << min << "m = " << translation(min)/100 << "h " << translation(min)%100 << "m";
	
}

int translation(int h, int m) { 
	return h * 60 + m; 
}
int translation(int min) {
	int h, m;
	h = min / 60;
	m = min % 60;
	return h * 100 + m;
}

// ********************************************* Задание 2 ***************************************
template <class T> T odd_sum(T array, T N);
template <class T> T between_negative_sum(T array, T N);
template <class T> T array_clearing(T array, T N);

double odd_sum(double* array, int N); // Суммирование несётных элиментов массива
double between_negative_sum(double* array, int N); // Суммирование чисел между первой и послендей отрицателной цифрой
void array_clearing(double* array, int N); // Удаление ввсех элементов по модулю меньших 1

float odd_sum(float* array, int N);
float between_negative_sum(float* array, int N);
void array_clearing(float* array, int N);

int odd_sum(int* array, int N);
int between_negative_sum(int* array, int N);
void array_clearing(int* array, int N);


void ex_2() {
	int N, type;
	cout << "Enter the size of the array: "; cin >> N;
	double* array = new double[N];
	float* array1 = new float[N];
	int* array2 = new int[N];

	cout << "Select the type of values for the array cells (1 - int, 2 - float, 3 - double): ";
	cin >> type;

	switch (type)
	{
	case 1:
	{
		for (int i = 1; i < N; i++) //Заполнение массива
		{
			cout << "array[" << i << "] = ";
			cin >> array2[i];
		}

		cout << "\nThe sum of the odd elements of the array is " << odd_sum(array2, N);
		cout << "\nThe sum of the elements between the first and the last negative number is " << between_negative_sum(array2, N);

		array_clearing(array2, N);
		cout << endl << "Compressed array: " << endl;
		for (int i = 0; i < N; i++) cout << "	" << array2[i];
	}

	case 2:
	{
		for (int i = 1; i < N; i++) //Заполнение массива
		{
			cout << "array[" << i << "] = ";
			cin >> array1[i];
		}

		cout << "\nThe sum of the odd elements of the array is " << odd_sum(array1, N);
		cout << "\nThe sum of the elements between the first and the last negative number is " << between_negative_sum(array1, N);

		array_clearing(array1, N);
		cout << endl << "Compressed array: " << endl;
		for (int i = 0; i < N; i++) cout << "	" << array1[i];
	}

	case 3:
	{
		for (int i = 1; i < N; i++) //Заполнение массива
		{
			cout << "array[" << i << "] = ";
			cin >> array[i];
		}

		cout << "\nThe sum of the odd elements of the array is " << odd_sum(array, N);
		cout << "\nThe sum of the elements between the first and the last negative number is " << between_negative_sum(array, N);

		array_clearing(array, N);
		cout << endl << "Compressed array: " << endl;
		for (int i = 0; i < N; i++) cout << "	" << array[i];
	}
	}
}

// Для double
double odd_sum(double* array, int N) {
	double sum = 0;
	for (int i = 1; i < N; i +=2)
	{
		sum += array[i];
	}
	return sum;
}
double between_negative_sum(double* array, int N) {
	int first = -1,last = 0;
	double fn = 0, ln = 0;

	for (int i = 0; i < N; i++) // Поиск первой отрицательной цифры
	{
		if ((array[i]) < 0 && (fn == 0)) {
			fn = array[i];
			first = i;
		}
	}
	for (int i = N; i >= 0; i--) // Поиск последней отрицательной цифры
	{
		if ((array[i]) < 0 && (ln == 0)) {
			ln = array[i];
			last = i;
		}
	}

	if (first != last) // Суммирование если первая и посленяя отрицательные элененты это не одно и то же
	{
		double sum = 0;
		for (int i = first+1; i < last; i++) sum += array[i];
		return sum;
	}
	else return 0;
}
void array_clearing(double* array, int N) {
	int zero = 0;

	for (int i = 0; i < N; i++) if (abs(array[i]) < 1) array[i] = 0; // Обнуление всех элементов меньше одного по модулю
	
	for (int i = 0; i < N; i++) 
	{
		if (array[i] == 0) 
		{
			for (int k = i; k < N; k++)
			{
				if (array[k] != 0)
				{
					array[i] = array[k];
					array[k] = 0;
					break;
				}
				else zero++;
			}

			if (zero == N - i) break;
		}
	}
}

// Для float
float odd_sum(float* array, int N) {
	float sum = 0;
	for (int i = 1; i < N; i += 2)
	{
		sum += array[i];
	}
	return sum;
}
float between_negative_sum(float* array, int N) {
	int first = -1, last = 0;
	float fn = 0, ln = 0;

	for (int i = 0; i < N; i++) // Поиск первой отрицательной цифры
	{
		if ((array[i]) < 0 && (fn == 0)) {
			fn = array[i];
			first = i;
		}
	}
	for (int i = N; i >= 0; i--) // Поиск последней отрицательной цифры
	{
		if ((array[i]) < 0 && (ln == 0)) {
			ln = array[i];
			last = i;
		}
	}

	if (first != last) // Суммирование если первая и посленяя отрицательные элененты это не одно и то же
	{
		float sum = 0;
		for (int i = first + 1; i < last; i++) sum += array[i];
		return sum;
	}
	else return 0;
}
void array_clearing(float* array, int N) {
	int zero = 0;

	for (int i = 0; i < N; i++) if (abs(array[i]) < 1) array[i] = 0; // Обнуление всех элементов меньше одного по модулю

	for (int i = 0; i < N; i++)
	{
		if (array[i] == 0)
		{
			for (int k = i; k < N; k++)
			{
				if (array[k] != 0)
				{
					array[i] = array[k];
					array[k] = 0;
					break;
				}
				else zero++;
			}

			if (zero == N - i) break;
		}
	}
}

// Для int
int odd_sum(int* array, int N) {
	int sum = 0;
	for (int i = 1; i < N; i += 2)
	{
		sum += array[i];
	}
	return sum;
}
int between_negative_sum(int* array, int N) {
	int first = -1, last = 0;
	int fn = 0, ln = 0;

	for (int i = 0; i < N; i++) // Поиск первой отрицательной цифры
	{
		if ((array[i]) < 0 && (fn == 0)) {
			fn = array[i];
			first = i;
		}
	}
	for (int i = N; i >= 0; i--) // Поиск последней отрицательной цифры
	{
		if ((array[i]) < 0 && (ln == 0)) {
			ln = array[i];
			last = i;
		}
	}

	if (first != last) // Суммирование если первая и посленяя отрицательные элененты это не одно и то же
	{
		int sum = 0;
		for (int i = first + 1; i < last; i++) sum += array[i];
		return sum;
	}
	else return 0;
}
void array_clearing(int* array, int N) {
	int zero = 0;

	for (int i = 0; i < N; i++) if (abs(array[i]) < 1) array[i] = 0; // Обнуление всех элементов меньше одного по модулю

	for (int i = 0; i < N; i++)
	{
		if (array[i] == 0)
		{
			for (int k = i; k < N; k++)
			{
				if (array[k] != 0)
				{
					array[i] = array[k];
					array[k] = 0;
					break;
				}
				else zero++;
			}

			if (zero == N - i) break;
		}
	}
}