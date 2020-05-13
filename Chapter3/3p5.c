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
	currNode = list;

	while(currNode && (currNode != pnode)){
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

PtrToNode intersect_list(PtrToNode L1, PtrToNode L2)
{
	PtrToNode result, curr, curr_l1, curr_l2;
	curr_l1 = L1->next;
	curr_l2 = L2->next;

	result = init_list();
	curr = result;

	while(curr_l1 && curr_l2){
		if(curr_l1->data < curr_l2->data){
			curr_l1 = curr_l1->next;
		}
		else if(curr_l1->data > curr_l2->data){
			curr_l2 = curr_l2->next;
		}
		else{
			result = insert_list(result, curr_l1->data, curr);

			curr = curr->next;
			curr_l1 = curr_l1->next;
			curr_l2 = curr_l2->next;
		}
	}
	return result;
}

PtrToNode union_list(PtrToNode L1, PtrToNode L2)
{
	PtrToNode result, curr, curr_l1, curr_l2;
	curr_l1 = L1->next;
	curr_l2 = L2->next;

	ElemType insertData;

	result = init_list();
	curr = result;

	while(curr_l1 && curr_l2){
		if(curr_l1->data < curr_l2->data){
			insertData = curr_l1->data;
			curr_l1 = curr_l1->next;
		}
		else if(curr_l1->data > curr_l2->data){
			insertData = curr_l2->data;
			curr_l2 = curr_l2->next;
		}
		else{
			insertData = curr_l1->data;
			curr_l1 = curr_l1->next;
			curr_l2 = curr_l2->next;
		}
		result = insert_list(result, insertData, curr);
		curr = curr->next;
	}

	while(curr_l1){
		result = insert_list(result, curr_l1->data, curr);
		curr = curr->next;
		curr_l1 = curr_l1->next;
	}
	while(curr_l2){
		result = insert_list(result, curr_l2->data, curr);
		curr = curr->next;
		curr_l2 = curr_l2->next;
	}

	return result;
}

int main(void)
{
	PtrToNode L1, L2, L;
	int size, data;

	printf("Please input size of L1: ");
	scanf("%d", &size);
	printf("Please input the data to create L1\n");
	L1 = create_list_t(size);
	print_list(L1);

	printf("Please input size of L2: ");
	scanf("%d", &size);
	printf("Please input the data to create L2\n");
	L2 = create_list_t(size);
	print_list(L2);

	printf("\nL is: ");
	L = union_list(L1, L2);
	print_list(L);
	
	return 0;
}
