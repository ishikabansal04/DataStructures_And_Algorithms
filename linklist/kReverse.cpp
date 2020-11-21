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
    
  };

    LinkedList reversePI(Node* head, int k){
        LinkedList original;
        LinkedList l;
        Node* p=head;
        Node* q=head;
        Node* tail=NULL;
        Node* r=NULL;
        while(q!=NULL && k>0){
            original.addLast(q->data);
            q=p->next;
            p->next=r;
            if(r==NULL){
                l.tail=p;
            }
            r=p;
            p=q;
            k--;
        }
        if(k==0 && q!=NULL){
            l.tail->next=q;
        }
        else if(k!=0){
            return original;
        }
        l.head=r;
        l.size=k;
        return l;
    }


    LinkedList kReverse(LinkedList l1, int k){
        LinkedList l, f;
        Node* prevptr=NULL;
        Node* ptr=l1.head;
        Node* temp_head=l1.head;
        Node* temp_tail=NULL;
        while(ptr!=NULL){
            l= reversePI(ptr, k);
            if(prevptr ==NULL){
                f.head=l.head;
                f.tail=l.tail;
                f.size=l.size;
                prevptr=l.tail;
            }
            else{
                f.tail->next=l.head;
                prevptr->next=l.head;
                f.tail=l.tail;
                prevptr= l.tail;
            }
            ptr=l.tail->next;
        }
        f.size=l1.size;
        return f;
    }


   int main(){
       LinkedList obj1;
       int size1;
       cin>>size1;
       for(int i=0;i<size1;i++){
           int val;
           cin>>val;
           obj1.addLast(val);
       }
       int k;
       cin>>k;
       obj1.display();
       obj1= kReverse(obj1, k);
       obj1.display();

       int val1,val2;
       cin>>val1;
       obj1.addFirst(val1);
       cin>>val2;
       obj1.addLast(val2);
       obj1.display();
       return 0;
   }
