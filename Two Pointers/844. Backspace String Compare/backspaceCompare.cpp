//O(N)额外空间复杂度（栈）
class Solution {
public:
    bool backspaceCompare(string S, string T) { //使用栈
        stack<char> sstack,tstack;
        for(char ch : S){
            if(ch == '#'){
                if(!sstack.empty()) sstack.pop();
            }
            else sstack.push(ch);
        }
        for(char ch : T){
            if(ch == '#'){
                if(!tstack.empty()) tstack.pop();
            }
            else tstack.push(ch);
        }
        if(sstack.size() != tstack.size()) return false;
        while(!sstack.empty() && !tstack.empty()){
            if(sstack.top() != tstack.top()) return false;
            sstack.pop();
            tstack.pop();
        }
        return true;
    }
};


class Solution {
public:
    bool backspaceCompare(string S, string T) { //使用栈
        int tops = 0,topt = 0;
        for(int i = 0; i < S.length(); i++){ //将字符串本身当做栈，和数组去重一个思路
            char c = T[i];
            if(c == '#'){
                if(tops > 0) tops--;
            }
            else S[tops++] = c;
        }
        
        for(int j = 0; j < T.length(); j++){
            char c = T[j];
            if(c == '#'){
                if(topt > 0) topt--;
            }
            else T[topt++] = c;
        }
        
        if(tops != topt) return false;
        return S.substr(0,tops) == T.substr(0,topt);
    }
};
