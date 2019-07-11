/**
 * @file:     link.cpp
 * @brief:   链表相关功能定义
 * @author:  gewuang
 * @version: 1.0.0
 * @date:    2019-07-09
 */

#include "public_lib.h"
#include "link.h"

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
Node<DATA>::Node(DATA data, Node<DATA>* next = NULL)
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
    Node<DATA> tmpPtr = head;
    int conPos = 0;

    while (tmpPtr != NULL && conPos < position)
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
    // TODO 
}

/**
 * @brief: 打印链表
 *
 * @tparam DATA
 */
template <class DATA>
void PrintLink()
{
    Node<DATA>* tmpPtr = head;

    while (tmpPtr->next != NULL)
    {
        tmpPtr = tmpPtr->next;
        cout << tmpPtr->data << " ";
    }
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
DATA SimpleLink<DATA>::GetELem(int position)
{
    DATA ret = 0;
    unsigned int len = Length();

    if(0 < position && position <= len)
    {
        ret = GetElemPtr(position)->data;
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

template <class DATA>
DATA GetPosition(const DATA data);
bool DeleteLink(int position);
{
    
}
bool InsertLink(int position, const DATA data);
bool ReverseLink();
SimpleLink<DATA>&operator=(const SimpleLink<DATA> &copy);   // 赋值运算符重载 

/**
 * @brief: 复制构造函数
 *
 * @tparam DATA
 * @param copy
 */
template <class DATA>
SimpleLink<DATA>::SimpleLink(const SimpleLink<DATA> &copy)
{

}
