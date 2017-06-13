/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(100*i);

   cout << "Contents of queue q1 (via  print):\n";
   print(q1); 
   cout << endl;

   Queue q2;
   q2 = q1;
   cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
   print(q2); 
   cout << endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;

   cout << "Front value in q2: " << q2.front() << endl;
   //------------------------------- move_to_front test-------------------
   int numToFront;
   cout << "Value of q1 to move to front: " << endl;
   cin >> numToFront;
   q1.move_to_front(numToFront);
   cout << "New front value of q1: " << q1.front() << endl;
   cout << "New q1: " << endl;
   print(q1);
	//---------------------------
	

	
   while (!q2.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q2.dequeue();
     q2.display(cout);
   }
   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2?" << endl << q2.front() << endl;
   cout << "Trying to remove front of q2: " << endl;
   q2.dequeue();
   
   	//------------------------------- merge_two_queues test 1-------------------
	while (!q1.empty()) {
		q1.dequeue();
	}
	while (!q2.empty()) {
		q2.dequeue();
	}
	q1.enqueue(1);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.enqueue(11);
 	q2.enqueue(2);
 	q2.enqueue(5);
 	q2.enqueue(6);
 	q2.enqueue(7);
 	q2.enqueue(10);
 	q1.enqueue(12);
 	q1.enqueue(13);
 	cout << "Contents of q1: " << endl;
 	print (q1);
 	cout << "Contents of q2: " << endl;
 	print (q2);
    cout << "----Merging q1 and q2----" << endl;
    q1.merge_two_queues(q2);
    cout << "Contents of q1: ";
    print(q1);
	//------------------------------- merge_two_queues test 2-------------------
	while (!q1.empty()) {
		q1.dequeue();
	}
	while (!q2.empty()) {
		q2.dequeue();
	}
 	q2.enqueue(2);
 	q2.enqueue(5);
 	q2.enqueue(6);
 	q2.enqueue(7);
 	q2.enqueue(10);
 	cout << "Contents of q1: " << endl;
 	print (q1);
 	cout << "Contents of q2: " << endl;
 	print (q2);
    cout << "----Merging q1 and q2----" << endl;
    q1.merge_two_queues(q2);
    cout << "Contents of q1: ";
    print(q1);
   	//------------------------------- merge_two_queues test 3-------------------
	while (!q1.empty()) {
		q1.dequeue();
	}
	while (!q2.empty()) {
		q2.dequeue();
	}
	q1.enqueue(1);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.enqueue(11);
 	q1.enqueue(12);
 	q1.enqueue(13);
 	cout << "Contents of q1: " << endl;
 	print (q1);
 	cout << "Contents of q2: " << endl;
 	print (q2);
    cout << "----Merging q1 and q2----" << endl;
    q1.merge_two_queues(q2);
    cout << "Contents of q1: ";
    print(q1);
   	//------------------------------- merge_two_queues test 4-------------------
	while (!q1.empty()) {
		q1.dequeue();
	}
	while (!q2.empty()) {
		q2.dequeue();
	}
 	cout << "Contents of q1: " << endl;
 	print (q1);
 	cout << "Contents of q2: " << endl;
 	print (q2);
    cout << "----Merging q1 and q2----" << endl;
    q1.merge_two_queues(q2);
    cout << "Contents of q1: ";
    print(q1);
	//--------------------------------------------------
	
	srand (time(NULL)); // random number seed
	int firstRandNum = rand()%60;
	cout << "Random number: " << endl;
	cout << firstRandNum <<endl;
	
   //system("PAUSE");
   return 0;
   
   
   
}
