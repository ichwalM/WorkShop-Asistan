#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *head = NULL, *tail, *n, *x;


void createNewNode(int data){
	n = new Node;
	n->data = data;
	tail = n;
	head = n;
	tail->next = NULL;
}

void addBack(int data){
	n = new Node;
	n->data = data;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void addFront(int data){
	n = new Node;
	n->data = data;
	n->next = head;
	head = n;
}

void addMid(int j, int data){
	x = head;
	while(x->data != j || x->next->data == j) x = x->next;
	n = new Node;
	n->data = data;
	n->next = x->next;
	x->next = n;
}

void removeFront(){
	x = head;
	head = head->next;
	delete x;
	x = NULL;
}

void removeBack(){
	x = head;
	while(x->next != tail) x = x->next;
	tail = x;
	delete x->next;
	tail->next = NULL;
}

void removeMid(int i){
	Node *temp=NULL;
	x = head;
	while(x->data != i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	delete x;
	x = NULL;
}

bool dataExists(int data){
	x = head;
	while(x != NULL){
		if (data == x->data)
			return true;
		x = x->next;
	}
	return false;
}

void remove(int data){
	if(data == head->data)
		removeFront();
	else if(data == tail->data)
		removeBack();
	else{
		if(dataExists(data))
		removeMid(data);
	}
}

void tampil(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
}

void insert(int data) {
    if (head == NULL) {
        createNewNode(data);
    } else if (data < head->data) {
        addFront(data);
    } else if (data > tail->data) {
        addBack(data);
    } else {
        x = head;
        while (x->next->data < data) {
            x = x->next;
        }
        addMid(x->data, data);
    }
}

void tampilBack(){
	Node *y = tail;
	x = head;
	while(y->data != head->data){
		while(x->next != y){
		x = x->next;
		}
		y = x;
		cout << x->next->data << " ";
		if (x == head) cout << x->data << " ";
		x = head;
	}
}

void tampilDariBelakang(Node* current) {
    if (current == NULL) {
        return;
    }
    tampilDariBelakang(current->next);
    cout << current->data << " ";
}

int main(){
	createNewNode(4);
	addBack(2);
	addBack(6);
	addBack(3);
	addBack(4);
	addBack(3);
	addFront(0);
	addMid(2, 1);
	cout << "Tampil dari depan   : " << endl;
    tampil();
    cout << endl;
    cout << "Tampil dari belakang: " << endl;
	tampilBack();
	// tampilDariBelakang(head);
}
