/* 
 * File:   Node.cpp
 * Author: amdiaz
 * 
 * Created on 4 de febrero de 2015, 13:53
 */

#include "Node.h"

template<class T>
Node<T>::Node() : data(), parent(nullptr) {
}

template<class T>
Node<T>::Node(T data) : data(data), parent(nullptr) {
}

template<class T>
void Node<T>::setParent(Node<T>* parent) {
    this->parent = parent;
}

template<class T>
Node<T>* Node<T>::getParent() const {
    return this->parent;
}

template<class T>
void Node<T>::setChildren(vector<Node<T>*> children) {
    this->children = children;
}

template<class T>
vector<Node<T>*>* Node<T>::getChildren() {
    return &this->children;
}

template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<class T>
T Node<T>::getData() {
    return this->data;
}

template<class T>
bool Node<T>::isLeaf() const {
    return (this->children.size() == 0) ? true : false;
}

template<class T>
bool Node<T>::isRoot() const {
    return (this->parent == nullptr) ? true : false;
}

template<class T>
void Node<T>::traverse(vector<Node<T>*> &nodeVector) {
    if (isLeaf()) {
        nodeVector.push_back(this);
    } else {
        nodeVector.push_back(this);
        for (Node<T>* node : getChildren()) {
            node->traverse(nodeVector);
        }
    }
}

template<class T>
void Node<T>::traverseInDepth(vector<Node<T>*> &nodeVector) {
    stack<Node<T>*> stackBreadth;
    stackBreadth.push(this);

    while (!stackBreadth.empty()) {
        Node<T>* current = stackBreadth.top();
        stackBreadth.pop();

        nodeVector.push_back(current);

        if (!current->isLeaf()) {
            for (Node<T>* node : current->getChildren()) {
                stackBreadth.push(node);
            }
        }

    }

}

template<class T>
void Node<T>::traverseInBreadth(vector<Node<T>*> &nodeVector) {
    queue<Node<T>*> queueDepth;
    if (isLeaf()) {
        nodeVector.push_back(this);
    } else {
        nodeVector.push_back(this);
        for (Node<T>* node : getChildren()) {
            queueDepth.push(node);
        }

        while (!queueDepth.empty()) {
            Node<T>* current = queueDepth.front();
            queueDepth.pop();

            nodeVector.push_back(current);

            if (!current->isLeaf()) {
                for (Node<T>* node : current->getChildren()) {
                    queueDepth.push(node);
                }
            }

        }

    }
}

template<class T>
bool Node<T>::goThoughParent(vector<Node<T>*>& nodeVector) {
    if (getParent() == NULL) {
        nodeVector.push_back(this);
        return false;
    } else {
        nodeVector.push_back(this);
        getParent()->goThoughParent(nodeVector);
    }

    return true;


}

template<class T>
void Node<T>::addElement(Node<T>* child) {
    child->setParent(this);
    this->children.push_back(child);
}

template<class T>
void Node<T>::addElement(T element) {
    addElement(new Node<T>(element));
}

template<class T>
Node<T>::~Node() {
    cout<<"Destructor, deallocate..."<<endl;
//    this->parent = nullptr;
    
    for (typename std::vector<Node<T>*>::iterator it = children.begin() ; it != children.end() ; it++) {
//        children.erase(it);
        delete *it;
    }
}

template<class T>
void Node<T>::removeElement(T targetElement) throw (ElementNotFoundException&) {
    try{
        Node<T>* node = searchElement(targetElement); //Buscamos el nodo a borrar
        
        if(!node->isRoot()){
            vector<Node<T>*>* nodes = node->getParent()->getChildren();
            
            cout << "nodes size" << nodes->size() << endl;
            
            typename vector<Node<T>*>::iterator position = std::find(nodes->begin(),nodes->end(), node);
            if (position != nodes->end()) {// == vector.end() means the element was not found
                nodes->erase(position);
            }
            
            cout << "nodes size" << nodes->size() << endl;
            
            
            delete node;
            //new Node<int>(1222);
            cout << "nodes size - " << node->getData() << endl;
            
        }else{
            delete node;
        }

    }catch(ElementNotFoundException& ex){
        throw ElementNotFoundException("ElementNotFoundException: element not removed.");
    }
    
}

template<class T>
Node<T>* Node<T>::searchElement(T targetElement) throw (ElementNotFoundException&) {
    Node<T>* search = findElement(targetElement);
    if(search == nullptr){
        throw ElementNotFoundException();
    }
    return search;
}

template<class T>
Node<T>* Node<T>::findElement(T targetElement) {
    Node<T>* current = nullptr;
    if(isLeaf()) {
        if(targetElement == getData()){
            return this;
        }
    }else{
        if(targetElement == getData()){
            return this;
        }
        vector<Node<T>*>* vectorNodes = getChildren();
        //recorro los hijos buscando el elemento
        for (size_t i=0; i<vectorNodes->size() && current == nullptr; ++i) {
              current = vectorNodes->at(i)->findElement(targetElement);
             
        }
    }
    
     return current;

}
