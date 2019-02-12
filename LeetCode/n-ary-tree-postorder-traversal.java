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
    public List<Integer> postorder(Node root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        postOrderUtil(root,result);
        
        return result;
    }
    
    public void postOrderUtil(Node root, ArrayList<Integer> result){
        if(root == null){
            return;
        }
        else{
            for(Node node: root.children){
                postOrderUtil(node,result);
            }
            result.add(root.val);
        }
    }
}