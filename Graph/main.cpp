#include "Graph.cpp"
#include "Search.cpp"
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> vec);
void printPath(vector<string> path);
int main()
{
	Graph myGraph;
	
	myGraph.AddEage("A","C");
	myGraph.AddEage("A","B",DOUBLE);	
	myGraph.AddEage("B","D");
	myGraph.AddEage("D","C");


	myGraph.DebugLog();

	cout << "Breadth Fist Search \n";
	vector<string>path = Search::BFS(myGraph.GetNode("A"), myGraph.GetNode("C"));
	printPath(path);
	
	cout << "Depth Fist Search \n";
	path = Search::DFS(myGraph.GetNode("A"), myGraph.GetNode("C"));
	printPath(path);

	return 0;
}

void printVector(vector<string> vec)
{
		string show = "[";
		for(string data:vec)
			show += data + ",";
		
		if(vec.size() > 0)
			show.pop_back();
		
		show += "]";
		
		cout << show << endl;
}

void printPath(vector<string> path)
{
		string show="";
		for(string data:path)
			show += data + " -> ";
		
		if(path.size() > 1){
			show.pop_back();
			show.pop_back();
			show.pop_back();
			show.pop_back();
		}
		cout << show << endl;

}

/*
 *		 (A) ==========> (C) 	
 *		  |               ^
 *		  |			      |
 *		  |	    		  |
 *		  |				  |
 *		 (B) ==========>  (D)
 */
