/*
 * Authors: Raphael, Paul, Henrik Saftig
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

//double psi[NUM + 1][NUM + 1];
double error , psi[NUM + 1][NUM + 1]={{0}} , psin[NUM + 1][NUM + 1];

//function declarations here
void init();
void jacobi();


ofstream File;
ofstream Filet;

int main() {

    File.open("data.dat");
    Filet.open("init.dat");
    init();

    jacobi();

    Filet.close();
    File.close();

    return 0;
}

//auxiliary function implementation here
void init(){
    for(int i = 0; i < NUM+1; i++){
        for(int j = 0; j < NUM+1; j++){
            psi[i][j] = i*i-j;
            psin[i][j] = psi[i][j];
            Filet << i << ";" << j << ";" << psi[i][j] << endl;
        }
    }

    /*
    //setting right and left edge
    for(i = 0; i < NUM+1; i++){
        psi[NUM][i] = 0;
        psi[0][i] = 0;

        File << NUM << ";" << i << ";" << psi[NUM][i] << endl;
        File << 0 << ";" << i << ";" << psi[0][i] << endl;
    }
    //setting bottom and upper edge
    for(i = 0; i < NUM+1; i++) {
        psi[i][0] = 1;
        psi[i][NUM] = 0;

        File << i << ";" << 0 << ";" << psi[i][0] << endl;
        File << i << ";" << NUM << ";" << psi[i][NUM] << endl;
    }
    */
}

void jacobi () {
    int i, j, k;
    k = 0;

    do {
        error = 0.0;
        for (i = 1; i < NUM; i++) {
            for (j = 1; j < NUM; j++) {
                psin[i][j] = 1.0/4.0*(psi[i + 1][j] + psin[i - 1][j] + psi[i][j + 1] + psin[i][j - 1]);
                error += abs(psin[i][j] - psi[i][j]);
            }}
        for (i = 1; i < NUM; i++) {
            for (j = 1; j < NUM; j++) {
                psi[i][j] = psin[i][j];
            }}
        error /= NUM*NUM;
        k++;

    } while (error > 1.e-9 && k < 10000);
    error /= NUM*NUM;

    for(i = 0; i < NUM+1; i++){
        for(j = 0; j < NUM+1; j++){
            File << i << ";" << j << ";" << psin[i][j] << endl;
        }
    }
}
