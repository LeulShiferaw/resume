struct stack{
	unsigned int count;
	int array[32];
};

typedef struct stack Stack;

void init(Stack*);
void push(Stack*, int);
void pop(Stack*);
void empty(Stack*);
int isEmpty(Stack*);
void print(Stack*);
void binary(Stack*,int);
