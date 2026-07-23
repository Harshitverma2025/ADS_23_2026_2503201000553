#include <iostream>
using namespace std;

const int MAX=10;
int stack[MAX];
int top=-1;

bool isEmpty(){
  return (top==-1);
}

bool isFull(){
  return (top==MAX-1);
}

void push(int value){
  if(top==MAX-1){
    cout<<"overflaw\n";
  }
  else{
    top++;
    stack[top]=value;
    cout<<value<<" pushed into the stack\n";
  }
}

void pop(){
  if(isEmpty()){
    cout<<"underflaw";
  }
  else{
    cout<<stack[top]<<" poped from the stack\n";
    top--;
  }
}

int main (){
  isEmpty();
  isFull();
  push(2);
  pop();
  return 0;
}