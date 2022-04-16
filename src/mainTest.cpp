#include<iostream>
#include"miniVector_impl.h"
using namespace std;

void miniVectorTest_pushback_int(){
    miniVector<int> vec;
    vec.push_back(1);
    vec.push_back(9);    
    vec.push_back(2);    
    vec.push_back(4);
    vec.push_back(3);    
    vec.print_info();
    cout<<"DEBUG: vec[2] " <<vec[2]<<endl;
    vec[13];
}


void miniVectorTest_pushback_char(){
    miniVector<char> vec;
    vec[1];
    vec.push_back('h');
    vec.push_back('a');    
    vec.push_back('p');    
    vec.push_back('p');
    vec.push_back('y');    
    vec.print_info();
    cout<<"DEBUG: vec[2] " <<vec[2]<<endl;

}
void miniVectorTest_insert()
{
    miniVector<int> vec(5,2);
    vec.insert(0,1);
    vec.print_info();
    vec.insert(8,1);

}


void miniVectorTest_popback(){
    miniVector<int> vec;
    vec.pop_back();
    miniVector<int> vec1(2,3);
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

}


void miniVectorTest_copy(){
    miniVector<int> vec(2,3);
    miniVector<int> vec1(vec);
    cout<<"LOG: vec1[1] "<<vec1[1]<<endl;
    miniVector<int> vec2 = vec1;
}

void miniVectorTest_copyoperator(){
    miniVector<int> vec(2,3);
    miniVector<int> vec1;
    miniVector<int> vec2;
    vec2=vec1 = vec;
    cout<<"LOG: vec1[1] "<<vec1[1]<<endl;
    cout<<"LOG: vec2[1] "<<vec2[1]<<endl;
   
}
int main(){

    miniVectorTest_copyoperator();
    

}