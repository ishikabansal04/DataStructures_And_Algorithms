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

    LinkedList MergeTwoSortedLinklist(LinkedList l1, LinkedList l2){
        Node* ptr1=l1.head;
        Node* ptr2=l2.head;
        LinkedList merged;
        if(l1.size==0) {
          return l2;
        }
        if(l2.size==0){
          return l1;
        }


        Node* l=new Node;
        merged.head = l;
          if(ptr1->data < ptr2->data){
            l->data = ptr1->data;
            ptr1=ptr1->next;
        }
        else{
            l->data =ptr2->data;
            ptr2=ptr2->next;
        }
        
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->data < ptr2->data){
                Node* temp=new Node;
                temp->data=ptr1->data;
                temp->next=NULL;
                l->next=temp;
                ptr1=ptr1->next;
                l=l->next;
            }
            else{
               Node* temp=new Node;
                temp->data=ptr2->data;
                temp->next=NULL;
                l->next=temp;
                ptr2=ptr2->next;
                l=l->next;
            }
        }
        while(ptr1!=NULL){
            Node* temp=new Node;
            temp->data=ptr1->data;
            temp->next=NULL;
            l->next=temp;
            l=l->next;
            ptr1=ptr1->next;
            if(ptr1==NULL){
                merged.tail=l;
            }
        }
        while(ptr2!=NULL){
            Node* temp=new Node;
            temp->data=ptr2->data;
            temp->next=NULL;
            l->next=temp;
            l=l->next;
            ptr2=ptr2->next;
            if(ptr2==NULL){
                merged.tail=l;
            }
        }
        return merged;
    }


   int main(){
       LinkedList obj1, obj2;
       int size1,size2;
       cin>>size1;
       for(int i=0;i<size1;i++){
           int val;
           cin>>val;
           obj1.addLast(val);
       }
       cin>>size2;
       for(int i=0;i<size2;i++){
           int val;
           cin>>val;
           obj2.addLast(val);
       }

        LinkedList merged= MergeTwoSortedLinklist(obj1, obj2);
        merged.display();
        
        obj1.display();
        obj2.display();

       return 0;
   }
