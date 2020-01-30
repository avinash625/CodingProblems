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
    public List<Integer> postorder(Node root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        postorderUtil(root,result);
        return result;
    }
    
    public void postorderUtil(Node root, ArrayList<Integer> result){
        if(root == null) return;
        else{
            for(int iter = 0; iter < root.children.size(); iter++){
                postorderUtil(root.children.get(iter), result);
            }
            result.add(root.val);
        }
    }
}