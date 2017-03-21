Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order. 
For example, Given the following matrix: 
[
	[ 1, 2, 3 ],
	[ 4, 5, 6 ],
	[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]. 

public class Solution{
    public List<Integer> spiralOrder(int[][] matrix){
        
    }
}
解题思路--本题代码借鉴了别人的思路.
1、设定边界值startx,endx,starty,endy.
2、左到右,上到下,右到左,下到上,直到while条件结束.
public class Solution{
    public ArrayList<Integer> spiralOrder(int[][] matrix){
		ArrayList<Integer> allList = new ArrayList<Integer>();
		if(matrix == null || matrix.length == 0){
			return allList;
		}
		allList = printfMatrix(matrix);
		return allList;
	}
	public ArrayList<Integer> printfMatrix(int[][] matrix){
		ArrayList<Integer> allList = new ArrayList<Integer>();
		int m = matrix.length;
		int n = matrix[0].length;
		int startx = 0;
		int starty = 0;
		int endx = m - 1;
		int endy = n - 1;
		while(startx <= endx && starty <= endy){
			for(int i = starty; i <= endy; i++){//当判别条件成立时至少该行可以打印
				allList.add(matrix[startx][i]);
			}
			for(int i = startx + 1; i <= endx; i++){
				allList.add(matrix[i][endy]);
			}
			if(startx != endx){//只有在不相等时才需要这一步(因为第一步中没有改变x坐标)
				for(int i = endy - 1; i >= starty; i--){
					allList.add(matrix[endx][i]);
				}
			}
			if(starty != endy){//同上
				for(int i = endx - 1; i > startx; i--){
					allList.add(matrix[i][starty]);
				}
			}
			startx++;
			endx--;
			starty++;
			endy--;
		}
		return allList;
	}
}
又是一道关于旋转矩阵的问题,思路都很固定.但具体写的时候很容易出错
package Level4;
import java.util.ArrayList;
public class S54{
	public static void main(String[] args){
		//int[][] matrix = {{1,2,3,4,5},{14,15,16,17,6},{13,20,19,18,7},{12,11,10,9,8}};
		int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
		//int[][] matrix = {{1,2,3}};
		System.out.println(spiralOrder(matrix));
	}
	public static ArrayList<Integer> spiralOrder(int[][] matrix){
		ArrayList<Integer> ret = new ArrayList<Integer>();
		if(matrix.length == 0){
			return ret;
		}
		int m = matrix.length;
		int n = matrix[0].length;
		int margin = 1;
		//rec(matrix, m, n, margin, 0, 0, ret);
		rec2(matrix, m, n, 0, ret);
		return ret;
	}
	public static void rec(int[][] matrix, int m, int n, int margin, int x, int y, ArrayList<Integer> ret){
		if(m <= 0 || n <= 0){
			return;
		}
		if(m == 1 && n == 1){//只包含一个元素的情况
			ret.add(matrix[x][y]);
			return;
		}else if(m == 1 && n != 1){//只有一行的情况
			for(int j = y; j < y + n; j++){
				ret.add(matrix[y][j]);
			}
			return;
		}else if(m != 1 && n == 1){//只有一列的情况
			for(int i = x; i < x + m; i++){
				ret.add(matrix[i][x]);
			}
			return;
		}
		//以下是有多行多列的情况
		for(int i = y; i < y + n - margin; i++){//向右
			ret.add(matrix[x][i]);
		}
		for(int i = x; i < x + m - margin; i++){//向下
			ret.add(matrix[i][y + n - margin]);
		}
		for(int i = y + n - margin; i > x; i--){//向左
			ret.add(matrix[x+m-margin][i]);
		}
		for(int i = x + m - margin; i > x; i--){//向上
			ret.add(matrix[i][y]);
		}
		rec(matrix, m - 2, n - 2, margin, x + 1, y + 1, ret);//改变长宽度和初始点位置
	}
	public static void rec2(int[][] matrix, int m, int n, int k, ArrayList<Integer> ret){
		if(m <= 0 || n <= 0){
			return;
		}
		if(m == 1){//只有一行时
			for(int j = 0; j < n; j++){
				ret.add(matrix[k][k + j]);
			}
			return;
		}
		if(n == 1){			//只有一列时
			for(int i = 0; i < m; i++){
				ret.add(matrix[k + i][k]);
			}
			return;
		}
		for(int j = 0; j < n - 1; j++){//从左上第一个到右上倒二个
			ret.add(matrix[k][k + j]);
		}
		for(int i = 0; i < m - 1; i++){//从右上第一个到右下倒二个
			ret.add(matrix[k+i][k+n-1]);
		}
		for(int j = 0; j < n - 1; j++){//从右下第一个到左下倒二个
			ret.add(matrix[k + m - 1][k + n - 1 - j]);
		}
		for(int i = 0; i < m - 1; i++){//从左下第一个到左上倒二个
			ret.add(matrix[k + m - 1 - i][k]);
		}
		rec2(matrix, m - 2, n - 2, k + 1, ret);//剩下m-2行和n-2列,k+1 level
	}
}