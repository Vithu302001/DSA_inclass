#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;



class Stack_array{
    int* Array;
    int Top_index ;
    int size;

public:
    Stack_array(int size){
        this->Array = new int[size];
        this->Top_index = -1;
        this->size = size;
    }
    bool Is_empty(){
        if (Top_index<0){
            return true;
            cout<<"empty"<<endl;
        }else{
            return false;
        }
    }

    bool Is_full(){
        if (Top_index == size-1){
            return true;
            cout <<"full"<<endl;
        }else{
            return false;
        }
    }

    void push(int element){
        if(Top_index < size -1 ){  
            Top_index++; 
            Array[Top_index] = element; 
            cout<<"successfully pushed "<< element <<endl;         
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop(){
        if(Top_index >= 0){
            int pop_element = Array[Top_index];
            Top_index--;
            return pop_element;
            cout<< "successfully popped "<< pop_element <<endl;
        } else {
            cout << "Stack underflow" << endl;
            return -1; 
        }
    }

    void display(){
        cout << "Stack elements: ";
        if(Top_index >= 0){
            for(int i = 0; i <=Top_index; i++){
                cout << Array[i] << " ";
            }
            cout << endl;
        } else {
            cout << "empty stack" << endl;
        }
    }
};

int main(){
    int inp_size;
    cout << "Input the size of array to create: " ;
    cin >> inp_size;
    cout<<endl;

    auto startTime = chrono::high_resolution_clock::now();

    Stack_array stack1(inp_size);
    stack1.push(8);
    stack1.push(10);
    stack1.push(5);
    stack1.push(11);
    stack1.push(15);
    stack1.push(23);
    stack1.push(6);
    stack1.push(18);
    stack1.push(20);
    stack1.push(17);
    stack1.display();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.display();
    stack1.push(4);
    stack1.push(30);
    stack1.push(3);
    stack1.push(1);
    stack1.display();

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    
    cout << "time taken for operation in stack using array " << duration << " microseconds"<< endl;


}
