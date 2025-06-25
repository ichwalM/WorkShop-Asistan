#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head=NULL, *n=NULL, *tail=NULL, *x=NULL;

void createNewNode(int data){
    n = new Node;
    n->data = data;
    tail=n;
    head=n;
    tail->next=NULL;
}
void addBack(int data){
	n = new Node;
	n->data = data;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}
void addFronNode(int data){
    n = new Node;
    n->data = data;
    n->next = head;
	head = n;
}
void removeFront(){
	x =head;
	head = head;
	head=head->next;
	delete(x);
}
void removeTail(){
	x =head;
	while(x->next != tail) x=x->next;
	tail = x;
	delete(x->next);
	tail->next = NULL;
}

void tampil(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
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
void addMid(int j, int data){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = data;
	n->next = x->next;
	x->next = n;
}

void insertion(int data){
	x=head;
	while(x->next != NULL && x->next->data < data){
		x=x->next;
	}addMid(x->data, data);
}

void push(int data){
	if(head==NULL){
		createNewNode(data);
	}else if(head->data >= data){
		addFronNode(data);
	}else if(tail->data <= data){
		addBack(data);
	}else{
		insertion(data);
	}
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
void pop(){
	removeFront();
}
int main(){
    push(6);
    push(4);
    push(10);
    push(7);
    push(8);
    push(5);
	remove(10);
    cout<<"Setelah di add:\n";
    tampil();
}
