#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertElement(Node** head, int value, int position) {
    Node* newNode = createNode(value);

    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri khong hop le.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// ham in ds
void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}

void insertHead(Node** head,int data){
	// tao node moi
	Node* newNode = createNode(data);
	newNode->next = *head;
	if(*head != NULL){
		(*head)->prev = newNode;
	}
	*head = newNode;
}

int main() {
    Node* head = NULL;
    int choice;
    int value, position;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Them vao dau\n");
        printf("2. Them phan tu tai vi tri bat ky\n");
        printf("3. In danh sach\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	printf("Moi nhap gia tri:");
				scanf("%d",&value);
                insertHead(&head,value);
                break;
          
            case 2: 
                printf("Nhap gia tri can them : ");
                scanf("%d", &value);
                printf("Nhap vi tri can chen:");
                scanf("%d", &position);
                insertElement(&head, value, position);
                break;
            
            case 3: 
                printf("Danh sach hien tai: ");
                printList(head);
                break;
            
            case 4: 
                printf("Ket thuc chuong trinh.\n");
                exit(0);
            
            default:
                printf("Lua chon khong hop le. Nhap lai.\n");
        }
    }

    return 0;
}

