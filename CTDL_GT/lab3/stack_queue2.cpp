#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 50

//Khai bao cau truc
struct Stack
{
	int a[MAX];
	int top;
};

//Khoi tao rong
void init(Stack& s) {
	s.top = -1;
}

//Cac thao tac
void push(Stack& s, const int x) {
	if (s.top < MAX) {
		s.a[++s.top] = x;
	}
}

bool isEmpty(Stack s) {
	return s.top == -1;
}

int pop(Stack& s) {
	if (!isEmpty(s)) {
		return s.a[s.top--];
	}
}

void printStack(Stack s) {
	for (int i = 0; i <= s.top; i++)
		cout << s.a[i] << " ";
	cout << endl;
}

//Ap dung
void convertDectoBin(int n) {
	Stack s;
	init(s);
	while (n != 0) {
		push(s, n % 2);
		n /= 2;
	}

	while (!isEmpty(s)) {
		cout << pop(s);
	}

	cout << endl;
}

void calExp(char str[]) {
	Stack s;
	init(s);

	char* p = strtok(str, " ");
	while (p != NULL) {
		if (isdigit(*p))
			push(s, atoi(p));
		else {
			int b = pop(s);
			int a = pop(s);
			switch (*p)
			{
			case '+':
				push(s, a + b); break;
			case '-':
				push(s, a - b); break;
			case '*':
				push(s, a * b); break;
			case '/':
				push(s, a / b); break;
			default:
				break;
			}
		}
		p = strtok(NULL, " ");
	}
	cout << pop(s) << endl;
}

int main() {
	//convertDectoBin(25);
	char str[] = "2 4 6 + * 5 / 1 -";
	calExp(str);
	system("pause");
	return 1;
}