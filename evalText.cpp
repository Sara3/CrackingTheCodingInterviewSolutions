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
		siz=0;
	}
	void push(int val){
		siz++;
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
			cout<<endl;
			n=n->next;
			cout<<endl;
		}
	}
	int pop(){
		siz--;
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
	int size(){
		return siz;
	}
private:
	Node* head;
	int siz;
};


bool isOp(char a){
	return a=='*' || a=='/' ||a=='+' ||a== '-' ;
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
	string exp = "10*2/3" ;
	string num ="";
	int inum;
	int i=0; 


	for(int i=0; i<=exp.size();i++){
		cout<<" exp["<<i<<"] = "<<exp[i]<<endl;

		if(exp[i]==' ') continue;
		else if(isNum(exp[i])) num=num+exp[i];
		else if(isOp(exp[i]) ){
			val.push(stoi(num));
			cout<<"num "<<num<<endl;
			num="";
			while (!op.empty() && hasPrecedence(exp[i], op.top())&&val.size()>1){
							val.push(applyOp(op.pop(), val.pop(), val.pop()));
			}
			cout<<"i = "<<i;
			op.push(exp[i]);
		}
		else if(exp[i]=='\0') val.push(stoi(num));
		else if(exp[i]=='(') op.push(exp[i]);
		else if(exp[i]==')'){
				while(op.top()!='(') 
					val.push(applyOp(op.pop(), val.pop(), val.pop()));
				op.pop();
			}
		
	}
	while(!op.empty())
		val.push(applyOp(op.pop(), val.pop(), val.pop()));
	cout<<val.pop();

	val.display();


	if(hasPrecedence('*', '/')){
		cout<<"yea";
	}else{
		cout<<"np";
	}
	

	return 0;
}