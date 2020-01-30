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
    public int maxDepth(Node root) {
        if(root == null) return 0;
        else{
            if(root.children.size() == 0) return 1;
            
            int maximum = maxDepth(root.children.get(0)), currentDepth;
            
            for(int iter = 1; iter < root.children.size(); iter++){
                currentDepth = maxDepth(root.children.get(iter));
                if(maximum < currentDepth)
                    maximum = currentDepth;
            }
            return maximum + 1;
        }
    }
}