#include<iostream>
using namespace std;

class DynamicArray{
private:
    int size , capacity ;
    int * arr ;
public:
    DynamicArray(){
        this->size = 0 ;
        this->capacity = 0;
        this->arr = NULL;
    }
    int getSize(){
        return this->size;
    }
    int getCapacity(){
        return this->capacity;
    }
    int get_at_index(int i){
        if (i >= size){
            return -1;
        }else{
            return arr[i];
        }
    };
    void add_at_end(int val){
        if(size == 0){
            int * temp = new int[1];
            size = size + 1;
            temp[0] = val;
            delete[] arr;
            this->arr = temp ;
            capacity = capacity + 1;
        }
        else if(size == capacity){
            capacity = capacity * 2;
            int * temp = new int[capacity];
            for(int i = 0 ; i < size ; i++){
                temp[i] = this->arr[i];
            }
            temp[this->size] = val;
            size = size + 1;
            delete[] arr;
            this->arr = temp;
        }else{
            this->arr[size] = val;
            size++;
        }
    }
    void insert_at_i(int index, int val){
        if(index == size){
            add_at_end(val);
        }
        else if(size == capacity){
            capacity = capacity * 2;
            int * temp = new int[capacity];
            for(int i = 0 ; i < index ; ++i){
                temp[i] = arr[i];
            }
            temp[index] = val;
            for(int i = index + 1 ; i <= size ; ++i){
                temp[i] = arr[i-1];
            }
            delete[] arr;
            arr = temp ;
            size = size + 1 ;
        }else{
            int * temp = new int[capacity];
            for(int i = 0 ; i < index ; ++i){
                temp[i] = arr[i];
            }
            temp[index] = val;
            for(int i = index + 1 ; i <= size ; ++i){
                temp[i] = arr[i-1];
            }
            delete[] arr;
            arr = temp ;
            size = size + 1 ;
        }
    }
    void delete_at(int index){
        if(index >= size){
            cout<<"Index Out Of Bound"<<endl;
            return ;
        }
        int * temp = new int[size];
        for(int i = 0 ; i < index ; ++i){
            temp[i] = arr[i];
        }
        for(int i = index + 1; i < size ; ++i){
            temp[i-1] = arr[i];
        }
        delete[] arr;
        arr = temp ;
        size = size -1 ;
    }
};