class Solution {
public:
    bool canAliceWin(int n) {
        int rm = 10;

        bool alice = true;

        while(n >= 0) {
            if(n-rm >= 0) n-=rm--;
            else return !alice;
            alice = !alice;
        }

        return alice;
    }
};