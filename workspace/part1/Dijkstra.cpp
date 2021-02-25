#include <iostream>
#define NODE_MAX 20001
#define EDGE_MAX 600001

using namespace std;

// 간선 구조체 정의
typedef struct Edge {
	int cost;
	int node;
} Edge;

void swap(Edge* a, Edge* b) {
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}

// 우선순위 큐 정의 및 삽입 함수 구현
typedef struct {
	Edge* heap[EDGE_MAX];
	int count;
} priorityQueue;

void push(priorityQueue* pq, Edge* edge) {
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	// 새 원소를 삽입한 이후에 상향식으로 힙을 구성
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

// 우선순위 큐 추출 함수 구현
Edge* pop(priorityQueue* pq) {
	if (pq->count <= 0) return NULL;
	Edge* res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	// 새 원소를 추출한 이후에 하향식으로 힙을 구성
	while (leftChild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost && rightChild < pq->count) target = rightChild;
		if (target == now) break; // 더 이상 내려가지 않아도 될 때 종료
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

// 간선 연결 리스트 구현
typedef struct Node {
	Edge* data;
	struct Node* next;
} Node;

int d[NODE_MAX];

void addNode(Node** target, int index, Edge* edge) {
	if (target[index] == NULL) {
		target[index] = new Node;
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else {
		Node* node = new Node;
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}


// Dijkstra Algorithm
int main(void) {
	int n, m, k;
	int ans[NODE_MAX];
	cin >> n >> m >> k;
	Node** adj = new Node * [n + 1];
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;
		ans[i] = INT_MAX;
	}
	priorityQueue* pq = new priorityQueue;
	pq->count = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge* edge = new Edge;
		edge->node = b;
		edge->cost = c;
		addNode(adj, a, edge);
	}

	ans[k] = 0;
	Edge* start = new Edge;
	start->cost = 0; start->node = k; push(pq, start);
	while (1) {
		Edge* now = pop(pq);
		if (now == NULL) break;
		int curNode = now->node;
		int curCost = now->cost;
		if (ans[curNode] < curCost) continue;
		Node* cur = adj[curNode];
		while (cur != NULL) {
			Edge* temp = cur->data;
			temp->cost += curCost;
			if (temp->cost < ans[temp->node]) { ans[temp->node] = temp->cost; push(pq, temp); }
			cur = cur->next;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == INT_MAX) cout << "INF" << endl;
		else cout << ans[i] << endl;
	}
	return 0;
}