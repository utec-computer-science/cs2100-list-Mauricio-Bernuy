#include "Node.h"
#include <random>
using namespace std;

template <typename T>
class Iterator{
    public:
        typedef T node_t;
        typedef typename node_t::value_t value_t;

    //protected:
        node_t * pointer; 

    public:
        Iterator(node_t* _pointer = nullptr):pointer(_pointer){
        }

        ~Iterator(void){
        }

        virtual bool operator!= (Iterator it){
            return pointer != it.pointer;
        }

        virtual value_t& operator* (void) {
            return **pointer;
        }
};

template <typename T>
class ForwardList {
    protected:
        ForwardListNode<T> *head;
        ForwardListNode<T> *tail;

    public:
        typedef ForwardListNode<T> node_t;

        friend class ForwardIterator;
        class ForwardIterator: public Iterator<node_t> {
            public:
                typedef typename Iterator<node_t>::node_t node_t;
                typedef typename Iterator<node_t>::value_t value_t;

            public: 
                ForwardIterator (node_t* pointer = nullptr):Iterator<node_t>(pointer){
                }

                ~ForwardIterator (void){
                }

                ForwardIterator& operator++ (void){
                    Iterator<node_t>::pointer = Iterator<node_t>::pointer->next; 
                    return *this;
                }

        };

        // constructors
        ForwardIterator begin(){
            return ForwardIterator(head);
        }

        ForwardIterator end(){
            return ForwardIterator(nullptr);
        }

        ForwardList(const ForwardList<T>& l2){ 
            head = nullptr;
            tail = nullptr;
            /*ForwardIterator it;
            for(it = l2->begin(); it != l2->end(); ++it){ //fix this and constructors are done
                push_back(*it);
            }*/
            node_t *l2node = l2.head;
            while(l2node != nullptr){
                push_back(l2node->content);
                l2node = l2node->next;
            }


			// Constructor copia
        }
        
        ForwardList(T* arr){ 
            head = nullptr;
            tail = nullptr;
            for (int i=0; i<=sizeof(arr); i++){
                push_back(arr[i]);
            }
			//Constructor  parametro, 
			//llena una lista a partir de un array
        }

        ForwardList(ForwardListNode<T> * node){
            head = node;
            tail = node;
			//Constructor por parametro, 
			//retorna una lista con un nodo
        }
        
        ForwardList(int size){
            head = nullptr;
            tail = nullptr;
            random_device rd;
            mt19937 rng(rd());
            uniform_real_distribution<float> distribution(1,50);
            
            for (int i=0; i<size; i++){
                push_back(distribution(rng));
            }
			//Constructor por parametro, 
			//retorna un lista de randoms de tamaño n
        }

        ForwardList(void){ 
            head = nullptr;
            tail = nullptr;
			//Constructor por defecto
        }

        // destructor
        ~ForwardList(void){
            clear();
        }

		  // Retorna una referencia al primer elemento
        T& front(void){return head->content;}; 
        
		  // Retorna una referencia al ultimo elemento
		T& back(void){return tail->content;}; 
        
		  // Inserta un elemento al final
        void push_back(const T& element){
            node_t *new_node = new node_t{element};
            
            if (head != nullptr){
                tail->next = new_node;
            } else{head = new_node;}
            tail = new_node;
        }; 

		  // Inserta un elemento al inicio
        void push_front(const T& element) {
            node_t *new_node = new node_t{element};
            
            if (tail == nullptr){tail = new_node;}
            else{new_node->next = head;}
            head = new_node;
        }

		  // Quita el ultimo elemento
        T pop_back(void){
            if (head != nullptr){
                T val = tail->content;
                node_t * pointer = head;
                if (head != tail){
                    while( pointer->next != tail){ 
                        pointer = pointer->next;
                    }
                    delete tail;
                    tail = pointer;
                    tail->next = nullptr;
                } else{
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                return val;
            }
        }

  		  // Quita el primer elemento
        T pop_front(void){
            if (head != nullptr){
                T val = head->content;
                node_t * pointer = head->next;
                delete head;
                head = pointer;
                return val;
            }
        };  

		  // Acceso aleatorio
        T& operator[] (const int& position) {
            if(head != nullptr && (position < size()) ){
                node_t * pointer = head;
                for (int i=0; i<position; i++){
                    pointer = pointer->next;
                }
                return pointer->content;
            }
        }; 
        
		  // la lista esta vacia?
        bool empty(void){
            return (head == nullptr);
        }; 

		  // retorna el tamaño de la lista
        unsigned int size(void){
            if (head != nullptr){
                int size = 0;
                node_t * pointer = head;
                do{
                    pointer = pointer->next;
                    size++;
                }
                while( pointer != nullptr);
                return size;
            }else{ return 0; };
        } 

		  // Elimina toda la lista
        void clear(void){
            while(!empty()){
                pop_back();
            }
        }

		  // Elimina un elemento en base a un puntero
        void erase(node_t* target){
            if (head != nullptr){
                node_t * prev = head;
                while( prev->next != target && prev != target && prev != nullptr){ 
                    prev = prev->next;
                }
                if(prev != nullptr){
                    if (target==head) head = target->next;
                    if (target==tail) tail = prev;
                    prev->next = target->next;
                    delete target;
                }        
            }
        }
        
		  // Inserta un elemento  en base a un puntero
        void insert(node_t* target, const T& element){ // i'll asume it's inserted after that pointer
            if (head != nullptr){            
                node_t *new_node = new node_t{element};
                new_node->next = target->next;
                target->next = new_node;
            }   
        }

		  // Elimina todos los elementos por similitud
        void remove(const T& element){
            ForwardIterator it = begin();
            while(it != end()){
                auto tempit = it;
                ++tempit;
                if(*it == element) {
                    erase(it.pointer);
                }
                it = tempit;
            } 
        } 

		  // ordena la lista
        //ForwardList& sort(void) = 0; 

		  // invierte la lista
        ForwardList& reverse(void){
            /*
            ForwardIterator it = n->begin();
            while(it != n->end()){
                push_front(*it);
                ++it;
            }
            //delete n;
            */
            int i = 0;
            int j;
            if (size()%2 == 0) j = size();
            else

        }

		  // Imprime la lista con cout
        template<typename __T>
        inline friend std::ostream& operator<<(std::ostream &os , ForwardList<__T>& list){
            ForwardIterator it = list.begin();
            while(it != list.end()){
                os << *it << " ";
                ++it;
            }
            os<<endl;
            return os;
        }
};

