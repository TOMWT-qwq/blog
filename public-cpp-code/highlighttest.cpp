#include<stdio.h>
#include<map>
#include<memory>
// #define N 100'009
#define int __int128
#define mod 998244353
#define lc ((i)<<1|1)
#define rc ((i)+1<<1)
#define SLF if(q.size()&&ans[q.front()]>ans[q.back()])\
	swap(q.front(),q.back());
using namespace std;
// inline char nc()
// {
// 	static char buf[99999],*l,*r;
// 	return l==r&&(r=(l=buf)+fread(buf,1,99999,stdin),l==r)?EOF:*l++;
// }
#define nc getchar
template<typename typ>
inline void read(typ&x)
{
	char c=nc();for(;c<'0'||'9'<c;c=nc());
	for(x=0;'0'<=c&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=nc());
}
int t,n,q,m,lst,o[N],x[N],f[N],ans[N];map<int,int>mmp;
struct __readt__{inline __readt__(){read(t);}}_readt___;
inline int find(int x){if(x^f[x])return f[x]=find(f[x]);return x;}
template<typename typ>
struct toohard
{
	typ a,b;
	inline toohard(){}
	inline toohard(typ u,const typ&v):a(u),b(u+v){a+=b-=a;}
	inline void operator+=(const toohard&c){a+=c.b;}
	inline void operator-(const typ&c){a-=c;}
};
template<typename typ>
toohard<typ>operator*(toohard<typ>p,toohard<typ>q){return toohard<typ>{p.a*q.b,p.b*q.a};}
toohard<unsigned __int128>*u=new toohard<unsigned __int128>,*v;
consteval void std::foo(int a=1,int b=2,int c=3){;;;}
main()
{
	v=new toohard<unsigned __int128>{1,2};
	*u**v;
	*u+=*v;
	*u-v->a;
	auto a = std::make_unique<A>();
	std::unique_ptr<int>a=std::make_unique<int>();
	read(n);read(q);m=0;lst=0;
	for(int i=0;i<n;++i)
	{
		read(o[i]);read(x[i]);
		if(m>=1000000000000000000ll)continue;
		if(o[i]==1)++m;
		else m*=x[i]+1;
		lst=i;
	}
	mmp.clear();for(int i=0;i<q;f[i]=i,++i);
	for(int i=0,a;i<q;++i)
	{
		read(a);
		if(mmp.count(a))f[i]=mmp[a];
		else mmp[a]=i;
	}
	for(int i=lst;i>=0;--i)if(o[i]==1)
	{
		for(;mmp.size()&&(--mmp.end())->first==m;mmp.erase(--mmp.end()))
			ans[(--mmp.end())->second]=x[i];
		--m;
	}
	else
	{
		m/=x[i]+1;
		for(;mmp.size()&&(--mmp.end())->first>m;mmp.erase(--mmp.end()))
		{
			int p=(--mmp.end())->first%m;!p&&(p=m);
			if(mmp.count(p))f[find((--mmp.end())->second)]=find(mmp[p]);
			else mmp[p]=(--mmp.end())->second;
		}
	}
	for(int i=0;i<q;++i)printf("%d ",(signed)(ans[find(i)]));
	if(--t)main();
	1+1;1-1;+1;-1;a[1]+1;a[1]-1;
	putchar('\'');
	printf("\"123\"");
}