/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        preorderUtil(root,result);
        return result;
    }
    
    public void preorderUtil(Node root, ArrayList<Integer> result){
        if(root == null) return;
        else{
            result.add(root.val);
            for(int iter = 0; iter < root.children.size() ; iter++){
                preorderUtil(root.children.get(iter), result);
            }
        }
    }
}