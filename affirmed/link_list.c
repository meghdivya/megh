
#include<stdio.h>
#include<stdlib.h>

typedef struct link_list{
	int data;
	struct link_list* next;
}link_list_t;

void add_number_to_list(link_list_t** head,  int data)
{
	if(*head == NULL)
	{
		printf("List is empty, Creating the head\n");
		*head = malloc(sizeof(link_list_t));
		(*head)->data = data;
		(*head)->next = NULL;
		printf("Data %d added\n", data);
	}
	else
	{
		link_list_t* tmp = *head;
		while(tmp->next)
		{
			tmp = tmp->next;
			//(*head) = (*head)->next;
		}
		
		tmp->next = malloc(sizeof(link_list_t));
		tmp->next->data = data;
		tmp->next->next = NULL;
		printf("Data %d added\n", data);
	}
	return;
}

void print_link_list(link_list_t* head)
{
	printf("going to print list\n");
	link_list_t* tmp = head;
	if(tmp)
	{
		while(tmp)
		{
			printf("[Data =%d ] ->", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
		
	}
	else
	{
		printf("Empty List\n");
	}
	return;
}

//void interactive_fn()
//{
//	printf("Enter a number to be added\n");
//	scanf("%d",&num);
//	
//
//}

int main()
{
	link_list_t* headp = NULL;
	int data;
	int i;
	while(1)
	{
		printf("Enter 1 to add, 2 to display, 3 to Exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				printf("Enter a number\n");
				scanf("%d", &data);
				add_number_to_list(&headp, data);
			}break;
			case 2:
			{
				print_link_list(headp);
			}break;
			case 3:
			{
				printf("Exiting\n");
				return 0;
			}break;
		}
		i = 0;
	}
	return 0;
}
