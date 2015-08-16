/********************************
 *@file:
 *@author: Pan HU
 *@data: 2015-8-16
 *@version: 0.1
 *@describe:
 ********************************/
#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

//入队的数据全部压入到栈1中
//出队时，如果栈2不为空则弹出栈2的栈顶元素，如果栈2为空则将栈1全部出栈到栈2

class queueBystack
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
		{
			if(stack1.empty())
			{
				throw runtime_error("pop failed queue is empty!");
			}
			while(stack1.size() != 0)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int tmp = stack2.top();
		stack2.pop();
		return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
	int arr[] = {1,2,3,4,5,6,7};

	queueBystack queue;
	queue.push(-1);
	
	try{
		cout<<queue.pop()<<endl;
	} catch (const runtime_error &e){
		cerr<<e.what()<<endl;
	}
	
	for(int i = 0; i < sizeof(arr)/sizeof(*arr); ++i)
	{
		queue.push(arr[i]);
	}
	
	for(int i = 0; i < sizeof(arr)/sizeof(*arr); ++i)
	{
		try{
			cout<<queue.pop()<<endl;
		} catch (const runtime_error &e){
			cerr<<e.what()<<endl;
		}
	}
	
	return 0;
}