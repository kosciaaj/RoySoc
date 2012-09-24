#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "Square.h"
#include "cinder/Rand.h";

using namespace ci;
using namespace ci::app;
using namespace std;

Square::~Square(){
	if (root_){
		Node* tmp = root_;
		while (tmp->next!=root_){
			Node* t = tmp;
			tmp = tmp->next;
			delete(t);
		}
		delete tmp;
		root_ = NULL;
	}
}
void Square::addNode(int info){
	if (num_items_ < 0)
		num_items_ = 0;
	num_items_++;
	Node* t = new Node(info, NULL);
	if (root_ == NULL){
		t->next = t;
		root_ = t;
		return;
	}
	Node* tmp = root_;
	while(tmp->next != root_){
		tmp = tmp->next;
	}
	tmp->next = t;
	t->next = root_;
}