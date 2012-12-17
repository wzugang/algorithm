#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 100
#define INF 999999999
using namespace std;


class P8XGraphBuilder {
    int dp[MAX_SIZE][MAX_SIZE];
    int d_score[MAX_SIZE];
    int n_nodes;
    public:
            int MIN(int a,int b){
                return a>b?b:a;
            }
            int get_max(int s){
                int m = -INF;
                for(int i=0; i<s; i++){
                    m = m>d_score[i]?m:d_score[i];
                }
                return m ;
            }
            int solve(vector <int> scores) {
                init();
                for(int i=0; i<scores.size();i++)
                {
                    d_score[i]=scores[i];
                }
                n_nodes = scores.size()+1;
                dp[2][1]=2*scores[0];
                for(int i=3; i<=n_nodes; i++){
                    for(int j=2; j<i; j++){
                        cout<<"i-> "<<i<<" j-> "<<j<<endl;
                        int ans = 0;
                        if(dp[i-1][j]!=-1){
                            cout<<"i-1, j"<<endl;
                            int m = -INF, pos=-1;
                            for(int w = 0; w < MIN((2*(i-1)-j),j); w++){
                                int t;
                                if((t = d_score[0] -d_score[w] +d_score[w+1]) > m){
                                    m=t;
                                    pos=w;
                                    cout<<"pos "<<pos<<" "<<m<<endl;
                                }
                            }
                            ans = dp[i-1][j] + m;
                        }
                        if(dp[i-1][j-1]!=-1){
                            cout<<"i-1, j-1"<<endl;
                            int t = dp[i-1][j-1]+d_score[j-1] - d_score[j-2] + d_score[0] ;
                            if(t>ans){
                                ans = t;
                            }
                        }
                        dp[i][j] = ans;
                        cout<<"dp["<<i<<"]["<<j<<"] = "<<ans<<endl;
                    }
                }
                int ans = -INF;
                for(int j=1; j<n_nodes; j++){
                    if(dp[n_nodes][j]>ans){
                        ans = dp[n_nodes][j];
                    }
                }
                return ans;
            }
            void init(){
                memset(dp,-1,sizeof(dp));
            }

};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	P8XGraphBuilder *obj;
	int answer;
	obj = new P8XGraphBuilder();
	clock_t startTime = clock();
	answer = obj->solve(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	{
	// ----- test 0 -----
	int t0[] = {1,3,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,0,0,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,2,3,4,5,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	{
	// ----- test 3 -----
	int t0[] = {5,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 15;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	{
	// ----- test 4 -----
	int t0[] = {1,3,2,5,3,7,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING