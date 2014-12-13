#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class node {
    public:
        node();
        void insert();
        void insert_arr();
        void print();
        void del();
        void locate();
    private:
        int value;
        node *next;
        node *head;
};

node::node() {
    head = 0;
}
void node::insert() {
    node *temp = new node;
    int a;
    cout<<"Enter value to be stored: ";
    cin>>temp->value;
    cout<<"\nChoose position:\n1. At beginning\n2. At end\n3. After a value\nEnter choice number here: ";
    cin>>a;
    if(a==1) {
        temp->next = head;
        head = temp;
        cout<<"Value "<<temp->value<<" inserted at the beginning successfully!\n";
    }
    else if(a==2) {
        node *ptr = head;
        if(ptr != 0) {
            while(ptr->next != 0) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        else {
            head = temp;
        }
        temp->next = 0;
        cout<<"Value "<<temp->value<<" inserted at the end successfully!\n";
    }
    else if(a==3) {
        int x;
        node *ptr = head;
        cout<<"Enter value after which node has to be inserted: ";
        cin>>x;
        while (ptr->next != 0 && ptr->value != x) {
            ptr = ptr->next;
        }
        if(ptr->next == 0 && ptr->value != x)
            cout<<"Sorry, Element not found!\n";
        else {
            temp->next = ptr->next;
            ptr->next = temp;
            cout<<"Value "<<temp->value<<" inserted successfully!\n";
        }
    }
    else {
        cout<<"Make a valid choice next time!\n\n";
    }

}

void node::insert_arr() {
    node *temp = new node;
    cout<<"Enter number of values you want to insert: ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" values in a single line, separated by a space: ";
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
}

void node::print() {
    node *h = head;
    while (h!= 0) {
        cout<<h->value<<"\t";
        h = h->next;
    }
    cout<<endl;
}

void node::del() {
    int a;
    cout<<"Enter value to delete: ";
    cin>>a;
    node *t = head;
    while(t->next->value != a || t->next !=0) {
        t = t->next;
    }
    if(t->next == 0)
        cout<<"Element not found!\n";
    else {
        node *temp = t->next;
        t->next = temp->next;
        delete temp;
    }
}

void node::locate() {
    cout<<"Enter value to locate: ";
    int a, c=1;
    cin>>a;
    node *t = head;
    if(t == 0)
    {
        cout<<"List is empty!\n";
    }
    else
    {
        while(t->value != a && t->next != 0) {
            c++;
            t = t->next;
        }
        if (t->value == a)
            cout<<"Element present at position "<<c<<endl;
        else
            cout<<"Element not found.\n";
    }
}

int main() {
    node ll;
    int opt;
    while(1) {
        cout << "1. Insert a node\n2. Insert a sequence of numbers\n3. Delete a node\n4. Locate a value\n5. Show all elements\n0. Exit\nEnter here: ";
        cin >> opt;
        switch(opt){
            case 0:
                exit(0);
            case 1:
                ll.insert();
                break;
            case 2:
                ll.insert_arr();
                break;
            case 3:
                ll.del();
                break;
            case 4:
                ll.locate();
                break;
            case 5:
                ll.print();
                break;
            default:
                cout<<"Make a valid choice!"<<endl;
                break;
        }
        cout<<endl;
    }
    return 0;
}
