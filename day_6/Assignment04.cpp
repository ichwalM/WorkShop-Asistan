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
void addLastNode(int data){
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
void push(int data){
	if(head==NULL){
		createNewNode(data);
	}else{
		addFronNode(data);
	}
}
void pop(){
	removeFront();
}
int main(){
    push(1);
    push(5);
    push(4);
    cout<<"Setelah di add:\n";
    tampil();
    cout<<"\nSetelah di pop:\n";
    pop();
    tampil();
}
