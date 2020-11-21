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


    Node* pointerRecursiveHelper(Node* left, Node* right){
        if(right==tail) return right;
        // cout<<right->data<<endl;
        Node* temp= pointerRecursiveHelper(left, right->next);
        
        if(right->next==tail){
          head=temp;
        }
        temp->next=right;
        // cout<<temp->data<<"   "<<temp->next->data<<endl;
        if(right==left){
          tail=right;
          right->next=NULL;
        }
        // cout<<right->data<<endl;
        return right;
    }

    LinkedList pointerRecursive(){
      LinkedList l;
      l.head=tail;
        Node* temp=pointerRecursiveHelper(head, head);
        // cout<<temp->data<<endl;
        l.tail=temp;
        l.size=size;
        return l;
    }


Node* reversePRHelper(Node *head){
    if(head == NULL || head-> next == NULL){
        return head;
    }// * 1 2 3 4 5            (head1)5 4 3 2 1-> NULL
    Node *head1 = reversePRHelper(head-> next);
    Node *tail = head-> next;
    tail-> next = head;
    head-> next = NULL;
    return head1;
}

public:

void reversePR(){
    Node *head1 = reversePRHelper(head);
    Node *temp = head1;
    tail= head;
    head=temp;
    while(temp != NULL){
        cout << temp-> data << ' ';
        temp=temp->next;
    }
    cout << '\n';
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
      //  obj= obj.pointerRecursive();
      obj.reversePR();
       obj.display();
       cout<<obj.head->data<<"  "<<obj.tail->data<<endl;
       int val1,val2;
       cin>>val1>>val2;
       obj.addLast(val1);
       obj.addFirst(val2);

       obj.display();
       return 0;
   }
