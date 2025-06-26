class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() == goal.length()){
            string result = s + s;
            size_t str = result.find(goal);

            return str != string::npos;
        }
        else{
            return false;
        }
    }
};