#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

// sort ans arry using recursion

// insert function
void insert_vector(vector<int> &arr, int temp)
{
    if (arr.size() == 0 || temp >= arr[arr.size() - 1])
    {
        arr.push_back(temp);
        return;
    }
    int val = arr[arr.size() - 1];
    arr.pop_back();
    insert_vector(arr, temp);
    arr.push_back(val);
}

void sortUsing_recursion(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return;
    }

    int temp = arr[arr.size() - 1];
    arr.pop_back();
    sortUsing_recursion(arr);
    insert_vector(arr, temp);
}

// sort an stack using recursion
void insert_stack(stack<int> &s, int temp)
{
    if (s.empty() || temp <= s.top())
    {
        s.push(temp);
        return;
    }
    int top = s.top();
    s.pop();
    insert_stack(s, temp);
    s.push(top);
}
void sort_stack(stack<int> &s)
{
    // Your code here
    if (s.empty() || s.size() == 1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sort_stack(s);
    insert_stack(s, temp);
}

// // sort an queue
// void insert_queue(queue<int>q,int temp){
//     if(q.empty()||)
// }

void sort_queue(queue<int> &q)
{
    if (q.empty() || q.size() == 1)
    {
        return;
    }
    int temp = q.front();
    q.pop();
    sort_queue(q);
    // insert_queue(q,temp);
}

// delete middle element from the stack using recursion
void deleteMiddle_stack(stack<int> &s, int i)
{
    if (i == 1 || s.empty())
    {
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    deleteMiddle_stack(s, --i); // Decrement i before making the recursive call
    s.push(val);
}

// reverse a stack using recursion

void reverse_stack_helper(stack<int> &s, int temp)
{

    if (s.empty())
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    reverse_stack_helper(s, temp);
    s.push(val);
}

void reverse_stack(stack<int> &s)
{
    if (s.size() <= 1)
    {
        return;
    }
    int val1 = s.top();
    s.pop();
    reverse_stack(s);
    reverse_stack_helper(s, val1);
}

// generating gramer using recursion
// =====================================
int generate_gramer(int n, int k)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }
    int mid = pow(2, n - 1); // finding the mid
    if (k <= mid)
    {
        return generate_gramer(n - 1, k);
    }

    return !generate_gramer(n, k - mid);
}

// ===============================================
// Tower of Hanoi
void tower_Hanoi(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        cout << "Moving n=" << n << " from " << from << "To " << to << endl;
        return;
    }
    // from->aux
    tower_Hanoi(n - 1, from, aux, to);
    cout << "Moving n=" << n << " from " << from << "To " << to << endl;

    // aux->to
    tower_Hanoi(n - 1, aux, to, from);
}

// print all subsets of string
void pritnSubsets(string input, string output)
{
    if (input.size() == 0)
    {
        cout << "Sub string is " << output << endl;
        return;
    }

    string in = input;
    string out = output;

    // agr choose kiya
    pritnSubsets(in.erase(0, 1), out + in[0]);
    // agr choose nhii kiya
    pritnSubsets(input.erase(0, 1), output);
}
// print all substring
void printSubstring(string str)
{
    if (str.size() < 1)
    {
        return;
    }
    cout << "SubString is " << str << endl;
    printSubstring(str.erase(0, 1));
}

// Permutation with spaces
void permutation_with_spaces(string output, string input)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    if (input.size() == 1)
    {
        cout << output + input << endl;
        return;
    }
    string in = input;
    string out = output;

    // agr chosse kiya
    string output1 = out + in[0] + "_";
    permutation_with_spaces(output1, in.erase(0, 1));

    // agr choose nhii kiya
    string output2 = output + input[0];
    permutation_with_spaces(output2, input.erase(0, 1));
}

void permutation_with_cases(string output, string input)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }

    //  agr number hai to
    if (input[0] <= 57 && input[0] >= 48)
    {
        string output1 = output + input[0];
        permutation_with_cases(output1, input.erase(0, 1));
        return;
    }
    //
    // agr uper case me change kiya hai tb
    string in = input;
    string out = output;
    string output1 = output + char(input[0] - 32);
    permutation_with_cases(output1, input.erase(0, 1));

    // agr chnage nhii kiya
    string output2 = out + in[0];
    permutation_with_cases(output2, in.erase(0, 1));
}

// Generate all Balanced Parentheses
void generate_parentheses(string output, int o, int c)
{
    if (c == 0 && o == 0)
    {
        cout << output << endl;
        return;
    }
    // if all opening brackets all over
    if (o == 0)
    {
        generate_parentheses(output + ')', o, c - 1);
        return;
    }

    //  if it is alredy balanced ex.. () then we can only use ( , (()) +(
    if (o == c)
    {
        generate_parentheses(output + '(', o - 1, c);
        return;
    }
    generate_parentheses(output + '(', o - 1, c);
    generate_parentheses(output + ')', o, c - 1);
}

// Print N-bit binary numbers having more 1’s than 0’s for any prefix

void print_Nbit_binary_numbers_having_moreOneThanZero(string output, int z, int o, int n)
{
    if (z + o == n && o >= z)
    {
        cout << output << endl;
        return;
    }
    if (z + o == n)
    {
        return;
    }

    print_Nbit_binary_numbers_having_moreOneThanZero(output + "1", z, o + 1, n);

    print_Nbit_binary_numbers_having_moreOneThanZero(output + "0", z + 1, o, n);
}

int main()
{
    // Input:  N = 3
    // Output: 111 110 101
    print_Nbit_binary_numbers_having_moreOneThanZero("", 0, 0, 3);

    cout
        << "\nCode executed success fully";
    return 0;
}