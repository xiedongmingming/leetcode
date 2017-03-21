Gray Code格雷码

The gray code is a binary numeral system where two successive values differ in only one bit. Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0. For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note: For a given n, a gray code sequence is not uniquely defined. For example, [0,2,3,1] is also a valid gray code sequence according to the above definition. For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
public class Solution{
    public List<Integer> grayCode(int n){
        
    }
}
graycode中文名叫格雷码,一看题就知道是模拟类型,写几个例子出来找规律.以3位格雷码为例.
0 0 0
0 0 1
0 1 1
0 1 0//逆序
1 1 0
1 1 1
1 0 1
1 0 0
可以看到第n位的格雷码由两部分构成,一部分是n-1位格雷码,再加上1<<(n-1)和n-1位格雷码的逆序的和.
public class Solution{
    public ArrayList<Integer> grayCode(int n){
        if(n == 0){
            ArrayList<Integer> result = new ArrayList<Integer>();
            result.add(0);
            return result;
        }
        ArrayList<Integer> tmp = grayCode(n - 1);
        int addNumber = 1 << (n - 1);//添加最高位(依次与逆序结合)
        ArrayList<Integer> result = new ArrayList<Integer>(tmp);
        for(int i = tmp.size() - 1; i >= 0; i--){
            result.add(addNumber + tmp.get(i));
        }
        return result;
    }
}