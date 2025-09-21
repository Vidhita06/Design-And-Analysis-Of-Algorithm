#include<iostream>
#include<limits>
#include<string>
using namespace std;

struct cost{
    int val;
    char dir;
};

int lrs(string a,int m,cost** c){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(i==0 || j==0){
                c[i][j].val=0;
                c[i][j].dir='h';
            }
            else if (a[i-1] == a[j-1] && i != j) {  
                // Same char but different index
                c[i][j].val = c[i-1][j-1].val + 1;
                c[i][j].dir = 'd';
            }
            else{
                c[i][j].val=max(c[i-1][j].val,c[i][j-1].val);
                if(c[i-1][j].val>=c[i][j-1].val){
                    c[i][j].dir='u';
                }
                else{
                    c[i][j].dir='s';
                }
            }
        }
    }
    return c[m-1][m-1].val;
}

void print_lrs(string a,cost** c,int i, int j){
    if(i==0 ||j==0){
        return;
    }
    if(c[i][j].dir=='d'){
        print_lrs(a,c,i-1,j-1);
        cout<<a[i];
    }
    else{
        if(c[i][j].dir=='u'){
            print_lrs(a,c,i-1,j);
        }
        else{
            print_lrs(a,c,i,j-1);
        }
    }
}
int main(){
    string a;
    cout << "Enter the String A:\n";
    cin >> a;
    int l=0;
    int m=a.length()+1;
    cost** c = new cost*[m];
    for (int i = 0; i < m; ++i) {
        c[i] = new cost[m];
    }
    l=lrs(a,m,c);
    
    cout << "---------------------------------------"<< endl;
    cout << "LRS: " << l << endl;
    cout << "PRINTING LRS: ";
    print_lrs(a,c,m-1,m-1);
    cout << endl;
    cout << "---------------------------------------"<< endl;
    return 0;
    
}