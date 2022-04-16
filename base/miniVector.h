#include<iostream>
#include<string.h>
#include"assert.h"
using namespace std;


template<typename T>
class miniVector{
    private:
             
        T* vectorArr;
        int capacity ;
        int size ;
        void memoryExpand(const int elem);
    public: 
        ~miniVector();
        miniVector():vectorArr(NULL),capacity(2),size(0) {};
        miniVector(const int cap);
        miniVector(const int ini_size,T ini_data);
        miniVector(const miniVector& vec);
        miniVector& operator=(const miniVector& vec);

        void push_back(const T& num);
        void print_info() const;
        T&  operator[](const int& index) const;
        void insert(const int& index,const T& data);
        void pop_back();
        void clear();
        
};