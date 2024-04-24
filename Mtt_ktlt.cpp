#include <iostream>
#include <math.h>
#include <ctime>
#define MAXVALUE 50
using namespace std;

void createArr(int**& arr, int &r, int &c);
void inputRandArr(int**& arr, int r, int c);
void printArr(int* arr, int size);
void printArr(int** arr, int r, int c);
int* getLastMin_Row(int** arr, int r_input, int c);
int tongcot(int** a, int current_r, int s_col, int sum);
int* flatMap(int** arr, int r, int c_input);
bool isPrime(int n);
void printPrime(int** arr, int r, int c);

int main()
{
	int r, c;
	int** arr = nullptr;
	//Tao mang 2 chieu ngau nhien
	createArr(arr, r, c);
	inputRandArr(arr, r, c);
	//Xuat mang
	cout << "Mang sinh so ngau nhien duoc tao:\n";
	printArr(arr, r, c);
	//Dia chi min cuoi cung
	int r_min;
	do
	{
		cout << "Nhap so dong can tim so nho nhat, tu 0 den " << r - 1 <<": ";
		cin >> r_min;
	} while (r_min < 0 || r_min > r - 1);
	int* getLastMin = getLastMin_Row(arr, r_min, c);
	cout << "Dia chi so nho nhat cuoi cung tren dong da nhap: " << getLastMin << endl;
	//Tong cot
	int c_sum;
	do
	{
		cout << "Nhap so cot can tinh tong, tu 0 den " << c - 1 << ": ";
		cin >> c_sum;
	} while (c_sum < 0 || c_sum > c - 1);
	int result = tongcot(arr, r - 1, c_sum, 0);
	cout << "Tong gia tri tren cot da nhap: " << result << endl;
	//Flatmap
	int c_flatmap, size = r;
	do
	{
		cout << "Nhap so cot can duoc flatMap, tu 0 den " << c - 1 << ": ";
		cin >> c_flatmap;
	} while (c_flatmap < 0 || c_flatmap > c - 1);
	int* getFlatMap = flatMap(arr, r, c_flatmap);
	cout << "Cot da nhap sau khi duoc flatMap: "; printArr(getFlatMap, size);
	cout << endl;
	//In so nguyen to trong mang
	printPrime(arr, r, c);

	//Giai phong
	for (int i = 0; i < r; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
	return 0;
}

void createArr(int**& arr, int &r, int &c)
{
	do
	{
		do
		{
			cout << "Nhap so dong: "; cin >> r;
		} while (r <= 0);
		cout << "Nhap so cot: "; cin >> c;
	} while (c <= 0);
	arr = new int*[r];
	for (int i = 0; i < r; i++)
		arr[i] = new int[c];
}

void inputRandArr(int**& arr, int r, int c)
{
	srand(time(NULL));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] = rand() % MAXVALUE + 1;
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

void printArr(int** arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
				cout << *(*(arr + i) + j) << "  ";
		cout << endl;
	}
}

int* getLastMin_Row(int** arr, int r_input, int c)
{
	//Tim min
	int min = arr[r_input][0];
	for (int j = 1; j < c; j++)
		min = min < arr[r_input][j] ? min : arr[r_input][j];
	//Lay min cuoi cung
	for (int j = c - 1; j >= 0; j--)
		if (arr[r_input][j] == min)
			return &arr[r_input][j];
}

int tongcot(int** a, int current_r, int s_col, int sum)
{
	if (current_r < 0)
		return sum;

	return tongcot(a, current_r - 1, s_col, sum + a[current_r][s_col]);
}

int* flatMap(int** arr, int r, int c_input)
{
	int* result = new int[r];
	for (int i = 0; i < r; i++)
		result[i] = arr[i][c_input];
	return result;
}

bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

void printPrime(int** arr, int r, int c)
{
	//int size = MAXVALUE + 1, countValue = 1, m = 0, n = 0;
	//int* containValue = new int[size] {0};
	//for (int i = 0; i < r; i++)
	//	for (int j = 0; j < c; j++)
	//		if(isPrime(arr[i][j]))
	//			containValue[arr[i][j]]++;
	//
	//bool isfinish = false, breakloop = false;
	//cout << "Cac so nguyen to trong mang (cach 1):\n";
	//_goback: //object de su dung lenh goto
	//for (int k = 0; k < size; k++)
	//{
	//	if (containValue[k] > 0)
	//	{
	//		cout << k << " ";
	//		if (isfinish)
	//		{
	//			breakloop = false;
	//			for (int i = m; i < r; i++)
	//			{
	//				for (int j = n; j < c; j++)
	//				{
	//					if (arr[i][j] == k && ((i == 0 && j == 0) || (i != m || j != n)))
	//					{
	//						cout << "- hang " << i << ", cot " << j << endl;
	//						m = i;
	//						n = j;
	//						k--;
	//						breakloop = true;
	//						if (i == r - 1 && j == c - 1)
	//						{
	//							m = 0;
	//							n = 0;
	//						}
	//						break;
	//					}
	//				}
	//				if (breakloop)
	//					break;
	//			}
	//		}
	//	}
	//}

	bool isfinish = false;

	cout << "\nCac so nguyen to trong mang (cach 1):\n";
	_goback:
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (isPrime(arr[i][j]))
			{
				cout << arr[i][j] << " ";
				if (isfinish)
				{
					cout << "- hang " << i << ", cot " << j << endl;
				}
			}
		}
	}

	if (!isfinish)
	{
		cout << "\nCac so nguyen to trong mang (cach 2):\n";
		isfinish = true;
		goto _goback;
	}
}




