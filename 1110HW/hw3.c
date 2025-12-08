#include <stdio.h>
#define N_SUIT 4
#define N_CARD 13

int main() {
    // DO SOMETHING HERE:
    // DECLARE AND INITIALIZE A 2D ARRAY.
    // YOU MAY ALSO USE FOUR 1D ARRAYS.
    int deck[N_SUIT][N_CARD] = {0};
    int n;

  	// The extra space in specifier helps to remove
    // the following '\n' in each line of input.
    scanf("%d", &n); 

    for(int i=0; i<n; i++) {
        char suit;
        int num;

      	// The extra space in specifier helps to remove
        // the following '\n' in each line of input.
        scanf(" %c %d", &suit, &num);

      	// DO SOMETHING HERE: UPDATE CARD DECK
        if(suit == 'S'){
            deck[0][num - 1] = num;
        }
        else if(suit == 'H'){
            deck[1][num - 1] = num;
        }
        else if(suit == 'C'){
            deck[2][num - 1] = num;
        }
        else if(suit == 'D'){
            deck[3][num - 1] = num;
        }
    }
    for(int i = 0;i < N_SUIT;i++){
        for(int j = 0;j < N_CARD;j++){
            if(deck[i][j] == 0){
                if(i == 0){
                    printf("S %d\n", j + 1);
                }
                else if(i == 1){
                    printf("H %d\n", j + 1);
                }
                else if(i == 2){
                    printf("C %d\n", j + 1);
                }
                else if(i == 3){
                    printf("D %d\n", j + 1);
                }
            }
        }
    }
  	// DO SOMETHING HERE: PRINT MISSING CARDS
    return 0;
}
