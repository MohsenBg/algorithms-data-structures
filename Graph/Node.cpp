#ifndef NODE_CPP
#define NODE_CPP

#include <memory>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Node
{
	private:
	vector<shared_ptr<Node>> neighbors;

	bool IsNeighborsExist (shared_ptr<Node> node)
	{	
		for(shared_ptr<Node>neighbor:neighbors)
			if(neighbor->name == node->name)
				return true;
		return false;
	}


	public:
	string name;
	
	Node(string Name)
	{
		name = Name;	
	}

	void AddNeighbors(shared_ptr<Node> node)
	{
		if(!IsNeighborsExist(node))
			neighbors.push_back(node);	
	}

	vector<shared_ptr<Node>> GetNeighbor()
	{
		return neighbors;
	}

	void DebugLog()
	{
	
		string show = "["+ name +"]: {";
		
		for(shared_ptr<Node>neighbor:neighbors)
			show += neighbor->name + ",";
		
		if(neighbors.size() > 0)
			show.pop_back();
		
		show += "}";
		
		cout << show << endl;
	}
};

#endif 

