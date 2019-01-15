#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> seq;
    int n;
    while(~scanf("%1d", &n)) seq.push_back(n);
    if(next_permutation(seq.begin(), seq.end()))
        for(int i : seq) printf("%d", i);
    else
        printf("0");
}
