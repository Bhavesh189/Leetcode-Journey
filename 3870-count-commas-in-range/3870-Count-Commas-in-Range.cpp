class Solution {
public:
    int countCommas(int n) {
        int size = 0;
        int m = n;

        while (n != 0) {
            size++;
            n/=10;
        }

        if(size<=3) return 0;

        return (n%3) + m-999;
    }
};