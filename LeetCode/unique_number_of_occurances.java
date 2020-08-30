class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<Integer,Integer>();
        for(int num: arr){
            if(map.containsKey(num) == false){
                map.put(num,1);
            }else{
                map.put(num, map.get(num)+1);
            }
        }

        HashMap<Integer,Integer> map1 = new HashMap<Integer, Integer>();


        for(int num: map.keySet()){
            if(map1.containsKey(map.get(num)) == true){
                return false;
            }else{
                map1.put(map.get(num), 1);
            }
        }
        return true;
    }
}