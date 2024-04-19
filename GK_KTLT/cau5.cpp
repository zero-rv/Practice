#include <iostream>
#include <math.h>
using namespace std;

int* A;//Tap A tu 1 den n
int* mark;//Danh dau so duoc chon (0: chua | 1: roi)
int n, k, node = 1;
void chinhhop(int i, int n, int k);
void inputIntArr(int*& arr, int size);
void printArr(int* arr, int size);
double giaithua(double n);
double s1(double n, double x);
double s2(double n);
int Fib(int n);
bool isOdd(int n);
bool isEven(int n);
bool isNeg(int n);
bool isPos(int n);
int countCondition(int* arr, int current_index, bool(*condition)(int));
bool asc(int a, int b);
void sort(int* arr, int current_index, bool(*condition)(int, int));

int main()
{
	//Tinh S(x,n)
	double n_s1, x;
	cout << "Nhap n cho S1(x,n): "; cin >> n_s1;
	cout << "Nhap x can tinh: "; cin >> x;
	double result_s1 = s1(n_s1, x);
	cout << "Ket qua S1(x,n) = " << result_s1;
	//Tinh S(n)
	double n_s2;
	do
	{
		cout << "\nNhap n cho S2(n) voi n >= 0: ";
		cin >> n_s2;
	} while (n_s2 < 0);
	double result_s2 = s2(n_s2);
	cout << "Ket qua S2(n) = " << result_s2;
	//Fibonacci
	int n_fib;
	do
	{
		cout << "\nNhap so Fib thu n can tinh voi n >= 0: ";
		cin >> n_fib;
	} while (n_fib < 0);
	int result_fib = Fib(n_fib);
	cout << "So hang thu " << n_fib << " cua day Fib = " << result_fib;
	//Nhap mang
	int size;
	cout << "\nNhap so phan tu cua mang: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Nhap mang: ";
	inputIntArr(arr, size);
	//So le
	int count_odd = countCondition(arr, size - 1, isOdd);
	cout << "So luong so le trong mang: " << count_odd;
	//So chan
	int count_even = countCondition(arr, size - 1, isEven);
	cout << "\nSo luong so chan trong mang: " << count_even;
	//So am
	int count_neg = countCondition(arr, size - 1, isNeg);
	cout << "\nSo luong so am trong mang: " << count_neg;
	//So duong
	int count_pos = countCondition(arr, size - 1, isPos);
	cout << "\nSo luong so duong trong mang: " << count_pos;
	//Tang dan
	sort(arr, size - 1, asc);
	cout << "\nMang sau khi sap xep tang dan: "; printArr(arr, size);
	//Hoan vi:
	cout << "\nNhap n phan tu muon hoan vi cua A, tu 1 den n: "; cin >> n;
	A = new int[n];
	mark = new int[n] {0};
	cout << "\nCo tat ca " << giaithua(n) << " hoan vi cua A:\n";
	chinhhop(0, n, n);
	delete[] A;
	delete[] mark;
	node = 1; //RESET so liet ke ve 1
	//May tinh
	do
	{
		do
		{
			cout << "\nNhap so may tinh dang co, toi da 10 may tinh: "; cin >> n;
		} while (n <= 0 || n > 10);
		cout << "\nNhap so khach hang thue may tinh, toi da " << n << " khach hang: "; cin >> k;
	} while (k > n);
	A = new int[k];
	mark = new int[n] {0};
	cout << "Co " << giaithua(n) / giaithua(n - k) << " cach bo tri lan luot khach hang vao cac may nhu sau:\n";
	chinhhop(0, n, k);

	delete[] arr;
	delete[] A;
	delete[] mark;
	arr = A = mark = nullptr;
	return 0;
}

void inputIntArr(int*& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

double giaithua(double n)
{
	if (n < 2)
		return n;
	return n * giaithua(n - 1);
}

double s1(double n, double x)
{
	if (n == 0)
		return 1;
	return (giaithua(n) / pow(x, n)) + s1(n - 1, x);
}

double s2(double n)
{
	if (n < 2)
		return n;
	return sqrt(n + s2(n - 1));
}

int Fib(int n)
{
	if (n < 2)
		return n;
	return Fib(n - 1) + Fib(n - 2);
}

bool isOdd(int n)
{
	return n % 2 != 0;
}

bool isEven(int n)
{
	return n % 2 == 0;
}

bool isNeg(int n)
{
	return n < 0;
}

bool isPos(int n)
{
	return n > 0;
}

int countCondition(int* arr, int current_index, bool(*condition)(int))
{
	if (current_index < 0)
		return 0;
	return (condition(arr[current_index]) ? 1 : 0) + countCondition(arr, current_index - 1, condition);
}


bool asc(int a, int b)
{
	return a > b;
}

void sort(int* arr, int current_index, bool(*condition)(int, int))
{
	if (current_index == 0)
		return;
	for (int i = 0; i < current_index; i++)
	{
		if (condition(arr[i],arr[i+1]))
		{
			int tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
		}
	}
	sort(arr, current_index - 1, condition);
}

void chinhhop(int i, int n, int k)
{
	if (i == k)
	{
		cout << "Cach " << node++ << ": ";
		printArr(A, k);
	}
	else
	{
		for (int j = 1; j <= n; j++)
		{
			if (mark[j - 1] == 0)
			{
				A[i] = j;
				mark[j - 1] = 1;
				chinhhop(i + 1, n, k);
				mark[j - 1] = 0;
			}
		}
	}
}