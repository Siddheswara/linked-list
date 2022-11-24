#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
}*first;
void create(int a[],int n){
    node *last,*t;
    first=new node;
    first->data=a[0];
    first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=a[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}
void insert(node *p,int pos,int x){
   node *t; 
    t=new node;
        t->data=x;
        if(pos==0){
        
        t->next=first;
        first=t;
    }
    else if(pos>0){
        
        for(int i=0;i<pos-1&&p;i++){
            p=p->next;
        }
        if(p){
        t->next=p->next;
        p->next=t;}
        
        
    }
}

void display(node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
        
    }
    cout<<endl;
}
void insertSorted(node *p,int x){
    node *t,*q=nullptr;
    t=new node;
    t->data=x;
    t->next=nullptr;
    if(first==nullptr){
        first=t;
    }
    else{
        while(p&&p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
            
        }
        else{
            t->next=q->next;
            q->next=t;
        }
            
        }
    }
int  deletenode(node *p, int pos){
   node *q=nullptr;
   int x;
   
   if(pos==1){
       first=p->next;
      x=p->data;
      delete p;
   }
   else{
       for(int i=0;i<pos-1;i++){
           q=p;
           p=p->next;
       }
       q->next=p->next;
       x=p->data;
       delete p;
   }
   return x;
} 
int isSorted(node *p){
    int x=-100;
    while(p){
        if(x<p->data){
            x=p->data;
            p=p->next;
        }
        else return 0;
    }
    return 1;
}
void removeDup(node *p){
    node*q=p->next;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
void reverseElements(node *p, int n){
 int a[n],i=0;
 while(p){
   a[i]=p->data;
   i++;
   p=p->next;
 }
 p=first;
 i--;
 while(p){
     p->data=a[i--];
     p=p->next;
     
 }
}
void reverseLinks(node *p){
  node  *q=nullptr;
    node  *r=nullptr;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }first=q;
}
void reverse(node *q,node *p){
    if(p!=NULL){
        reverse(p,p->next);
        p->next=q;
    }
    else first=q;
}
int main()
{
 
 int a[]={10,20,30,40,50,60,70,80,90,100};
 create(a,10);
 create(a,10);
 display(first);
cout<<endl;
 display(second);
 


    return 0;
}