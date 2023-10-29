#include <iostream>
using namespace std;
class Queue
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    Queue(int capacity)
    {
        size = capacity;
        arr = new int[size];
        front = rear = -1;
    }
    void push(int val)
    {
        if (rear == size - 1)
        {
            cout << "queue is full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void pop()
    {
        if (front == -1 && rear == -1)
        {   cout<<"UNDERFLOW";
            return;
        }
        int val = arr[front];
        cout<<"VALUE POPPED:"<<arr[front]<<endl;
        if (front == rear)
        {   
            front = rear = -1;
        }
        else
        {
            
            front++;
        }
        return ;
    }
    void peek()
    {
        if (front == -1 && rear == -1)
        {   cout<<"UNDERFLOW";
            return ;
        }
        cout<<"PEEK ELEMENT IS:"
            <<arr[front]<<endl;
    }
    void display(){
        cout<<"QUEUE LOOKS LIKE:\n";
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    bool empty()
    {
        return front == -1 && rear == -1;
    }
};
int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.display();
    q.pop();
    q.display();
    q.peek();
    
}
