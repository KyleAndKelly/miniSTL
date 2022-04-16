#include"miniVector.h"

template<typename T>
void miniVector<T>::memoryExpand(const int elem){
    
    T* newArr = new T[elem*capacity];
    cout<<"DEBUG: create newArr success"<<endl;
    memcpy(newArr,vectorArr,size*sizeof(T));

    delete[] vectorArr;
    vectorArr = newArr;
    capacity = elem*capacity;
    cout<<"DEBUG:  capacity "<< capacity<<endl;     
    
}


template<typename T>
miniVector<T>::miniVector(const int cap){
    capacity = cap;
    size = 0;
    vectorArr = new T[capacity];
    cout<<"LOG: capcity "<<capacity<<endl;
    cout<<"LOG: size "<<size<<endl;

}


template<typename T>
miniVector<T>::miniVector(const int ini_size,T ini_data){
    
    capacity = 20+ini_size;
    size = ini_size;
    vectorArr = new T[capacity];
    // memset(vectorArr, ini_data,ini_size);
    for(int i=0;i<ini_size;i++)
    {
        vectorArr[i] = ini_data;
        
    }
    cout<<"LOG: capcity "<<capacity<<endl;
    cout<<"LOG: size "<<size<<endl;

    
}

template<typename T>
miniVector<T>::~miniVector(){
    delete[] vectorArr;
    vectorArr = NULL;
    
}


template<typename T>
void miniVector<T>::push_back(const T& num)
{

    if(vectorArr == NULL)
    {
        capacity = 2;
        size = 0;
        vectorArr = new T[capacity];

    }
    if(size >= capacity)
    {
         memoryExpand(2);//2倍扩容
    }

    vectorArr[size] = num;
    ++size;
    cout<<"DEBUG: size="<<size<<endl;
    cout<<"DEBUG: vectorArr["<<size-1<<"]="<<vectorArr[size-1]<<endl;
    cout<<"DEBUG: capacity"<<capacity<<endl;              
    return;    

}


template<typename T>
void miniVector<T>::print_info() const 
{
    cout<<"LOG vector capacity: "<< capacity<<endl;
    cout<<"LOG vector size: "<< size<<endl;   
    cout<<"LOG vector data: "; 
    for(auto i=0;i<size;i++){
       cout<<vectorArr[i]<<" "; 
    }
    cout<<endl;
}



template<typename T>
T&  miniVector<T>::operator[](const int& index) const
{
    if(vectorArr == NULL)
    {
        cout<<"Error: Memory Not Initial!"<<endl;
       
    }

    if( index >= size || index < 0)
    {
        cout<<"Error: Out of Ranger!"<<endl;
       
    }
    return vectorArr[index];
}

template<typename T>
void miniVector<T>::insert(const int& index,const T& data){
    if(vectorArr == NULL)//如果还没有初始化
    {
        cout<<"Error: Vector is not Initial!"<<endl;
        return;
    }
    if(index >= size-1){
        cout<<"Error: The insert index should be from 0 to "<<size-1<<" "<<endl;
        return;
    }
    if(size>=capacity){
        memoryExpand(2);
    }
    
    for(int i = size-1;i>= index;i--)
    {
        vectorArr[i+1]=vectorArr[i];
    }
    vectorArr[index]= data;
    ++size;
    cout<<"DEBUG: vectorArr["<<index<<"]="<<vectorArr[index]<<endl;
    return;
}




template<typename T>
void miniVector<T>::pop_back()
{
    if(vectorArr == NULL || size == 0)
    {
        cout<<"Error: Vector size is 0!"<<endl;
        return;
    }
    
    --size;
    cout<<"LOG: size "<< size<<endl;
    cout<<"LOG: capacity "<<capacity<<endl;
    
}




template<typename T>
miniVector<T>::miniVector(const miniVector& vec){
    //深拷贝

    capacity = vec.capacity;
    size = vec.size;
    vectorArr = new T[capacity];
    memcpy(vectorArr,vec.vectorArr,size*sizeof(T));
    cout<<"LOG: now in miniVector(const miniVector& vec)  "<<endl;
    cout<<"LOG: size "<<size<<endl;
    cout<<"LOG: capacity "<<capacity<<endl;
}




template<typename T>
miniVector<T>& miniVector<T>::operator=(const miniVector& vec){
     //深拷贝
    if(this == &vec) return *this;
    
    capacity = vec.capacity;
    size = vec.size;
    delete[] vectorArr;
    vectorArr = new T[capacity];
    memcpy(vectorArr,vec.vectorArr,size*sizeof(T));
    cout<<"LOG: now in miniVector operator=  "<<endl;
    cout<<"LOG: size "<<size<<endl;
    cout<<"LOG: capacity "<<capacity<<endl;
    return *this;
    
}


template<typename T>
void miniVector<T>::clear()
{
    size=0;
}