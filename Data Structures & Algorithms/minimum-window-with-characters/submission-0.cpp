class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.empty() || t.size() > s.size()){
            return "";
        }
        int start= 0;
        int left = 0;
        int required = t.size();
        int minLen = INT_MAX;

        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;

        for(char ch : t){
            freq1[ch]++;
        } 

        for(int right = 0; right < s.size(); right++){
            if(freq2[s[right]] < freq1[s[right]]){
                required--;
            }
            freq2[s[right]]++;
            while(required == 0){
                int len = right - left + 1;
                if(len < minLen){
                    minLen = len;
                    start = left;
                }
                if(freq2[s[left]] == freq1[s[left]]){
                    required++;
                }
                freq2[s[left]]--;
                left++;
            }
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};
