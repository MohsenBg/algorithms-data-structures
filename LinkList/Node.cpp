

class Node
{
	public:
	int value;
	
	Node(int Value)
	{
		value = Value;
	}

	void setNext(Node *node)
	{
		delete  next;
		next  = node;
	}

	Node *Next()
	{
		
		if(next == nullptr)
			return nullptr;

		return next;
	}

	private:
		Node *next;
};
