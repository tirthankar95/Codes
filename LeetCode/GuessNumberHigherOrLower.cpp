/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
typedef long long ll;
class Solution {
public:
    int guessNumber(int n) {
        ll lb=1,ub=n;
        while(lb<=ub)
        {
            ll mid=(lb+ub)/2;
            if(guess(mid)==-1)ub=mid-1;
            else if(guess(mid)==1)lb=mid+1;
            else return mid;
        }
        return lb;
    }
};