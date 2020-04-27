
template <typename T>
class ForwardListNode{
    public:
        typedef T value_t;
        value_t content;
        ForwardListNode<T>* next;

        ForwardListNode (const T& _content){
            content = _content;
            next = nullptr;
        }

        ~ForwardListNode(void){
        }

        value_t& operator*(void){
            return content;
        }

        /*template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
            _out << "Nodo: [v: " <<  _node.content << ", p: " << &_node << "]";
            return _out;
        }*/
};