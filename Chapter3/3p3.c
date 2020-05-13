#include <stdio.h>
#include <stdlib.h>

//------------------------------------------
// Only implement single linked list
//------------------------------------------

typedef struct node Node;
typedef struct node* PtrToNode;
typedef int ElemType;

struct node{
	ElemType data;
	PtrToNode next;
};

//init node
PtrToNode init_node(PtrToNode node, ElemType data)
{
	node = (PtrToNode)malloc(sizeof(Node));
	if(node == NULL){
		printf("Malloc Failed!\n");
		return NULL;
	}
	node->data = data;
	node->next = NULL;

	return node;
}

// init list
PtrToNode init_list(void)
{
	PtrToNode node;
	node = (PtrToNode)malloc(sizeof(Node));
	if(node == NULL){
		printf("Malloc Failed!\n");
		return NULL;
	}
	node->next = NULL;

	return node;
}

// head create linked list
PtrToNode create_list_h(int number)
{
	PtrToNode head;
	head = init_list();
	
	ElemType data;
	while(number--){	// input non-decimal will reuten non-zero
		scanf("%d", &data);
		PtrToNode curr;
		curr = init_node(curr, data);
		curr->next = head->next;
		head->next = curr;
	}

	return head;
}

// tail create linked list
PtrToNode create_list_t(int number)
{
	PtrToNode head;
	head = init_list();

	PtrToNode end;	// end pointer
	end = head;		// point to head first

	ElemType data;
	while(number--){
		scanf("%d", &data);
		PtrToNode curr;
		curr = init_node(curr, data);
		end->next = curr;
		end = curr;
	}
	
	return head;
}

// print linked list
int print_list(PtrToNode list)
{
	PtrToNode currNode;
	currNode = list->next;

	while(currNode){
		printf("%d -> ", currNode -> data);	
		currNode = currNode -> next;
	}
	printf("NULL\n");
	
	return 0;
}


// insert element to list
PtrToNode insert_list(PtrToNode list, ElemType data, PtrToNode pnode)
{
	PtrToNode currNode;
	currNode = list->next;

	while(currNode && (currNode->data != pnode->data)){
		currNode = currNode->next;
	}
	
	PtrToNode tmpCell;
	tmpCell = init_node(tmpCell, data);
	tmpCell->next = currNode->next;
	currNode->next = tmpCell;

	return list;
}

// delete element from list
PtrToNode delete_list(PtrToNode list, ElemType data)
{
	PtrToNode preNode, currNode;
	preNode = list;
	currNode = list->next;

	while(currNode){
		if(currNode->data == data){
			preNode->next = currNode->next;
		}
		preNode = currNode;
		currNode = currNode->next;
	}

	return list;
}

// print the specific position element of l given by p
int printLots(PtrToNode L, PtrToNode P)
{
	PtrToNode llocal, plocal;
	llocal = L->next;
	plocal = P->next;
	ElemType pos;

	while(plocal){
		int count = 1;
		llocal = L->next;

		pos = plocal->data;
		while(count != pos){
			count++;
			llocal = llocal->next;
		}
		printf("%d ", llocal->data);

		plocal = plocal->next;
	}
	printf("\n");

	return 0;
}

PtrToNode swap_list(PtrToNode list, ElemType data)
{
	PtrToNode curr, pre;
	pre = curr = list->next;

	while(curr->data != data){
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
	curr->next = curr->next->next;
	pre->next->next = curr;
	
	return list;
}

int main(void)
{
	PtrToNode List;
	int size, data;

	printf("Please input size of List: ");
	scanf("%d", &size);
	printf("Please input the data to create List\n");
	List = create_list_t(size);
	print_list(List);

	printf("Please input the data you want to swap: ");
	scanf("%d", &data);
	List = swap_list(List, data);
	print_list(List);
	
	return 0;
}
