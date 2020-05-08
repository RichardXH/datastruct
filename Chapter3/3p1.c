#include <stdio.h>
#include <stdlib.h>

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
PtrToNode create_list_h(void)
{
	PtrToNode head;
	head = init_list();
	
	ElemType data;
	while(scanf("%d", &data) != EOF){	//EOF -- Ctrl-D in linux
		PtrToNode curr;
		curr = init_node(curr, data);
		curr->next = head->next;
		head->next = curr;
	}

	return head;
}

// tail create linked list
PtrToNode create_list_t(void)
{
	PtrToNode head;
	head = init_list();

	PtrToNode end;	// end pointer
	end = head;		// point to head first

	ElemType data;
	while(scanf("%d", &data) != EOF){
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

int main(void)
{
	PtrToNode head;
	
	printf("Please input the data to create a linked list\n");
	head = create_list_h();
	
	printf("The linked list is: ");
	print_list(head);
	
	return 0;
}
