/* 
 * File:   Node.h
 * Author: amdiaz
 *
 * Created on 4 de febrero de 2015, 13:53
 */

#ifndef NODE_H
#define	NODE_H

#include <algorithm> //find()

#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
#include <queue>
#include <stack>

#include "Data.h"

using namespace std;

template<class T>
class Node
{  
private:
    T data;
    Node<T>* parent;
    vector<Node<T>*> children;    
    
    Node<T>* findElement(T targetElement);
    
public:
        
    Node();
    Node(T data);
    ~Node();
    
    void setParent(Node<T>* parent);
    Node<T>* getParent() const;
    
    void setData(T data);
    T getData();
    
    void setChildren(vector<Node<T>*> children);
    vector<Node<T>*>* getChildren();
    
    bool isLeaf() const;
    bool isRoot() const;
    
    void traverse(vector<Node<T>*> &nodeVector);
    void traverseInDepth(vector<Node<T>*> &nodeVector);
    void traverseInBreadth(vector<Node<T>*> &nodeVector);
    
    bool goThoughParent(vector<Node<T>*> &nodeVector);
    
    
    void addElement (T element);
    void addElement (Node<T>* element);
    void removeElement (T targetElement) throw (ElementNotFoundException&);
    Node<T>* searchElement(T targetElement) throw (ElementNotFoundException&);
protected:
    
};

#endif


