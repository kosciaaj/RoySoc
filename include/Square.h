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
		Node *ori;
		int num;
	public:
		Square() : ori() {}
		~Square();
		void addNode(int info);
		Node* at(int index);
		void incr();
		void reverse(Square sent);
		void setLength(int length);
		int length();
};

#endif


