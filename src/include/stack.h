/**
 * @file:    stack.h
 * @brief:   
 * @author:  gewuang
 * @version: 1.0.0
 * @date:    2019-07-24
 */
#ifndef __STACK__
#define __STACK__

#include "public_lib.h"

template<class DATA>
struct stackNode
{
    DATA data;      // 数据
    stackNode<DATA> *next;   // next指针

    stackNode();         // 无参构造函数
    stackNode(DATA data, stackNode<DATA>* next = NULL);       // 有参构造函数
};

template<class DATA>
class Stack
{
    private:
    public:
        Stack();
        virtual ~Stack();

};

/**
 * @brief: stackNode类无参构造函数
 *
 * @tparam DATA
 */
template <class DATA>
stackNode<DATA>::stackNode()
{
    data = 0;
    next = NULL;
}

/**
 * @brief: stackNode类有参构造函数
 *
 * @tparam DATA
 * @param data
 * @param next
 */
template <class DATA>
stackNode<DATA>::stackNode(DATA data, stackNode<DATA>* next)
{
    this->data = data;
    this->next = next;
}


#endif
