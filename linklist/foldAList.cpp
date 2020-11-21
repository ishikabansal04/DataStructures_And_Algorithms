#include<iostream>
#include<string>
using namespace std;

    class Node {
        public:
        int data;
        Node* next;
        Node(){
        }
    };

    class LinkedList {
        public:
        Node* head=NULL;
        Node* tail=NULL;
        int size=0;

    void addLast(int val) {
      Node* temp = new Node();
      temp->data = val;
      temp->next = NULL;

      if (size == 0) {
        head = temp;
        tail = temp;
      } else {
        tail->next = temp;
        tail = temp;
      }

      size++;
    }

    int sizeofList(){
      return size;
    }

    void display() {
      for (Node* temp = head; temp != NULL; temp = temp->next) {
        cout<<temp->data<<" ";
      }
      cout<<endl;
    }

    void removeFirst() {
      if (size == 0) {
        cout<<"List is empty"<<endl;
      } else if (size == 1) {
        head = tail = NULL;
        size = 0;
      } else {
        head = head->next;
        size--;
      }
    }

     int getFirst() {
      if (size == 0) {
        cout<<"List is empty"<<endl;
        return -1;
      } else {
        return head->data;
      }
    }

     int getLast() {
      if (size == 0) {
        cout<<"List is empty"<<endl;
        return -1;
      } else {
        return tail->data;
      }
    }

     int getAt(int idx) {
      if (size == 0) {
        cout<<"List is empty"<<endl;
        return -1;
      } else if (idx < 0 || idx >= size) {
        cout<<"Invalid arguments"<<endl;
        return -1;
      } else {
        Node* temp = head;
        for (int i = 0; i < idx; i++) {
          temp = temp->next;
        }
        return temp->data;
      }
    }

     void addFirst(int val) {
      Node* temp = new Node();
      temp->data = val;
      temp->next = head;
      head = temp;

      if (size == 0) {
        tail = temp;
      }

      size++;
    }

     void addAt(int idx, int val) {
      if (idx < 0 || idx > size) {
        cout<<"Invalid arguments"<<endl;
      } else if (idx == 0) {
        addFirst(val);
      } else if (idx == size) {
        addLast(val);
      } else {
        Node* node = new Node();
        node->data = val;

        Node* temp = head;
        for (int i = 0; i < idx - 1; i++) {
          temp = temp->next;
        }
        node->next = temp->next;

        temp->next = node;
        size++;
      }
    }

     void removeLast() {
      if (size == 0) {
        cout<<"List is empty"<<endl;
      } else if (size == 1) {
        head = tail = NULL;
        size = 0;
      } else {
        Node* temp = head;
        for (int i = 0; i < size - 2; i++) {
          temp = temp->next;
        }

        tail = temp;
        tail->next = NULL;
        size--;
      }
    }


     void removeAt(int idx) {
      // write your code here
      if(head==NULL){
          cout<<"List is empty"<<endl;
          return;
      }
      if(idx==0){
          removeFirst();
      }
      else if(idx>size-1){
          cout<<"Invalid arguments"<<endl;
          return;
      }
      else if(idx==size-1){
          removeLast();
      }
      else if(size==1){
          head=NULL;
          tail=NULL;
          size=0;
      }
      else{
          Node* temp=head;
          Node* prev=NULL;
          while(temp!=NULL && idx>0){
              prev=temp;
              temp=temp->next;
              idx--;
          }
          prev->next=temp->next;
          temp->next=NULL;
          size--;
      } 
    }


    Node* getMid(){
        if(head == NULL){
            return NULL;
        }
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=tail && fast!=NULL && fast!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    LinkedList reversePI(Node* head,Node* tail){
        LinkedList l;
        Node* p=head;
        Node* q=head;
        Node* r=NULL;
        while(q!=NULL){
            q=p->next;
            p->next=r;
            if(r==NULL){
                l.tail=p;
            }
            r=p;
            p=q;
        }
        l.head=r;
        return l;
    }

    void fold(){
        Node* tail1=getMid();
        Node* head2=tail1->next;
        tail1->next=NULL;
        Node* head1=head;
        Node* tail2=tail;
        LinkedList l;
        l= reversePI(head2, tail2);
        head2=l.head;
        tail2=l.tail;
        while(head1!=NULL && head2!=NULL){
            Node* temp1=head1->next;
            head1->next=head2;
            Node* temp2=head2->next;
            head2->next=temp1;
            head1=temp1;
            head2=temp2;
        }
        if(head1==NULL){
            tail=tail2;
        }
        else{
            tail=head1;
        }
    }

  };

   int main(){
       LinkedList obj;
       int size;
       cin>>size;
       for(int i=0;i<size;i++){
           int val;
           cin >>val;
           obj.addLast(val);
       }
       obj.display();
       obj.fold();
       obj.display();
       int val1,val2;
       cin>>val1>>val2;
       obj.addFirst(val1);
       obj.addLast(val2);
       obj.display();
   }
