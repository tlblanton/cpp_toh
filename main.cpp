#include <iostream>
#include <vector>
#include <string>

using namespace std;

//I like to think that this namespace makes these global variables a little less bad, but in reality it may not. Boo globals.
namespace tylerSpace
{
    vector<int> A;
    vector<int> B;
    vector<int> C;
}


using namespace tylerSpace;

void display(vector<int> A, vector<int> B, vector<int> C);

void hanoi(int rings, vector<int>& A, vector<int>& B, vector<int>& C);





int main()
{
    int rings;


    cout << "How many rings are on tower A?" << endl;
    cin >> rings;
    for(int i = rings; i > 0; --i)
    {
        A.push_back(i);
    }

    display(A, B, C);

    hanoi(rings, A, B, C);

    return 0;
}


void hanoi(int rings, vector<int>& start, vector<int>& aux, vector<int>& end)
{
    if(rings == 1)
    {
        end.push_back(start[start.size()-1]);
        start.pop_back();
        display(A, B, C);
    }
    else
    {
        hanoi(rings-1, start, end, aux);
        end.push_back(start[start.size()-1]);
        start.pop_back();
        display(A, B, C);

        hanoi(rings-1, aux, start, end);
    }
}


void display(vector<int> A, vector<int>B, vector<int>C)
{
    cout << "[";
    for(int i = 0; i < A.size(); ++i)
    {
        if(i != A.size()-1)
        {
            cout << A[i] << ", ";
        }
        else
        {
            cout << A[i] << "]" << endl;
        }
    }
    if(A.size() == 0)
    {
        cout << "]" << endl;
    }

    cout << "[";
    for(int i = 0; i < B.size(); ++i)
    {
        if(i != B.size()-1)
        {
            cout << B[i] << ", ";
        }
        else
        {
            cout << B[i] << "]" << endl;
        }
    }
    if(B.size() == 0)
    {
        cout << "]" << endl;
    }

    cout << "[";
    for(int i = 0; i < C.size(); ++i)
    {
        if(i != C.size()-1)
        {
            cout << C[i] << ", ";
        }
        else
        {
            cout << C[i] << "]" << endl;
        }
    }
    if(C.size() == 0)
    {
        cout << "]" << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}