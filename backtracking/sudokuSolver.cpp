#include "sudokuSolver.h"
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define um unordered_map<int, int>
#define si set<int>
#define sc set<char>
#define usi set<int>
#define usf set<float>

template <typename P>
void swapp(P &a, P &b) {
    P temp = a;
    a = b;
    b = temp;
}

/* FUNCTIONS */
#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define lm(it, map) for (auto it = map.begin(); it != map.end(); it++)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }



/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/* clang-format on */

// Gets an option taking into consideration usedOptions and allowed values depending on row, column and grid.
bool SudokuSolver::getOption(Square &sq)
{
    f(i, 0, 9)
    {
        if (!inRow(sq, i) && !inColumn(sq, i) && !inGrid(sq, i) && !sq.usedOptions[i])
        {
            sq.val = i;
            sq.usedOptions[i] = 1;
            return true;
        }
    }
    return false;
}

bool SudokuSolver::inRow(Square &sq, int possibleOption)
{
    f(i, 0, 9)
    {
        if (grid[sq.row][i].val == i)
            return true;
    }
    return false;
}

bool SudokuSolver::inColumn(Square &sq, int possibleOption)
{
    f(i, 0, 9)
    {
        if (grid[i][sq.row].val == i)
            return true;
    }
    return false;
}

bool SudokuSolver::inGrid(Square &sq, int possibleOption)
{
    int start_row = 0;
    int start_col = 0;
    if (sq.row < 4)
        start_row = 0;
    if (sq.row < 7)
        start_row = 3;
    else
    {
        start_row = 6;
    }
    if (sq.col < 4)
        start_col = 0;
    if (sq.col < 7)
        start_col = 3;
    else
    {
        start_col = 6;
    }
    f(row, start_row, start_row + 3)
    {
        f(column, start_col, start_col + 3)
        {
            if (grid[row][column].val == possibleOption)
                return true;
        }
    }
    return false;
}

unordered_map<int, Square[9]> SudokuSolver::parseInput()
{
    unordered_map<int, Square[9]> grid;
    f(i, 0, 9)
    {
        string s;
        cin >> s;
        f(j, 0, 9)
        {
            if (s.at(j) != '.')
                grid[i][j] = {.row = i, .col = j, .val = stoi(string(1, s.at(j)))};
        }
    }
    return grid;
}

void SudokuSolver::printGrid()
{
    f(i, 0, 9)
    {
        for (Square &sq : grid[i])
        {
            cout << sq.val;
        }
        cout << "\n";
    }
}

void SudokuSolver::solver(int r, int c)
{
    cout << grid[r][c].val << " \n";
    if (r == 8 && c == 8)
    {
        cout << "Solved";
    }
    else if (grid[r][c].val == 0)
    {
        bool anyOption = getOption(grid[r][c]);
        if (!anyOption)
        {
            Square *last_sq = changed_squares.top();
            changed_squares.pop();
            last_sq->val = 0;
            last_sq->possibleOption = false;
            solver(last_sq->row, last_sq->col);
        }
        else
        {
            changed_squares.push(&grid[r][c]);
        }
    }
    else if (c == 8)
    {
        solver(r + 1, 0);
    }
    solver(r, c + 1);
}

/* Main()  function */
int main()
{
    SudokuSolver sudokuSolver = SudokuSolver();
    sudokuSolver.solver(0, 0);
    // if isSolved : print board
    sudokuSolver.printGrid();
    return 0;
}

/*

.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.

*/