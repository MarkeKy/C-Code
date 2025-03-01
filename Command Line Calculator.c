#include <stdio.h>
#include <math.h>
// Global Variables////////////////////////////////////////////////
int i_1;
int i_2;
char option; //initializes option variable
int c; //eats character if there is one in the buffer, prevents crashes caused by scanf

//FUNCTION PROTOTYPES//////////////////////////////////////////////
float min(float a, float b);
float max(float a, float b);
char options();
void E();
float B(float number_1, float number_2, char Operator);
float U(char Operator,float number_1);

//START OF MAIN FUNCTION///////////////////////////////////////////
int main(){
	printf("Welcome to my Command-Line Calculator (CLC)\nDeveloper: Sharmarke Kedie\nVersion: Assignment 3\nDate: 2024/03/31\n----------------------------------- \n\n");
	float number_1; //initializes number_1 variable
	float number_2; //initializes number_2 variable
	float result; //initializes result variable
	char Operator; //initializes Operator variable
	int i; //input validator
	float A[5] = {0};//initialize to zero
	printf("\nSelect one of the following items:\nB) - Binary Matematical Operations, such as addition and subtraction.\nU) - Unary Mathematical Operations, such as square root, and log.\nA) - Advanced Mathematical Operations, using variables, arrays.\nV) - Define variables and assign them values.\nE) - Exit \n"); // Displays menu
	scanf(" %c", &option);
	while (1){
	    if (option == 'B'){
	            printf("Please enter the first number \n");
	            i_1 = scanf("%f", &number_1);
	            if (i_1 != 1){
	                c = getchar();
	            } //Prevents crashing while also not doing input validation. Removes char if entered
	            printf("Please enter the operation (+,-,/,*,%%,P,X,I) \n");
	            scanf(" %c", &Operator); // Gets operator from user
	        
	            printf("Please enter the second number: \n");
	            i_2 = scanf("%f", &number_2); // Gets second number from user
	            if (i_2 != 1){
	                c = getchar();
	            } //Prevents crashing while also not doing input validation. Removes char if entered. Otherwise, it does nothing
	            printf("The result is %.2f\n",B(number_1,number_2,Operator));
	    }
	    else if (option == 'V') {
	        char slot;
	            do {
	                printf ("Select a memory solt (a,b,c,d,e) \n");
	                scanf(" %c", &slot);
	                if (slot != 'a' && slot != 'b' && slot != 'c' && slot != 'd' && slot != 'e'){//without if, invalid output would always be displayed even if correct
	                    printf("Invalid input! \n");
	                }
	            } while (slot != 'a' && slot != 'b' && slot != 'c' && slot != 'd' && slot != 'e');//ensures that value received is the correct one
	            if (slot == 'a'){
	                do {
	                    printf("Enter a number into slot %c \n", slot);
	                    i = scanf("\n%f", &number_1);
	                    if (i != 1){
	                        c = getchar();
	                        printf("Invalid input! \n");
	                    }
	                } while (i != 1);
	                A[0] = number_1;
	            }
	            else if (slot == 'b'){
	               do {
	                    printf("Enter a number into slot %c \n", slot);
	                    i = scanf("\n%f", &number_1);
	                    if (i != 1){
	                        c = getchar();
	                        printf("Invalid input! \n");
	                    }
	                } while (i != 1);
	                A[1] = number_1;
	                
	            }
	            else if (slot == 'c'){
	                do {
	                    printf("Enter a number into slot %c \n", slot);
	                    i = scanf("\n%f", &number_1);
	                    if (i != 1){
	                        c = getchar();
	                        printf("Invalid input! \n");
	                    }
	                } while (i != 1);
	                A[2] = number_1;
	            }
	            else if (slot == 'd'){
	                do {
	                    printf("Enter a number into slot %c \n", slot);
	                    i = scanf("\n%f", &number_1);
	                    if (i != 1){
	                        c = getchar();
	                        printf("Invalid input! \n");
	                    }
	                } while (i != 1);
	                A[3] = number_1;
	            }
	            else if (slot == 'e'){
	                do {
	                    printf("Enter a number into slot %c \n", slot);
	                    i = scanf("\n%f", &number_1);
	                    if (i != 1){
	                        c = getchar();
	                        printf("Invalid input! \n");
	                    }
	                } while (i != 1);
	                A[4] = number_1;
	            }
	        
	    }
	    else if (option == 'U') {
	            printf("Please enter an operator [S(square root),L(ln),E(exponent for e),C(ceiling(x)),F(floor(x))] \n");
	            scanf(" %c", &Operator); // Gets operator from user
	            printf("Please enter a number\n");
	            i_1 = scanf("%f", &number_1);
	            printf("The result is %.2f\n",U(Operator, number_1));
	        
	    }
	    else if (option == 'E'){
	        E();
	        break;
	    }
	    else if (option == 'A') {
	        while (1){ //SUBMENU
	          option = options();
	          if (option == 'B'){
	          do {
	              printf("Please enter the first number: \n");
	              i = scanf("%f", &number_1); // Gets number from user
	              if (i != 1){
	                  c = getchar();
	                  if (c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'e'){
	                      printf("Invalid input! \n");
	                  }
	                  else if (c == 'a'){
	                      number_1 = A[0];
	                      break;
	                  }
	                  else if (c == 'b'){
	                      number_1 = A[1];
	                      break;
	                  }
	                  else if (c == 'c'){
	                      number_1 = A[2];
	                      break;
	                  }
	                  else if (c == 'd'){
	                      number_1 = A[3];
	                      break;
	                  }
	                  else if (c == 'e'){
	                      number_1 = A[4];
	                      break;
	                  }
	              }
	          }while (i != 1);
	        printf("Please enter the operation (+,-,/,*,%%,P,X,I) \n");
	        scanf(" %c", &Operator); // Gets operator from user
	          do {
	              printf("Please enter the second number: \n");
	              i = scanf("%f", &number_2); // Gets number from user
	              if (i != 1){
	                  c = getchar();
	                  if (c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'e'){
	                      printf("Invalid input! \n");
	                  }
	                  else if (c == 'a'){
	                      number_2 = A[0];
	                      break;
	                  }
	                  else if (c == 'b'){
	                      number_2 = A[1];
	                      break;
	                  }
	                  else if (c == 'c'){
	                      number_2 = A[2];
	                      break;
	                  }
	                  else if (c == 'd'){
	                      number_2 = A[3];
	                      break;
	                  }
	                  else if (c == 'e'){
	                      number_2 = A[4];
	                      break;
	                  }
	              }
	          }while (i != 1);
	          i_1 = 1; //Correct inputs are gotten
	          i_2 = 1;
	          printf("The result is %.2f\n", B(number_1,number_2,Operator));
	    }
	    else if (option == 'E'){
	        break;
	    }
	    else if (option == 'U'){
	         do {
	              printf("Please enter the first number: \n");
	              i = scanf("%f", &number_1); // Gets number from user
	              if (i != 1){
	                  c = getchar();
	                  if (c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'e'){
	                      printf("Invalid input! \n");
	                  }
	                  else if (c == 'a'){
	                      number_1 = A[0];
	                      break;
	                  }
	                  else if (c == 'b'){
	                      number_1 = A[1];
	                      break;
	                  }
	                  else if (c == 'c'){
	                      number_1 = A[2];
	                      break;
	                  }
	                  else if (c == 'd'){
	                      number_1 = A[3];
	                      break;
	                  }
	                  else if (c == 'e'){
	                      number_1 = A[4];
	                      break;
	                  }
	              }
	          }while (i != 1);
	            printf("Please enter an operator [S(square root),L(ln),E(exponent for e),C(ceiling(x)),F(floor(x))] \n");
	            scanf(" %c", &Operator); // Gets operator from user
	           i_1 = 1;
	           printf("The result is %.2f\n", U(Operator,number_1));
	     }
	     else{
	         printf("Invalid option!\n");//If first character obtained isn't valid
	     }
	        }
	    }
	    option = options();
	}
	return 0;
}
//END OF MAIN FUNCTION/////////////////////////////////////////////

