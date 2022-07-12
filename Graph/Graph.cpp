#ifndef GRAP_CPP
#define GRAP_CPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include "Node.cpp"
using namespace std;

enum PATH  {SINGEL , DOUBLE};
class Graph
{
	private:
	map<string,shared_ptr<Node>> nodes;
	
	shared_ptr<Node> FindNode(string name)
	{
		if(nodes.count(name) == 1)
			return nodes[name];


		nodes[name] = shared_ptr<Node>(new Node(name)); 
		return  nodes[name];
	}
	

	public:
	void AddEage(string from , string to,PATH path=SINGEL)
	{
		shared_ptr<Node> From = FindNode(from);
		shared_ptr<Node> To = FindNode(to);	
		From->AddNeighbors(To);
		if(path == DOUBLE)
			To->AddNeighbors(From);
	}

	void DebugLog()
	{
		
		for(auto it = nodes.begin(); it != nodes.end(); it++)
			it->second->DebugLog();
		
	}

	shared_ptr<Node> GetNode(string name)
	{
		return nodes[name];
	}
};

#endif
