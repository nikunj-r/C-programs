typedef struct node
{
    void *dataptr;
    struct node *link;              
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

     stack = (STACK *)malloc(sizeof(STACK));         
     if(stack)
     {
         stack->count = 0;    
         stack->top = NULL;          
     }
     return stack;
}

//Push stack
bool pushStack(STACK *stack,void *dataInptr)
{
     STACK_NODE 

     newptr = (STACK_NODE *)malloc(sizeof(STACK_NODE));
     if(!newptr)
     return false;

     newptr->dataptr = dataInptr;

     newptr->link = stack->top;     
     stack->top = newptr;

     (stack->count)++;
     return true;
}

//ADT Pop stack
void *popStack(STACK *stack)
{
    void *dataOutptr;
    STACK_NODE *temp;         

    if(stack->count == 0)
    dataOutptr = NULL;
    else
    {
        temp = stack->top;
        dataOutptr = stack->top->dataptr;
        stack->top = stack->top->link;
        free(temp);
        (stack->count)--;   
    }

    return dataOutptr;   
}

//Peep stack
void *stacktop(STACK *stack)
{
      if(stack->count == 0)
      return NULL;
      else
      return stack->top->dataptr;     
}

//Stack underflow or empty
bool emptyStack(STACK *stack)
{
      return(stack->count == 0);
}

//Stack overflow or full
bool fullstack(STACK *stack)
{
      STACK_NODE *temp;  

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
