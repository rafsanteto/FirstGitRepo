#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

struct node
	{
		int data;
		struct node *f;
		struct node *b;
	};
void add_front(struct node **front, struct node * new_node)
{
	new_node->f=*front;
	if(*front)
		(*front)->b=new_node;
	*front=new_node;
}








int traverse_list(struct node * start)
{
	struct node * ptr;
	ptr = start;

	printf("\n\nList :: ");
	if(ptr==NULL)
	{
		printf("List Empty");
	}
    cout<<"-------------------------------------------------"<<endl;
	printf("\nBACK\t\tINFO\t\tCURRENT\t\tLINK");
	 printf("\n%u\t\t%d\t\t%u\t\t%u",0,ptr->data,ptr,ptr->f);

	   ptr = ptr->f;



	while(ptr !=NULL)
	{
	   printf("\n%u\t\t%d\t\t%u\t\t%u",ptr->b,ptr->data,ptr,ptr->f);

	   ptr = ptr->f;
	}
	printf("\n");
//	  getch();
return 0;
}










int delete_pos(struct node **front , int pos)
{
	struct node *cur;

	if(pos==0 )
		{
			cur=*front;
			*front=(*front)->f;
			(*front)->f->b=NULL;
		}
	else
		{
			int i=0;
			cur=*front;
			while(i<pos && cur)
				{
					cur=cur->f;
					i++;
				}
			if(cur)
				{
					cur->b->f=cur->f;
				}

		}
	if(cur)
				{
					free(cur);
					return 1;
				}


	else
		return 0;
}
//int *a;
int delete_elm(struct node **front, int data)
{
	struct node *cur;
	cur=*front;
	while(cur && cur->data !=data)
		{
			cur=cur->f;
		}
	if(cur)
		{
			if(cur==*front)
				{
					*front=(*front)->f;
					(*front)->b=NULL;
				}
			else
				{
					cur->b->f=cur->f;
					//free(cur);
					return 1;
				}
		}
	else return 0;
}




void clean(struct node * front)
{
	struct node *cur=front;
	while(front)
		{
			cur=front;
			front=front->f;
			free(cur);
		}
}


int get_option()
{
	int option;
	do
		{
			cout<<"1: to insert at the beginning of the list\n";
			cout<<"2: to delete an element from the given position \n";
			cout<<"3: to delete an element from the given value \n";
			cout<<"4: display link list \n";
			cout<<"5: QUIT\n";
			cout<<"choose : ";
			cin>>option;
		}while(option<0 || option >6);
	return option;
}
int get_data()
{
	int data;
	//int c=c;

//	  a=(int *)malloc (30*sizeof(int));

	cout<<"enter the data \n";
	cin>>data;
	//linked[c]=data;
	//count++;
	return data;
}

/*int show(int n)
{
for(int i=0;i<n;i++)
	cout<<linked[i]<<"->";
return 0;
}
*/
void display_list(struct node *front)
{
	struct node * cur=front;
	cout<<"the list is : \n";
	if(!cur)
		{
			cout<<"empty ";
		}
	else
		{
			while (cur!=NULL)
				{
					cout<<cur->data;
					if(cur->f)
						cout<<" ->";
					cur=cur->f;
				}
			cout<<"\n \n";
		}
}
int main()
{
	struct node * front=0;
	struct node * new_node;
	int data,pos;
	int min, max,count=0;
	while (1)
		{
			switch(get_option())
				{
				case 1:

					data=get_data();
					//count++;
					new_node=(struct node * )malloc(sizeof (struct node));
					new_node->data=data;
					add_front(&front, new_node);
					//get_option();
					break;
				case 2:
					cout<<"	   enter the position \n";
					cin>>pos;
					if(delete_pos(&front,pos)==0)
						cout<<"there is no elemet at position "<<pos<<endl;
					break;
				case 3:
					data=get_data();
					if(delete_elm(&front, data)==0)
						{
							cout<<"there is no element which value is"<<data<<endl;
						}
					break;
				case 4:
					   traverse_list(front );
								display_list(front);
						break;
				case 5:
					clean(front);
					cout<<"~~~~~~~~HAVE A GREAT FUN WITH LINK LIST~~~~~~~~ \n";
                    cout<<"\nSUBMITTED TO :\n\t\t LITON JUDE ROZARIO \n";
                    cout<<"\nSUBMITTED BY :\n\t\tMD. RAFSAN JANI (414)\n\t\tMD. ASHRAFUL ISLAM(415)\n";

                    exit (0);
				}
			//display_list(front);
		}
	return 0;
}

