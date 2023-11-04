/*
Programming Project

The aim of this project is to build a reverse polish notation calculator for polynomials over one variable in
reals that can do symbolic differentiation !
Reverse polish notation (RPN) or the postfix notation is a mathematical notation where the operator appears
after the operands. For example, “5 + 3” in postfix is “5 3 +”. This allows an mathematical expression to be
written without the need of using parenthesis.
You are given an expression in the RPN form and your task is to evaluate the RPN expression.
*/

#include<bits/stdc++.h>
using namespace std;

double result(double n1, double n2, char sign) {
	switch (sign) {
		case '+' :
			return n1 + n2;
		case '-' :
			return n1 - n2;
		case '*' :
			return n1 * n2;
		case '/' :
			if(n2 != 0) {
				return n1 / n2;
			}
			return -3.0;
		case '^' :
			return pow(n1, n2);
		default :
			cout << "Sign not available for now" << endl;
			return 0.0;
	}
}

double calculateExp(string input, vector<char>& operators) {
	stack<double> containing_integers;
	int n = input.size();
	int i = 0;

	while(i < n) {
		if(count(operators.begin(), operators.end(), input[i]) != 0) {
			if(containing_integers.size() < 2) {
				return -2.0;
			}
			int n2 = containing_integers.top();
			containing_integers.pop();
			int n1 = containing_integers.top();
			containing_integers.pop();

			int newNum = result(n1, n2, input[i]);

			if(newNum == -2.0) {
				return newNum;
			}

			containing_integers.push(newNum);
			i += 1;
		}

		else if(input[i] == ' ') {
			i += 1;
		}

		else {
			string s = "";
			while(input[i] != ' ' && i < input.size()) {
				s.push_back(input[i]);
				i += 1;
			}

			double num = stod(s);
			s = "";
			containing_integers.push(num);
		}
	}

	if(containing_integers.size() != 1) {
		cout << "final output se pehle " << endl;
		return -1.0;
	}

	double ans = containing_integers.top();
	containing_integers.pop();
	
	return ans;
}

int main() {
	string input;
    cout << "Enter the RPN expression: ";
    getline(cin, input);

	cout << "Input is : " << input << " of size " << input.size() << endl;

	vector<char> operators = {'+', '-', '*', '/', '^'};
	
	double res = calculateExp(input, operators);

	if(res == -1.0) {
		cout << "Error Occured" << endl;
	}

	else if(res == -2.0) {
		cout << "Stack underflow improper notation" << endl;
	}

	else if(res == -3.0) {
		cout << "Division by zero error" << endl;
	}

	else {
		cout << "Result is: " << fixed << setprecision(6) << res << endl;
	}

	return 0;
}
