Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. For example, Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6. The above elevation map is represented by array [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
总结:通过两边向中间计算雨水量,当两边中的较低边的下一个搜索方向比当前更低时,表示此处一定有雨水,同时更新左右的位置变量和当前左右位置的有效高度.
public class Solution{
    public int trap(int[] A){
        if(A == null || A.length == 0){
			return 0;
		}
        int res = 0;//用于记录总的雨水量
        int start = 0;
        int end = A.length - 1;//start、end记录最右边和最左边的位置
        int height = Math.min(A[start], A[end]);//height记录当前的高度,每次移动一位,更新最大的盛水量.
        while(start < end){
            if(A[start] < A[end]){
                res += Math.max(height - A[start + 1], 0);//看由于左右最高边的存在在此是否可以聚集到水
                height = Math.max(height, Math.min(A[start + 1], A[end]));//跟新
                ++start;
            }else{
                res += Math.max(height - A[end - 1], 0);
                height = Math.max(height, Math.min(A[start], A[end - 1]));
                --end;
            }
        }
        return res;
    }
}