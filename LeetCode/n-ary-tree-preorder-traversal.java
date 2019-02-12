/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        preOrderUtil(root,result);
        return result;
    }
    
    public void preOrderUtil(Node root, ArrayList<Integer> result){
        if(root == null){
            return;
        }
        else{
            result.add(root.val);
            for(Node node: root.children){
                preOrderUtil(node,result);
            }
            
        }
    }
}