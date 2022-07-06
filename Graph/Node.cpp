#ifndef NODE_CPP
#define NODE_CPP

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Node
{
	private:
	vector<Node*> neighbors;

	bool IsNeighborsExist (Node node)
	{	
		for(Node *neighbor:neighbors)
			if(neighbor->name == node.name)
				return true;
		return false;
	}


	public:
	string name;
	
	Node(string Name)
	{
		name = Name;	
	}

	void AddNeighbors(Node *node)
	{
		if(!IsNeighborsExist(*node))
			neighbors.push_back(node);	
	}

	vector<Node*> GetNeighbor()
	{
		return neighbors;
	}

	void DebugLog()
	{
	
		string show = "["+ name +"]: {";
		
		for(Node *neighbor:neighbors)
			show += neighbor->name + ",";
		
		if(neighbors.size() > 0)
			show.pop_back();
		
		show += "}";
		
		cout << show << endl;
	}
};

#endif 

