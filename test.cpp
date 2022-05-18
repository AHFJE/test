#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

ll p,a,x,y,r,c1,c2,m;

ll qpow(ll r, ll n, ll mod){//计算a^n % mod
    ll re = 1;
    while(n){
        if(n & 1)
            re = (re * r) % mod;
        n >>= 1;
        r = (r * r) % mod;
    }
    return re % mod;
}

ll byy(ll lp){//求Zlp*的本原元
    bool flag;
    for(ll i=2;i<lp;i++){
        flag=true;
        for(ll j=2;j<lp-1;j++){
            if((lp-1)%j==0){
                if(qpow(i,j,lp)==1) flag=false;
            }
        }
        if(flag) return i;
    }
}

ll inv(ll la, ll lp){//求逆元——扩展欧几里得算法
    if(la == 1) return 1;
    return inv(lp%la,lp)*(lp-lp/la)%lp;
}

void encode(ll la,ll lp,ll ly,ll lr){
    printf("\n======加密======\n");
    c1=qpow(la,lr,lp);
    c2=(m*qpow(ly,lr,lp))%lp;
    printf("得到的密文为c1=%lld   c2=%lld\n",c1,c2);
}

void decode(ll lx,ll lp){
    printf("\n======解密======\n");
    c1=qpow(c1,lx,lp);
    c1=inv(c1,lp);
    m=(c2*c1)%lp;
    printf("得到的明文为m=%lld\n",m);
}

int main(){
    printf("请输入参数p并随机选取密钥x(0<x<p-1):");
    scanf("%lld%lld",&p,&x);
    a=byy(p);
    y=qpow(a,x,p);
    printf("计算出本原元a=%lld   公钥y=%lld\n",a,y);
    printf("请输入要加密的明文m(m=Zp*)：");
    scanf("%lld",&m);
    printf("请输入随机产生的参数r(r=Zp*,gcd(r,p-1)=1):");
    scanf("%lld",&r);

    encode(a,p,y,r);  //加密
    decode(x,p);  //解密
}