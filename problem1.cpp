#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n=1,h,i;
    char c;
	unsigned input[100001];
    unsigned hight[100001];
    unsigned shadow[100001];

    while(1)
    {
        scanf("%d",&input[n]);
        if((c=getchar())=='\n') break;
        n++;
    }
	for(i=1;i<=n;i++) hight[i]=input[n+1-i];
	int r=1,pos;
    shadow[1]=hight[1];
    for(i=2;i<=n;i++){
		if (hight[i]>=shadow[r]){
			r++;
			shadow[r]=hight[i];
		}
		else{
			pos=upper_bound(shadow+1,shadow+r,hight[i])-shadow;
			shadow[pos]=hight[i];
		}	
    }
	cout<<r<<endl;
    return 0;
}