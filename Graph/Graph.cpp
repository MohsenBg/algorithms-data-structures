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
	Node *newNode = new Node(name);
	nodes[name] = newNode; 
	return  newNode;
	
	}
	public:

	void AddEage(string from , string to,PATH path=SINGEL)
	{
		Node *From = FindNode(from);
		Node *To = FindNode(to);	
		From->AddNeighbors(*(To));
		if(path == DOUBLE)
			To->AddNeighbors(*(From));
	}

	void DebugLog()
	{
		
		for(auto it = nodes.begin(); it != nodes.end(); it++)
			it->second->DebugLog();
		
	}
};
