typedef struct node
{
    void *dataptr;
    struct node *link;                //link is a pointer to a node like struct node
}STACK_NODE;

typedef struct
{
     int count;
     STACK_NODE *top;
}STACK;

//ADT Create stack
STACK *createstack(void)
{
     STACK *stack;

     stack = (STACK *)malloc(sizeof(STACK));               //Allocates memory
     if(stack)
     {
         stack->count = 0;           //stack points to STACK
         stack->top = NULL;          //top is a pointer so initialized to NULL
     }
     return stack;
}

//Push stack
bool pushStack(STACK *stack,void *dataInptr)
{
     STACK_NODE *newptr;            //newptr points to stack_node

     newptr = (STACK_NODE *)malloc(sizeof(STACK_NODE));
     if(!newptr)
     return false;

     newptr->dataptr = dataInptr;

     newptr->link = stack->top;     //newptr is a pointer to stack_node and stack is a pointer to STACK
     stack->top = newptr;

     (stack->count)++;
     return true;
}

//ADT Pop stack
void *popStack(STACK *stack)
{
    void *dataOutptr;
    STACK_NODE *temp;           //temp points to stack_node

    if(stack->count == 0)
    dataOutptr = NULL;
    else
    {
        temp = stack->top;
        dataOutptr = stack->top->dataptr;
        stack->top = stack->top->link;
        //free(temp);
        (stack->count)--;      //like top--
    }

    return dataOutptr;         //returns popvalue;
}

//Peep stack
void *stacktop(STACK *stack)
{
      if(stack->count == 0)
      return NULL;
      else
      return stack->top->dataptr;     //returns top value without deleting
}

//Stack underflow or empty
bool emptyStack(STACK *stack)
{
      return(stack->count == 0);
}

//Stack overflow or full
bool fullstack(STACK *stack)
{
      STACK_NODE *temp;       //temp points to stack_node

      if(temp = (STACK_NODE *)malloc(sizeof(*(stack->top))))
      {
          free(temp);
          return false;
      }
      return true;
}

//Stack count
int stackcount(STACK *stack)
{
      return stack->count;
}
