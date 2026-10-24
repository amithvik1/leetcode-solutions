class Solution {
public:
    int days(string s){
        int month = ((s[0] - '0')*10 + s[1] - '0') - 1;
        const int dm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day = 0; 
        for(int i = 0; i < month; i++){
            day += dm[i];
        }
        day += ((s[3] - '0')*10 + s[4] - '0');
        return day; 
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aa = days(arriveAlice);
        int la = days(leaveAlice);
        int ab = days(arriveBob);
        int lb = days(leaveBob);
        int ans = min(la,lb) - max(aa,ab) + 1; 
        if(ans < 0) return 0; 
        return ans; 
    }
};
