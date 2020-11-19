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


      Node* getNodeAt(int idx) {
            if (size == 0) {
              cout<<"List is empty"<<endl;
              return NULL;
            } else if (idx < 0 || idx >= size) {
              cout<<"Invalid arguments"<<endl;
              return NULL;
            } else {
              Node* temp = head;
              for (int i = 0; i < idx; i++) {
                temp = temp->next;
              }
              return temp;
            }
          }


    void reverseDI(){
      for(int i=0;i<(size/2);i++){
        Node* one=getNodeAt(i);
        Node* two=getNodeAt(size-i-1);
        int temp=one->data;
        one->data=two->data;
        two->data=temp;
      }
    }
  };

   int main(){
       LinkedList obj;
       string str;
    do{
        cin>>str;
        if(str=="addFirst"){
            int val;
            cin>>val;
            obj.addFirst(val);
            
        }
        
        else if(str=="addLast"){
            int val;
            cin>>val;
            obj.addLast(val);
        }
        else if(str=="addAt"){
            int idx,val;
            cin>>idx>>val;
            obj.addAt(idx,val);
        }
        else if(str=="removeFirst"){
            obj.removeFirst();
        }
        else if(str=="removeLast"){
            obj.removeLast();
        }
        else if(str=="removeAt"){
            int idx;
            cin>>idx;
            obj.removeAt(idx);
        }
        else if(str=="size"){
            cout<<obj.sizeofList()<<endl;
        }
        else if(str=="display"){
            obj.display();
        }
        else if(str=="getAt"){
            int idx;
            cin>>idx;
            cout<<obj.getAt(idx)<<endl;
        }
        else if(str=="getFirst"){
            cout<<obj.getFirst()<<endl;
        }
        else if(str=="getLast"){
            cout<<obj.getLast()<<endl;
        }
        else if(str=="reverseDI"){
            obj.reverseDI();
        }
    }while(str!="quit");
       return 0;
   }
