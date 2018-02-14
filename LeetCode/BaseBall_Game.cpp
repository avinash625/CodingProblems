class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<long long int> points;
        points.push(0);
        points.push(0);
        long long int result = 0;
        for(int iter = 0;iter< ops.size();iter++){
            if(ops[iter].compare("+") == 0){
                long long int first = points.top();
                points.pop();
                long long int second = points.top();
                points.pop();
                points.push(second);
                points.push(first);
                points.push(first+second);
                result = result + points.top();
                cout<<result<<endl;
            }
            else if(ops[iter].compare("D") == 0){
                long long int first = points.top();
                points.push(first*2);
                result = result+ points.top();
            }
            else if(ops[iter].compare("C") == 0){
                result = result - points.top();
                points.pop();
            }
            else{
                points.push(stoi(ops[iter]));
                result = result + stoi(ops[iter]);
            }
        }
        return result;
    }
};
