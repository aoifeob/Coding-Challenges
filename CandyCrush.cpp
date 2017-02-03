#include <iostream>
#include <fstream>

using namespace std;

//function to check for matches after new candy falls down
bool check_match(int *board, int W, int H){
    int is_match = false;

    //scan array for 3 matching candies in a row
    //check horizontally
    // j is row index, i is column index
    for (int j=0;j<H;j++){ //check rows from top to bottom
        for (int i=1;i<=W-1;i++){ //check groups of 3 adjacent candies for matches
            if (board[i+W*j]==board[(i-1)+W*j] && board[i+W*j]==board[(i+1)+W*j]){
                is_match=true; //found a match
            }
            else{
                is_match=false; //didn't find a match
            }
        }
    }
    if (is_match==false){
        //check vertically
        // j is column index, i is row index
        for (int j=0;j<W;j++){//check columns from left to right
            for (int i=1;i<H-1;i++){ //check groups of 3 adjacent candies for matches
                if (board[j+W*i]==board[(j-1)+W*i] && board[j+W*i]==board[(j+1)+W*i]){
                    is_match=true; //found a match
                }
                else {
                    is_match=false;
                }
            }
        }
    }

    return is_match; //true if a match exists, false otherwise
}

//function to find a valid move on the board
void find_move(int *board, int W, int H){
    int r1,r2,c1,c2; //coordinates of candies to be swapped
    int chosen_move[4]; //array of coordinates
    int found_move = false;

    //scan array for possible moves
    //j is row index, i is column index
    for (int j=0;j<H;j++){ //check rows from top to bottom
        for (int i=1;i<=W;i++){ //check groups of 2 adjacent candies for matches
            if (board[i+W*j]==board[(i-1)+W*j]){
                if (i=1){ //check for valid swaps to the right of the candy pair
                    if (board[i+W*j]==board[(i+1)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=i;
                        c2=i+1;
                    }
                    else if (board[i+W*j]==board[(i+1)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i+1;
                    }
                    else {
                        found_move=false; //no move found
                    }
                }
                else if (i=W){ //check for valid swaps to the left of the candy pair
                    if (board[i+W*j]==board[(i-2)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=i;
                        c2=i-2;
                    }
                    else if (board[i+W*j]==board[(i-2)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i-2;
                    }
                    }
                    else{
                        found_move=false; //no move found
                    }
                }
                else if (i>1 && i<W){ //check for valid swaps on both sides of the pair
                    if (board[i+W*j]==board[(i-2)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=i;
                        c2=i-2;
                    }
                    else if (board[i+W*j]==board[(i-2)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i-2;
                    }
                    else if (board[i+W*j]==board[(i+1)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=1;
                        c2=i+1;
                    }
                    else if (board[i+W*j]==board[(i+1)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i+1;
                    }
                    else{
                        found_move=false; //no move found
                }
            }
            else{
                found_move=false; //didn't find a move
            }
        }
    }
    if (found_move==false){
        //check vertically
        // j is column index, i is row index
        for (int j=0;j<W;j++){//check columns from left to right
            for (int i=1;i<H-1;i++){ //check groups of 2 adjacent candies for matches
                if (board[j+W*i]==board[(j-1)+W*i] && board[j+W*i]==board[(j+1)+W*i]){
                    if (i=1){ //check for valid swaps to the right of the candy pair
                    if (board[i+W*j]==board[(i+1)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=i;
                        c2=i+1;
                    }
                    else if (board[i+W*j]==board[(i+1)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i+1;
                    }
                    else {
                        found_move=false; //no move found
                    }
                }
                else if (i=W){ //check for valid swaps to the left of the candy pair
                    if (board[i+W*j]==board[(i-2)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=i;
                        c2=i-2;
                    }
                    else if (board[i+W*j]==board[(i-2)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i-2;
                    }
                    }
                    else{
                        found_move=false; //no move found
                    }
                }
                else if (i>1 && i<W){ //check for valid swaps on both sides of the pair
                    if (board[i+W*j]==board[(i-2)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=i;
                        c2=i-2;
                    }
                    else if (board[i+W*j]==board[(i-2)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i-2;
                    }
                    else if (board[i+W*j]==board[(i+1)+W*(j-1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j-1;
                        c1=1;
                        c2=i+1;
                    }
                    else if (board[i+W*j]==board[(i+1)+W*(j+1)]){
                        found_move=true; //found a move
                        r1=j;
                        r2=j+1;
                        c1=i;
                        c2=i+1;
                    }
                    else{
                        found_move=false; //no move found
                    }
                }
                else {
                    found_move=false; //didn't find a move
                }
            }
        }
    }
    chosen_move[0]=r1;
    chosen_move[1]=c1;
    chosen_move[2]=r2;
    chosen_move[3]=c2;
}

int main(){
    int W; //game board width
    int H; //game board height
    int B; //number of buffer lines
    int M; //number of allowed moves
    int score=0; //player score
    int candy_len = 3; //length of candy to be destroyed
    int board[W*H]; //game board array
    int buffer[W*B]; //buffer array
    //cells of array referenced by [cX+W*rX]

   /*   Example Visualisation:
         (0 0 0 0 0)

         (1 2 3 4 5)
         (5 4 3 2 1)
         (1 2 4 5 3)

         (1 2 3 4 5)
         (6 3 2 5 1)
         (3 4 6 1 2)

         Integers greater than 0 represent candies
         0 represents a blank space
   */

    //open input file and assign values to correct variables
    ifstream input_file;
    input_file.open ("cc_input.txt");
    if (input_file.is_open()){
        while (){
        //read in file
        }
        input_file.close();
    }
    else {
        cout<<"Unable to open file.\n";
    }

    while (M>0){ //while more moves can be made
        find_move(board, W, H); //call function to find a move
        int r1 = chosen_move[0]; //assign row and column values for the move to variables
        int c1 = chosen_move[1];
        int r2 = chosen_move[2];
        int c2 = chosen_move[3];
        swap(board[c1+W*r1],board[c2+W*r2]); //swap two candies
        //write the values to be swapped
        ofstream output_file;
        output_file.open ("cc_output.txt", ios::app);
        if (output_file.is_open()){
            output_file << r1 << "," << c1 << "," << r1 << "," << c2 <<"\n";
            output_file.close;
        }
        else{
            cout<<"Unable to open file.\n"
            }
        is_match = true;
        while (is_match == true){ //while there is a match on the board
               score += candy_len^2; //add to score
               board[c1+W*r1] = 0;
               board[c2+W*r2] = 0; //replace candies with 0
               if(there are non-zero values in higher rows){ //check if there are non-zero values in higher rows and buffer rows
                   //shift non-zero values down and zero values up
               }
               is_match = check_match(board, W, H); //check for any new matches caused by falling candies
           }
           M--; //decrement remaining moves allowed
    }

    return 0;
}
