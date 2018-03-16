struct stack{
	unsigned int count;
	char array[100][30];
};

typedef struct stack Stack;

void init(Stack*);
void push(Stack*, char[]);
char* pop(Stack*);
void empty(Stack*);
int isEmpty(Stack*);
void print(Stack*);
void binary(Stack*,int);
