#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
string a[1000+10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
char ds[] = {'L', 'U', 'R', 'D'};
bool visi[1000+10][1000+10];
pair<int, int> grid[1000+10][1000+10];

void path(){

	int x,y;
	for(int i =0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(a[i][j] == 'A'){
				x=i;y=j;break;
			}
		}
	}
	queue<pair<int, int>> q; 
	q.push({x,y});
	visi[x][y] = true;
	
	grid[x][y] = {-1,-1};
	int steps = 0;

	queue<pair<int, int>> dangerQueue;
	for(int i =0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(a[i][j] == 'M'){
				dangerQueue.push({i,j});
				visi[i][j] = true;

			}
		}
	}
	while(1){
		int dQsize = dangerQueue.size();
		for(int i=0; i<dQsize; ++i){
			int cu,cv;
			tie(cu,cv) = dangerQueue.front();
			dangerQueue.pop();

			for(int j=0; j<4; ++j){
				int neighboru = cu + dx[j];
				int neighborv = cv + dy[j];
				if(neighboru<0 || neighboru>=n || neighborv<0 || neighborv>=m || a[neighboru][neighborv] == '#'){
					continue;
				}

				if(visi[neighboru][neighborv] == false){
					dangerQueue.push({neighboru, neighborv});
					visi[neighboru][neighborv] = true;
				}
			}
		}


		int qsize = q.size();
		if(qsize == 0){
			cout<<"NO";return;
		}
		for(int i=0; i<qsize; ++i){
			int cu,cv;
			tie(cu,cv) = q.front();
			q.pop();

			if(cu == 0 || cu == n-1 || cv == 0 || cv == m-1){
				//todo
				cout<<"YES"<<endl;
				string shortestPath = "";
				while(!(cu == x && cv == y)){

					int parentx = grid[cu][cv].first;
					int parenty = grid[cu][cv].second;

					for(int t=0; t<4; ++t){

						if(-parentx+cu == dx[t] && -parenty+cv == dy[t]){
							shortestPath.push_back(ds[t]);
						}

					}
					cu = parentx;
					cv = parenty;


				}
				reverse(shortestPath.begin(), shortestPath.end());
				cout<<shortestPath.length()<<endl<<shortestPath;
				return;

			}

			for(int j=0; j<4; ++j){
				int neighboru = cu + dx[j];
				int neighborv = cv + dy[j];
				if(neighboru<0 || neighboru>=n || neighborv<0 || neighborv>=m || a[neighboru][neighborv] == '#'){
					continue;
				}

				if(visi[neighboru][neighborv] == false){
					grid[neighboru][neighborv] = {cu,cv};
					q.push({neighboru, neighborv});
					visi[neighboru][neighborv] = true;
				}
			}
		}

		
	

	}
	cout<<"NO";return;



}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	m = a[0].length();
	memset(visi, false, sizeof(visi));
	path();

}
