#include<stdio.h>
#include "queue.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort_range(int a[], int first, int last) {

   if (last <= first) 
      return; // base case: length is <= 1

   int pivot = a[first]; // first element is the pivot
   int pos = last; // where to put next larger element

   // move items greater than the pivot to the back
   for (int i = last; i > first; --i) {
      if (a[i] > pivot) {
        swap(&a[pos], &a[i]);
        --pos; 
      }
   }

   swap(&a[first], &a[pos]); // put pivot in correct place

   // recursive calls to quicksort
   quicksort_range(a, first, pos - 1);
   quicksort_range(a, pos + 1, last);
}

void quicksort(int a[], int len) { // wrapper function
  quicksort_range(a, 0, len - 1);
}

void print_array(int array[], int len){
    for(int i = 0; i < len; i++)
       printf("%2d ", array[i]);
    printf("\n\n");
}

void iterative_quicksort(int a[], int len){

   struct queue *first_Q = create();//initializes queue
   struct queue *last_Q = create();//initializes queue
   int queue_size = 1;
   int current_pos = 0;
   add(first_Q,0);
   add(last_Q,len-1);

   int first = front(first_Q);//first becomes first item in queue
   int last = front(last_Q);//last becomes first item in queue
   while(!(is_empty(first_Q))) {
         int pivot = a[first]; // first element is the pivot
         int pos = last; // where to put next larger element
         // move items greater than the pivot to the back
         for (int i = last; i > first; --i) {
            if (a[i] > pivot) {
              swap(&a[pos], &a[i]);
             --pos;
            }
         }
         swap(&a[first], &a[pos]); // put pivot in correct place

         if(first < pos - 1) {
           //First "recursive" call
           add(first_Q,first);//adding to queue, use add
           add(last_Q,pos-1);//adding to queue, use add
           queue_size++;
           rm(first_Q);//removes element from queue, no longer needed
           rm(last_Q);
         }

         if(pos + 1 < last) {
           add(first_Q,pos+1);
           add(last_Q,last);
           queue_size++;
           rm(first_Q);//removes element from queue, no longer needed
           rm(last_Q);
         }
         if(current_pos >= queue_size){
         break;
         }

         
         current_pos++;
         first = front(first_Q);//gets item from Q
         last = front(last_Q);//gets item from Q
         
         
         
   }
   destroy(first_Q);//destroys queues to prevent memory leaks
   destroy(last_Q);


}

int main() {

   int array[30] = {}; //all 0s
   int len = 30;

   for(int i = len; i > 0; i--)
       array[len-i] = i; 
   //array = {30, 29, 28, 27, 26, ..., 3, 2, 1}
   print_array(array, len);

   //quicksort(array, len);
   iterative_quicksort(array, len);
   print_array(array, len);

   return 0;
}
