#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data) {
	if (rear >= SIZE) {
		printf("Queue overflow.\n");
		return;
	}
	queue[rear++] = data;
}

int pop() {
	if (front == rear) {
		printf("Queue underflow.\n");
		return -INF;
	}
	return queue[front++];
}

void show() {
	printf("Front of queue\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("Rear of queue\n");
}

int main(void) {
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();
	return 0;
}