//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    void insertAtBottom(stack<int> &s, int element) {
        // base case
        if (s.empty()) {
            s.push(element);
            return;
        }

        int num = s.top();
        s.pop();

        // recursive call
        insertAtBottom(s, element);

        s.push(num);
    }

    int cnt = 0; // Member variable to keep track of the count

    void Reverse(stack<int> &St) {
        // base case
        if (cnt == St.size()) {
            return;
        }
        
        int num = St.top(); // Get the top element directly
        St.pop();
        Reverse(St);
        insertAtBottom(St, num); // Insert the element at the bottom

        // Increment the count
        cnt++;

        // Recursive call
        
    }
};












//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends