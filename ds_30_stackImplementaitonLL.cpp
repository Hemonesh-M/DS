#include<iostream>
using namespace std;
#define n 7
class stackLL{
    public:
    int value;
    stackLL *next;
    stackLL(int value){
        this->value=value;
        next=NULL;
    }
};
int curr_size=0;
void push(stackLL *&top,int value){
        stackLL *node=new stackLL(value);
        if(node==NULL){
            cout<<"OVERFLOW\n";
            return ;
        }
        else if(curr_size>=n){
            cout<<"OVERFLOW stackLL ALREADY HAS 7 MEMBERS\n";
            return ;
        }
        node->next=top;
        top=node;
        curr_size++;
}
void pop(stackLL *&top){
        if(top==NULL){
            cout<<"UNDERFLOW\n";
            return;
        }
        stackLL* todelete=top;
        cout<<"VALUE POPPED IS:"<<top->value<<endl;
        top=top->next;
        delete(todelete);
        curr_size--;
}
void printtop(stackLL *top){
        if(top==NULL){
            cout<<"UNDERFLOW\n";
            return;
        }
        cout<<"VALUE AT TOP IS:"<<top->value<<endl;
    }
void display(stackLL *top){
        if(top==NULL){
            cout<<"UNDERFLOW\n";
            return;
        }
        while(top!=NULL){
            cout<<top->value<<"\n";
            top=top->next;
        }cout<<endl;
}
bool empty(stackLL *top){
        return(top==NULL);
    }
int main(){
    stackLL *top=NULL;
    push(top,1);
    push(top,2);
    push(top,3);
    push(top,4);
    display(top);
    pop(top);
    display(top);
    printtop(top);
    cout<<"NUMBER OF ELEMENT LEFT IN STACK:"<<curr_size;
}