#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <stddef.h>
#include <time.h>
#include <string.h>

//Program will end after a option is chosen and completed
//////////////////////////array sizes//////////////////////////////
#define d 4
#define e 5
#define f 7
#define g 5
#define h 6

/////////////////////FUNCTION PROTOTYPES///////////////////////////
int fib_non(int N); // non-recursive fib function
int fib_rec(int N); // recursive fib function
char pal_non(char a[], int n);// non-recursive palindrome
bool pal_rec(char[],int n, int s);//recursive palindrome
void bubble_non(int array[]);//non recursive bubble sort
int bubble_inner(int array[],int n);//recursive bubble sort
void bubble_outer(int array[],int n);//recursive bubble sort
bool test_sort_non(int array[]);//non-recursive test bubble sort
bool test_sort_rec(int array[],int n);//recursive test bubble sort
void print_array(int array[]);//PRINTS ARRAYS. An extra function


 ////////////////////START OF MAIN/////////////////////////////////
int main() {

    
    printf("Hi, please choose one of the following options:\nA - Fibonacci series function (non-recursive)\nB - Fibonnacci series function (recursive)\nC - Palindrome checker (non-recursive)\nD - Palindrome checker (recursive)\nE - Bubble sort (non recursive)\nF - Bubble sort (recursive)\nG - Testing Test Function With Unsorted Array Using Assert (non recursive)\nH - Testing Test Function With Unsorted Array Using Assert (recursive)\n");
    char option;
    scanf(" %c", &option);
    char a[] = "noon"; //for palindrome questions
    char b[] = "abcba";
    char c[] = "racecar";
    char k[] = "no-on";
    char l[] = "fngrek";
    char m[] = "noo-n";
    time_t t;/* Intializes random number generator */
    srand((unsigned) time(&t)); 
    if (option == 'A' || option == 'a'){
    int N;
    printf("Please enter a positive number:\t");
    scanf("%d", &N);
    assert(N >=0);
    printf("The result is %d\n", fib_non(N));
    }
    if (option == 'B' || option == 'b'){
    int N;
    printf("Please enter a positive number:\t");
    assert(N >=0);
    scanf("%d", &N);
    printf("The result is %d\n", fib_rec(N));
    }
    if (option == 'C' || option == 'c'){
        assert(pal_non(a,d)== 'Y');
        if (pal_non(a,d) == 'Y'){
            printf("The word noon is a palindrome\n");
        }
        else{
            printf("The word noon is not a palindrome\n");
        }
        if (pal_non(b,e) == 'Y'){
            printf("The word abcba is a palindrome\n");
        }
        else{
            printf("The word abcba is not a palindrome\n");
        }
        if (pal_non(c,f) == 'Y'){
            printf("The word racecar is a palindrome\n");
        }
        else{
            printf("The word racecar is a palindrome\n");
        }
        if (pal_non(k,g) == 'Y'){
            printf("The word no-on is a palindrome\n");
        }
        else{
            printf("The word no-on is not a palindrome\n");
        }
        if (pal_non(l,h) == 'Y'){
            printf("The word fngrek is a palindrome\n");
        }
        else{
            printf("The word fngrek is not a palindrome\n");
        }
        if (pal_non(m,5) == 'Y'){
            printf("The word noo-n is a palindrome\n");
        }
        else{
            printf("The word noo-n is a palindrome\n");
        }
    }
    if (option == 'D' || option == 'd'){
        int s = 0; //starting index
        assert(pal_rec(a,d,s));
        if (pal_rec(a,d,s)){
            printf("The word noon is a palindrome\n");
        }
        else{
            printf("This is not a palindrome\n");
        }
        if (pal_rec(b,e,s)){
            printf("The word abcba is a palindrome\n");
        }
        if (pal_rec(c,f,s)){
            printf("The word racecar is a palindrome\n");
        }
        if (pal_rec(k,g,s)){
            printf("The word no-on is a palindrome\n");
        }
        else{
            printf("The word no-on is not a palindrome\n");
        }
        if (pal_rec(l,h,s)){
            printf("The word fngrek is a palindrome\n");
        }
        else{
            printf("The word fngrek is not a palindrome\n");
        }
        if (pal_rec(m,5,s)){
             printf("The word noo-n is a palindrome\n");
        }
        else{
             printf("The word noo-n is a palindrome\n");
        }
    }

    if (option == 'E' || option == 'e'){
        int array[30];//array size is 30
        for(int i=0; i < 30 ; i++){
        array[i] = rand() % 1001;//0 to 1000
   }
   printf("Unsorted A:[");
   print_array(array);//prints array
   bubble_non(array);//sorts the array
   assert(test_sort_non(array));//tests (non recursively) if array                          //is sorted
   assert(test_sort_rec(array,30));//tests (recursively) if array is
                                // sorted
   printf("Sorted A:[");//If not sorted, code is stopped
   print_array(array);
   for(int i=0; i < 30 ; i++){
       array[i] = rand() % 1001;//0 to 1000
   }
   printf("Unsorted B:[");
   print_array(array);
   bubble_non(array);//sorts the array
   printf("Sorted B:[");
   print_array(array);
    }
   if (option == 'F'|| option == 'f'){
   int array[30];//array size 30
   for(int i=0; i < 30 ; i++){
       array[i] = rand() % 1001;//0 to 1000
   }
   printf("Unsorted A:[");
   print_array(array);
   bubble_outer(array,30);//sorts the array
   printf("Sorted A:[");
   print_array(array);
   for(int i=0; i < 30 ; i++){
       array[i] = rand() % 1001;//0 to 1000
   }
   printf("Unsorted B:[");
   print_array(array);
   bubble_outer(array,30);//sorts the array
   printf("Sorted B:[");
   print_array(array);
   }
    int array[30];//Randomizes for the test function
   for(int i=0; i < 30 ; i++){
       array[i] = rand() % 1001;//0 to 1000
   }
   if (option == 'G' || option == 'g'){
       printf("Array[");
       print_array(array);
       assert(test_sort_non(array)); //Final check, will always output error. I put it at the end regardless of option choosen
   }
   if (option == 'H' || option == 'h'){
       printf("Array[");//shows unsorted array
       print_array(array);
       assert(test_sort_rec(array,30)); //Final array check, will always output error. I put it at the end regardless of option choosen
   }
    return 0;
}
////////////////////END OF MAIN////////////////////////////////////
//////////////////FIBONACCI NON-RECURSIVE//////////////////////////
int fib_non(int N){
    assert(N >= 0); //Stops code if input is not positive
    int p1 = 1; //previous (p1) is 1 for the 3rd term (N == 2), and p2 is 0
    int p2 = 0;
    int result = 0;
    if (N<2){  //First two terms always return themself, 0 and 1//
        return N;  
    }
    for (int i = 2; i<= N; i++){
        result = p1 + p2; /* for term 2, the two prior terms are 1
and 0. For every following term, the second previous term (p2) becomes p1,and the previous term (p1) is the result that you just got. It starts from the bottom and works up */
        p2 = p1; 
        p1 = result;
    }
    return result;
}
/////////////////////FIBONACCI RECURSIVE///////////////////////////
int fib_rec(int N){
    assert(N >=0);
    if (N<2){//base cases N = 1, N = 0. Will always be itself
        return N;
    }
    return fib_rec(N-1) + fib_rec(N-2);//recursive step
}
/////////////////Palindrome NON-RECURSIVE//////////////////////////
char pal_non(char a[],int n){ /*receives size of array and array                                 of that size*/
int result = 0; // is it palidrome or not
    for (int i = 0,j= n-1; i < n/2; i++,j--){
        if (a[i] != a[j]){
        if(!('A'<= a[j] && a[j]<='Z')||!('a'<=a[j]&& a[j]<='z')){
            j--;//last character not
        }                           // a letter, so skip it
        if(!('A'<= a[i]||a[i]<='Z')||!('a'<=a[i]||a[i]<='z')){
            i++;//first character not letter
        }                          // so skip
    }
        if (a[i] == a[j]){ // Checks the pairs, outside going in
            result++;          // Number of checks is n/2 - 1
        }
    }
    if (result == n/2){
        
        return 'Y'; // returns Y (yes) if palindrome
    }
    else{
        return 'N'; // returns N (no) if not palindrome
    }
}
///////////////////Palindrome Recursive////////////////////////////
bool pal_rec(char a[],int n,int s){
    if (n<= 1){
        return true;// 1 letter words are always palindromes
    }
    if (s>n){ //base case 
        return true;// all comparisons have been made 
    }               // thus it's a palindrome
    else if (a[n-1] != a[s]){
        if(!('A'<= a[n-1] && a[n-1]<='Z')||!('a'<=a[n-1]&& a[n-1]<='z')){
            return pal_rec(a,n-1,s);//last character not
        }                           // a letter, so skip it
        if(!('A'<= a[s]||a[s]<='Z')||!('a'<=a[s]||a[s]<='z')){
            return pal_rec(a,n,s+1);//first character not letter
        }                          // so skip
       else{
           return false; //Both are letters and they aren't same
       }                 // So not a palindrome
    }
     return pal_rec(a,n-1,s+1); //Go to next comparison
}

