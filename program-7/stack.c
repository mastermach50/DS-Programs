#include<stdio.h>
#define max 5
int stack[max], top = -1;
void push() {
    if (top == max - 1) {
        printf("Stack Overflow\n");
    } else {
		printf("Enter element to push: ");
		scanf("%d", &stack[++top]);
    }
}
void pop() {
    if (top == - 1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d was popped\n", stack[--top + 1]);
    }
}
void peek() {
    if (top == - 1) {
        printf("Stack is empty\n");
    } else {
		printf("%d is at top\n", stack[top]);
    }
}
void display() {
    if (top == - 1) {
        printf("Stack is empty\n");
    } else {
        for (int i=0; i<top+1;i++){
            printf("%d ", stack[i]);    
        }
        printf("\n");
    }
}
int main() {
    while (1) {
       	int ch;
        printf("What would you like to do?\n"
        "\t[0] Display the stack\n"
        "\t[1] Push to stack\n"
        "\t[2] Pop from stack\n"
        "\t[3] Peek the stack\n"
        "\t[4] Exit\n"
        "Enter your choice: "
        );
       	scanf("%d", &ch);
       	switch (ch) {
       	case 0:
       		display();
       		break;
       	case 1:
       		push();
       		break;
       	case 2:
			pop();
       		break;
       	case 3:
       		peek();
       		break;
       	case 4:
       		return 0;
       	default:
       		printf("[ Enter a valid choice ]\n");
       	}
       	printf("\n");
    }
}
