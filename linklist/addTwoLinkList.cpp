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

    int addtwolistHelper(Node* ptr1, int p1, Node* ptr2, int p2, LinkedList ans){
        if(p1==0 && p2==0){
            return 0;
        }
        int carry=0;
        if(p1>p2){
            carry=addtwolistHelper(ptr1->next, p1-1, ptr2, p2,ans);
            carry=carry+ptr1->data;
            // cout<<carry<<endl;
            ans.addFirst(carry%10);
            // cout<<ans.head->data;
            carry=carry/10;
        }
        else if(p2>p1){
            carry=addtwolistHelper(ptr1, p1, ptr2->next, p2-1, ans);
            carry=carry+ptr2->data;
            // cout<<carry<<endl;
            ans.addFirst(carry%10);
            // cout<<ans.head->data;
            carry=carry/10;
        }
        else{
            carry=addtwolistHelper(ptr1->next, p1-1, ptr2->next, p2-1, ans);
            carry=carry+ptr2->data+ ptr1->data;
            // cout<<carry<<endl;
            ans.addFirst(carry%10);
            // cout<<ans.head->data;
            carry=carry/10;
        }
        return carry;
    }

    LinkedList AddTwoLinkList(LinkedList l1, LinkedList l2){
        LinkedList obj;
        int carry= addtwolistHelper(l1.head, l1.size, l2.head, l2.size, obj);
        obj.display();
        while(carry){
            obj.addFirst(carry%10);
            carry=carry/10;
        }
        return obj;
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

        LinkedList merged= AddTwoLinkList(obj1, obj2);
        merged.display();
        
        // obj1.display();
        // obj2.display();

       return 0;
   }
