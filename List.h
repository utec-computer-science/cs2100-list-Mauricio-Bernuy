#include "Node.h"
#include <random>
using namespace std;

template <typename T>
class List {
    protected:
        Node<T> *head;
        Node<T> *tail;

    public:
        List(List){ 
			// Constructor copia
        }
        
        List(T*){ 
			//Constructor  parametro, 
			//llena una lista a partir de un array
        }

        List(Node<T>*){ 
			//Constructor por parametro, 
			//retorna una lista con un nodo
        }

        List(int size){
            random_device device;
            mt19937 generator(device());
            uniform_int_distribution<int> distribution(1,100);
            
            for (i=0; i<size; i++){
                push_back(distribution(generator));
            }
			//Constructor por parametro, 
			//retorna un lista de randoms de tamaño n
        }

        List(void){ 
			//Constructor por defecto
        }

        ~List(void){
        }

		  // Retorna una referencia al primer elemento
        T front(void){return head->value}; 
        
		  // Retorna una referencia al ultimo elemento
		T back(void){return tail->value}; 
        
		  // Inserta un elemento al final
        void push_back(const T& element){
            Node<T> * new_node = new Node<T>{element, nullptr};
            if (head != nullptr){
                tail->next = new_node;
            } else{head = new_node;}
            tail = new_node;
        }; 

		  // Inserta un elemento al inicio
        void push_front(const T& element) {
            Node<T> * new_node = new Node<T>{element, head};
            head = new_node;
            if (tail == nullptr){tail = new_node;}
        }

		  // Quita el ultimo elemento y retorna una referencia
        T& pop_back(void){
            if (head != nullptr){
                T val = tail->value;
                Node<T> * pointer = head;
                if (head != tail){
                    while( pointer->next != tail){ 
                        pointer = pointer->nextNode;
                    }
                    delete tail;
                    tail = pointer;
                } else{
                    delete head;
                    head = nullptr;
                    tail = nullptr
                }
                return val;
            }
        }

  		  // Quita el primer elemento y retorna una referencia
        T& pop_front(void){
            if (head != nullptr){
                T val = head->value;
                Node<T> * pointer = head->next;
                delete head;
                head = pointer;
                return val;
            }
        };  

		  // Acceso aleatorio
        T& operator[] (const int& position) {
            if(head != nullptr){
                Node<T> * pointer = head;
                for (int i=0; i<position; i++){
                    pointer = pointer->nextNode;
                }
                return pointer->value;
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
                Node<T> * pointer = head;
                do{
                    pointer = pointer->nextNode;
                    size++;
                }
                while( pointer != tail);
                return size;
            }else{ return 0 };
        } 

		  // Elimina toda la lista
        void clear(void){
            while(head != nullptr){
                this->pop_back();
            }
        }

		  // Elimina un elemento en base a un puntero
        void erase(Node<T>*) = 0; 
        
		  // Inserta un elemento  en base a un puntero
        void insert(Node<T>*, const T&) = 0; 

		  // Elimina todos los elementos por similitud
        void remove(const T&) = 0; 

		  // ordena la lista
        List& sort(void) = 0; 

		  // invierte la lista
        List& reverse(void) = 0; 

		  // Imprime la lista con cout
        template<typename __T>
        inline friend std::ostream& operator<<
			(std::ostream& , const List<__T>& ); 
}