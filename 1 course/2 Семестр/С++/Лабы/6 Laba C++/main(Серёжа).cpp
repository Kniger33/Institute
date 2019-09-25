#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <class type>
class Stack{
private:
    vector<type> stck;
public:
    Stack(){}

    void push(type i){
        if (stck.size() < 60)
            stck.push_back(i);
        else
            cout << "Stack is full!" << endl;
    }

    type pop(){
        if (stck.size() > 0){
            type tmp = stck.back();
            stck.pop_back();
            return tmp;
        }
        else{
            cout << "Stack is empty!" << endl;
            return 0;
        }
    }

    bool cmp(Stack object){
        if (stck.size() != object.stck.size()){
            cout << "Stacks are not equal" << endl;
            return false;
        }
        else{
            int cnt_of_true = 0;

            for (int i = 0; i < stck.size(); i++){
                if (stck.at(i) == object.stck.at(i))
                    cnt_of_true++;
            }

            if (cnt_of_true == stck.size()){
                cout << "Stacks are equal" << endl;
                return true;
            }
            else{
                cout << "Stacks are not equal" << endl;
                return false;
            }
        }
    }

    void clear(){
        stck.clear();
    }

};

int main()
{
    Stack<double> stck;
    Stack<double> stck1;
    stck.push(10);
    cout << "stck push 10" << endl;
    stck1.push(110);
    cout << "stck1 push 110" << endl;
    cout << "cmp stck1 and stck: ";
    stck.cmp(stck1);
    cout << "stck and stck1 was cleared: ";
    stck1.pop();
    stck.pop();
    stck.cmp(stck1);
    cout << stck.pop() << endl << stck1.pop() << endl;
    cout << "stck push 15, 20, 30" << endl;
    stck.push(15);
    stck.push(20);
    stck.push(30);
    cout << "stck pop: " << stck.pop() << endl;
    cout << "stck1 push 15, 20" << endl;
    stck1.push(15);
    stck1.push(20);
    cout << "cmp stck1 and stck: ";
    stck.cmp(stck1);
    stck1.clear();
    stck.clear();
    cout << "stck and stck1 clear" << endl;
    cout << stck.pop() << endl << stck1.pop() << endl;
    return 0;
}
