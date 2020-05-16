#include <iostream>

template <typename T>
class Node {
    public: 
        typedef T value_t;
        value_t value;

        Node(const value_t& _value):value(_value){
        }

        ~Node(void){
        }

        value_t& operator*(void){
            return value;
        }

        template <typename _T>
        inline friend std::ostream& operator<< (std::ostream& _out, const Node<_T>& _node){
            _out << "Node content: " <<  _node.value;
            return _out;
        }
};

template <typename T>
class ForwardListNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        ForwardListNode<T>* next;

    public:
        ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~ForwardListNode(void){
        }

        template <typename _T>
        inline friend std::ostream& operator<< (std::ostream& _out, const ForwardListNode<_T>& _node){
            _out << "Node: [content: " <<  _node.value << ", next: " << _node.next << "]";
            return _out;
        }
};

template <typename T>
class DoubleListNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        DoubleListNode<T>* next;
        DoubleListNode<T>* prev;

    public:
        DoubleListNode(const T& _value):Node<T>(_value),next(nullptr),prev(nullptr){
        }

        ~DoubleListNode(void){
        }

        template <typename _T>
        inline friend std::ostream& operator<< (std::ostream& _out, const DoubleListNode<_T>& _node){
            _out << "Node: [content: " <<  _node.value << ", next: " << _node.next << ", prev: " << _node.prev << "]";
            return _out;
        }
};

template <typename T>
class CircularListNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        CircularListNode<T>* next;
        CircularListNode<T>* head;

    public:
        CircularListNode(const T& _value):Node<T>(_value),next(nullptr),head(nullptr){
        }

        ~CircularListNode(void){
        }

        template <typename _T>
        inline friend std::ostream& operator<< (std::ostream& _out, const CircularListNode<_T>& _node){
            _out << "Node: [content: " <<  _node.value << ", next: " << _node.next << ", head: " << _node.head << "]";
            return _out;
        }
};