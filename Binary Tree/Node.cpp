#ifndef NODE_CPP
#define NODE_CPP

#include <memory>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class ID
{	
	private:
		char charecters[36] = { 'a','b','c','d','e','f','g','h','i'
			,'j','k','l','m','n','o','p','q','r','s','t','u','v','w'
			,'x','y','z','0','1','2','3','4','5','6','7','8','9' }; 
		vector<string> ides;
		
		bool IsIdExit(string id) const
		{
			for(string exitsId:ides)
				if(exitsId == id)
					return true;
			return false;
		}

	public:
	 string genrateId() const
	{
		string id;
		do{
			id="";
			for(int i=0;i <10 ;i++)
			{
				int index = (rand() % 35);
				id.push_back(charecters[index]);	
			}
		}while(IsIdExit(id));
		
		return  id;
	}
};

const ID ID_Contorller = ID();

class Node
{
	private:
	string id;
	int value;
	shared_ptr<Node> right;
	shared_ptr<Node> left;	
	struct BothChild
	{
		BothChild(shared_ptr<Node>Right,shared_ptr<Node> left)
		{
			right = Right;
			Left = left;
		}
	shared_ptr<Node> right;
	shared_ptr<Node> Left;
	};


	public:
		Node(int Value)
		{
			value = Value;
			id = ID_Contorller.genrateId();
		}

		void ChangeValue(int Value)
		{
			value = Value;
		}
		
		int GetValue()
		{
			return value; 	
		}

		void SetRightNode(shared_ptr<Node> node)
		{
			right = node;
		}

		void SetLeftNode(shared_ptr<Node> node)
		{
			left = node;
		}


		shared_ptr<Node>GetLeftNode()
		{
			return  left;
		}

		shared_ptr<Node>GetRightNode()
		{
			return  right;
		}
		
		BothChild GetBothChild()
		{
			return BothChild(right,left);
		}
		
		void DebugLog()
		{
			string show = "{\n";
			show += "   id:"+ id+ "\n";
			show += "   value:"+to_string(value)+ "\n";
			if(right == nullptr)
				show += "   right: nullptr \n";
			else
			{
				show += "   right:{ \n";
				show += "      id:"+right->id+ "\n";
				show += "      value:"+to_string(right->value)+"\n";
				show += "   }\n";
			}

			if(left == nullptr)
				show += "   left: nullptr \n";
			else
			{
				show += "   left:{\n";
				show += "      id:"+ left->id + "\n";
				show += "      value:"+to_string(left->value)+"\n";
				show  += "   }\n";
			}
			show += "}\n";
			cout << show;
		}
};

#endif 

