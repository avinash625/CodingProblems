class Solution {
    public String destCity(List<List<String>> paths) {
        Iterator listiterator = paths.iterator();
        HashMap<String,Boolean> map = new HashMap<String, Boolean>();
        while(listiterator.hasNext()){
            List l1 = (List) listiterator.next();
            String start = (String)l1.get(0);
            String end = (String)l1.get(1);
            map.put(start, false);
            if(map.getOrDefault(end, null) == null){
                map.put(end, true);
            }
        }
        for(String st: map.keySet()){
            if(map.get(st) == true) return st;
        }
        return "";
    }
}