// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"
#include <cassert> 
int lazycache[10000]={0};

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
	int temp;
    int m=0;

   
    if (i>j){
        temp=i;
        i=j;
        j=temp;
    }
    assert(i>0);
    assert(j>0);
    int s=1;

    for(int a=i; a<=j; a++){

        int c = 1;
         s=1;
        int n = a;
        while (n> 1) {
	       if((c<10000)&&(lazycache[(unsigned)c]!=0)){
	           s=s+lazycache[(unsigned)c];
	           c=1;
        	}
            if ((n % 2) == 0){
                n = (n / 2);
		          s++;
            }
            else{
                n = (3 * n) + 1;
		        s=s+2;
	        }
            ++c;
	    }
        assert(c > 0);
        if(c>m){
            m=c;
        }
	   if (s<=10000 && i<10000){
	   	lazycache[(unsigned)c]=s;
	   }
    }
    return m;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
