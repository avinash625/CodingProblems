class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        HashMap<Integer, ArrayList<Integer>> groupBuckets = new HashMap<Integer,ArrayList<Integer>>();
        int maximum = groupSizes[0];
        for(int iter = 0; iter< groupSizes.length; iter++){
            if(groupBuckets.get(groupSizes[iter]) == null ){
                ArrayList<Integer> arr = new ArrayList<Integer>();
                arr.add(iter);
                groupBuckets.put(groupSizes[iter], arr);
            }else{
                (groupBuckets.get(groupSizes[iter])).add(iter);
            }

            if(groupSizes[iter] >  maximum){
                maximum  = groupSizes[iter];
            }
        }
        
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        
        for(Integer key : groupBuckets.keySet()){
            ArrayList<Integer> currentList = groupBuckets.get(key);
            int currentIndex = 0;
            
            while(currentIndex < currentList.size()){
                ArrayList<Integer> rList = new ArrayList<Integer>();
                int count = 0;
                while(count < key){
                    rList.add(currentList.get(currentIndex));
                    count++;
                    currentIndex++;
                }
                
                result.add(rList);
            }
        }
        
        return result;
    }
}