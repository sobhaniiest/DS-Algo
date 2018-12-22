//Sobhan Mondal

#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
	int data;
	struct linked_list *node;
}LL;

void Create(LL **H)
{
	int val;
	printf("Enter the value : ");
	scanf("%d",&val);
	LL *current;
	if(*H == NULL)
	{
		(*H) = (LL *)malloc(sizeof(LL));
		(*H)->data = val;
		(*H)->node = NULL;
	}
	else
	{
		current = *H;
		while(current->node)
			current = current->node;
		current->node = (LL *)malloc(sizeof(LL));
		current->node->data = val;
		current->node->node = NULL;
	}
}

void Display(LL **H)
{
	LL *current = *H;
	while(current)
	{
		printf("%d -> ",current->data);
		current = current->node;
	}
	printf("NULL\n");
}

void Delete(LL **H)
{
	int val;
	printf("Entre the value : ");
	scanf("%d",&val);
	LL *current = *H;
	LL *prev = *H;
	if((*H) == NULL)
		printf("Error!!!\n");
	else
	{
		if((*H)->data == val)
			(*H) = (*H)->node;
		else
		{
			while(current->data != val)
			{
				prev = current;
				current = current->node;
				if(!current)
					break;
			}
			if(current)
				prev->node = current->node;
			else
				printf("Error!!!\n");
		}
	}
}

void Insert_before(LL **H)
{
	int val,n;
	printf("Enter the search value : ");
	scanf("%d",&val);
	printf("Enter the insert value : ");
	scanf("%d",&n);

	if((*H) == NULL)
		printf("Error!!!\n");
	else
	{
		LL *current = *H,*prev,*temp = *H;
		if((*H)->data == val)
		{
			current = (LL *)malloc(sizeof(LL));
			current->data = n;
			current->node = temp;
			(*H) = current;
		}
		else
		{
			while(current->data != val)
			{
				prev = current;
				current = current->node;
				if(!current)
					break;
			}
			if(current)
			{
				prev->node = (LL *)malloc(sizeof(LL));
				prev->node->data = n;
				prev->node->node = current;
			}
			else
				printf("Error!!!\n");

		}
	}
}

void Insert_after(LL **H)
{
	int val,n;
	printf("Enter the search value : ");
	scanf("%d",&val);
	printf("Enter the insert value : ");
	scanf("%d",&n);

	if((*H) == NULL)
		printf("Error!!!\n");
	else
	{
		LL *current = *H,*post,*temp = *H;
		post = current->node;
		while(current->data != val)
		{
			current = current->node;
			if(!current)
				break;
			post = current->node;
		}
		if(current)
		{
			current->node = (LL *)malloc(sizeof(LL));
			current->node->data = n;
			current->node->node = post;
		}
		else
			printf("Error!!!\n");
	}
}

int main()
{
	LL *Head;
	Head = NULL;
	int c;
	while(1)
	{
		printf("Your Choice : ");
		scanf("%d",&c);
		if(c == 1)
			Create(&Head);
		if(c == 2)
			Display(&Head);
		if(c == 3)
			Delete(&Head);
		if(c == 4)
			Insert_before(&Head);
		if(c == 5)
			Insert_after(&Head);
		if(c == 0)
			exit(0);
	}
}