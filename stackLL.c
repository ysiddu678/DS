#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack *next;
	
};
struct stack *top=NULL;
struct stack* push(struct stack *top, int val)
{
	struct stack *ptr = malloc(sizeof(struct stack));
	ptr->data = val;
	ptr->next = top;
	top = ptr;
	return top;
}

struct stack* pop(struct stack *top)
{
	struct stack *ptr = top;
	if (top == NULL)
	{
		printf("\nSTACK UNDERFLOW");
	}

else
{
	top=top->next;
	printf("\nthe value being deleted is: %d",ptr->data);
	free(ptr);
}
return top;

}
int peek(struct stack *top)
{
	return (top==NULL) ? -1 : top->data;
}
struct stack* display(struct stack *top)
{
	struct stack  *ptr=top;
	if(top==NULL)
	{
		printf("\nSTACK IS EMPTY");
		
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
			
		}
	}
	return top;
	
}
int main()
{
	int val,option;
	do
	{
		printf("\n*****MAIN MENU*****");
		printf("\n1. PUSH");
		printf("\n2. POP");
		printf("\n3. PEEK");
		printf("\n4. DISPLAY");
		printf("\n5. EXIT");
		printf("\nEnter your option: ");
		scanf("%d",&option);
		
		switch (option)
		{
			case 1:
				printf("\nEnter the number to be pushed on stack: ");
				scanf("%d",&val);
				top=push(top,val);
				break;
				case 2:
					top=pop(top);
					break;
					case 3:
						val=peek(top);
						if(val != -1)
						printf("\nThe value at the top of stack is: %d",val);
						else
						printf("\nSTACK IS EMPTY");
						break;
						case 4:
							top=display(top);
							break;
							
		}
		
	} while (option != 5);
	return 0;
	
}

