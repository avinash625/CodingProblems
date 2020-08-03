class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        if(points.length == 1) return 0;
        int x1,x2, y1, y2, p1, q1;
        x1 = points[0][0];
        y1 = points[0][1];
        p1 = x1;
        q1 = y1;
        int totalSeconds = 0;
        int width, height;
        for(int pointIter = 1; pointIter < points.length; pointIter++){
            x2 = points[pointIter][0];
            y2 = points[pointIter][1];
            
            int distance = Math.min(Math.abs(p1-x2), Math.abs(q1-y2));
            totalSeconds += distance;
            
            if(Math.abs(p1-x2) > Math.abs(q1-y2)){
                totalSeconds += (Math.abs(p1-x2) - distance);
            }else if(Math.abs(q1-y2) > Math.abs(p1-x2)){
                totalSeconds += (Math.abs(q1-y2)- distance);
            }
            p1 = x2;
            q1 = y2;
        }
        return totalSeconds;
    }
}