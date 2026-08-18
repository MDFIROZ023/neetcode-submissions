class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){return false;}
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for(char ch: s1){
            freq1[ch]++;
        }
        int k = s1.size();
        for(int i = 0; i < k; i++){
            freq2[s2[i]]++;
        }
        if(freq1 == freq2){return true;}
        int left = 0;
        for(int right = k; right < s2.size(); right++){
            freq2[s2[right]]++;
            if(right-left+1 > k){
                freq2[s2[left]]--;
                if(freq2[s2[left]] == 0){
                    freq2.erase(s2[left]);
                }
                left++;
            }
            if(freq1 == freq2){return true;}
        }
        return false;
    }
};
