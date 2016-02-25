#include <iostream>
#include <vector>
using namespace std;

//I like to think that this namespace makes these global variables a little less bad, but in reality it may not. Boo globals.
class customStack
{
public:
    vector<int> stack;
    string name;
    customStack(string nName) : name(nName)
    {}
};
namespace tylerSpace{

    int moves = 0;
    customStack A("A");
    customStack B("B");
    customStack C("C");
}
using namespace tylerSpace;

void display(customStack A, customStack B, customStack C);

void hanoi(int rings, customStack& A, customStack& B, customStack& C);


int main()
{
    int rings;
    cout << "How many rings are on tower A?" << endl;
    cin >> rings;
    for(int i = rings-1; i > -1; --i)
    {
        A.stack.push_back(i);
    }

    display(A, B, C);

    hanoi(rings, A, B, C);
    cout << "Number of Moves: " << moves << endl;

    return 0;
}

void hanoi(int rings, customStack& start, customStack& aux, customStack& end)
{
    if(rings == 1)
    {
        end.stack.push_back(start.stack[start.stack.size()-1]);
        moves++;
        start.stack.pop_back();
        cout << start.name << " -> " << end.name << endl;
        display(A, B, C);
    }
    else
    {
        hanoi(rings-1, start, end, aux);
        end.stack.push_back(start.stack[start.stack.size()-1]);
        moves++;
        start.stack.pop_back();
        cout << start.name << " -> " << end.name << endl;
        display(A, B, C);
        hanoi(rings-1, aux, start, end);
    }
}


void display(customStack A, customStack B, customStack C)
{
    cout << "** Move Number: " << moves << endl;

    cout << "[";
    for(int i = 0; i < A.stack.size(); ++i)
    {
        if(i != A.stack.size()-1)
        {
            cout << A.stack[i] << ", ";
        }
        else
        {
            cout << A.stack[i] << "]" << endl;
        }
    }
    if(A.stack.size() == 0)
    {
        cout << "]" << endl;
    }

    cout << "[";
    for(int i = 0; i < B.stack.size(); ++i)
    {
        if(i != B.stack.size()-1)
        {
            cout << B.stack[i] << ", ";
        }
        else
        {
            cout << B.stack[i] << "]" << endl;
        }
    }
    if(B.stack.size() == 0)
    {
        cout << "]" << endl;
    }

    cout << "[";
    for(int i = 0; i < C.stack.size(); ++i)
    {
        if(i != C.stack.size()-1)
        {
            cout << C.stack[i] << ", ";
        }
        else
        {
            cout << C.stack[i] << "]" << endl;
        }
    }
    if(C.stack.size() == 0)
    {
        cout << "]" << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}