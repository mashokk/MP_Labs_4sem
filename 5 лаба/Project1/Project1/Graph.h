#pragma once
#include <list>
#include "Graph.h"
namespace graph
{
    struct AList;
    struct AMatrix
    {
        int nV;                  
        int* mr;                 
        AMatrix(int n, int mr[]);
        AMatrix(const AList& al);
        void set(int i, int j, int r);  
        int  get(int i, int j)const;    
    };

    struct AList  
    {
        int nV;
        std::list<int>* mr;       
        void create(int n);       
        AList(int n, int mr[]);    
        AList(const AMatrix& am); 
        void add(int i, int j);      
        int  size(int i) const;      
        int  get(int i, int j)const; 
    };

};