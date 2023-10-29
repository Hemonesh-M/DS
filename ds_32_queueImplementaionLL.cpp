#include<iostream>
#define n 7
using namespace std;
int curr_size=0;
class queue{
    public:
    int value;
    queue *next;
    queue(int value){
        this->value=value;
        next=NULL;
    }
};
void enqueue(queue *&front,queue*&back,int value){
        queue *node=new queue(value);
        if(node==NULL){
            cout<<"OVERFLOW\n";
            return;
        }
        else if(curr_size>=n){
            cout<<"OVERFLOW\n";
            return;
        }
        curr_size++;
        if(front==NULL){
            back=node;
            front=node;
            return;
        }
        back->next=node;
        back=node;
        
    }
    void dequeue(queue *&front,queue *&back){
        if(front==NULL){
            cout<<"UNDERFLOW\n";
            return;
        }
        queue *todelete=front;
        cout<<"ELEMENT DELETED:"<<front->value<<endl;
        front=front->next;
        delete(todelete);
        curr_size--;
    }
    void display(queue *front){
        if(front==NULL){
            cout<<"NO ITEM TO DISPLAY\n";
            return;
        }
        while(front!=NULL){
            cout<<front->value<<" ";
            front=front->next;
        }cout<<endl;
    }
    void printFront(queue *front){
        if(front==NULL){
            cout<<"QUEUE IS EMPTY\n";
            return;
        }
        cout<<"ELEMENT IN FRONT IS:"<<front->value<<endl;
    }
int main(){
    queue *front=NULL;
    queue *back=NULL;
    enqueue(front,back,1);
    enqueue(front,back,2);
    cout<<"QUEUE LOOKS LIKE:\n";
    display(front);
    dequeue(front,back);
    dequeue(front,back);
    dequeue(front,back);
}