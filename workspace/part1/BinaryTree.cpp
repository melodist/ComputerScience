#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

typedef struct Node{
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return node;
}

// preorder traverse - root is front
void preorder(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void preorder_nonrecursive(Node* root) {
	Node* n;
	stack<Node*> stack;

	stack.push(root);

	while (!stack.empty()) {
		n = stack.top();
		stack.pop();
		printf("%d ", n->data);

		if (n->rightChild != NULL) stack.push(n->rightChild);
		if (n->leftChild != NULL) stack.push(n->leftChild);
	}
}

// inorder traverse - root is middle
void inorder(Node* root) {
	if (root) {
		inorder(root->leftChild);
		printf("%d ", root->data);
		inorder(root->rightChild);
	}
}

void inorder_nonrecursive(Node* root) {
	stack<Node*> stack;

	while (true) {
		while (root != NULL) {
			stack.push(root);
			root = root->leftChild;
		}

		if (!stack.empty()) {
			root = stack.top();
			stack.pop();
			printf("%d ", root->data);

			root = root->rightChild;
		}
		else break;
	}
}

// postorder traverse - root is rear
void postorder(Node* root) {
	if (root) {
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d ", root->data);
	}
}

void postorder_nonrecursive(Node* root) {
	stack<Node*> s1;
	stack<Node*> s2;
	Node* n;

	s1.push(root);

	while (!s1.empty()) {
		n = s1.top();
		s1.pop();

		s2.push(n);
		if (n->leftChild != NULL) s1.push(n->leftChild);
		if (n->rightChild != NULL) s1.push(n->rightChild);
	}

	while (!s2.empty()) {
		n = s2.top();
		s2.pop();
		printf("%d ", n->data);
	}

}

int main(void) {
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);
	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(50, n2, n3);
	preorder(n1); // 50 17 5 23 48 37 50
	printf("\n");
	preorder_nonrecursive(n1); // 50 17 5 23 48 37 50
	printf("\n");
	inorder(n1); // 5 17 23 50 37 23 50
	printf("\n");
	inorder_nonrecursive(n1); // 5 17 23 50 37 23 50
	printf("\n");
	postorder(n1); // 5 23 17 37 50 23 50
	printf("\n");
	postorder_nonrecursive(n1); // 5 23 17 37 50 23 50
	printf("\n");
	return 0;
}