////////////////////////Bubble Sort Non-Recursive//////////////////
void bubble_non(int array[]){ //array is pass by reference, no  
                             //return required
    int temp = 0;
    for (int j = 0; j<30 - 1;j++){//swap portion of function
       for (int k = 0; k < (30-j-1);k++){//30-j-1, so that
           if (array[k] > array[k+1]){   //the last element after
               temp = array[k];      //sorting isn't checked
               array[k] = array[k+1];
               array[k+1] = temp;
               
           }
       }
   }

}
//////////////////////Bubble Sort Recursive////////////////////////
int bubble_inner(int array[],int n){ //inner loop of bubble sort
    int swap = 0;//number of swaps that occur with one pass through
    int temp = 0; //list
    if(n<2){ //array is sorted for in this run through
        return swap;
    }
    if(array[0]>array[1]){//compares the first two elements
        temp = array[0];  //swaps if condition is met
        array[0]=array[1];
        array[1]=temp;
        swap++;
    }
    swap +=bubble_inner(array+1,n-1);//compares the next two elements, swaps if needed
    return swap;//tells other loop that swap occurred
}
void bubble_outer(int array[],int n){
    int swap = bubble_inner(array,n);
    if(swap >=1){
        bubble_outer(array,n);
    }
}
//////////////////Non-recursive Test function//////////////////////
bool test_sort_non(int array[]){
    int swap = 0;//shows if any swaps are made
    for (int j = 0; j<30 - 1;j++){//swap portion of function
           if (array[j] > array[j+1]){   //the last element after
              swap++;
           }
   }
   if (swap>0){
       return false; //There's atleast 1 swap, thus not sorted
   }
   else{
       return true;//sorted
   }
}
/////////////Recursive Test Function///////////////////////////////
bool test_sort_rec(int array[],int n){
    if (n<2){
        return true;
    }
    if (array[n-1]<array[n-2]){
        return false; //not sorted cause previous is greater than first
    }
    return test_sort_rec(array,n-1);
}
/////////////////Print Array///////////////////////////////////////
void print_array(int array[]){
   for (int l = 0; l<30;l++){
       if (l == 29){
           printf("%d",array[l]);
       }
       else{
           printf("%d,", array[l]);
       }
   }
   printf("]\n\n");
}
