#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
int dp[105][105];  
int val[5][5]={  
    5,-1,-2,-1,-3,  
    -1,5,-3,-2,-4,  
    -2,-3,5,-2,-2,  
    -1,-2,-2,5,-1,  
    -3,-4,-2,-1,-5  
};  
char s1[105],s2[105];  
int change(char x){  
    if(x=='A')  
    return 0;  
    if(x=='C')  
    return 1;  
    if(x=='G')  
    return 2;  
    if(x=='T')  
    return 3;  
    if(x==' ')  
    return 4;  
}  
int main(){                                     //dp[i][j]代表s1前i个与s2前j个匹配的最大值  
    int t,l1,l2,i,j;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&l1);  
        getchar();  
        scanf("%s",s1+1);  
        scanf("%d",&l2);  
        getchar();  
        scanf("%s",s2+1);  
        memset(dp,0,sizeof(dp));  
        for(i=1;i<=l1;i++)                      //理解意义是两个串的每一位进行对齐也就知道需要初始化  
        dp[i][0]=dp[i-1][0]+val[change(s1[i])][change(' ')];  
        for(i=1;i<=l2;i++)                      //s1与s2和空串匹配的值  
        dp[0][i]=dp[0][i-1]+val[change(s2[i])][change(' ')];  
        for(i=1;i<=l1;i++)  
        for(j=1;j<=l2;j++)                      //其实就是相当于s1串的一位与s2串的对齐剩下的与空格匹配  
        dp[i][j]=max(dp[i-1][j-1]+val[change(s1[i])][change(s2[j])],  
                     max(dp[i-1][j]+val[change(s1[i])][change(' ')],  
                     dp[i][j-1]+val[change(s2[j])][change(' ')]));  
        printf("%d\n",dp[l1][l2]);  
    }  
    return 0;  
}  
