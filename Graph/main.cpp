#include "Graph.cpp"
#include "Search.cpp"
#include <iostream>
using namespace std;

int main()
{
	Graph myGraph;
	
	myGraph.AddEage("A","B");
	myGraph.AddEage("A","C",DOUBLE);
	myGraph.AddEage("A","D",DOUBLE);	
	myGraph.AddEage("D","C");
	myGraph.AddEage("C","B");

	myGraph.DebugLog();
	
	Node Start = *(myGraph.GetNode("A"));
	
	Search::DFS(Start);
	cout << "----------------\n" <<endl;
	Search::BFS(Start);
	
	return 0;
}

/*
 *		 (A) ==========> (B) 	
 *		  | \             ^
 *		  |		\	      |
 *		  |	    	\	  |
 *		  |				\ |
 *		 (D) =========>  (c)
 */
