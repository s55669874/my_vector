/*
     自製vector
     完成：
     push_back
     自動擴大容量
     back
     size
     pop_back
*/

#include <iostream>
using namespace std;

template <typename Object> //宣告一個型態object


class my_vector{
private:
     int v_size;
     int v_msize; //先假設他的大小為某數字
     Object* object;
public:
     my_vector() : v_size(0), v_msize(5)
     {
          object = new Object[5];
     }
     explicit my_vector(int vmsize) : v_msize(vmsize), v_size(0)
     {
          object = new Object[vmsize];
     }
     ~my_vector() { delete[] object; }

     void expanse(int new_size){
          if(v_msize < new_size){
               Object *temp = new Object[new_size];
               for(int i = 0 ; i < v_msize ; i++){
                    temp[i] = object[i];
               }
               v_msize = new_size;
               object = temp;
               //delete[] temp;
          }
     }

     int size(){
          return v_size;
     }

     void push_back(Object val){
          if(v_size == v_msize){//到最大直了，要擴張
               expanse(v_msize * 2 + 1);
          }
          object[v_size] = val;
          v_size++;
     }

     int back(){
          if(v_size) return object[v_size-1];
     }

     void pop_back(){
          if(v_size) v_size--;
     }
};

int main(){
     my_vector<int> test;
     for(int i = 0 ; i < 6 ; i++){
          test.push_back(i);
          cout << "now number: " << i << " now size : " << test.size() << endl;
     }
     cout << "now last num: " << test.back() << endl;
     test.pop_back();
     cout << "after pop_back now last num: " << test.back() << endl;
     return 0;
}
