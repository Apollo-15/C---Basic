#include <iostream>

class CSet
{
private:
	struct Node
	{
		int iKey = 0;

		Node* pLeft = nullptr; // smaller
		Node* pRight = nullptr; // bigger
	};

	Node* m_pRoot = nullptr;
	unsigned int m_uiSize = 0;

	bool AddToNode(Node*& node, const int iKey);
	void PrintNode(const Node* const node) const;
	bool CheckKey(const Node* const node, const int iKey) const;
	bool AddExistedNode(Node*& node, Node*& nodeForAdd);
	void DeleteNode(Node*& node, const int iKey);
	void ClearAll(Node*& node);

public:
	CSet() {};
	CSet(const CSet& obj) = delete;
	~CSet() { ClearAll(); };

	void Add(const int iKey);
	void Delete(const int iKey);
	bool IsExist(const int iKey) const;
	void ClearAll();

	void PrintTree() const;
};

int main()
{
	CSet s;

	s.Add(88);
	s.Add(1);
	s.Add(1000);
	s.Add(-2);
	s.Add(0);
	s.Add(102);
	s.Add(102);
	s.Add(102);

	std::cout << "=====================" << "\n";
	s.PrintTree();
	std::cout << "\n";
	std::cout << s.IsExist(77) << "\n";
	std::cout << s.IsExist(1000) << "\n";
	std::cout << "\n";

	std::cout << "=====================" << "\n";
	s.Delete(22222);
	s.Delete(-2);
	s.Delete(1000);
	s.PrintTree();

	std::cout << "=====================" << "\n";
	std::cout << "Tree before cleaning: " << "\n";
	s.PrintTree();
	std::cout << "Tree After cleaning: " << "\n";
	s.ClearAll();
	s.PrintTree();
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Well, y'all can see there's nothin' left here :D" << "\n";

	std::cin.get();

	return 0;
}

void CSet::Add(const int iKey)
{
	if (AddToNode(m_pRoot, iKey))
	{
		m_pRoot = new Node;
		m_pRoot->iKey = iKey;
		++m_uiSize;
	}
}

bool CSet::AddToNode(Node*& node, const int iKey)
{
	if (node == nullptr)
		return true;

	if (node->iKey > iKey)
	{
		if (AddToNode(node->pLeft, iKey))
		{
			Node* newNode = new Node;
			newNode->iKey = iKey;

			node->pLeft = newNode;

			++m_uiSize;
		}
	}
	else if (node->iKey < iKey)
	{
		if (AddToNode(node->pRight, iKey))
		{
			Node* newNode = new Node;
			newNode->iKey = iKey;

			node->pRight = newNode;

			++m_uiSize;
		}
	}

	return false;
}

void CSet::PrintTree() const
{
	PrintNode(m_pRoot);
}

void CSet::PrintNode(const Node* const node) const
{
	if (node == nullptr)
		return;

	PrintNode(node->pLeft);
	std::cout << node->iKey << "\n";
	PrintNode(node->pRight);
}

bool CSet::IsExist(const int iKey) const
{
	return CheckKey(m_pRoot, iKey);
}

bool CSet::CheckKey(const Node* const node, const int iKey) const
{
	if (node == nullptr)
		return false;

	if (node->iKey == iKey)
		return true;
	else if (node->iKey > iKey)
		return CheckKey(node->pLeft, iKey);
	else
		return CheckKey(node->pRight, iKey);
}

void CSet::Delete(const int iKey)
{
	DeleteNode(m_pRoot, iKey);
}

void CSet::DeleteNode(Node*& node, const int iKey)
{
	if (node == nullptr)
		return;

	if (node->iKey == iKey)
	{
		Node* tmp = nullptr;

		if (node->pRight != nullptr)
		{
			tmp = node->pRight;

			if (node->pLeft != nullptr)
			{
				AddExistedNode(node->pRight, node->pLeft);
			}
		}
		else if (node->pLeft != nullptr)
		{
			tmp = node->pLeft;
		}

		delete node;
		node = tmp;

		return;
	}
	else if (node->iKey > iKey)
		DeleteNode(node->pLeft, iKey);
	else
		DeleteNode(node->pRight, iKey);

	return;
}

bool CSet::AddExistedNode(Node*& node, Node*& nodeForAdd)
{
	if (node == nullptr)
		return true;

	if (node->iKey > nodeForAdd->iKey)
	{
		if (AddExistedNode(node->pLeft, nodeForAdd))
		{
			node->pLeft = nodeForAdd;
		}
	}
	else if (node->iKey < nodeForAdd->iKey)
	{
		if (AddExistedNode(node->pRight, nodeForAdd))
		{
			node->pRight = nodeForAdd;
		}
	}

	return false;
}

void CSet::ClearAll(Node*& node)
{
	if (node == nullptr)
	{
		return;
	}

	ClearAll(node->pRight);
	ClearAll(node->pLeft);

	delete(node);

	node = nullptr;
}

void CSet::ClearAll()
{
	ClearAll(m_pRoot);
	m_uiSize = 0;
}