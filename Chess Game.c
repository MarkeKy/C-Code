#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 8

char* rook_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* bishop_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* queen_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);

//TODO:
char* pawn_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* knight_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);
char* king_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user);


void print_board(char board[SIZE][SIZE]){
    printf("   ");
    for(int i = 0; i < SIZE; i++)
       printf("%d ", i);
    printf("\n");

    for(int i = 0; i < SIZE; i++){
       printf("%d  ", i);
       for(int j = 0; j < SIZE; j++)
         printf("%c ", board[i][j]);
       printf("\n");
    }
    return;
}

int get_position(int *r, int *c){
        int success = scanf("%d %d", r, c);
        if(success == 2) return 1;
        success = scanf("%d,%d", r, c);
        if(success == 2) return 1;
        success = scanf("%d-%d", r, c);
        if(success == 2) return 1;
        success = scanf("(%d,%d)", r, c);
        if(success == 2) return 1;
        int ch; //Clear the input      
        while ((ch = getchar()) != '\n' && ch != EOF);
        return 0;
}

int main() {
    char board[SIZE][SIZE] = { 
        "RNBQKBNR",
        "PPPPPPPP",
        "........",
        "........",
        "........",
        "........",
        "pppppppp",
        "rnbqkbnr"
    };

    print_board(board);//prints the board

    bool user = true;
    char *moved_piece;
    int r, c, new_r, new_c;

    //We skip any kind of check for game end or winning conditions, so we have an endless loop
    while(1){ 
        printf("User %d: Please choose a piece (provide r and c):\n", user ? 1 : 2); 
        while(1){
            if(get_position(&r, &c))
               break;
            printf("Error. Could not read input, try again.\n");
        } 
        printf("User %d: Please provide destination (provide new_r and new_c):\n", user ? 1 : 2); 
        while(1){
            if(get_position(&new_r, &new_c))   
               break;
            printf("Error. Could not read input, try again.\n");
        }

        int success = 0;

        //try all moves until one succeeds
        moved_piece = rook_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
           printf("Rook moved successfully!\n");
           success = 1;
        }
        moved_piece = bishop_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
           printf("Bishop moved successfully!\n");
           success = 1;
        }
        moved_piece = queen_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
           printf("Queen moved successfully!\n");
           success = 1;
        }
        //Uncomment to test other moves
        moved_piece = pawn_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
          printf("Pawn moved successfully!\n");
          success = 1;
        }
        moved_piece = knight_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
          printf("Knight moved successfully!\n");
          success = 1;
        }
        moved_piece = king_move(board, r, c, new_r, new_c, user);
        if(moved_piece) {
          printf("King moved successfully!\n");
          success = 1;
        }

        if(success) {
          print_board(board);
          user = !user; //change turn
        } else{
          printf("Error. Could not make move, invalid position or piece. Please try again.\n\n");
        }
    }

    return 0;
}

char* rook_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
    //Validate the piece is a rook
    char piece = board[r][c];
    if ((user && piece != 'r') || (!user && piece != 'R'))
        return NULL;

    //Validate the move is in a straight line
    if (r != new_r && c != new_c)
        return NULL;

    //Validate we moved
    if(r == new_r && c == new_c)
        return NULL;


    //check all positions aside from start/end
    //Validate no pieces are in the path
    if(r == new_r && c > new_c){
        for(int i = new_c+1; i < c; i++)
          if(board[r][i] != '.')
             return NULL;
    } else if(r == new_r && c < new_c){
        for(int i = c+1; i < new_c; i++)
          if(board[r][i] != '.')
             return NULL;
    }

    if(c == new_c && r > new_r){
        for(int i = new_r+1; i < r; i++)
          if(board[i][c] != '.')
            return NULL;
    } else if(c == new_c && r < new_r){
        for(int i = r+1; i < new_r; i++)
          if(board[i][c] != '.')
            return NULL;
    }

    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;

    //Move the rook and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
}

char* bishop_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
    //Validate the piece is a bishop
    char piece = board[r][c];
    if ((user && piece != 'b') || (!user && piece != 'B'))
        return NULL;

    //Validate the move is diagonal
    if (abs(new_r - r) != abs(new_c - c))
        return NULL;

    //Validate we moved
    if(r == new_r && c == new_c)
        return NULL;

    //Check if a piece is in the way diagonally (4 directions)
    if (new_r > r && new_c > c) { // moving down-right
        for (int i = r + 1, j = c + 1; i < new_r && j < new_c; i++, j++) 
            if (board[i][j] != '.') 
                return NULL;
    } else if (new_r > r && new_c < c) { // moving down-left
        for (int i = r + 1, j = c - 1; i < new_r && j > new_c; i++, j--) 
            if (board[i][j] != '.') 
                return NULL;
    } else if (new_r < r && new_c > c) { // moving up-right
        for (int i = r - 1, j = c + 1; i > new_r && j < new_c; i--, j++) {
            if (board[i][j] != '.') 
                return NULL;
            printf("%c\n", board[i][j]);
            }
    } else if (new_r < r && new_c < c) {// moving up-left
        for (int i = r - 1, j = c - 1; i > new_r && j > new_c; i--, j--) 
            if (board[i][j] != '.') 
                return NULL;
    }

    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;

    //Move the rook and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
}

