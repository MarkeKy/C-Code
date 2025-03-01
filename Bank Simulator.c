
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#define a 30//length of character arrays
///////////////////STRUCTURES////////////////////////////////////////////////
struct llnode{//customers in the bank
    char first_name[30];//max length of first name is 30
    char last_name[30];//max length of last name is 30
    double balance;//default balance is $0
    char secret_password[30];//max length of password is 30
    char transact_ID[12];//field for transaction ID
    char customer_ID[12];
    struct llnode * next;//pointer to the next node or NULL
};
struct llist{//Creates the linked list
    struct llnode * front;//pointer to the last customer in list
    struct llnode * back;//pointer to the first customer in the list
};
struct transact{//transaction definition
    char source_trans[30];
    double sent;
    char dest_trans[30];
};
struct transact_block{
    struct transact block[6];//block of transaction (array)
    struct transact_block *next;//necessary for linked list
};
struct transact_list{
    struct transact_block *front;
};
////////////////////Functions Prototypes/////////////////////////////////////
struct llist * list_create();//creates linked list, initiallizes it
void add_customer(struct llist * lst);//create customer, add user input to this function 
void remove_customer(struct llist * lst);//Removes customer from list
void display_customer(const struct llist * lst);//Displays an existing customer
struct transact_list * trans_list_create(void);//create trans_act list
int check_password(char source[],struct llist * lst);
void insert_block(struct llist * lst,struct transact_list *trans);
void get_balance(struct llist * lst,struct transact_list *trans);
void list_destroy(struct llist * lst);//Destroys list
void list_destroy_trans(struct transact_list * lst);//Destroys list
/////////////////////////////////Start of Main //////////////////////////////
int main() {
    printf("Bank Menu:\n      1 - Create new customer\n      2 - Delete customer\n      3 - Display customer\n      4 - Insert transactions\n      5 - Exit\n");
    int option = 0;
    int return_value = 0;
    srand(time(0));//for customer_ID and Transaction ID
    struct llist *customer_list = list_create();//creates customer list for option 1
    struct transact_list *transaction_list = trans_list_create();//creates transaction list for option 4
    do{
    printf("\nPlease select an option:");
    return_value = scanf("%d",&option);
    if (return_value != 1 || option < 1 || 5 <option){//checks if valid input
        printf("\nError, invalid option chosen");
        getchar();//removes character from buffer if user enters a character
    }
    if (option == 1){
        printf("\nPlease enter the customer information:");
        add_customer(customer_list);//function that adds customer to list
                                    //only adds one customer at a time
    }
    if (option == 2){
        remove_customer(customer_list);//Function that removes customer
        
    }
    if (option == 3){
        display_customer(customer_list);//Function that displays customer
    }
    if (option == 4){
        insert_block(customer_list,transaction_list);//Transaction function
        get_balance(customer_list,transaction_list);//Update balance
    }
    } while(option != 5);
    printf("\nGoodbye!");
    list_destroy(customer_list);//free heap memory
    list_destroy_trans(transaction_list);//free heap memory
    return 0;
}
//////////////////////////////////////Functions/////////////////////////////
///////////Create Customer List Function////////////////////////////////////
struct llist * list_create(void) {
struct llist * lst = malloc(sizeof(struct llist));
lst->front = NULL;
return lst;
}
////////////////////Add customer function//////////////////////////////////
void add_customer(struct llist * lst){//adds customer to front of list
    char confirm_password[30];
    struct llnode * newnode = malloc(sizeof(struct llnode));//gets heap memory for node (customer)
    printf("\nFirst name: ");
    scanf("%s" ,newnode->first_name);//this works!!!!
    printf("\nLast Name: ");
    scanf("%s",newnode->last_name);//last name of customer
    newnode->balance = 0;//balance is zero by default
    while(true){//password checker
        printf("\nPassword: ");
        scanf("%s",newnode->secret_password);
        printf("\nConfirm Password: ");
        scanf("%s",confirm_password);
        if (strcmp(newnode->secret_password,confirm_password)==0){
            break;//same passwords were entered
        }
        else{
            printf("\nPasswords don't match");//same passwords weren't entered
        }
    }//end of password checker
    char trans[12];
    for (int i = 0; i<5;i++){//use string copy
        trans[i] = rand() % 26 + 65;//random Capital letter
    }
    trans[5] = '-';
    trans[11] = '\0';
    for (int j = 6;j<11;j++){
        trans[j] = rand() % 10 + 48;//random 1 digit number 
    }
    char cust[12];
    for (int i = 0; i<5;i++){//use string copy
        cust[i] = rand() % 26 + 65;//random Capital letter
    }
    cust[5] = '-';
    cust[11] = '\0';
    for (int j = 6;j<11;j++){
        cust[j] = rand() % 10 + 48;//random 1 digit number 
    }
    strcpy(newnode->transact_ID,trans);//copies to transact field
    strcpy(newnode->customer_ID,cust);//copies to customer field
    printf("\nCustomer Successfully Saved with customer ID: %s",newnode->customer_ID);
    if(lst->front == NULL){//adding customer to the back of list
        newnode->next = lst->front;//first customer points to NULL
        lst->front = newnode;//first customer
        lst->back = newnode;//last customer (also first customerhere)
    }
    else{//there is a customer in the list and thus you add to back of list
           lst->back->next = newnode; //last customer points to new customer
           lst->back = newnode; //list now points to the new customer
           newnode->next = NULL; //new customer points to NULL,back of list
        }
}
////////////////Customer Remove/////////////////////////////////////////////
void remove_customer(struct llist * lst){
    char cus[30];//customer ID checker
    char pass[30];//secret password checker
    printf("\nPlease enter the customer ID: ");
    scanf("%s",cus);
    struct llnode*node = lst->front;
    struct llnode*previous = lst->front;
    while(node){
        if(strcmp(node->customer_ID,cus) == 0){
            if(node->balance == 0){
                printf("\nPlease enter the secret password: ");
                scanf("%s",pass);
                if(strcmp(node->secret_password,pass) == 0){
                printf("\nCustomer account for %s %s has been successfully deleted.\n",node->first_name,node->last_name);
                //Delete node
                //node is first
                if(node == lst->front){
                    assert(node);
                    struct llnode * old_front = lst->front;
                    lst->front = lst->front->next;
                    if(lst->front == lst->back){
                        lst->back = lst->front;//keep track of back
                    }
                    free(old_front);
                    return;
                }
                assert(node);//check if not NULL
                struct llnode * remove_node = node;
                previous->next = node->next;
                if(node->next == NULL){
                    lst->back = node;//keep track of back
                }
                free(remove_node);
                return;
                }//Secret password was invalid
                else{
                    printf("\nInvalid secret password\n");
                    return;
                }
            }
        else{
            printf("\n Customer balance is not zero, can't delete");
            return;
        }
        }
        previous = node;//keep track of previous
        node = node->next;
    }
    printf("\nInvalid customer ID");
    return;
}
///////////////DISPLAY CUSTOMER FUNCTION////////////////////////////////////
void display_customer(const struct llist * lst){
    char cus[30];//customer ID checker
    printf("\nPlease enter the customer ID: ");
    scanf("%s",cus);
    struct llnode*node = lst->front;
    while(node){//iterate through list till end of node is reached
        if(strcmp(node->customer_ID,cus) == 0){
            printf("\nCustomer details:\n     Name: %s %s\n     Balance: $%.2f\n     Customer ID: %s\n     Transaction ID: %s\n",node->first_name,node->last_name,node->balance,node->customer_ID,node->transact_ID);
            return;
        }
        node = node->next;
    }
    printf("\nInvalid customer ID");
    return;
}
/////////////////////////CREATE TRANSACT LIST FUNCTION//////////////////////
struct transact_list * trans_list_create(void) {
struct transact_list * trans_lst = malloc(sizeof(struct transact_list));
trans_lst->front = NULL;
return trans_lst;
}//Function creates memory in heap
///////////////////////CHECK SECRET PASSWORD////////////////////////////////
int check_password(char source[],struct llist * lst){//return 1 if true; 0 if false
    //Gets parameters from insert_block. Checks secret password if needed
    //Checks if source ID is correct
    char deposit[] = "Deposit";
    char secret[30];
    if(strcmp(source,deposit)==0)
              return 1;//source is deposit, doesn't need password check
    printf("\n     Password:");
    scanf("%s",secret);
    struct llnode*node_2 = lst->front;
    while(node_2){//checking source
        if(strcmp(node_2->transact_ID,source)==0){
            if(strcmp(node_2->secret_password,secret)== 0)
            return 1;//ID exists and correct password
            else{
                printf("\nIncorrect password");
                return 0;//ID exist and incorrect password
            }
        }
        node_2 = node_2->next;//iterate through list
        }
        printf("\nInvalid Source");
        return 0;
}
/////////////////////////////INSERT BLOCK FUNCTION//////////////////////////
void insert_block(struct llist * lst,struct transact_list *trans){
    struct transact_block * block = malloc(sizeof(struct transact_block));//gets heap memory for node (transaction block)
    int i = 0;
    while(i<5){//max 5 transactions, then return and update Balance (via get balance function)
    do{
    int des = 0;
    printf("\nPlease insert the transactions ");
    printf("\n     Source: ");
    int ret= scanf("%s",block->block[i].source_trans);
    if (i>= 1 && ret==EOF){//atleast 1 transaction was made
        clearerr(stdin);//clear EOF flag
        block->next = trans->front;//prevent segmentation fault
        trans->front = block;//and to keep prior transactions
        return;
    }
    else if(ret == EOF){
        clearerr(stdin);//Clear EOF flag and continue, no transaction was made prior
    }//at least 1 transaction needs to be made before exiting
    printf("\n     Amount: ");
    scanf("%lf", &block->block[i].sent);
    printf("\n     Destination: ");
    scanf("%s",block->block[i].dest_trans);
    struct llnode*node = lst->front;
    while(node){//checking destination
        if(strcmp(node->transact_ID,block->block[i].dest_trans)==0){
            des++;
            }
        node = node->next;
    }
    if(check_password(block->block[i].source_trans,lst) && des == 1){
     break;
     }
     if (des != 1){
     printf("\nInvalid Destination");
    }
    }while(true);
    i++;
    }
    block->next = trans->front;
    trans->front = block;
    return;
}
/////////////////////////////////////GET BALANCE////////////////////////////
void get_balance(struct llist * lst,struct transact_list *trans){
    for (int i = 0; i<6; i++){//going through whole block done
        struct llnode * node = lst->front;
        while (node) {
            if(strcmp(node->transact_ID,trans->front->block[i].source_trans)==0){
                //It's a source, money was removed
                node->balance -= trans->front->block[i].sent;
            }
            if(strcmp(node->transact_ID,trans->front->block[i].dest_trans)==0){
                //It's a destination, money was added
                node->balance += trans->front->block[i].sent;
            }
            node = node->next;
        }
        
    }
    return;
}
//////////////////////LIST DESTROY//////////////////////////////////////////
void list_destroy(struct llist * lst) {//Destroy customer list
struct llnode * curnode = lst->front;
struct llnode * nextnode = NULL;
while (curnode) {
nextnode = curnode->next;
free(curnode);
curnode = nextnode;
}
free(lst);
}
void list_destroy_trans(struct transact_list * lst) {//Destroy transact list
struct transact_block * curnode = lst->front;
struct transact_block * nextnode = NULL;
while (curnode) {
nextnode = curnode->next;
free(curnode);
curnode = nextnode;
}
free(lst);
}
