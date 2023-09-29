#include<bits/stdc++.h>
using namespace std;

//VALID PALINDROME
bool isPalindrome(string &s) {
        int n=s.size();
        string ans="";
    for(int i=0;i<n;i++){

        if((s[i]>=48&&s[i]<=57)||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)){
            if(s[i]>=65&&s[i]<=90){
                ans+=(s[i]+32);
            }else{
                ans+=s[i];
            }
        }


    }
    
    for(int i=0;i<ans.size()/2;i++){
        if(ans[i]!=ans[ans.size()-1-i])
        return false;
    }


        return true;
    }

    // Is anagram

 bool isAnagram(string s, string t) {
        int n1=s.size(),n2=t.size();
        if(n1!=n2)return false;
        if(n1==0&&n2==0)return true;

       vector<int>v1(26,0);
       vector<int>v2(26,0);

       for(int i=0;i<n1;i++){
           v1[s[i]-97]++;
           v2[t[i]-97]++;
       }

   for (int i = 0; i < n1; i++)
   {
    cout<<v1[i]<<" "<<v2[i];
    cout<<endl;
   }
   

       return v1==v2;
    }



    bool isValidBraket(string s) {
        stack<char>stack;
    for (int  i = 0; i < s.size(); i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
                stack.push(s[i]);
        }else{
            if(stack.empty())return false;

            if((stack.top()=='('&&s[i]==')')||(stack.top()=='{'&&s[i]=='}')||stack.top()=='['&&s[i]==']'){
                stack.pop();
            }else{
                return false;
            }

        }
    }

    return stack.empty();
    
    }

    // adjacent dublicate remove
    string removeDuplicates(string s) {
        string ans="";
        int n=s.size();
        vector<char>v;
        if(n<2){
            return s;
        }

        v.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(v.size()==0){
                v.push_back(s[i]);
            }else if(v.back()==s[i]){
                v.pop_back();
            }else{
                v.push_back(s[i]);
            }
        }

    for(auto i:v){
        ans+=i;
    }

return ans;

    }

        // longest substring without repetation
     int lengthOfLongestSubstring(string s) {
        int a=0;
        int j=0;
        int mx=0;
        set<char>set1;
        
        while(j<s.size()){
            if(set1.find(s[j])==set1.end()){
                set1.insert(s[j]);
                j++;
                int x=set1.size();
                mx=max(x,mx);

            }else{
                set1.erase(s[a]);
                a++;
            }
        }
        return mx;
    }
         // longest substring  repetation ans you can change anu number k times
    // not able to solve
     int characterReplacement(string s, int k) {
         // Initialize variables
        int max_len = 0;
        int start = 0;
        int max_count = 0;
        int char_count[26] = {0};
        // Slide the window through the string
        for (int end = 0; end < s.length(); end++) {
            // Increment the count for the current character
            char_count[s[end] - 'A']++;
            // Update the max count of any character in the current window
            max_count = max(max_count, char_count[s[end] - 'A']);
            
            // Check if we can shrink the window by replacing characters
            while (end - start + 1 - max_count > k) {
                // Decrement the count for the character at the start of the window
                char_count[s[start] - 'A']--;
                // Move the start of the window forward by one character
                start++;
            }
            // Update the max length of the substrings with at most K replacements
            max_len = max(max_len, end - start + 1);
        }
        return max_len;
    }

    // finding anagrams 
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1){
            if(strs[0]==""){
                return {{""}};
            }
        }
        vector<vector<string>>ans;
        map<string,vector<string>>mymap;
        for(int i=0;i<strs.size();i++){
            string s1=strs[i];
            sort(s1.begin(),s1.end());
            mymap[s1].push_back(strs[i]);
        }

for(auto i:mymap){
ans.push_back(i.second);
}
return ans;
    }


// longest sub string which is palindrome
// bool isPalindrome(string s){
//     int n=s.size();
//     if(n<2){
//         return true;
//     }
//     for(int i=0;i<n/2;i++){
//         if(s[i]!=s[n-1-i]){
//             return false;
//         }
//     }
//     return true;
// }
string longestPalindrome(string s) {
        int j=0;
        string s1="",ans="";
        while(j<s.size()){
                s1+=s[j];
            if(isPalindrome(s1)){
                if(s1.size()>ans.size()){
                    ans=s1;
                }
                 cout<<" if=>"<<s1<<endl;
                j++;
            }else{
                cout<<" else=>"<<s1<<endl;
                s1.erase(0,1);
                   j++;
            }
        }
        return ans;
    }

    // Nu of substring in the given string
    int countSubstrings(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        int ans=0;
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        //base case when length =1
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            ans++;
        }
        // for lenth 2
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=(s[i]==s[i+1]);
            if(dp[i][i+1])ans++;
        }
        //for lenth >2

        for(int len=3;len<=n;len++){
            for(int i=0,j=i+len-1;j<n;i++,j++){
                dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
                if(dp[i][j])ans++;
            }
        }

        return ans;
    }
// minimum window substring 
 string minWindow(string s, string t) {
        int n1=s.size();,n2=t.size();
        if(n2>n1){
            return "";
        }
        int j=0;
        int i=0;
       string  ans=""
        while(j<n1){
            if(s[j]==t[0]){
                ans+=s[j];
                
            }
        }
    }
int main(){
   string s="ADOBECODEBANC",t="ABC";

  cout<<"sub string : "<<minWindow(s,t);
    return 0;
}