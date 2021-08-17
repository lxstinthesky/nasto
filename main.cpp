/*
 * Authors: Raphael, Paul, Henrik
 * solving navier-stokes-equation as mentioned in Demtröder 1 p. 227 equ. 8.35a
*/

#include <iostream>
#include <cmath>
#include <fstream>

//physical variable declaration here
#define ETA 1 //viscosity
#define RHO 1 //density
#define NUM 100 //SHOULD BE EVEN NUMBER

using namespace std;

//global variable declarations here

double psi[NUM][NUM];

//function declarations here
void init();

int main() {
    init();
    for(int n = 0; n < NUM/2; n++){
        int i = n;
        int j = n;
        for(i = i + 1; i< NUM-n-1; i++){
            psi[i+1][j] = 2 * psi[i][j] - psi[i-1][j];
        }
        for(j = j + 1; j < NUM-n-1; j++){
            psi[i][j+1] = 2 * psi[i][j] - psi[i][j-1];
        }
        for(; i > n+1; i--){
            psi[i-1][j] = 2 * psi[i][j] - psi[i+1][j];
        }
        for(; j > n+1; j--){
            psi[i][j-1] = 2 * psi[i][j] - psi[i][j+1];
        }
    }
    return 0;
}

//auxiliary function implementation here
void init(){
    int i;
    //setting bottom edge
    for(i = 0; i < NUM; i++){
        psi[i][0] = 1;
    }
    //setting right edge
    for(i = 0; i < NUM; i++){
        psi[NUM-1][i] = 0;
    }
    //setting upper edge
    for(i = 0; i < NUM; i++){
        psi[i][NUM-1] = 1;
    }
    //setting left edge
    for(i = 0; i < NUM; i++){
        psi[0][i] = 0;
    }
}

//kannst du des jetzt auch sehen??