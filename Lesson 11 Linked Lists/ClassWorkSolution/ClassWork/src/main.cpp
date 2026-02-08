#include <iostream>

class TwoWayList
{
private:
    struct Node
    {
        int value = 0;
        Node* pNext = nullptr;
        Node* pPrev = nullptr;
    };

    Node* m_pHead = nullptr;
    Node* m_pTail = nullptr;
    unsigned int m_uiSize = 0;

public:
    TwoWayList() = default;
    TwoWayList(const TwoWayList& obj);
    ~TwoWayList();

    unsigned int Size() const;
    bool IsEmpty() const;

    void PushBack(int value);
    bool Get(unsigned int uiPos, int& value) const;
    bool Insert(unsigned int uiPos, int value);
    bool Delete(unsigned int uiPos);
    void Clear();
};

void ShowList(const TwoWayList& twl);

unsigned int TwoWayList::Size() const
{
    return m_uiSize;
}

bool TwoWayList::IsEmpty() const
{
    return m_uiSize == 0;
}

void TwoWayList::PushBack(int value)
{
    Node* newNode = new Node{ value };

    if (!m_pHead)
    {
        m_pHead = m_pTail = newNode;
    }
    else
    {
        m_pTail->pNext = newNode;
        newNode->pPrev = m_pTail;
        m_pTail = newNode;
    }

    ++m_uiSize;
}

bool TwoWayList::Get(unsigned int uiPos, int& value) const
{
    if (uiPos >= m_uiSize)
    {
	    return false;
    }

    Node* tmp = m_pHead;
    for (unsigned int i = 0; i < uiPos; ++i)
    {
	    tmp = tmp->pNext;
    }

    value = tmp->value;
    return true;
}

bool TwoWayList::Insert(unsigned int uiPos, int value)
{
    if (uiPos > m_uiSize)
    {
	    return false;
    }

    Node* newNode = new Node{ value };

    if (uiPos == 0)
    {
        newNode->pNext = m_pHead;
        if (m_pHead)
            m_pHead->pPrev = newNode;
        else
            m_pTail = newNode;

        m_pHead = newNode;
    }
    else if (uiPos == m_uiSize)
    {
        newNode->pPrev = m_pTail;
        m_pTail->pNext = newNode;
        m_pTail = newNode;
    }
    else
    {
        Node* tmp = m_pHead;
        for (unsigned int i = 0; i < uiPos; ++i)
            tmp = tmp->pNext;

        newNode->pNext = tmp;
        newNode->pPrev = tmp->pPrev;
        tmp->pPrev->pNext = newNode;
        tmp->pPrev = newNode;
    }

    ++m_uiSize;
    return true;
}

bool TwoWayList::Delete(unsigned int uiPos)
{
    if (uiPos >= m_uiSize)
    {
	    return false;
    }

    Node* tmp = m_pHead;
    for (unsigned int i = 0; i < uiPos; ++i)
    {
	    tmp = tmp->pNext;
    }

    if (tmp == m_pHead)
    {
        m_pHead = tmp->pNext;
        if (m_pHead)
            m_pHead->pPrev = nullptr;
        else
            m_pTail = nullptr;
    }
    else if (tmp == m_pTail)
    {
        m_pTail = tmp->pPrev;
        m_pTail->pNext = nullptr;
    }
    else
    {
        tmp->pPrev->pNext = tmp->pNext;
        tmp->pNext->pPrev = tmp->pPrev;
    }

    delete tmp;
    --m_uiSize;
    return true;
}

void TwoWayList::Clear()
{
    while (m_pHead)
    {
        Node* tmp = m_pHead;
        m_pHead = m_pHead->pNext;
        delete tmp;
    }

    m_pTail = nullptr;
    m_uiSize = 0;
}

TwoWayList::~TwoWayList()
{
    Clear();
}

TwoWayList::TwoWayList(const TwoWayList& obj)
{
    for (unsigned int i = 0; i < obj.m_uiSize; ++i)
    {
        int value;
        obj.Get(i, value);
        PushBack(value);
    }
}

void ShowList(const TwoWayList& twl)
{
    if (twl.IsEmpty())
    {
        std::cout << "List is empty\n";
        return;
    }

    for (unsigned int i = 0; i < twl.Size(); ++i)
    {
        int value;
        twl.Get(i, value);
        std::cout << "[" << i << "] = " << value << '\n';
    }
}
