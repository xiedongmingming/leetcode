Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number. The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based. You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target = 9
Output: index1 = 1, index2 = 2 

public class Solution{
    public int[] twoSum(int[] numbers, int target){
    }
}

class Pair implements Comparable<Pair>{//可以用于比较的键值对
    public int number;
    public int idx;
    public Pair(int number, int idx){
        this.number = number;
        this.idx = idx;
    }
    public int compareTo(Pair other){
        return this.number - other.number;
    }
}
public class Solution{
    public int[] twoSum(int[] numbers, int target){
        int n = numbers.length;
        Pair[] pairs = new Pair[n];
        for(int i = 0; i < n; ++i){
            pairs[i] = new Pair(numbers[i], i + 1);
        }
        Arrays.sort(pairs);//排序
        int[] result = new int[2];
        int begin = 0;
        int end = n - 1;
        while(begin < end){
            if(pairs[begin].number + pairs[end].number < target){
                begin++;
            }else if(pairs[begin].number + pairs[end].number > target){
                end--;
            }else{
                if(pairs[begin].idx > pairs[end].idx){//注意此处值大小已经排序过了
                    result[0] = pairs[end].idx;
                    result[1] = pairs[begin].idx;
                }else{
					result[0] = pairs[begin].idx;
					result[1] = pairs[end].idx;
                }
                break;
            }
        }
        return result;
    }
}