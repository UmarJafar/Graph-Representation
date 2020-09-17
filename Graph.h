#pragma once
#include <vector> 
#include  <iostream>
#include "bits/stdc++.h"
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

class vertices{
public:
	string name;
	vertices(string n){
		name = n;
	}
};

class Graph
{
	vector<vertices> V;
	vector<Node*> E; // or Node* E[no of vertices]; statically

	bool DeleteNode(int source, int destination);

public:
	bool *visited;

	int VertexPtr(string vertex);
	Graph();
	void Print();
	bool InsertVertex(string vertex);
	bool DeleteVertex(string v);
	bool DeleteEdge(string v, string v2);
	bool InsertEdge(string start, string end);
	void PrintVertices();
	void PrintEdges();
	bool Adjacent(string vertex);
	bool IsConnected(string v1, string v2);
	void BFS(string v); 
	void DFS(int v);
	void DFS(string v);

	void TSort();// topological sort
	int DFS4TSort(int vertex, int index, int* ResultArray);

	~Graph();
};

