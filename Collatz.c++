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
    // <your code>
    assert (i > 0 && j > 0);
    assert (i < 1000000 && j < 1000000);

    int max_cycle = 1;
    int current_cycle = 1;
    int temp;

    if (i > j) {
        temp = j;
        j = i;
        i = temp;
    }

    for (int m = i; m <= j; ++m) {
        int val = m;
        current_cycle = 1;

        while (val > 1) {
            if (val % 2 == 0) {
                val = val / 2;
            } else {
                val = 3 * val + 1;
            }
            ++current_cycle;
        }

        if (current_cycle > max_cycle) {
            max_cycle = current_cycle;
        }
    }

    assert (max_cycle > 0);
    return max_cycle;}

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
