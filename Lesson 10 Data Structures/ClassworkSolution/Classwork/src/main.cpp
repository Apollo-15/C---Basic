#include <iostream>

struct Node
{
    int iValue = 0;
    Node* pNext = nullptr;
};

// ShowList
void ShowList(const Node* pHead);
// AddNode
void AddNode(Node*& pHead, int value);
// ClearList
void ClearList(Node*& pHead);
// DeleteNode
bool DeleteNode(Node*& pHead, unsigned int position);
// InsertNode
bool InsertNode(Node*& pHead, unsigned int position, int value);

int main()
{
    Node* pHead = nullptr;

    ShowList(pHead);

    AddNode(pHead, 10);
    AddNode(pHead, 25);
    AddNode(pHead, 72);
    AddNode(pHead, 36);

    ShowList(pHead);

    //ClearList(pHead);
    std::cout << "--------------------" << "\n";
    //DeleteNode(pHead, 0);

    InsertNode(pHead, 2, 5);

    ShowList(pHead);
	
	std::cin.get();

    return 0;
}

void AddNode(Node*& pHead, int value)
{
    Node* pNewNode = new Node;
    pNewNode->iValue = value;

    if (pHead == nullptr)
    {
        pHead = pNewNode;
        return;
    }

    Node* tmp = pHead;

    while (tmp->pNext != nullptr)
    {
        tmp = tmp->pNext;
    }

    tmp->pNext = pNewNode;
}

void ShowList(const Node* pHead)
{
	while (pHead != nullptr)
	{
		std::cout << pHead->iValue << "\n";
        pHead = pHead->pNext;
	}
}

void ClearList(Node*& pHead)
{
    Node* tmp = nullptr;

    while (pHead != nullptr)
    {
        tmp = pHead->pNext;
        delete pHead;
        pHead = tmp;
    }
}

bool DeleteNode(Node*& pHead, unsigned int position)
{
    if (pHead == nullptr) { return false; }

    if (position == 0)
    {
        Node* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
        return true;
    }

    Node* tmpPrev = nullptr;
    Node* tmp = pHead;

    for (size_t i = 0; i < position; ++i)
    {
        tmpPrev = tmp;
        if (tmp != nullptr)
            tmp = tmp->pNext;
        else
            return false;
    }

    if (tmp != nullptr)
    {
        tmpPrev->pNext = tmp->pNext;
        delete tmp;
        return true;
    }
    else
        return false;
}

bool InsertNode(Node*& pHead, unsigned int position, int value)
{
    Node* pNewNode = new Node;
    pNewNode->iValue = value;

    if (position == 0)
    {
        pNewNode->pNext = pHead;
        pHead = pNewNode;
        return true;
    }

    Node* prev = pHead;

    for (size_t i = 0; i < position - 1; ++i)
    {
        prev = prev->pNext;
    }

    if (prev == nullptr)
    {
        delete pNewNode;
        return false;
    }

    pNewNode->pNext = prev->pNext;
    prev->pNext = pNewNode;

    return true;
}