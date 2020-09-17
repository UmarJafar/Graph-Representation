#include "stdafx.h"
#include "Graph.h"
#include <queue> 

Graph::Graph()
{
	V.reserve(10);
	V.reserve(10);
}

bool Graph::InsertVertex(string v){//insertion is fine
	for (int i = 0; i < V.size(); i++){
		if (V[i].name == v){
			return false;
		}
	}
	V.push_back(v);
	E.push_back(NULL);
	return true;
}

void Graph::PrintVertices(){
	cout << endl;
	for (int i = 0; i < V.size(); i++){
		cout << V[i].name << endl;
	}
}

bool Graph::InsertEdge(string v1, string v2){//need modification
	int a = VertexPtr(v1);
	int b = VertexPtr(v2);
	if (a == -1 || b == -1 || a == b) return false;
	Node* t1 = new Node(b);
	Node* t2 = new Node(a);
	// what about dublication
	if (E[a] == NULL){
		E[a] = t1;
	}
	else{
		t1->next = E[a];
		E[a] = t1;
	}
	
	if (E[b] == NULL){
		E[b] = t2;
	}
	else{
		t2->next = E[b];
		E[b] = t2;
	}

	return true;
}
bool Graph::DeleteNode(int a, int b){//private method
	Node *t = E[a];
	if (E[a] == NULL){
		return false;
	}
	if (t->data == b){
		E[a] = t->next;
		delete t;
		return true;
	}
	else{
		while (t->next != NULL){
			if (t->next->data == b){
				Node *t2 = t->next;
				t->next = t->next->next;
				delete t2;
				return true;
			}
			t = t->next;
		}
	}
	return false;
}
bool Graph::DeleteEdge(string v1, string v2){
	int a = VertexPtr(v1);
	int b = VertexPtr(v2);
	if (a == -1 || b == -1 || a == b) return false;
	return DeleteNode(a, b) && DeleteNode(b, a);

}

void Graph::PrintEdges(){
	cout << endl;
	for (int i = 0; i < E.size(); i++){
		Node *t = E[i];
		while (t != NULL){
			cout << V[i].name << "---" << V[t->data].name << endl;
			t = t->next;
		}
	}
}

void Graph::Print(){
	cout << endl;
	for (int i = 0; i < V.size(); i++){
		cout << V[i].name << " : ";
		Node *t = E[i];
		while (t != NULL){
			cout << V[t->data].name << ", ";
			t = t->next;
		}
		cout << endl;
	}
}

bool Graph::Adjacent(string v){
	int a = VertexPtr(v);
	if (a == -1) return false;
	cout << endl;
	Node *t = E[a];
	while (t != NULL){
		cout << v << " is connected with " << V[t->data].name << endl;
		t = t->next;
	}
	return true;
}

bool Graph::IsConnected(string v1, string v2){
	int a = VertexPtr(v1);
	int b = VertexPtr(v2);
	if (a == -1 || b == -1 || a == b) return false;
	
	Node *t = E[a];
	while (t != NULL){
		if (t->data == b){
			return true;
		}
		t = t->next;
	}
	return false;
}

int Graph::VertexPtr(string v){
	for (int i = 0; i < V.size(); i++){
		if (V[i].name == v){
			return i;
		}
	}
	return -1;
}

bool Graph::DeleteVertex(string v){ //here you find the need of multilist implementation
	int a = VertexPtr(v);
	if (a == -1) return false;
	Node* t = E[a];
	while (t != NULL){
		Node* t2 = t;
		DeleteNode(t->data, a);
		t = t->next;
		delete t2;
	}
	E.erase(E.begin() + a);
	V.erase(V.begin() + a);
	// the Edges disturbed???
	// continue from here......
	return true;
}

void Graph::BFS(string v){
	int a = VertexPtr(v);
	if (a == -1) return;
	
	Node *t = E[a];
	queue<int> Q;
	visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++) visited[i] = false;
	
	cout << V[a].name << ", ";
	visited[a] = true;
	Q.push(a);
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		t = E[x];
		while (t != NULL){
			if (!visited[t->data]){
			cout << V[t->data].name << ", ";
			visited[t->data] = true;
			Q.push(t->data);
			}
			t = t->next;
		}
	}
	delete[] visited;
}

void Graph::DFS(string v){
	int a = VertexPtr(v);
	if (a == -1) return;
	visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++) visited[i] = false;
	DFS(a);
	delete[] visited;
	
}
void Graph::DFS(int a){
	cout << V[a].name << "  ";
	visited[a] = true;
	Node* t = E[a];
	while (t != NULL){
		if (!visited[t->data]){
			DFS(t->data);
		}
		t = t->next;
	}
}


void Graph::TSort(){
	visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++) visited[i] = false;

	int *TSortResult = new int[V.size()];
	int i = V.size() - 1; //iterator for Result array
	for (int j = 0; j < V.size(); j++){
		if (visited[j] == false){
			i = DFS4TSort(j, i, TSortResult);
		}

	}
	
	for (int i = 0; i < V.size; i++){
		cout << V[TSortResult[i]].name << "  ";
	}

	delete[] TSortResult;
	delete[] visited;
}

int Graph::DFS4TSort(int v, int index, int* TSortResult){
	visited[v] = true;
	Node *t = E[v];
	while (t != NULL){
		if (!visited[t->data]){
			index = DFS4TSort(t->data, index, TSortResult);
		}
		t = t->next;
	}
	TSortResult[index] = v;
	return index - 1;
}


Graph::~Graph()
{
	
}
