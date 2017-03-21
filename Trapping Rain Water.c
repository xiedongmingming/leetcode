Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. For example, Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6. The above elevation map is represented by array [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
�ܽ�:ͨ���������м������ˮ��,�������еĽϵͱߵ���һ����������ȵ�ǰ����ʱ,��ʾ�˴�һ������ˮ,ͬʱ�������ҵ�λ�ñ����͵�ǰ����λ�õ���Ч�߶�.
public class Solution{
    public int trap(int[] A){
        if(A == null || A.length == 0){
			return 0;
		}
        int res = 0;//���ڼ�¼�ܵ���ˮ��
        int start = 0;
        int end = A.length - 1;//start��end��¼���ұߺ�����ߵ�λ��
        int height = Math.min(A[start], A[end]);//height��¼��ǰ�ĸ߶�,ÿ���ƶ�һλ,��������ʢˮ��.
        while(start < end){
            if(A[start] < A[end]){
                res += Math.max(height - A[start + 1], 0);//������������߱ߵĴ����ڴ��Ƿ���Ծۼ���ˮ
                height = Math.max(height, Math.min(A[start + 1], A[end]));//����
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