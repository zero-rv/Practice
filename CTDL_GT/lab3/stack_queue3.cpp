#include <iostream>
using namespace std;

//struct Node
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};
//struct Queue
struct Queue {
    Node* top;
    Node* rear;
    int size;
    const int MAX = 100;

    // Constructor
    Queue() : top(nullptr), rear(nullptr), size(0) {}
};
//check if Queque is empty 
bool isEmpty(Queue& q) {
    return q.top == nullptr;
}
//check if Queue is full
bool isFull(Queue& q) {
    return q.size >= q.MAX;
}
//add new Node to Queue
bool addQueue(Queue& q, int data) {
    if (isFull(q)) {
        cout << "Queue hien tai da day." << endl;
        return false;
    }
    Node* NewNode = new Node(data);
    if (isEmpty(q)) {
        q.top = q.rear = NewNode;
    }
    else {
        q.rear->next = NewNode;
        q.rear = NewNode;
    }
    ++q.size;
    return true;
}
//remove 1 Node from Queue
int removeQueue(Queue& q) {
    if (isEmpty(q)) {
        return -99999999; //Default Null Queue
    }

    Node* temp = q.top;
    int value = temp->data;

    q.top = q.top->next;
    if (q.top == nullptr) {
        q.rear = nullptr;
    }

    delete temp;
    --q.size;

    return value;
}
//print Queue func
void printQueue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue hien tai dang rong." << endl;
        return;
    }
    Node* current = q.top;
    cout << "Cac phan tu trong queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}
//Menu
int menu() {

    cout << "==========================================\n";
    cout << "1. Them phan tu vao queue                 \n";
    cout << "2. Xoa phan tu khoi queue                 \n";
    cout << "3. Hien thi tat ca cac phan tu trong queue\n";
    cout << "4. Thoat chuong trinh                     \n";
    cout << "==========================================\n";
    int select;
    cout << "Chon thao tac: "; cin >> select;
    return select;
}
//Main
int main() {
    Queue q;
    while (true)
    {
        system("cls");
        int x = menu();
        int data, removeValue;
        switch (x) {
        case 1:
            cout << "Nhap phan tu can them: ";
            cin >> data;
            if (addQueue(q, data)) {
                cout << "Phan tu " << data << " da duoc them vao queue.\n";
            }
            break;
        case 2:
            removeValue = removeQueue(q);
            if (removeValue == -99999999)
                cout << "Queue hien tai dang rong." << endl;
            else
                cout << "Phan tu " << removeValue << " da duoc xoa khoi queue.\n";
            break;
        case 3:
            printQueue(q);
            cout << endl;
            break;
        case 4:
            cout << "Ban da thoat chuong trinh.\n";
            system("pause");
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
            break;
        }
        system("pause");
    }
    return 0;
}