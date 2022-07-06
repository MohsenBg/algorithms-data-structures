#ifndef GRAP_CPP
#define GRAP_CPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Node.cpp"
using namespace std;

enum PATH  {SINGEL , DOUBLE};
class Graph
{
	private:
	map<string,Node*> nodes;
	
	Node *FindNode(string name)
	{
		if(nodes.count(name) == 1)
			return nodes[name];


		nodes[name] = new Node(name); 
		return  nodes[name];
	}
	

	public:
	void AddEage(string from , string to,PATH path=SINGEL)
	{
		Node *From = FindNode(from);
		Node *To = FindNode(to);	
		From->AddNeighbors(To);
		if(path == DOUBLE)
			To->AddNeighbors(From);
	}

	void DebugLog()
	{
		
		for(auto it = nodes.begin(); it != nodes.end(); it++)
			it->second->DebugLog();
		
	}

	Node *GetNode(string name)
	{
		return nodes[name];
	}
};

#endif
