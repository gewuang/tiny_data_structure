/**
 * @file:     link.h
 * @brief:   链表相关内容声明
 * @author:  gewuang
 * @version: 1.0.0
 * @date:    2019-07-09
 */

#ifndef __LINK_H_
#define __LINK_H_

#include "public_lib.h"

template <class DATA>
struct Node
{
    DATA data;          // 数据域
    Node<DATA> * next;  // 指针域

    Node();             // 无参构造函数
    Node(DATA data, Node<DATA>* next = NULL);   // 有参构造函数
};

template <class DATA>
class SimpleLink
{
    private:
        Node<DATA>* head;   // 头节点指针
        Node<DATA>* GetElemPtr(int position) const;   // 获取对应位置的指针
        void Init();
    public:
        SimpleLink();       // 构造函数
        virtual ~SimpleLink();      // 析构函数
        SimpleLink(const SimpleLink<DATA> &copy);   // 复制构造函数
        SimpleLink<DATA>&operator=(const SimpleLink<DATA> &copy);   // 赋值运算符重载
        unsigned int Length() const;
        bool IsEmpty() const;
        void Clear();
        void PrintLink();
        void Traverse(void (*Visit)(DATA &));
        void GetLink(DATA * datas);
        void AddElem(const DATA data);
        bool DeleteLink(int position);
        bool InsertLink(int position, const DATA data);
        bool ReverseLink();
        bool GetELem(unsigned int position, DATA &elem) const;
        bool SetELem(int position, const DATA data);
        int GetPosition(const DATA data);
};

/**
 * @brief: Node类无参构造函数
 *
 * @tparam DATA
 */
template <class DATA>
Node<DATA>::Node()
{
    data = 0;
    next = NULL;
}

/**
 * @brief: Node类有参构造函数
 *
 * @tparam DATA
 * @param data
 * @param next
 */
template <class DATA>
Node<DATA>::Node(DATA data, Node<DATA>* next)
{
    this->data = data;
    this->next = next;
}

/**
 * @brief: 获取对应相关节点指针(内部)
 *
 * @tparam DATA
 * @param position
 *
 * @return: 对应节点指针
 */
template <class DATA>
Node<DATA>* SimpleLink<DATA>::GetElemPtr(int position) const
{
    Node<DATA>* tmpPtr = head;
    int conPos = 0;

    while (tmpPtr->next != NULL && conPos < position)
    {
        tmpPtr = tmpPtr->next;
        conPos++;
    }

    return tmpPtr;
}

/**
 * @brief: 初始化链表（内部）
 *
 * @tparam DATA
 */
template <class DATA>
void SimpleLink<DATA>::Init()
{
    head = new Node<DATA>;
}

/**
 * @brief: 构造函数
 *
 * @tparam DATA
 */
template <class DATA>
SimpleLink<DATA>::SimpleLink()
{
    cout << "data create!" << endl;
    Init();
}

/**
 * @brief: 析构函数
 *
 * @tparam DATA
 */
template <class DATA>
SimpleLink<DATA>::~SimpleLink()
{
    cout << "data delete!" << endl;
    Clear();
    delete head;
}

/**
 * @brief: 获取长度
 *
 * @tparam DATA
 *
 * @return: 长度
 */
template <class DATA>
unsigned int SimpleLink<DATA>::Length() const
{
    unsigned int len = 0;
    Node<DATA>* tmpPtr = head;

    while (tmpPtr->next != NULL)
    {
        len++;
        tmpPtr = tmpPtr->next;
    }

    return len;
}

/**
 * @brief: 判断是否为空
 *
 * @return true/false
 */
template <class DATA>
bool SimpleLink<DATA>::IsEmpty() const
{
    return head->next == NULL ? true : false;
}

/**
 * @brief:  清空链表
 *
 * @tparam DATA
 */
template <class DATA>
void SimpleLink<DATA>::Clear()
{
    unsigned int len = Length();

    while (len > 0)
    {
        DeleteLink(1);
        len = len - 1;
    }
}

/**
 * @brief: 打印链表
 *
 * @tparam DATA
 */
template <class DATA>
void SimpleLink<DATA>::PrintLink()
{
    Node<DATA>* tmpPtr = head;

    while (tmpPtr->next != NULL)
    {
        tmpPtr = tmpPtr->next;
        cout << tmpPtr->data << " ";
    }
    cout << endl;
}

/**
 * @brief: *Visit函数遍历处理链表中的值
 *
 * @tparam DATA
 * @param Visit 函数指针
 */
template <class DATA>
void SimpleLink<DATA>::Traverse(void (*Visit)(DATA &))
{
    Node<DATA>* tmpPtr = head;

    while (tmpPtr->next == NULL)
    {
        tmpPtr = tmpPtr->next;
        (*Visit)(tmpPtr->data);     // 对链表中每个数据通过函数处理
    }
}

