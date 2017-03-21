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
����˼·--����������˱��˵�˼·.
1���趨�߽�ֵstartx,endx,starty,endy.
2������,�ϵ���,�ҵ���,�µ���,ֱ��while��������.
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
			for(int i = starty; i <= endy; i++){//���б���������ʱ���ٸ��п��Դ�ӡ
				allList.add(matrix[startx][i]);
			}
			for(int i = startx + 1; i <= endx; i++){
				allList.add(matrix[i][endy]);
			}
			if(startx != endx){//ֻ���ڲ����ʱ����Ҫ��һ��(��Ϊ��һ����û�иı�x����)
				for(int i = endy - 1; i >= starty; i--){
					allList.add(matrix[endx][i]);
				}
			}
			if(starty != endy){//ͬ��
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
����һ��������ת���������,˼·���̶ܹ�.������д��ʱ������׳���
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
		if(m == 1 && n == 1){//ֻ����һ��Ԫ�ص����
			ret.add(matrix[x][y]);
			return;
		}else if(m == 1 && n != 1){//ֻ��һ�е����
			for(int j = y; j < y + n; j++){
				ret.add(matrix[y][j]);
			}
			return;
		}else if(m != 1 && n == 1){//ֻ��һ�е����
			for(int i = x; i < x + m; i++){
				ret.add(matrix[i][x]);
			}
			return;
		}
		//�������ж��ж��е����
		for(int i = y; i < y + n - margin; i++){//����
			ret.add(matrix[x][i]);
		}
		for(int i = x; i < x + m - margin; i++){//����
			ret.add(matrix[i][y + n - margin]);
		}
		for(int i = y + n - margin; i > x; i--){//����
			ret.add(matrix[x+m-margin][i]);
		}
		for(int i = x + m - margin; i > x; i--){//����
			ret.add(matrix[i][y]);
		}
		rec(matrix, m - 2, n - 2, margin, x + 1, y + 1, ret);//�ı䳤��Ⱥͳ�ʼ��λ��
	}
	public static void rec2(int[][] matrix, int m, int n, int k, ArrayList<Integer> ret){
		if(m <= 0 || n <= 0){
			return;
		}
		if(m == 1){//ֻ��һ��ʱ
			for(int j = 0; j < n; j++){
				ret.add(matrix[k][k + j]);
			}
			return;
		}
		if(n == 1){			//ֻ��һ��ʱ
			for(int i = 0; i < m; i++){
				ret.add(matrix[k + i][k]);
			}
			return;
		}
		for(int j = 0; j < n - 1; j++){//�����ϵ�һ�������ϵ�����
			ret.add(matrix[k][k + j]);
		}
		for(int i = 0; i < m - 1; i++){//�����ϵ�һ�������µ�����
			ret.add(matrix[k+i][k+n-1]);
		}
		for(int j = 0; j < n - 1; j++){//�����µ�һ�������µ�����
			ret.add(matrix[k + m - 1][k + n - 1 - j]);
		}
		for(int i = 0; i < m - 1; i++){//�����µ�һ�������ϵ�����
			ret.add(matrix[k + m - 1 - i][k]);
		}
		rec2(matrix, m - 2, n - 2, k + 1, ret);//ʣ��m-2�к�n-2��,k+1 level
	}
}