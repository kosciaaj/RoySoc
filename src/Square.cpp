#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "Square.h"
#include "cinder/Rand.h";

using namespace ci;
using namespace ci::app;
using namespace std;

Square::~Square(){
	if (ori){

		Node* temp = ori;
		while (temp->next!=ori){

			Node* t = temp;
			temp = temp->next;
			delete(t);
		}

		delete temp;
		ori = NULL;
	}
}
// Based on class lecture
void Square::addNode(int info){

	if (num < 0)
		num = 0;

	num++;
	Node* n = new Node(info, NULL);
	if (ori == NULL){

		n->next = n;
		ori = n;
		return;
	}

	Node* temp = ori;
	while(temp->next != ori){

		temp = temp->next;
	}

	temp->next = n;
	n->next = ori;
}