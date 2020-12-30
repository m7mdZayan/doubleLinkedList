#include <iostream>
#include <string.h>

using namespace std;

struct node{
    int id;
    char name[30];
    node * prev;
    node * next;
};

class LinkedList{
node * head;
node * tail;
public:
    LinkedList(){
    head = tail = NULL;
    }
    void append(int id,char name[]){

    node * temp = new node();

    temp->id = id;
    strcpy(temp->name , name);

    if( head == NULL ){
        head = tail = temp;
        temp->next = temp->prev = NULL;
    }
    else{
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail= temp;
        }
    }

    void display(){

    node* temp = head;

    while( temp != NULL ){
        cout << temp->id << " : " << temp->name <<endl;
        temp = temp->next;
    }


    }

    int getCount(){
    int c =0 ;
    node * temp = head;

    while( temp != NULL ){

        c++;
    temp = temp->next;
    }
    return c;
    }

    node* searchById( int id){
    node * temp = head;

    while( temp != NULL ){
        if ( temp->id == id ) return temp;

        temp = temp->next;
    }
    return NULL;

    }


    void deleteById( int id ){

    node * temp = searchById(id);

    if ( temp== NULL ){
            return;
    }
    else if (head == tail){
        head = tail = NULL;
        delete temp;
    }
    else if (temp == head ){
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }
    else if ( temp == tail ){
        tail = temp->prev;
        tail->next = NULL;
        delete temp;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    }


    ~LinkedList(){
    delete head;
    delete tail;

    cout << "destructor" << endl;
    }
    };


int main()
{
    LinkedList myList;
    myList.append(1,"Mohamed");
    myList.append(2,"Sara");
    myList.append(3,"Ahmed");
    myList.append(4,"Nada");
    myList.append(5,"Adam");

    node* ptr = myList.searchById(2);

     myList.display();
     cout << "this list has " << myList.getCount() << " elements" << endl;;

     cout << ptr->name << endl;
     myList.deleteById(5);
     myList.display();



    return 0;
}
