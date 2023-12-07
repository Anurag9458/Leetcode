class Solution {
public:
    string reverseVowels(string s) {
        string temp;
        int n=s.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]=='a'|| s[i]=='e' || s[i]=='o'|| s[i]=='u' || s[i]=='i'|| s[i]=='A'|| s[i]=='E' || s[i]=='I'|| s[i]=='O' || s[i]=='U')
            {temp.push_back(s[i]);v.push_back(i);}
        }
        // cout<<temp<<" ";
        reverse(begin(temp),end(temp));
        int j=0;
        for(int i:v)
        s[i]=temp[j++];
        return s;
    }
};