#ifndef GRAP_CPP
#define GRAP_CPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include "Node.cpp"
using namespace std;


// Depth Breath Map(has table)
enum ALGORITHM {DFS,BFS,MAP};

struct TreeNode
{
	TreeNode(string Id, int Value)
	{
		id = Id;
		value = Value;
	}
	string id;
	int value;
};

class Tree
{
	private :
		map <string,shared_ptr<Node>> nodes;
		map <int,vector<string>> reverseMap;
		shared_ptr<Node> head;
		vector<shared_ptr<Node>> leafs;

		shared_ptr<Node> FindNodeMap(string id)
		{
			if(nodes.count(id) == 1)
				return nodes[id];
			else	
				return nullptr;
		}

		shared_ptr<Node> FindNodeBFS(string id)
		{
			map<string,bool>visited;
			vector<shared_ptr<Node>> quene;
			quene.push_back(head);
			while(quene.size())
			{
				shared_ptr<Node> currentNode = quene[0];
				quene.erase(quene.begin());
				
				if(currentNode->GetId() == id)
					return currentNode;
			
				Node::BothChild	children = currentNode->GetBothChild();
				quene.push_back(children.left);
				quene.push_back(children.right);
			}

			return nullptr;
		}
		

		shared_ptr<Node> FindNodeDFS(string id)
		{
			map<string,bool>visited;
			vector<shared_ptr<Node>> stack;
			stack.push_back(head);
			while(stack.size())
			{
				shared_ptr<Node> currentNode = stack.back();
				stack.pop_back();
				
				if(currentNode->GetId() == id)
					return currentNode;
			
				Node::BothChild	children = currentNode->GetBothChild();
				stack.push_back(children.left);
				stack.push_back(children.right);
			}

			return nullptr;
		}

		void setMap(shared_ptr<Node> node)
		{
			nodes[node->GetId()] = node;
			if(reverseMap.count(node->GetValue()) == 1)
			{
				vector<string> currentIdes = reverseMap[node->GetValue()];
				currentIdes.push_back(node->GetId());
				reverseMap[node->GetValue()] = currentIdes;
			}
			else{
				vector<string> newVectorId= {node->GetId()};
				reverseMap[node->GetValue()] = newVectorId;
			}
		}

	public : 
		
		Tree(TreeNode Head)
		{
			head = shared_ptr<Node>(new Node(Head.id,Head.value));
			setMap(head);
			leafs.push_back(head);
		}

				
		shared_ptr<Node> GetHead()
		{
			return head;
		}


		vector<shared_ptr<Node>> GetLeafs()
		{
			return leafs;
		}

	
		
		vector<string> GetIdWithValue(int Value)
		{
			if(reverseMap.count(Value)== 0)
				return vector<string>();
			return reverseMap[Value];
		}
		

		shared_ptr<Node> FindNodeWithId(string id  ,ALGORITHM algorithm=MAP)
		{
			shared_ptr<Node>node;
			switch(algorithm)
			{
				case DFS:
					node = FindNodeDFS(id);
				break;
				
				case BFS:
					node = FindNodeBFS(id);
				break;
				
				case MAP:
					node = FindNodeMap(id);
				break;

				default:
					node = FindNodeMap(id);
				 break;
			}

			return node;
		}
		
		vector<string> FindNodeWithValue(int Value)
		{
			if(reverseMap.count(Value) > 0)
					return reverseMap[Value];
			
			return vector<string>();
		}

		void ChangeValueNode(string id , int newValue ,ALGORITHM algorithm=MAP)
		{
			shared_ptr<Node> node = FindNodeWithId(id,algorithm);	
			node->ChangeValue(newValue);
		}
		
		bool AddRightNode(string ParnetId,TreeNode RigthNode)
		{
			shared_ptr<Node> parnet = FindNodeWithId(ParnetId);
			if(parnet == nullptr)
				return false;

			shared_ptr<Node> rightNode =shared_ptr<Node>(new Node(RigthNode.id,RigthNode.value));
			parnet->SetRightNode(rightNode);
			
			setMap(rightNode);
			return true;
		};
	
		bool AddLeftNode(string ParnetId,TreeNode LeftNode)
		{
			shared_ptr<Node> parnet = FindNodeWithId(ParnetId);
			if(parnet == nullptr)
				return false;

			shared_ptr<Node> leftNode =shared_ptr<Node>(new Node(LeftNode.id,LeftNode.value));
			parnet->SetLeftNode(leftNode);
			
			setMap(leftNode);
			return true;
		};

		bool AddBothNode(string ParnetId,TreeNode LeftNode,TreeNode RigthNode)
		{
			shared_ptr<Node> parnet = FindNodeWithId(ParnetId);
			if(parnet == nullptr)
				return false;
			
			AddLeftNode(ParnetId,  LeftNode);
			AddRightNode(ParnetId,RigthNode);
			return true;
		};
};

#endif
