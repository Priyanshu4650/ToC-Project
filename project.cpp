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

int result(int n1, int n2, char sign) {
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
			return -1;
		case '^' :
			return pow(n1, n2);
		default :
			cout << "Sign not available for now" << endl;
			return 0;
	}
}

int calculateExp(string input) {
	vector<int> containing_integers;
	int n = input.size();
	int temp = 0;

	for(int i=0;i<n;i++) {
		cout << "Now " << input[i] << " " << i << endl;
		if(isdigit(input[i])) {
			temp = temp * 10 + (input[i] - '0');
			cout << "Curr number " << temp << endl;
		}
		else if(input[i] == ' ') {
			if(temp != 0) {
				cout << "Pushed " << temp << endl;
				containing_integers.push_back(temp);
				temp = 0;
			}
		}	
		else {
			if(containing_integers.size() < 2) {
				cout << "Stack underflow" << endl;
				return -2;
			}
			int num2 = containing_integers[containing_integers.size() - 1];
			containing_integers.pop_back();
			int num1 = containing_integers[containing_integers.size() - 1];
			containing_integers.pop_back();

			cout << num1 << " " << num2 << endl;

			int newNum = result(num1, num2, input[i]);

			cout << "Result of the operation " << newNum << endl;

			if(newNum == -1) {
				cout << "Result se pehle" << endl;
				return -1;
			}
			
			containing_integers.push_back(newNum);
		}

		cout << "Current stack" << endl;
		for(int i=0;i<containing_integers.size();i++) {
			cout <<containing_integers[i] << " ";
		}
		cout << endl;
	}

	for(int i=0;i<containing_integers.size();i++) {
		cout <<containing_integers[i] << " ";
	}
	cout << endl;

	if(containing_integers.size() != 1) {
		cout << "final output se pehle " << endl;
		return -1;
	}

	int ans = containing_integers[containing_integers.size() - 1];
	containing_integers.pop_back();
	
	return ans;
}

int main() {
	string input;
    cout << "Enter the RPN expression: ";
    getline(cin, input);

	cout << "Input is : " << input << " of size " << input.size() << endl;
	
	int res = calculateExp(input);

	if(res == -1) {
		cout << "Error Occured" << endl;
	}

	else if(res == -2) {
		cout << "Stack underflow improper notation" << endl;
	}

	else {
		cout << "Result is : " << res << endl;
	}

	return 0;
}
