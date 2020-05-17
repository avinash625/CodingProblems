class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int count = 0;
        for(int current_student = 0; current_student < startTime.length; current_student++){
            if(queryTime >= startTime[current_student] && queryTime <= endTime[current_student]){
                count++;
            }
        }
        return count;
    }
}