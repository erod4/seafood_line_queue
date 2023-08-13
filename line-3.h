
#ifndef LINE_H
#define LINE_H
#include <string>
#include <iostream>

using namespace std;

class Line
{

//dynamic queue
private:
  
  struct QueueNode
{
  string value;//holds name of customer
  int ticket; //holds raffle ticket of customer

  QueueNode *next;//Pointer to next node
};
  
  QueueNode *front;//Front of queue
  QueueNode *rear;//Rear of queue

public:
//constructor
  Line();
  
  ~Line();
  //accesors & mutators
  void enqueue(string);
  void dequeue();
  void clear();

  bool isEmpty() const;
  int sizeOf(QueueNode *) const;
  int numNodes() const;
  void qContents() const; 
  string raffle(QueueNode *, int) const;
  void winner() const;

};

#endif