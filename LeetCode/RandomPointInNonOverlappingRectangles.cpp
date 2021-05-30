////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
I originally use (x2 - x1) * (y2 - y1) to calculate the area of each rectangle, and sum all of them together, but got failed in the test cases. After reading the posts, I found correct answers used (x2 - x1 + 1) * (y2 - y1 + 1) to calculate area, which I didn't understand at the first beginning. Now I know the answer: what we want is actually not area, but the number of integer points in each rectangle.

We need to note that in this question, what we are asked to pick in each rectangle is integer point! So, using the real area size of each rectangle is incorrect to measure the relative probability of being picked up between rectangles. For example, let's say we have 2 rectangles, [0, 1, 0, 1] and [0, 2, 0, 2], we can see that the area ratio between them is 1 : 4, but their number of integer points' ratio is 4 : 9 (4 integer points in 1st rectangle and 9 integer points in 2nd one)! So, if we want to pick a random integer point, the probability of picking it in the 1st rectangle should be 4/13. If we use area to measure this probability, it'll be 1/5, which is wrong.

I am thinking that in this problem if we are asked to pick any point inside a rectangle(return a double[]), instead of integer point, then using area is the correct answer. Correct me if I am wrong.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    //concept is simple
    //we need to pick the coordinates from the rectangle space
    //for that we will use rand() function to find out randomly any rectangle
    //but to which we will apply rand()
    //that should be cumulative sum of areas why?? because we can't use area of any rect that's not unique but cumulative sum is unique
    //area of any rectangle can be given by (x[2]-x[0]+1) * (x[3]-x[1]+1)
    //we will store this inside a rectangle to store the cumulative sum for each rectange
private:
    vector<vector<int>> rects;
    vector<pair<int,int>> sums;
    int sum = 0;
    
    //returns index of random sum if found returns that index else returns lowerBound(index with value not lesser than randomSum)
    int findIndexOfRandomSum(int randomSum) {
        int lowerBound = 0, upperBound = sums.size() - 1;
        while(lowerBound <= upperBound) {
            int middle = lowerBound + (upperBound - lowerBound)/2;
            int sumValue = sums[middle].first;
            if(sumValue > randomSum) {
                upperBound = middle - 1;
            } else if(sumValue < randomSum) {
                lowerBound = middle + 1;    
            } else {
                return middle;
            }   
        }
        return lowerBound;     
    }
    
public:
    Solution(vector<vector<int>>& rects) {
        int size = rects.size();
        this->rects = rects;
        for(int i = 0; i < size; i++) {
            int x1 = rects[i][0], x2 = rects[i][2], y1 = rects[i][1], y2 = rects[i][3];
            sum += ((x2-x1+1)*(y2-y1+1));
            sums.push_back(make_pair(sum, i));
        }    
    }
    
    vector<int> pick() {
        int randomSum = rand()%(sum) + 1; //gives random value from 0 to sum inclusive all
        int index = findIndexOfRandomSum(randomSum);
        int x1 = rects[index][0], x2 = rects[index][2], y1 = rects[index][1], y2 = rects[index][3];
        vector<int> result;
        result.push_back(x1 + rand()%(x2-x1+1));
        result.push_back(y1+rand()%(y2-y1+1));
        return result;     
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////