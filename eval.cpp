#include <iostream>
using namespace std; 
class stack{
public:
	struct Node{
		int data; 
		Node *next; 
	};
	stack(){
		head = NULL;
	}
	void push(int val){
		Node* n = new Node(); 
		n->data=val; 
		n->next = head; 
		head = n;
	}
	void display(){
		Node *n;
		n=head;
		while(n!=NULL){
			cout<<n->data;
			n=n->next;
		}
	}
	int pop(){
		Node *n = head;
		head=head->next;
		return n->data;
	}
	int top(){
		return head->data;
	}
	bool empty(){
		return head==NULL;
	}
private:
	Node* head;
};


bool isOp(char a){
	return a=='*' || a=='/' ||a=='+' ||a== '-';
}
bool isNum(char a){
	return a>='0' && a<='9';
}

 int applyOp(char op, int b, int a){
        switch (op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw runtime_error("Cannot divide by zero");
            return a / b;
        }
        return 0;
    }
    bool hasPrecedence(char op1, char op2){
        if (op2 == '(' || op2 == ')')
            return false;
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return false;
        else
            return true;
    }


int main(){
	stack val;
	stack op;
	string exp = "100 *  2 + 12 -2";
	string num ="";
	int inum;
	int i=0; 


	for(int i=0; i<exp.size();i++){
		if(exp[i]==' ') continue;
		if(isNum(exp[i])) num=num+exp[i];
		else if(exp[i]=='(') op.push(exp[i]);
		else if(exp[i]==')'){
			while(op.top()!='('){
					val.push(applyOp(op.pop(), val.pop(), val.pop()));
				}
				op.pop();
		}
		else if(isOp(exp[i])){
			val.push(stoi(num));
				while(!op.empty() && hasPrecedence(exp[i],op.top())){
					val.push(applyOp(op.pop(),val.pop(), val.pop()));
				}
			op.push(exp[i]);
			num="";
		}

	}
	val.push(stoi(num));
	while(!op.empty()){
				val.push(applyOp(op.pop(), val.pop(), val.pop()));
			}

			cout<<val.pop();

	return 0;
}