class Solution {

    bool check(int i, int n2,string &haystack,string &needle){
        int a = 0;
        for(int j = i; j < (i + n2) && j< haystack.size();j++){
            if(haystack[j] != needle[a++])
            return 0;
        }
        return 1;
    }

public:
    int strStr(string haystack, string needle) {
        vector<int> v1(26,0),v2(26,0);
        int n1 = haystack.size(), n2  = needle.size();
        if(n2> n1)return -1;
        for(char c:needle){
            v1[c-'a']++;
        }

        int j = 0, i = 0;
        while(j < n2){
            v2[haystack[j]-'a']++;
            j++;
        }
        for(int i : v1){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int j : v2){
            cout<<j<<" ";
        }
        if(v1 == v2){
            if(check(i,n2,haystack, needle))
            return 0;
        }
        while(j < n1){
            v2[haystack[j]-'a']++;
            v2[haystack[i]-'a']--;
            if(v1 == v2 && check(i+1,n2,haystack, needle)){
                return i+1;
            }
            i++;
            j++;
        }
        return -1;
    }
};