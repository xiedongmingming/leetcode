Subsets

Given a set of distinct integers, S, return all possible subsets. Note: Elements in a subset must be in non-descending order. The solution set must not contain duplicate subsets. For example, If S = [1, 2, 3], a solution is: 
[
  [3],
  [1],
  [2],
  [1, 2, 3],
  [1, 3],
  [2, 3],
  [1, 2],
  []
]
public class Solution{
    public List<List<Integer>> subsets(int[] S){
    }
}
//递归解法
public class Solution{
    public ArrayList<ArrayList<Integer>> subsets(int[] S){
        Arrays.sort(S);//对元素进行排序
        return getSubsets(S, 0);
    }
    public ArrayList<ArrayList<Integer>> getSubsets(int[] S, int start_index){
        ArrayList<ArrayList<Integer>> allSubsets;//当前节点的所有子集
        if(start_index == S.length){//已经递归到最后了
            allSubsets = new ArrayList<ArrayList<Integer>>();//生成列表对象
            allSubsets.add(new ArrayList<Integer>());//添加空
        }else{
            allSubsets = getSubsets(S, start_index + 1);//返回从当前节点之后的所有节点的所有子集
            ArrayList<ArrayList<Integer>> tmpSubsets = new ArrayList<ArrayList<Integer>>();//在原有的基础上添加当前元素
            for(ArrayList<Integer> subset : allSubsets){//遍历所有子集
                ArrayList<Integer> s = new ArrayList<Integer>();
                s.add(S[start_index]);//将当前节点添加到所有子集中
                s.addAll(subset);
                tmpSubsets.add(s);
            }
            allSubsets.addAll(tmpSubsets);
        }
        return allSubsets;
    }
}
//DFS算法
public class Solution{
    public ArrayList<ArrayList<Integer>> subsets(int[] S){
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        list.add(new ArrayList<Integer>());//添加空元素
        Arrays.sort(S);
        dfs(S, list, path, 0);
        return list;
    }
    public void dfs(int[] S, ArrayList<ArrayList<Integer>> list, ArrayList<Integer> path, int index){
        for(int i = index; i < S.length; i++){
            path.add(S[i]);//将当前元素添加到path路径中
            list.add(new ArrayList<Integer>(path));
            dfs(S, list, path, i + 1);//将带有当前元素的路径path全部遍历
            path.remove(path.size() - 1);//将当前元素从path路径中删除
        }
    }
}

public class Solution{
    public ArrayList<ArrayList<Integer>> subsets(int[] S){
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        list.add(new ArrayList<Integer>());
        Arrays.sort(S);
        dfs(S, list, path, 0);
        return list;
    }
    public void dfs(int[] S, ArrayList<ArrayList<Integer>> list, ArrayList<Integer> path, int index){
        if(index < S.length){
            path.add(S[index]);
            list.add(new ArrayList<Integer>(path));
            dfs(S, list, path, index + 1);
            path.remove(path.size() - 1);
            dfs(S, list, path, index + 1);//相当于执行循环
        }
    }
}