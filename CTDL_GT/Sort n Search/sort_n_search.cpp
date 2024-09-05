#include <iostream>
#include <ctime>
#define MAX 500
using namespace std;

//Input arr
void input(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
//Create random int arr
void inputRand(int* arr, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 1000 + 1;
}
void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
//if a is greater than b
bool isGreater(int a, int b)
{
	return a > b;
}
//swap between values
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
/*           SORT METHODS           */
//Insertion
void insertionSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int x = a[i], pos = i - 1;
		while (pos >=0 && isGreater(a[pos], x))
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
//Selection
void selectionSort(int* a, int n)
{
	for (int k = 0; k  < n; k ++)
	{
		int min_index = k;
		for (int i = k + 1; i < n; i++)
			if (isGreater(a[min_index], a[i]))
				min_index = i;
		swap(a[k], a[min_index]);
	}
}
//Bubble
void bubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (isGreater(a[j - 1], a[j]))
				swap(a[j - 1], a[j]);
}
//Interchange
void interchangeSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (isGreater(a[i], a[j]))
				swap(a[i], a[j]);
}
//Quick
void quickSort(int *a, int left, int right) {
	int l = left, r = right;
	int center = a[(left + right) / 2];
	while (l < r) {
		while (isGreater(center, a[l]))
			l++;
		while (isGreater(a[r], center))
			r--;
		if (l <= r) {
			swap(a[l], a[r]);
			l++; r--;
		}
	}
	if (left < r)
		quickSort(a, left, r);
	if (l < right)
		quickSort(a, l, right);
}
//Heap
void heap(int *a, int n, int i) {
	int l = 2 * i + 1, r = 2 * i + 2;
	int maxPos = i;

	if (l<n && a[l]>a[maxPos])
		maxPos = l;
	if (r<n && a[r]>a[maxPos])
		maxPos = r;

	if (maxPos == i)
		return;

	swap(a[i], a[maxPos]);
	heap(a, n, maxPos);
}
void heapSort(int *a, int n) {
	int i = n / 2 - 1;
	while (i >= 0) {
		heap(a, n, i);
		i--;
	}
	for (int right = n - 1; right > 0; right--) {
		swap(a[0], a[right]);
		heap(a, right, 0);
	}
}
//Merge
void merge(int *a, int low, int high, int mid)
{
	int i, j, k, c[MAX / 2];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k++] = a[i];
			i++;
		}
		else
		{
			c[k++] = a[j];
			j++;
		}
	}
	while (i <= mid)
	{
		c[k++] = a[i];
		i++;
	}
	while (j <= high)
	{
		c[k++] = a[j];
		j++;
	}
	for (i = low; i < k; i++)
		a[i] = c[i];
}
void mergeSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, right, mid);
}
/*                                  */
/*              Search              */
//Search
int search(int* a, int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}
//Binary Search
int binarySearch(int* a, int n, int x)
{
	int l = 0, r = n - 1, mid;//l: left, r: right
	while (l<=r)
	{
		mid = (l + r) / 2;
		if (a[mid] == x)
			return mid;
		else if (isGreater(a[mid], x))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
//menu
int menu()
{
	system("cls");
	cout << "---------- CHUONG 3: SAP XEP THU TU & TIM KIEM ----------\n";
	cout << "0.  Khoi tao danh sach ngau nhien                        \n";
	cout << "1.  Nhap danh sach                                       \n";
	cout << "2.  Xuat danh sach                                       \n";
	cout << "3.  Sap xep SELECTION SORT                               \n";
	cout << "4.  Sap xep INSERTION SORT                               \n";
	cout << "5.  Sap xep BUBBLE SORT                                  \n";
	cout << "6.  Sap xep INTERCHANGE SORT                             \n";
	cout << "7.  Sap xep QUICK SORT                                   \n";
	cout << "8.  Sap xep HEAPS SORT                                   \n";
	cout << "9.  Sap xep MERGE SORT                                   \n";
	cout << "10. Tim kiem phan tu bang TIM KIEM TUAN TU               \n";
	cout << "11. Tim kiem phan tu bang TIM KIEM NHI PHAN              \n";
	cout << "12. Thoat chuong trinh                                   \n";
	int select;
	cout << "Lua chon cua ban: "; cin >> select;
	return select;
}

//Main
int main()
{
	int arr[MAX], n, x, index;
	while (true)
	{
		int select = menu();
		switch (select)
		{
		case 0:
			do
			{
				cout << "Nhap so phan tu cua danh sach: ";
				cin >> n;
			} while (n <= 0);
			inputRand(arr, n);
			cout << "\nDanh sach ngau nhien co n phan tu: "; print(arr, n);
			break;
		case 1:
			do
			{
				cout << "Nhap so phan tu cua danh sach: ";
				cin >> n;
			} while (n <= 0);
			cout << "Nhap gia tri cho danh sach: ";
			input(arr, n);
			break;
		case 2:
			cout << "\nDanh sach: "; print(arr, n);
			break;
		case 3:
			//Selection
			selectionSort(arr, n);
			cout << "\nSelection sort: "; print(arr, n);
			break;
		case 4:
			//Insertion
			insertionSort(arr, n);
			cout << "\nInsertion sort: "; print(arr, n);
			break;
		case 5:
			//Bubble
			bubbleSort(arr, n);
			cout << "\nBubble sort: "; print(arr, n);
			break;
		case 6:
			//Interchange
			interchangeSort(arr, n);
			cout << "\nInterchange sort: "; print(arr, n);
			break;
		case 7:
			//Quick
			quickSort(arr, 0, n - 1);
			cout << "\nQuick sort: "; print(arr, n);
			break;
		case 8:
			//Heap
			heapSort(arr, n);
			cout << "\nHeap sort: "; print(arr, n);
			break;
		case 9:
			//Merge
			mergeSort(arr, 0, n-1);
			cout << "\nMerge sort: "; print(arr, n);
			break;
		case 10:
			//Search
			cout << "\nNhap gia tri can tim trong danh sach: "; cin >> x;
			index = search(arr, n, x);
			if (index != -1)
				cout << "Tim thay x tai vi tri a[" << index << "]";
			else
				cout << "Khong tim thay x trong danh sach!";
			break;
		case 11:
			//Binary Search
			selectionSort(arr, n);
			cout << "\nDanh sach co thu tu: "; print(arr, n);
			cout << "\nNhap gia tri can tim trong danh sach: "; cin >> x;
			index = binarySearch(arr, n, x);
			if (index != -1)
				cout << "Tim thay x tai vi tri a[" << index << "]";
			else
				cout << "Khong tim thay x trong danh sach!";
			break;
		case 12:
			cout << "Ban da thoat chuong trinh!\n";
			system("pause");
			return 0;
		default:
			cout << "Lua chon khong hop le!";
			system("pause");
			break;
		}
		int iscont;
		cout << "\n1.Tiep tuc | 0.Thoat: "; cin >> iscont;
		if (!iscont)
		{
			cout << "Ban da thoat chuong trinh!";
			break;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}