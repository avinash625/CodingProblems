class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<Integer, Integer>();
        for(int num : nums){
            //log(" checking neighbours of "+ num);
            checkNeighbours(map,num);
        }
        int maximum = 0;
        for(int num: nums){
            if(map.get(num) > maximum){
                maximum = map.get(num);
            }
        }
        return maximum;
    }
    
    public void log(String str){
        System.out.println(str);
    }
    
    public void checkNeighbours(HashMap<Integer, Integer> map, int key){
        //log("checking value  : " + key);
        updateValue(map,key);
        //log("value after updating " + key +" :" + getValue(map,key));
        //log("Hash Value after update at " + key + " is "+ getValue(map,key));
    }
    public void updateValue(HashMap<Integer, Integer> map, int key){
        if(getValue(map,key) != 0){
            return;
        }
        int left = getValue(map,key-1);
        int right = getValue(map,key+1);
        //log("updated value of "+ key +" to "+ (left+right+1));
        updateMap(map,key, left + right + 1);
        if(right != 0){
            updateMap(map,key+right, getValue(map,key));
            //log("updated the Hashvalue of "+ (key+right) +" : " + getValue(map,key) );
        }
            
        if(left != 0){
            updateMap(map,key- left, getValue(map,key));
            //log("updated the Hashvalue of "+ (key-left) +" : " + getValue(map,key) );
        }
            
    }
    
    public void updateMap(HashMap<Integer, Integer> map, int key, int value){
        map.put(key,value);
    }
    
    public int getValue(HashMap<Integer,Integer> map, int key){
        return map.getOrDefault(key,0);
    }
}