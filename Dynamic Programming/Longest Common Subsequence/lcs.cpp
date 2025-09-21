#include<iostream>
#include<string>
using namespace std;

struct cost{
    int val;
    char dir;
};

int lcs(string a,string b,int m,int n,cost** c){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                c[i][j].val=0;
                c[i][j].dir='h';
            }
            else{
                if(a[i-1]!=b[j-1]){
                    c[i][j].val = max(c[i-1][j].val, c[i][j-1].val);
                    if(c[i-1][j].val >= c[i][j-1].val){
                        c[i][j].dir='u';  // up
                    } else {
                        c[i][j].dir='s';  // side
                    }
                }
                else{ // characters match
                    c[i][j].val = c[i-1][j-1].val+1;
                    c[i][j].dir='d'; // diagonal
                }
            }
        }
    }
    return c[m-1][n-1].val;
}

void print_lcs(string a,cost** c,int i, int j){
    if(i==0 || j==0) return;
    if(c[i][j].dir=='d'){
        print_lcs(a,c,i-1,j-1);
        cout << a[i-1];  // print character
    }
    else if(c[i][j].dir=='u'){
        print_lcs(a,c,i-1,j);
    }
    else{
        print_lcs(a,c,i,j-1);
    }
}

int main(){
    string a,b;
    cout << "Enter the String A:\n";
    cin >> a;
    cout << "Enter the String B:\n";
    cin >> b;

    int m=a.length()+1;
    int n=b.length()+1;

    cost** c = new cost*[m];
    for (int i = 0; i < m; ++i) {
        c[i] = new cost[n];
    }

    int l = lcs(a,b,m,n,c);

    cout << "---------------------------------------"<< endl;
    cout << "Length of LCS: " << l << endl;
    cout << "-------------PRINTING LCS----------"<< endl;
    print_lcs(a,c,m-1,n-1);
    cout << endl;

    // cleanup
    for(int i=0;i<m;i++) delete[] c[i];
    delete[] c;

    return 0;
}
