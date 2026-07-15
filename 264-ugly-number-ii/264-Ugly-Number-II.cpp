class Solution {
public:
    
    int arr[1691] = {0};
    int nthUglyNumber(int n) {
        arr[1] = 1;
        if(arr[n] != 0) return arr[n];

        int x, y, z;
        x = y = z = 1;

        for(int i = 2; i <= n; i++) {
            arr[i] = min({arr[x]*2, arr[y]*3, arr[z]*5});

            if(arr[x]*2 == arr[i]) x++;
            if(arr[y]*3 == arr[i]) y++;
            if(arr[z]*5 == arr[i]) z++;
        }

        return arr[n];
    }
};