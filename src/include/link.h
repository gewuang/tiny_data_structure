/**
 * @file:     link.h
 * @brief:   链表相关内容声明 
 * @author:  gewuang
 * @version: 1.0.0
 * @date:    2019-07-09
 */

#ifndef __LINK_H_
#define __LINK_H_

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
        void GetLink(DATA * datas);
        void AddElem(const DATA data);
        bool DeleteLink(int position);
        bool InsertLink(int position, const DATA data);
        bool ReverseLink();
        DATA GetELem(int position);
        bool SetELem(int position, const DATA data);
        DATA GetPosition(const DATA data);
};

#endif
