/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

void Queue::move_to_front(int key) {
	Queue::NodePointer current = myFront; 
	Queue::NodePointer previous = myFront;
	while (current != NULL) {
		if (current->data == key) {
			previous->next = current->next;
			current->next = myFront;
			myFront = current; 
			return;
		}
		previous = current;
		current = current->next;
	}
}


void Queue::merge_two_queues(Queue::Queue q2) {
	Queue q3;
	Queue::NodePointer ptr;
	while (myFront != 0 && q2.myFront != 0) { //Lets exhaust a list
		if (q2.empty()) {
			for (ptr = myFront; ptr != 0; ptr = ptr->next) {
				q3.enqueue(front());
				dequeue();
			}	
		}
		if (empty()) {
			for (ptr = q2.myFront; ptr != 0; ptr = ptr->next) {
				q3.enqueue(q2.front());
				q2.dequeue();
			}
		}
		else {
			if (front() <= q2.front()) {
				q3.enqueue(front());
				dequeue();
			}
			if (front() > q2.front()) {
				q3.enqueue(q2.front());
				q2.dequeue();
			}
		}
	}
	if (empty()) { // after exhausting q1, if there is more in q2
			for (ptr = q2.myFront; ptr != 0; ptr = ptr->next) {
				q3.enqueue(q2.front());
				q2.dequeue();
			}
	}
	if (q2.empty()) { // after exhausting q2, if there is more in q1
			for (ptr = myFront; ptr != 0; ptr = ptr->next) {
				q3.enqueue(front());
				dequeue();
			}	
	}
	for (ptr = q3.myFront; ptr != 0; ptr = ptr->next) { // take everything from q3 and put into q1
		enqueue(q3.front());
		q3.dequeue();
	}		
}




