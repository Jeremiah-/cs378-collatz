#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair


#define USING_ARRAY true

#ifdef USING_ARRAY
int cycle_cache[1000000] = {}; 
#endif

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

    // let m = j / 2. If i < m, max_cycle_length(i, j) = max_cycle_length(m, j)
    if (i < (j >> 1)) {
        i = j >> 1;
    }

    for (int m = i; m <= j; ++m) {
        int val = m;
        current_cycle = 1;

        #ifdef USING_ARRAY
        if (cycle_cache[val] != 0) {
            current_cycle = cycle_cache[val];
        }
        #endif
        
        if (current_cycle == 1) {
            while (val > 1) {
                if (val % 2 == 0) {
                    val >>= 1;
                } else {
                    // this does 3n + 1 AND divides by 2
                    val += ((val >> 1) + 1);
                    ++current_cycle;
                }
                ++current_cycle;
            }
        }

        if (current_cycle > max_cycle) {
            max_cycle = current_cycle;
        }

        #ifdef USING_ARRAY
        cycle_cache[m] = current_cycle;
        #endif
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


int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}