/**
 * @brief: 在尾端添加链表数据
 *
 * @tparam DATA
 * @param data
 *
 * @return
 */
template <class DATA>
void SimpleLink<DATA>::AddElem(const DATA data)
{
    unsigned int len = Length();
    Node<DATA>* tmpPtr = GetElemPtr(len);
    Node<DATA>* newPtr = new Node<DATA>(data, NULL);

    tmpPtr->next = newPtr;
}

/**
 * @brief: 获取对应位置的值
 *
 * @tparam DATA
 * @param position  位置
 *
 * @return 返回对应的值
 */
template <class DATA>
bool SimpleLink<DATA>::GetELem(unsigned int position, DATA & elem) const
{
    bool ret = false;
    unsigned int len = Length();

    if(0 < position && position <= len)
    {
        elem = GetElemPtr(position)->data;
        ret = true;
    }

    return ret;
}

/**
 * @brief: 设置数据
 *
 * @tparam DATA
 * @param position 设置的位置
 * @param data 设置的数据
 *
 * @return
 */
template <class DATA>
bool SimpleLink<DATA>::SetELem(int position, const DATA data)
{
    bool ret = false;
    unsigned int len = Length();

    if(0 < position && position <= len)
    {
        GetElemPtr(position)->data = data;
        ret = true;
    }

    return ret;
}

/**
 * @brief: 获得数据对应的位置
 *
 * @tparam DATA
 * @param data
 *
 * @return 找到返回位置，错误返回-1
 */
template <class DATA>
int SimpleLink<DATA>::GetPosition(const DATA data)
{
    int position = 0;
    int ret = -1;
    Node<DATA>* tmpPtr = head;

    while (tmpPtr->next != NULL)
    {
        tmpPtr = tmpPtr->next;
        position++;
        if(data == tmpPtr->data)
        {
            ret = position;
            break;
        }
    }

    return ret;
}

/**
 * @brief: 删除对应位置的内容
 *
 * @tparam DATA
 * @param position
 *
 * @return true/false
 */
template <class DATA>
bool SimpleLink<DATA>::DeleteLink(int position)
{
    bool ret = false;
    unsigned int len = Length();

    Node<DATA>* pre = GetElemPtr(position-1);
    Node<DATA>* del = pre->next;

    if(position < len && position > 0)
    {
        pre->next = del->next;
        delete del;
        ret = true;
    }

    return ret;
}

/**
 * @brief: 插入数据
 *
 * @tparam DATA
 * @param position 插入的位置
 * @param data 插入的数据
 *
 * @return
 */
template <class DATA>
bool SimpleLink<DATA>::InsertLink(int position, const DATA data)
{
    bool ret = false;
    Node<DATA>* pre = GetElemPtr(position-1);
    Node<DATA>* next = pre->next;

    if(position <= Length() && position > 0)
    {
        Node<DATA> * newPtr = NULL;

        newPtr = new Node<DATA> (data, next);
        pre->next = newPtr;
        ret = true;
    }

    return ret;
}

/**
 * @brief: 反转链表
 *
 * @tparam DATA
 *
 * @return
 */
template <class DATA>
bool SimpleLink<DATA>::ReverseLink()
{
    bool ret = false;
    Node<DATA>* tmpPtr = head;
    Node<DATA>* Head = head;
    Node<DATA>* prePtr = head->next;
    Node<DATA>* nextPtr = prePtr->next;

    while(nextPtr != NULL)
    {
        prePtr->next = nextPtr->next;
        nextPtr->next = Head->next;
        Head->next = nextPtr;
        nextPtr = prePtr->next;
    }
    if (nextPtr == NULL)
    {
        ret = true;
    }

    return ret;
}

/**
 * @brief: 赋值运算符重载
 *
 * @tparam DATA
 * @param copy
 */
template <class DATA>
SimpleLink<DATA>&SimpleLink<DATA>::operator=(const SimpleLink<DATA> &copy)
{
    if(&copy != this)
    {
        // 添加数据
        unsigned int len = copy.Length();
        DATA elem;

        // 清掉现有的
        Clear();

        for(unsigned int i = 1; i <= len; i++)
        {
            copy.GetELem(i, elem);
            AddElem(elem);
        }
    }
    return *this;
}

/**
 * @brief: 复制构造函数
 *
 * @tparam DATA
 * @param copy
 */
template <class DATA>
SimpleLink<DATA>::SimpleLink(const SimpleLink<DATA> &copy)
{
     // 添加数据
    unsigned int len = copy.Length();
    DATA elem;

    Init();

    for(unsigned int i = 1; i <= len; i++)
    {
        copy.GetELem(i, elem);
        AddElem(elem);
    }
}

#endif
