#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;


struct Node{
    int value ;
    Node *link;

    Node(){
        value = 0;
        link = nullptr;
    }

    Node(int value){
        this->value = value;
        link = nullptr;
    }

    bool Is_empty(){
        return (link == nullptr);
    }

    void push(int value){
        Node *new_node = new Node(value);
        if(Is_empty()){
            link = new_node;
        } else {
            new_node->link = link;
            link = new_node;
            cout<<"successfully pushed "<< value <<endl;   
        }
    }

    int pop(){
        if(Is_empty()){
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            int pop_element = link->value;
            Node *top = link;
            link = link->link;
            return pop_element;
            cout<< "successfully popped "<< pop_element <<endl;
        }
    }

    void display(){
        cout << "Stack elements: ";
        if(Is_empty()){
            cout << "Stack is empty." << endl;
        } else {
            cout << "top>>";
            Node *top = link;
            while(top != nullptr){
                cout << top->value << " ";
                top = top->link;
            }
            cout << endl;
        }
    }
};

int main(){
    auto startTime = chrono::high_resolution_clock::now();
    Node* stack1 = new Node();
    stack1->push(8);
    stack1->push(10);
    stack1->push(5);
    stack1->push(11);
    stack1->push(15);
    stack1->push(23);
    stack1->push(6);
    stack1->push(18);
    stack1->push(20);
    stack1->push(17);
    stack1->display();
    stack1->pop();
    stack1->pop();
    stack1->pop();
    stack1->pop();
    stack1->pop();
    stack1->display();
    stack1->push(4);
    stack1->push(30);
    stack1->push(3);
    stack1->push(1);
    stack1->display();

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    
    cout << "time taken for operation in stack array using linked list " << duration << " microseconds"<< endl;
}