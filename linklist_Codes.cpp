#include<stdio.h>
#include<stdlib.h>
struct linklist
{
	struct linklist *p;
	int data;
};
struct linklist *header;
void create(int);
void show();
void insert_sort(int);
void reverse();
int count()
{
	struct linklist *run=header;
	int len=0;
	while(run!=NULL)
	{
		len++;
		run=run->p;
	}
	return(len);
}
void del_last()
{
	struct linklist *prev,*curr=header;
	while(curr->p!=NULL)
	{
		prev=curr;
		curr=curr->p;
	}
	prev->p=NULL;
	show();
}
void sort()
{
	struct linklist *next,*curr=header;
	int temp;
	while(curr!=NULL)
	{
		next=curr->p;
		while(next!=NULL)
		{  
		   if(curr->data > next->data)
		   {
		   
			temp=curr->data;
			curr->data=next->data;
			next->data=temp;
		}   
		next=next->p;
		}
		curr=curr->p;
	}
	show();
}
main()

{
	create(12);
	create(3);
	create(11);
	create(9);
	create(87);
	create(23);
	create(8);
	create(32);
	create(76);
	create(73);
	printf("here is your linklist\n");
	show();
	printf("\nafter reverse linklist \n");
	reverse();
	printf("\nafter deletion linklist \n");
	del_last();
	printf("\nthe sorted list\n");
	sort();
	insert_sort(55);
	printf("\n");
    show();
	int t=count();
	printf("\ntotal node =%d",t);

     	
}
void create(int t)
{
	struct linklist *temp,*traverse;
	temp=(struct linklist*)malloc(sizeof(struct linklist));
	temp->data=t;
	temp->p=NULL;
	if(header==NULL)
	{
		header=temp;
	}
	else
	{
		traverse=header;
		while(traverse->p!=NULL)
		
		{
			traverse=traverse->p;
		}
		traverse->p=temp;
		traverse=temp;
	}
	
}
void show()
{
	struct linklist *print=header;
	while(print!=NULL)
	{
		printf("[%d]  ",print->data);
		print=print->p;
	}
} 

void reverse()

{
	struct linklist *curr=header,*prev=NULL,*next;
	if(curr->p==NULL)
	{
		printf("NO reverse implented\n");
	}
	else
	{
	
	while(curr!=NULL)
	{
	  next=curr->p;
	  curr->p=prev;
	  prev=curr;
	  curr=next;
	}
	header=prev;
   show();
    }

}
void insert_sort(int t)
{
	struct linklist *curr=header,*temp,*prev,*next;
	temp=(struct linklist*)malloc(sizeof(struct linklist));
	temp->data=t;
	temp->p=NULL;
	while(curr->data < temp->data )
	{   next=curr;
		curr=curr->p;
	}
	prev=next->p;
	next->p=temp;
	temp->p=prev;
	
}
