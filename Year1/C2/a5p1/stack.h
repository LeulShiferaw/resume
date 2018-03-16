struct stack{
	unsigned int count;
	int array[12];
};

typedef struct stack Stack;

void init(Stack*);
void push(Stack*, int);
void pop(Stack*);
void empty(Stack*);
int isEmpty(Stack*);
void print(Stack*);