char* queen_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user) {
    char piece = board[r][c];
    char queen_piece = user ? 'q' : 'Q';
    char rook_piece = user ? 'r' : 'R';
    char bishop_piece = user ? 'b' : 'B';

    if (piece != queen_piece)
        return NULL;

    //Check rook move for queen
    board[r][c] = rook_piece;
    char* moved_piece = rook_move(board, r, c, new_r, new_c, user);
    if (moved_piece != NULL) { //Success
        *moved_piece = queen_piece;
        return moved_piece;
    }

    //Check bishop move for queen
    board[r][c] = bishop_piece;
    moved_piece = bishop_move(board, r, c, new_r, new_c, user);
    if (moved_piece != NULL) { //Success
        *moved_piece = queen_piece;
        return moved_piece;
    }

    //Revert changes and return NULL on failure
    board[r][c] = queen_piece;
    return NULL;
}
char* pawn_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user){
    //Validate the piece is a pawn
    char piece = board[r][c];
    if ((user && piece != 'p') || (!user && piece != 'P'))
        return NULL;
    
    //Validate we moved
    if(r == new_r && c == new_c)
        return NULL;
        
    //Validate initial Move
    if(r == 6 || r == 1){//initial move allows 2 place movement
        if(abs(r-new_r) == 2){//we are trying to move two places ahead
            if (new_c != c)// we didn't move vertically
                 return NULL;//Can only move 2 places veritcally at start
            if((user && board[r-1][c] != '.')|| (!user && board[r+1][c] != '.'))//we moved when piece was there
                 return NULL;

    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
      return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
      return NULL;

    //Move the pawn and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
        }
    }
    //End of intial moves
    
    //Check the destination (can't be friendly piece)
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;
     
    //Validate regular move  
    if((abs(r - new_r) != 1 && c != new_c) || (abs(r-new_r) != 1 && abs(c-new_c)!= 1))//we didn't move one place vertically or
        return NULL;//we didn't move one place vertically and one place horizontally (i.e., 1 place diagonally), thus invalid move
    if (user){
        if (r - new_r < 0)
         return NULL;//user can't move backwards
    }
    if (!user){
        if(new_r - r < 0)//enemy moved backwards
           return NULL;
    }
    if(abs(r - new_r) == 1 && c == new_c){
        if (dest_piece != '.')
            return NULL;//can't move 1 forward if any piece is there
    }    
       
    //Validate capture 
    if(abs(r-new_r) == 1 && abs(c - new_c) == 1){
        if (dest_piece == '.')
             return NULL;
        //If destination is friendly piece or empty, can't move diagonally
       //Since we already checked if destination piece is friendly, we must
       //check if it's empty, hence last check
    }
    //Move the pawn and capture if necessary (and promote if necessary)
    if ((user && new_r == 0) || (!user && new_r == 7)){
        char new_piece;
        printf("\nWhich piece would you like to replace the pawn with (q,r,b,n):");
        scanf(" %c", &new_piece);
        if (user == false){//enemy piece
            new_piece = toupper(new_piece);
        }
        board[new_r][new_c] = new_piece;
        board[r][c] = '.';

        return &board[new_r][new_c];
        
    }
    //Move the pawn and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
        
}
char* knight_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user){
    //Validate the piece is a Knight
    char piece = board[r][c];
    if ((user && piece != 'n') || (!user && piece != 'N'))
        return NULL;
    
    //Validate we moved
    if(r == new_r && c == new_c)
        return NULL;
    
    //Jump Validation
    if (abs(r-new_r) == 1){//they moved 1 vertically 
        if(abs(c-new_c) != 2){
            return NULL;//They didn't move twice horizontally to the left or right thus incorrect
        }
    }           
    else if (abs(r-new_r) == 2){//they moved 2 vertically 
        if(abs(c-new_c) != 1){
            return NULL;//They didn't move oncehorizontally to the left or right thus incorrect
        }
    }
    else if (abs(c-new_c) == 1){//they moved 1 horizontally
        if(abs(r-new_r) != 2){
            return NULL;//They didn't move twice vertically to the left or right thus incorrect
        }
    }
    else if (abs(c-new_c) == 2){//they moved 2 horizontally
        if(abs(r-new_r) != 1){
            return NULL;//They didn't move once vertically to the left or right thus incorrect
        }
    }
    else{
        return NULL;//no valid starting move has been made or executed properly
    }
    
    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;

    //Move the Knight and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c];
}
char* king_move(char board[SIZE][SIZE], int r, int c, int new_r, int new_c, bool user){
    //Validate the piece is a King
    char piece = board[r][c];
    if ((user && piece != 'k') || (!user && piece != 'K'))
        return NULL;
    
    //Validate we moved
    if(r == new_r && c == new_c)
        return NULL;
        
    //Validate we moved 1 place
    if (abs(new_r - r) != 1 && abs(new_c - c) != 1)
              return NULL;
                       
    //Check the destination
    char dest_piece = board[new_r][new_c];
    if(user && (dest_piece >= 'a' && dest_piece <= 'z'))
       return NULL;
    if(!user && (dest_piece >= 'A' && dest_piece <= 'Z'))
       return NULL;

    //Move the King and capture if necessary
    board[new_r][new_c] = piece;
    board[r][c] = '.';

    return &board[new_r][new_c]; 
           
}
