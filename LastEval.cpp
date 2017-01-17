/*
Note: all the adge cases are not tested
*/

#include <iostream>
#include <stack>
using namespace std;
//Helper Function 1: 
//pop 2 values from vStack and one from op.
//push the result to val stack
void applyOp(stack<double> &vStack, stack<char> &opStack){
    double rightOperand = vStack.top();
    vStack.pop();
    double leftOperand = vStack.top();
    vStack.pop();
    char op = opStack.top();
    opStack.pop();
    double result = 0;
    switch (op){
        case '+':
            result = leftOperand + rightOperand;
            break;
        case '-':
            result = leftOperand - rightOperand;
            break;
        case '*':
            result = leftOperand * rightOperand;
            break;
        case '/':
        	if(rightOperand==0)
        		throw invalid_argument("Cannot divide by zero");
            result = leftOperand / rightOperand;
            break;
    }

    vStack.push(result);
}
//helper function 2:
//see if the op in hand and the op. on of opStack has precedence  
bool hasPrecedence(char op, char prevOp){
     bool evaluate = false;

    switch (op)
    {
        case '+':
        case '-':
            evaluate = (prevOp != '(');
            break;
        case '*':
        case '/':
            evaluate = (prevOp == '*' || prevOp == '/');
            break;
        case ')':
            evaluate = true;
            break;
    }

    return evaluate;
 }
//Helper 3: apply operation 
void ProcessInputOperator(char op, stack<double> &vStack, stack<char> &opStack){
    while (!opStack.empty() && hasPrecedence(op, opStack.top()))
        applyOp(vStack, opStack);
    opStack.push(op);
}
//Helper 4: get the all digits of the number
int ProcessInputNumber(string exp, int pos, stack<double> &vStack){
   string value = "";
    while (pos < exp.size() && exp[pos] >= '0' && exp[pos] <= '9' || exp[pos]=='.' ){
        //value = 10 * value + (int)(exp[pos++] - '0');//works for int 
         value = value + exp[pos++] ;
    }
         vStack.push(stod(value));
    return pos;
}
//Helper 5: if ) eval. until (
void ProcessClosingParenthesis(stack<double> &vStack, stack<char> &opStack){
    while (opStack.top() != '(')
        applyOp(vStack, opStack);
    opStack.pop(); // Remove the opening parenthesis
}

//Bringing it all together

double EvaluateExpression(string exp){
    stack<double> vStack ; //store values 
    stack<char> opStack ; //store Opertations 
    opStack.push('('); // Implicit opening parenthesis

    int pos = 0;
    while (pos <= exp.size()){
        if (pos == exp.size() || exp[pos] == ')'){ //if ) 
            ProcessClosingParenthesis(vStack, opStack); //evalueate what is inside ()
            pos++;
        }
        else if (exp[pos] >= '0' && exp[pos] <= '9'){ // if number
            pos = ProcessInputNumber(exp, pos, vStack); //Get the all the digits of that number
        }
        else {
            ProcessInputOperator(exp[pos], vStack, opStack); //apply operation
            pos++;
        }
    }

    return vStack.top(); // Result 

}

int main(){
	string s;
	cout<<"Write the Expression whiteout space: ";
	cin>>s;
 	double l = EvaluateExpression(s);
	cout<<"The string evaluates to: "<<l;

	return 0; 
}