#include <stdio.h>
#include <malloc.h>

/* Node Structure*/
struct node {
	int i;
	struct node *next;
};

/*Printing the given link list*/
void p_list(struct node *temp)
{
	int j = 0;
	while(temp) {
		printf("%d) data :-\t %d\n", j, temp->i);
		temp = temp->next;
		j++;
	}
}

/*To reverse the link list*/
struct node *reverse_list(struct node *temp)
{
	struct node *current, *previous = NULL;

	current = temp->next;

	while(current) {
		temp->next = previous;
		previous = temp;
		temp = current;
		current = current->next;
	}
	temp->next = previous; 	// Challenge 2
	return temp;
}

/* Main function */
int main()
{
	int x,y;
	struct node *dptr, *temp;
	printf("Enter the length of link list\n");
	scanf("%d",&x);

	if(x <= 0)
		return -1;

	dptr = malloc(sizeof(struct node));
	temp = dptr;
	for (y=0; y<(x-1); y++) {
		dptr->next = malloc(sizeof(struct node)); //Challenge 1
		dptr = dptr->next;
		
	}
	dptr = temp;
	for (y=0; y<x; y++) {
		printf("Enter the data for each node\n");
		scanf("%d",&dptr->i);
		dptr = dptr->next;
	}
	printf("---------------Link List Created--------------\n");
	p_list(temp);
	printf("---------------Reversing the Link List --------\n");
	temp = reverse_list(temp);
	p_list(temp);	
	free(temp);
	return 0;
}
