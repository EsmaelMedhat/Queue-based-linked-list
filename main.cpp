#include <iostream>
using namespace std;
template<class type>
class Node
{
  public:
  Node():link(NULL){};
  void set_data(type data){this->data=data;}
  void set_link(Node*link){this->link=link;}
  Node* get_link(){return link;}
  type get_data(){return data;}
 private:
 type data;
 Node*link;
};
template<class type>
class Queue{
private:
Node<type>*front;
Node<type>*rear;
int size;
public:
Queue(){
front=rear=nullptr;
size=0;
}
bool isempty()  //o(1)
{
return front==NULL;
}
void enque(type new_item)  //o(N)
{
Node<type>*newnode=new Node<type>;
newnode->set_data(new_item);
if(isempty())
front=rear=newnode;
else{
rear->set_link(newnode);
rear=newnode;
}
size++;
}
void deque()  //o(N)
{
if(isempty())
cout<<"Queue is empty";
else if(front==rear){
 Node<type>*newnode=front;
 delete newnode;
 front =rear=NULL;
size--;
}
else{
    Node<type>*newnode=front;
    front=front->get_link();
    delete newnode;
size--;
}
}
type peek()  //o(1)
{
return front->get_data();}
type getrear()  //o(1);
{
return rear->get_data();
}
int count()  //o(1)
{
return size;
}
void clear()  //o(N)
{
while(!isempty()){
  deque();
}
}
bool isfind(type item)  //o(N)
{
Node<type>*temp=front;
while(temp!=NULL){
if(item==temp->get_data())
return true;
temp=temp->get_link();
}
return false;
}
void display()  //o(N)
{
if(isempty())
cout<<"Queue is empty\n";
else{
int number=1;
Node<type>*temp=front;
cout<<"------------- all element --------------\n";
while(temp!=NULL){

cout<<"Item "<<number<<" : "<<temp->get_data()<<endl;
temp=temp->get_link();
number++;
}
}
}
};
int main(){
Queue<int>m;m.enque(100);
m.enque(1010);m.enque(1002);m.enque(101);m.enque(10);
m.deque();
m.display();
cout<<m.count()<<endl;
return 0;
}
