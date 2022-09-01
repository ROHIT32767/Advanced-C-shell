#ifndef _MYDLL_H
#define _MYDLL_H

typedef struct node* NodePtr ;


typedef NodePtr Position ;

struct node{

	int Element ;
	Position Next;
    Position Prev;
};

typedef struct my_dll{
struct node* root;
struct node* tail; 
}List;



NodePtr MakeNode(int X); 
int get_size(List* L);
void print_reverse(List* L);
int find(List* L,int x);
void insert_at(List* L,int x,int index); 
void prune(List* L);
void print(List* L);
void insert(List* L,int x);
void Delete(List* L,int index);
int IsEmpty(List* L);

#endif







