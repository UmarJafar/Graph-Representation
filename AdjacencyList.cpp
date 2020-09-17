#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include "bits/stdc++.h"
#include <vector>
#include "Graph.h"
#include <queue> 

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	Graph G;

	int res;
	string str, str1, str2;
	bool boolres;
	vector<string> adj;
	char ch;
	while (1){
		cout << "\nPress 1 to print vertice " << endl;
		cout << "Press 2 to insert edge " << endl;
		cout << "Press 3 to print adjacency list " << endl;
		cout << "Press 4 to delete edge " << endl;
		cout << "Press 5 to find if the two vertices are adjacent" << endl;
		cout << "Press 6 to print all edges " << endl;
		cout << "Press 7 to find all the adjacent of a vertix " << endl;
		cout << "Press 8 to insert vertex " << endl;
		cout << "Press 9 to delete vertex " << endl;
		cout << "Press 10 to perform BFS " << endl;
		cout << "Press 11 to make example Graph A to H" <<endl;
		cout << "Press 12 to perform DFS " << endl;
		cout << "Press 13 to perform Topological Sort " << endl;

		int ch;
		cin >> ch;
		switch (ch){
		case 1:
			cout << endl;
			G.PrintVertices();
			break;
		case 2:
			cout << "\nEnter start and end of the edge(v1 --> v2): ";
			cin >> str1 >> str2;
			boolres = G.InsertEdge(str1, str2);
			if (boolres){
				cout << "\nEdge inserted Successfully!" << endl;
			}
			else{
				cout << "\nWrong input or self joining!" << endl;
			}
			break;
		case 3:
			G.Print();
			break;
		case 4:
			cout << "\nEnter start and end of the edge(v1 --> v2) for deletion: ";
			cin >> str1 >> str2;
			boolres = G.DeleteEdge(str1, str2);
			if (boolres){
				cout << "\nEdge deleted Successfully!" << endl;
			}
			else{
				cout << "\nEdge does not exist or Wrong input!" << endl;
			}
			break;
		case 5:
			cout << "\nEnter first and second  vetex: ";
			cin >> str1 >> str2;
			if (G.IsConnected(str1, str2)){
				cout << str1 << " and " << str2 << " are adjacent to each other." << endl;
			}
			else{
				cout << str1 << " and " << str2 << " are not adjacent to each other." << endl;
			}
			break;
		case 6:
			G.PrintEdges();
			break;
		case 7:
			cout << "\nEnter the name vetex: ";
			cin >> str1;
			if (!G.Adjacent(str1)){
				cout << "\n Wrong input!" << endl;
			}
			break;
		case 8:
			cout << "\nEnter the name vetex: ";
			cin >> str1;
			if (!G.InsertVertex(str1)){
				cout << "\n Duplication not Allowed!" << endl;
			}
			else{
				cout << "\nVetex inserted success!" << endl;
			}
			break;
		case 9:
			/*cout << "\nEnter the name vetex for deletion: ";
			cin >> str1;
			if (!G.DeleteVertex(str1)){
				cout << "\nWrong input!" << endl;
			}
			else{
				cout << "\nVetex deleted success!" << endl;
			}
			*/
			break;
		case 10:
			cout << "Enter the starting vertex: ";
			cin >> str1;
			G.BFS(str1);
			break;
		case 11:
			// 8 V
			G.InsertVertex("A");
			G.InsertVertex("B");
			G.InsertVertex("C");
			G.InsertVertex("D");
			G.InsertVertex("E");
			G.InsertVertex("F");
			G.InsertVertex("G");
			G.InsertVertex("H");
			// 10 E			
			G.InsertEdge("A", "D");
			G.InsertEdge("A", "C");
			G.InsertEdge("A", "B");

			G.InsertEdge("B", "F");
			G.InsertEdge("B", "E");

			G.InsertEdge("C", "G");

			G.InsertEdge("F", "H");
			G.InsertEdge("E", "H");
			G.InsertEdge("D", "H");
			G.InsertEdge("G", "H");
			
			/*
			G.InsertVertex("0");
			G.InsertVertex("1");
			G.InsertVertex("2");
			G.InsertVertex("3");

			G.InsertEdge("0", "1");
			G.InsertEdge("0", "2");
			G.InsertEdge("0", "3");
			G.InsertEdge("1", "2");
			G.InsertEdge("1", "3");
			G.InsertEdge("2", "3");*/
			
			cout << "Success" <<endl;
			break;
		case 12:
			cout << "Enter the starting vertex: ";
			cin >> str1;
			G.DFS(str1);
			break;
		case 13:
			//Assumption: The Graph is DAG (Directed Acyclic Graph)
			/* 	A
			    /\
			   C  B   */
			G.InsertVertex("A");
			G.InsertVertex("B");
			G.InsertVertex("C");

			G.TSort();
		}
	}

	_getch();
	return 0;
}