//Option Function//////////////////////////////////////////////////
char options(){
    if (option == 'A'){
        do{printf("Please select your option ( B , U , E ) \n");
	    scanf(" %c", &option); // Gets new option from user
	    if (option != 'B' && option != 'U' && option != 'E'){
	        printf("Invalid option! \n");
	    }
	    } while (option != 'B' && option != 'U' && option != 'A' && option != 'V' && option != 'E');// if neither, continues asking user for one of it
        
    }
    else {
        do{printf("Please select your option ( B , U , A , V , E ) \n");
	    scanf(" %c", &option); // Gets new option from user
	    if (option != 'B' && option != 'U' && option != 'A' && option != 'V' && option != 'E'){
	        printf("Invalid option! \n");
	    }
	    } while (option != 'B' && option != 'U' && option != 'A' && option != 'V' && option != 'E');// if neither, continues asking user for one of it
    }
	return option;
}
///////////////////////////////////////////////////////////////////
 //End Function/////////////////////////////////////////////////////
void E(){
    	printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!"); // Ending message of calculator
}
///////////////////////////////////////////////////////////////////
//Binary Function//////////////////////////////////////////////////
float B(float number_1, float number_2, char Operator){
    do{
        if (i_1 != 1){
	                c = getchar(); //prevents infinite loop if user enters a character by assigning the left -over character to c variable
	                printf("Invalid first number!\n");
	                printf("Please enter the first number \n");
	                i_1 = scanf("%f", &number_1);
	            }
	        }while (i_1 != 1);
	do {
	    if (Operator != '+' && Operator != '-' && Operator != '/' && Operator != '*' && Operator != '%' && Operator != 'P' && Operator != 'X' && Operator != 'I'){
	            printf("Invalid operator! \n");
	            printf("Please enter the operation (+,-,/,*,%%,P,X,I) \n");
	        scanf(" %c", &Operator); // Gets operator from user
	        }
	        } while (Operator != '+' && Operator != '-' && Operator != '/' && Operator != '*' && Operator != '%' && Operator != 'P' && Operator != 'X' && Operator != 'I');
	do {
	    if (i_2 != 1){
	                c = getchar();
	                printf("Invalid second number! \n");
	                printf("Please enter the second number: \n");
	                i_2 = scanf("%f", &number_2); // Gets second number from user
	            }
	        }while (i_2 != 1);
	
    
    if (Operator == '+'){ // Determines operator user chose
	            return number_1 + number_2; 
	            
	        }
	        else if (Operator == '-'){
	            return number_1 - number_2;
	        }
	        else if (Operator == '/'){
	            return number_1 / number_2;
	        }
	        else if (Operator == '*'){
	            return number_1 * number_2;
	        }
	        else if (Operator == '%'){
	            return fmod(number_1,number_2);
	            
	        }
	        else if (Operator == 'P'){
	            return pow(number_1,number_2);
	            
	        }
	        else if (Operator == 'X'){
	            return max(number_1,number_2);
	        }
	        else if (Operator == 'I'){
	            return min(number_1,number_2);
	    }
}
///////////////////////////////////////////////////////////////////
//Unary Function///////////////////////////////////////////////////
float U(char Operator,float number_1){
    do{
         if (Operator != 'S' && Operator != 'L' && Operator != 'E' && Operator != 'C' && Operator != 'F'){
	                printf("Invalid operator! \n");
	                printf("Please enter an operator [S(square root),L(ln),E(exponent for e),C(ceiling(x)),F(floor(x))] \n");
	            scanf(" %c", &Operator); // Gets operator from user
	            } 
	  }while (Operator != 'S' && Operator != 'L' && Operator != 'E' && Operator != 'C' && Operator != 'F');
	do{
        if (i_1 != 1){
	                c = getchar(); //prevents infinite loop if user enters a character by assigning the left -over character to c variable
	                printf("Invalid number!\n");
	                printf("Please enter the first number \n");
	                i_1 = scanf("%f", &number_1);
	            }
	        }while (i_1 != 1);
	 if (Operator == 'S'){
	            return sqrt((double)number_1);
	        }
	        else if (Operator == 'L'){
	            return log((double)number_1);
	        }
	        else if (Operator == 'E'){
	            return exp((double)number_1);
	        }
	        else if (Operator == 'C'){
	            return ceil((double)number_1);
	        }
	        else if (Operator == 'F'){
	            return floor((double)number_1);
	        }
}
//Other Functions//////////////////////////////////////////////////
float min(float a, float b){
    return (a<b?a:b);
}//function that checks if a < b. If yes, then return a else return b
float max(float a, float b){
    return (a>b?a:b);
} //function that checks if a > b. If yes, then return a else return b