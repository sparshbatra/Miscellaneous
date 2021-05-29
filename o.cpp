#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool seive[1000000+1];
vector<ll> v;

int main()
{

    //Write code here
    memset(seive, false, sizeof(seive));
    seive[0]=true;
    seive[1]=true;
  

    for(ll i=2; i<1000001; ++i){
        if(seive[i] == false){
            v.push_back(i);
            // cout<<"false "<<i<<endl;
            for(ll j=i*i; j<1000001; j+=i){
                seive[j] = true;
            }
        }
       
    }
    ll t;cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll lb = lower_bound(v.begin(), v.end(), l)-v.begin();
        ll rb = lower_bound(v.begin(), v.end(), r)-v.begin();
        if(lb==rb){
            if(rb == v.size() || v[rb] > r){
                cout<<-1<<endl;

            }
            else if(v[rb] == r){
                cout<<0<<endl;
            }
        }
        else{
            if(v[rb] > r){
                cout<<v[rb-1]-v[lb]<<endl;
            }
            else if(v[rb] == r){
                cout<<v[rb]-v[lb]<<endl;
            }
        }

    }


}

// Rax, a school student, was bored at home in the pandemic. He wanted to play but there was no one to play with. He was doing some mathematics questions including prime numbers and thought of creating a game using the same. After a few days of work, he was ready with his game. He wants to play the game with you.


// GAME:

// Rax will randomly provide you a range [ L , R ] (both inclusive) and you have to tell him the maximum difference between the prime numbers in the given range. There are three answers possible for the given range.

// There are two distinct prime numbers in the given range so the maximum difference can be found.

// There is only one distinct prime number in the given range. The maximum difference in this case would be 0.

// There are no prime numbers in the given range. The output for this case would be -1.


// To win the game, the participant should answer the prime difference correctly for the given range.


// Example:

// Range: [ 1, 10 ]

// The maximum difference between the prime numbers in the given range is 5.

// Difference = 7 - 2 = 5


// Range: [ 5, 5 ]

// There is only one distinct prime number so the maximum difference would be 0.


// Range: [ 8 , 10 ]

// There is no prime number in the given range so the output for the given range would be -1.


// Can you win the game?



// Input Format
// The first line of input consists of the number of test cases, T

// Next T lines each consists of two space-separated integers, L and R



// Constraints
// 1<= T <=10

// 2<= L<= R<=10^6



// Output Format
// For each test case, print the maximum difference in the given range in a separate line. 

// Sample TestCase 1
// Input
// 5
// 5 5
// 2 7
// 8 10
// 10 20
// 4 5
// Output
// 0
// 5
// -1
// 8
// 0
// Explanation

// Test Case 1: [ 5 - 5 ] = 0

// Test Case 2: [ 7 - 2 ] = 5

// Test Case 3: No prime number in the given range. Output = -1

// Test Case 4: [ 19 - 11 ] = 8

// Test Case 5: The difference would be 0 since there is only one prime number in the given range.
// Time Limit(X):
// 0.50 sec(s) for each input.
// Memory Limit:
// 512 MB
// Source Limit:
// 100 KB
// Allowed Languages:
// C, C++, C++11, C++14, C#, Java, Java 8, Kotlin, PHP, PHP 7, Python, Python 3, Perl, Ruby, Node Js, Scala, Clojure, Haskell, Lua, Erlang, Swift, VBnet, Js, Objc, Pascal, Go, F#, D, Groovy, Tcl, Ocaml, Smalltalk, Cobol, Racket, Bash, GNU Octave, Rust, Common LISP, R, Julia, Fortran, Ada, Prolog, Icon, Elixir, CoffeeScript, Brainfuck, Pypy, Lolcode, Nim, Picolisp, Pike, pypy3


// Judge Environment


