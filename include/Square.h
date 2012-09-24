class Square{
public:
	Square (int depth, int position, int offset, int width);
	//Next and previous pointers
	Square* next;
	Square* prev;
	// Pointer to the sentinal
	Square* sent;

	int depth;
	int position;
	int offset;
	int width;

	void draw();
	void update();
	void addSquare();
};
void insertAfter();

