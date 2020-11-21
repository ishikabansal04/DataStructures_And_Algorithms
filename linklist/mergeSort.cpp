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

    LinkedList* MergeTwoSortedLinklist(LinkedList l1, LinkedList l2)
{
    LinkedList *output_ll = new LinkedList();
    Node *head1 = l1.head;
    Node *head2 = l2.head;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            output_ll->addLast(head1->data);
            head1 = head1->next;
        }
        else
        {
            output_ll->addLast(head2->data);
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
    {
        while (head2 != NULL)
        {
            output_ll->addLast(head2->data);
            head2 = head2-> next;
        }
    }
    else
    {
        while (head1 != NULL)
        {
            output_ll->addLast(head1->data);
            head1 = head1-> next;
        }
    }
    return output_ll;
}

    Node* getMid(Node* head, Node* tail){
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

    LinkedList MergeSort(Node* head, Node* tail){
        if(head==tail){
            LinkedList l;
            l.addLast(head->data);
            return l;
        }
        // Node* mid=getMid(head, tail);
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=tail && fast!=NULL && fast!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* mid=slow;
        LinkedList left= MergeSort(head, mid);
        LinkedList right=MergeSort(mid->next, tail);
        // cout<<left.head->data<<"    "<<right.head->data<<endl;
        // left.display();
        // right.display();
        LinkedList *merged= MergeTwoSortedLinklist(left,right);
        // merged.display();
        return *merged;
    }


   int main(){
       LinkedList obj1;
       int size1,size2;
       cin>>size1;
       for(int i=0;i<size1;i++){
           int val;
           cin>>val;
           obj1.addLast(val);
       }
        LinkedList merged = MergeSort(obj1.head, obj1.tail);
        merged.display();
        
        obj1.display();
        

       return 0;
   }
