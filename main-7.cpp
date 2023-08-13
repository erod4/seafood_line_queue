
# include "line.h"
#include <iostream>

using namespace std;

//predefined functions
int menu(int &);

void name(Line &);

void order(Line &);

void count(Line &);

void people(Line &);

void winner(Line &);

void exitFunc();

void error();
  


int main() 
{
//class line with sefood obj
Line seaFood;
int choice=0;
cout<<"Hello, Welcome to Point Loma Seafoods\n";
  //infinite menu loop while choice isn't 6
  while (choice != 6) 
  {
    choice = menu(choice);
    switch (choice) 
    {
      //menu functions with seafood obj argument passed by reference
    case 1:
      name(seaFood);
      break;
    case 2:
      order(seaFood);
      break;
    case 3:
      count(seaFood);
      break;
    case 4:
      winner(seaFood);
      break;
    case 5:
      people(seaFood);
      break;
    case 6:
      exitFunc();
    default:
      error();
      break;
    }

  }
}



int menu(int &choice) {
  
 //displays menu as long as choice isn't 6
  cout << "\n1. Enter Name\n";
  cout << "2. Place order\n";
  cout << "3. Line size\n";
  cout << "4. Raffle\n";
  cout << "5. People in line\n";
  cout << "6. Exit\n";

  
  cout << "\n\nPlease Enter an Option (1-6) and hit return: ";
  cin >> choice;
  return choice;
}

void name(Line &seaFood)
{
  string name;
  cout<<"Please Enter your name (1-20 characters)\nName: ";
  getline(cin, name);
  
  while(name.size()>20||name.size()<1)//validates for name size
    {
      
      cout<<"\n\nError\nPlease Enter your name (1-20 characters)\nName: ";
      getline(cin, name);
    }
  //adds person to back of line
  seaFood.enqueue(name);
  
}
void order(Line &seaFood)
{
  //validates for people being in line so that they can order
  if(seaFood.numNodes()<0)
    {
      cout<<"\nSorry, please join the wait list.\n\n";
    }
  else
  {
    //allows next person in line to order
    seaFood.dequeue();
  }
  
}

void count(Line &seaFood)
{
  //displays count of queue nodes
  if(seaFood.numNodes()==1)
  {
    cout<<"\nThere is currently "<<seaFood.numNodes()<<" person in line.\n\n";
  }
  else
  {
    cout<<"\nThere are currently "<<seaFood.numNodes()<<" people in line.\n\n";
  }
  
}

void people(Line &seaFood)
{
  //lists all customers
  cout<<"\nCustomers: \n";
  seaFood.qContents();
 
}

void winner(Line &seaFood)
{
  //if no people in line then no raffle
  if(seaFood.numNodes()<1)
  {
    cout<<"\n\nThere are currently no people participating in raffle.\n";
  }
  else
  {
    seaFood.winner();
  }
}

void exitFunc() 
{

  cout<<"Exiting Application";
  for(int i=0;i<9;i++)
    {
      cout<<".";
    }
  exit(0);
}

void error() 
{
  cout << "\nSorry, incorrect option. Please try again.\n\n";
  
}