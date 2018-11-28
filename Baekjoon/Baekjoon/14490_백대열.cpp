#include<bits/stdc++.h>
int gcd(int a, int b){
        if(b == 0)
                return a;
        return gcd(b, a%b);
}
int main(){
        char msg[1234];
        int a = 0, b = 0;
        scanf("%s", msg);
        int i = 0;
        for(; msg[i] != ':'; ++i)
                a = a * 10 + msg[i] - '0';
        ++i;
        for(; msg[i] != '\0'; ++i)
                b = b * 10 + msg[i] - '0';
        int g = gcd(a, b);
        printf("%d:%d", a / g, b / g);
}
