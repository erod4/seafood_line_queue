

# include<iostream>
#include <stdlib.h>
# include "line.h"

using namespace std;

Line::Line()//constructor
{
  //sets front/rear node to null
  front = nullptr;
  rear = nullptr;
  
}

Line::~Line()//destructor
{
  //calls clear func to delete queue contents
  clear();
}
void Line::enqueue(string name)
{
  //validates for string size
  if(name.size()>20||name.size()<0)
  {
    exit(EXIT_FAILURE);
  }
  QueueNode *newNode=nullptr;

  //create new node and store name
  newNode=new QueueNode;
  newNode->value=name;
  newNode->ticket=rand() % 500 +1;//random ticket number between 1-500
  newNode->next=nullptr;
  
  if(isEmpty())//if no nodes in queue then front and rear node are the same new node
  {
    cout<<"\n\nWelcome "<<newNode->value<<" your raffle number is "<<newNode->ticket<<endl;
    front = newNode;
    rear = newNode;
  }
  else//otherwise adds new node to end of queue
  {
   cout<<"\n\nWelcome "<<newNode->value<<" your raffle number is "<<newNode->ticket<<endl;
   rear->next=newNode;
   rear=newNode;
  }

  
}

void Line::dequeue()
{
  QueueNode *temp=nullptr;
  //validates for queue being empty
  if(isEmpty())
  {
    cout<<"\nPlease Add People to the Line.\n";
  }
    //if string isn't empty then pushes first person in line to order
  else
  {
   string name=front->value;//stores name of node being deleted
   
    temp=front;
    front=front->next;
    delete temp;
   cout<<"\n\nThank you for your patience, "<<name<<". We are ready for you to order.\n";
  //delete node
    
  }
}

bool Line::isEmpty() const
{
  bool status;
  //is empty returns false if there are nodes in queue and true if there are no nodes
  if(numNodes()>0)
  {
    status=false;
    
  }
  else
  {
    status=true;
  }
  return status;
}

void Line::clear()
{
  //deletes nodes of queue while nodes exist;
  while(!isEmpty())
    {
      dequeue();
    }
}

int Line::sizeOf(QueueNode *nodePtr) const//size of line 
{
  if(nodePtr!=nullptr)//utilizes recursion to get size of nodes
  {
    //adds 1 to the size of the nodes until end of nodes is reached
    return 1+sizeOf(nodePtr->next);
    
  }
  else
  {
    //if no nodes will return 0
    return 0;
  }
}

int Line::numNodes() const
{
  //return size of queue in order to use in main.cpp
  int size=sizeOf(front);
  return size;
}

void Line::qContents() const
{
  //if no nodes can't display customers
    if (front==nullptr)
    {
        cout << "\nThere are currently no customers in line.\n\n";
    }
    //iterates through queue and displays line order, name, raffle ticket
    else
    {
      int loc=1;
        QueueNode *nodePtr = front;
        while (nodePtr != nullptr)
        {
            cout<<"("<<loc<<"). ";
            cout << "Name: " << nodePtr->value << " Ticket: " << nodePtr->ticket << endl;
            nodePtr = nodePtr->next;
            loc++;
        }
    }
}
string Line::raffle(QueueNode* nodePtr, int max) const
{
  //winner is set to none in case there is no winner 
  string winner = "none";
  //chooses a random number between 1-max(500)
  int pick = rand() % max + 1;
  //if list is empty returns no one as winner
  if (nodePtr == nullptr) 
  {
    return winner;
  }
  //if ticket matches with random number return winner's name
  if (nodePtr->ticket == pick) 
  {
    winner = nodePtr->value;
  } 
  //if ticket does not match with random number then recurssion is used to iterate through queue
  else 
  {
    winner = raffle(nodePtr->next, max);
  }
  return winner;
}
void Line::winner() const
{
  string winner = "none";
  while (winner == "none")
  {
    //if there was no winner found then the raffle function is called again which generates a new random raffle pick
    winner = raffle(front, 500);
  }

  cout << "\n\nCongratulations " << winner << " you are today's raffle winner\n";
  cout << "Please, select from the following two prizes\n\n";
 
  int choice=0;
  //user prize menu
  while (choice < 1 || choice > 2)
  {
    
    cout << "1. Free t-shirt\n2. Free side dish\n\nchoice: ";
    cin >> choice;
  }

  switch (choice)
  {
    case 1:
      cout << "Congrats on your new shirt. Please, proceed to counter to redeem price.\n\n";
      break;
    case 2:
      cout << "Congrats on your free side dish. Please, proceed to counter to redeem price.\n\n";
      break;
  }
}


 
