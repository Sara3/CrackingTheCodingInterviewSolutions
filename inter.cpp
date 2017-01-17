#include <iostream>
//#include <stack>
using namespace std; 
//The STL stack does not have any return value for pop()
//Thus, I created my own stack class for the sake of this exercise. 
//It is not complete(memory managment) but will do the job here


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


bool hasPrecedence(char op1, char op2){
        if (op2 == '(' || op2 == ')')
            return false;
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return false;
        else
            return true;
    }



int evaluate(string exp){
	int i=0; 
	stack values; 
	stack op;
	
	for(int i=0; i<exp.size();i++){
		if(exp[i]==' ') continue;

		cout<<"exp[i] "<<exp[i]<<endl;
			if(exp[i]>='0' && exp[i]<='9'){
				string num =""; 
				while(i<exp.size() && exp[i]>='0' && exp[i]<='9'){
					num = num+exp[i++];
				}
				values.push(stoi(num));
			}


			/*
			else if(exp[i]=='('){
				op.push(exp[i]);
			}else if(exp[i]==')'){
				while(op.top()!='('){
					values.push(applyOp(op.pop(), values.pop(), values.pop()));
					//values.pop(); values.pop();op.pop();
				}
				op.pop();
			}*/
			else if(exp[i] == '+' || exp[i] == '-' ||
                     exp[i] == '*' || exp[i] == '/')
			{
				while(!op.empty() && hasPrecedence(exp[i],op.top())){
					values.push(applyOp(op.pop(),values.pop(), values.pop()));
					//op.pop();values.pop(); values.pop();
				}
				op.push(exp[i]);
			}
	}
	values.display();
	cout<<endl;
	cout<<"op "<<endl;
	op.display();
			while(!op.empty()){
				values.push(applyOp(op.pop(), values.pop(), values.pop()));
				//op.pop(); values.pop(); values.pop();
			}
			return values.pop();
}

int main(){
	string expression = "10+222*6"; 
	//cin>>expression; 
	


	cout<<evaluate(expression);
	

	return 0;
}