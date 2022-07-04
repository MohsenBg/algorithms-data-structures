#include "Graph.cpp"
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
