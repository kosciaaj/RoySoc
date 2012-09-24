#ifndef SQAURE_H

#define SQUARE_H

struct Node{
	int data;
	Node* next;
	Node(int x, Node* y) : data(x), next(y){}
};

class RoySocApp;

class Square {
	private:
		Node *root_;
		int num_items_;
	public:
		Square() : root_() {}
		~Square();
		void addNode(int info);
		Node* at(int index);
		void bump();
		void reverse();
		void setLength(int length);
		int length();
};

#endif


