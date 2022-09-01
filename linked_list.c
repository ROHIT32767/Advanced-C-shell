#include "headers.h"

int IsEmpty(List *L)
{
	return (L->root == NULL && L->tail == NULL);
}
int get_size(List *L)
{

	NodePtr P = L->root;
	int ans = 1;
	int x = IsEmpty(L);
	if (x == 1)
	{
		return 0;
	}
	while (P->Next != NULL)
	{
		ans++;
		P = P->Next;
	}
	return ans;
}
void print_reverse(List *L)
{
	NodePtr P;
	P = L->tail;
	while (P != NULL)
	{
		printf("%d ", P->Element);
		P = P->Prev;
	}
}

void prune(List *L)
{
	if (L->root == NULL)
	{
		return;
	}
	else
	{
		NodePtr Ptr2 = L->root->Next;
		NodePtr tempPtr;
		NodePtr Ptr1 = L->root;

		while (Ptr1 != NULL && Ptr2 != NULL)
		{

			if (Ptr2->Next == NULL)
			{
				L->tail = Ptr2->Prev;
				Ptr1->Next = NULL;
				free(Ptr2);
				return;
			}

			else
			{
				Ptr1->Next = Ptr2->Next;
				tempPtr = Ptr1;
				Ptr1 = Ptr1->Next;
				free(Ptr2);
				if (Ptr1 != NULL)
				{
					Ptr1->Prev = tempPtr;
					Ptr2 = Ptr1->Next;
				}
			}
		}
	}
}

void insert_at(List *list, int x, int index, char *string)
{
	NodePtr newnode = MakeNode(x, string);
	if (index == get_size(list))
	{
		insert(list, x, string);
	}
	else
	{

		if (index == 0)
		{
			newnode->Next = list->root;
			list->root = newnode;
			newnode->Next->Prev = newnode;
		}
		else
		{
			int i = 0;
			NodePtr p = list->root;
			while (i < (index))
			{
				p = p->Next;
				i++;
			}
			newnode->Next = p;
			newnode->Prev = p->Prev;
			p->Prev->Next = newnode;
			p->Prev = newnode;
		}
	}
}

NodePtr MakeNode(int X, char *string)
{
	NodePtr P = (NodePtr)malloc(sizeof(struct node));
	assert(P != NULL);
	P->Element = X;
	P->process_name = (char *)malloc(600 * sizeof(char));
	strcpy(P->process_name, string);
	// printf("process_name is %s and string is %s\n",P->process_name,string);
	P->Next = NULL;
	P->Prev = NULL;
	return P;
}

INT Delete(List *L, int index)
{
	NodePtr P = L->root;
	int i = 0;

	if (get_size(L) == 1)
	{
		if (index == 0)
		{
			free(P);
			L->root = NULL;
			L->tail = NULL;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		if ((index >= get_size((L)) && (index < 0)))
		{
			return -1;
		}
		else
		{
			while (P != NULL)
			{
				if (i == index)
				{
					if (index == get_size(L) - 1)
					{
						L->tail->Next = NULL;
						L->tail = P->Prev;
						P->Prev->Next = NULL;
						free(P);
						return 1;
					}
					else
					{
						if (index == 0)
						{
							NodePtr X = L->root;
							L->root = L->root->Next;
							L->root->Prev = NULL;
							free(X);
							return 1;
						}
						else
						{
							P->Next->Prev = P->Prev;
							P->Prev->Next = P->Next;
							free(P);
							return 1;
						}
					}

					break;
				}
				P = P->Next;
				i++;
			}
		}
	}
}

void insert(List *L, int x, char *string)
{
	if (IsEmpty(L))
	{
		L->root = MakeNode(x, string);
		L->tail = L->root;
	}
	else
	{
		NodePtr P = L->tail;
		P->Next = MakeNode(x, string);
		P->Next->Prev = P;
		L->tail = P->Next;
	}
}
void print(List *L)
{
	NodePtr P;
	P = L->root;
	while (P != NULL)
	{
		printf("%d %s ", P->Element, P->process_name);
		P = P->Next;
	}

	printf("\n");
}

int find(List *L, int X, char *string)
{
	NodePtr P = L->root;
	int index = 0;
	int ans = -1;
	while (P != NULL)
	{
		if ((P->Element) == X)
		{
			ans = index;
			return ans;
		}
		index++;
		P = P->Next;
	}
	return -1;
}
char *find_string(List *L, int X)
{
	NodePtr P = L->root;
	int index = 0;
	int ans = -1;
	while (P != NULL)
	{
		if ((P->Element) == X)
		{
			char *X = P->process_name;
			return X;
		}
		index++;
		P = P->Next;
	}
	return NULL;
}