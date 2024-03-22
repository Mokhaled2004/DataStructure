#include <iostream>
#include <stack>
using namespace std;

bool arePaired(char open ,char close) {

    if (open == '(' && close == ')' ){
        return true;
    }
    else if (open == '{' && close == '}' ){
        return true;
    }
    else if (open == '[' && close == ']' ){
        return true;
    }
    return false;

}


bool areBalanced (string exp) {

    stack <char> s;
    int length  = exp.length();
    for (int i = 0;i<length;i++) {

        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')

            s.push(exp[i]);

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {

            if (s.empty() || !arePaired(s.top(),exp[i])) {
                    return  false;
                }
                else {
                    s.pop();
                }

        }

        return s.empty() ? true : false;

    }

}



int main()
{

    string expression;
    cout << "Enter an expression:";
    cin >> expression;
    if (areBalanced(expression))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";






    return 0;
}

