class Solution {
public:

    pair<int, int> getNum(string &s) {
        return {stoi(s.substr(0, 2)), stoi(s.substr(3, 2))};
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        pair<int, int> aa = getNum(arriveAlice);
        pair<int, int> la = getNum(leaveAlice);

        pair<int, int> ab = getNum(arriveBob);
        pair<int, int> lb = getNum(leaveBob);

        int arr[366] = {0};
        
        int mina = ((275 * aa.first) / 9) - (2 * ((aa.first + 9) / 12)) + aa.second - 30;
        int maxa = ((275 * la.first) / 9) - (2 * ((la.first + 9) / 12)) + la.second - 30;

        int minb = ((275 * ab.first) / 9) - (2 * ((ab.first + 9) / 12)) + ab.second - 30;
        int maxb = ((275 * lb.first) / 9) - (2 * ((lb.first + 9) / 12)) + lb.second - 30;

        int ans = 0;

        for(int i = 1; i < 366; i++) {
            if((i <= maxa && i >= mina) && (i <= maxb && i >= minb)) ans++;
        }

        return ans;
    }
};