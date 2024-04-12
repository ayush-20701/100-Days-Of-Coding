#include <bits/stdc++.h>

using namespace std;

void solve(stack<int>& inputStack, int count, int N) {
   // Base case 
   if(count == N/2) {
      inputStack.pop();
      return;
   }
   int temp = inputStack.top();
   inputStack.pop();

   solve(inputStack, count + 1, N);

   inputStack.push(temp);
}

void deleteMiddle(stack<int>& inputStack, int N){
   int count = 0;
   solve(inputStack, count, N);
}

int main() {
   stack<int> inputStack;

   // Push elements into the stack
   inputStack.push(1);
   inputStack.push(2);
   inputStack.push(3);
   inputStack.push(4);
   inputStack.push(5);

   int N = inputStack.size();

   cout << "Original Stack: ";
   while (!inputStack.empty()) {
      cout << inputStack.top() << " ";
      inputStack.pop();
   }
   cout << endl;

   // Push elements again for the demonstration
   inputStack.push(1);
   inputStack.push(2);
   inputStack.push(3);
   inputStack.push(4);
   inputStack.push(5);

   deleteMiddle(inputStack, N);

   cout << "Stack after deleting middle element: ";
   while (!inputStack.empty()) {
      cout << inputStack.top() << " ";
      inputStack.pop();
   }
   cout << endl;

   return 0;
}
