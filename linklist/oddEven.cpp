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

      if (head == NULL) {
        head = temp;
        tail = temp;
      } 
      else {
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

    LinkedList oddEven(LinkedList l1){
        LinkedList odd;
        LinkedList even;
        Node* ptr=l1.head;
        LinkedList l;
        Node* even_head=NULL;
        Node* odd_head=NULL;
        while(ptr!=NULL){
                if(ptr->data %2 ==0){
                    even.addLast(ptr->data);
                    ptr=ptr->next;
                }
                else{
                    odd.addLast(ptr->data);
                    ptr=ptr->next;
                }
        }
       
        if(odd.tail!=NULL){
          odd.tail->next=even.head;
          l.head=odd.head;

          if(even.tail!=NULL){
            l.tail=even.tail;
          }
          else{
            l.tail=odd.tail;
          }
          l.size=odd.size+even.size;
        }
        else{
          l.head=even.head;
          l.tail=even.tail;
          l.size=odd.size+even.size;
        }
        return l;

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
       obj1.display();
       obj1= oddEven(obj1);
       obj1.display();

       int val1,val2;
       cin>>val1;
       obj1.addFirst(val1);
       cin>>val2;
       obj1.addLast(val2);
       obj1.display();
       return 0;
   }
