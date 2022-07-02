#include <bits/stdc++.h>
using namespace std;
struct Queue {
   int top, end, n;
   int* queue;
   Queue(int c){
      top = end = 0;
      n = c;
      queue = new int;
   }
   ~Queue() { delete[] queue;
}
void Enqueue(int data){
   if (n == end) {
      printf("\nQueue is full\n");
      return;
   }
   else {
      queue[end] = data;
      end++;
   }
   return;
}
void Dequeue(){
   if (top == end) {
      printf("\nQueue is empty\n");
      return;
   }
   else {
      for (int i = 0; i < end - 1; i++) {
         queue[i] = queue[i + 1];
      }
      end--;
   }
   return;
}
void Display(){
   int i;
   if (top == end) {
      printf("\nQueue is Empty\n");
      return;
   }
   for (i = top; i < end; i++) {
      printf(" %d <-- ", queue[i]);
   }
   return;
}
void Front(){
   if (top == end) {
      printf("\nQueue is Empty\n");
      return;
   }
   printf("\nFront Element is: %d", queue[top]);
   return;
}
};
int main(void){
   Queue q(4);
   q.Display();
   q.Enqueue(12);
   q.Enqueue(89);
   q.Enqueue(65);
   q.Enqueue(34);
   q.Display();
   q.Enqueue(92);
   q.Display();
   q.Dequeue();
   q.Dequeue();
   q.Display();
   q.Front();
   return 0;
}
