//
//  Heap.h
//  Heap
//
//  Created by Vinod Gupta on 2/20/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#ifndef Heap_Heap_h
#define Heap_Heap_h

#include <vector>
#include <math.h>

template <class T>
class Heap
{
public:
    Heap() {}
    virtual ~Heap() {}
    
    void Heapify(unsigned int i)
    {
        int leftChild = getLeftChild(i);
        int rightChild = getRightChild(i);
        
        while(leftChild < _heap.size())
        {
            bool hasRightChild = (rightChild < _heap.size());
            
            int minChild =leftChild;
            if(hasRightChild && _heap[rightChild] < _heap[leftChild])
            {
                minChild = rightChild;
            }
            
            if(_heap[i] > _heap[minChild])
            {
                T tmp = _heap[i];
                _heap[i] = _heap[minChild];
                _heap[minChild] = tmp;
            }
            
            i = minChild;
            leftChild = getLeftChild(minChild);
            rightChild = getRightChild(minChild);
        }
    }
    
    void Insert(T val)
    {
        _heap.push_back(val);
        int pos = (int)_heap.size()-1;
        while(pos > 0)
        {
            int parent = getParentIndex(pos);
            if(_heap[parent] > _heap[pos])
            {
                T tmp = _heap[parent];
                _heap[parent] = _heap[pos];
                _heap[pos] = tmp;
            }
            pos = parent;
        }
    }
    
    
    T DelMin()
    {
        size_t heapSize =_heap.size();
        
        if(!heapSize)
            throw "Heap is empty";
        
        int lastPos = (int)_heap.size() - 1;
        T min = _heap[0];
        
        _heap[0] = _heap[lastPos];
        _heap.erase(_heap.end() - 1);
        
        if(heapSize > 1)
        {
            Heapify(0);
        }
        return min;
    }
    
    T min()
    {
        if(_heap.empty())
            throw "Heap is empty";
        
        return _heap[0];
    }
    
    bool empty() {return _heap.empty();}
    
private:
    unsigned int getParentIndex(unsigned int i) {return floor((i-1)/2);}
    unsigned int getLeftChild(unsigned int i) {return (i*2) + 1;}
    unsigned int getRightChild(unsigned int i) {return (i*2) + 2;}
    std::vector<T> _heap;
};

#endif
