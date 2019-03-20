#include <bits/stdc++.h>
using namespace std;
template <class T>
class NrInt{
private:
    int lg,sgn;
    char *p;
public:
    int getSgn(){
        return sgn;
    }
    void setSgn(int x){
        sgn=x;
    }
    NrInt(){
        sgn=1;
        lg=0;
        p=new char[1];
        *p=0;
    }
    ~NrInt(){
        delete[] p;
    }
    NrInt(const NrInt &v){
        sgn=v.sgn;
        lg=v.lg;
        p=new char[lg+1];
        strcpy(p,v.p);
    }
    NrInt(const char *c){
        lg=strlen(c);
        if(c[0]=='-')
        {
            sgn=-1;
            p=new char[lg];
            strcpy(p,c+1);
            lg--;
        }
        else
        {
            sgn=1;
            p=new char[lg+1];
            strcpy(p,c);
        }
        strrev(p);
    }
    NrInt operator=(const NrInt &v){
        if(this==&v)
            return *this;
            sgn=v.sgn;
        lg=v.lg;
        delete[] p;
        p=new char[lg+1];
        strcpy(p,v.p);
        return *this;
    }
    NrInt operator=(const char *c){
        char s[100];
        lg=strlen(c);
        if(c[0]=='-')
        {
            sgn=-1;
            strcpy(s,c+1);
            lg--;
        }
        else
        {
            sgn=1;
            strcpy(s,c);
        }
        strrev(s);
        p=new char[lg+1];
        strcpy(p,s);
        return *this;
    }
    bool operator==(const NrInt &v) const{
        if(strcmp(p,v.p)==0&&sgn==v.sgn)
            return 1;
        return 0;
    }
    bool operator!=(const NrInt &v) const{
        if(*this==v)
            return 0;
        return 1;
    }
    bool operator<(const NrInt &v) const{
        if(sgn==-1&&v.sgn==1)
            return 1;
        if(sgn==1&&v.sgn==-1)
            return 0;
        if(sgn==1&&v.sgn==1)
        {
            if(lg<v.lg)
                return 1;
            else
            if(lg==v.lg)
            {
                char s1[100],s2[100];
                strcpy(s1,p);
                strcpy(s2,v.p);
                strrev(s1);
                strrev(s2);
                if(strcmp(s1,s2)<0)
                    return 1;
            }
            return 0;
        }
        if(sgn==-1&&v.sgn==-1)
        {
            if(lg>v.lg)
                return 1;
            else
            if(lg==v.lg)
            {
                char s1[100],s2[100];
                strcpy(s1,p);
                strcpy(s2,v.p);
                strrev(s1);
                strrev(s2);
                if(strcmp(s1,s2)>0)
                    return 1;
            }
            return 0;
        }
    }
    bool operator>(NrInt &v) const{
        if(*this<v||*this==v)
            return 0;
        return 1;
    }
    NrInt operator+(NrInt &v){
        NrInt v2;
        int q=0,w=0;
        if(sgn<0)
        {
            sgn=1;
            q=1;
        }
        if(v.sgn<0)
        {
            v.sgn=1;
            w=1;
        }
        if(q==w)
        {
            char s[100];
            int l,i;
            if(lg<v.lg)
            {
                l=v.lg;
                for(i=lg;i<v.lg;i++)
                    p[i]='0';
            }
            else
            {
                l=lg;
                for(i=v.lg;i<lg;i++)
                    v.p[i]='0';
            }
            int k=0,d;
            for(i=0;i<l;i++)
            {
                d=p[i]-'0'+v.p[i]-'0';
                d+=k;
                if(d>9)
                {
                    d-=10;
                    k=1;
                }
                else
                    k=0;
                s[i]=d+'0';
            }
            if(k==1)
                {
                    s[l]='1';
                    s[l+1]=0;
                }
            else
                    s[l]=0;
            strrev(s);
            p[lg]=0;
            v.p[v.lg]=0;
            v2=s;
            if(q)
                v2.sgn=-1;
        }
        if(q&&!w)
        {
            v2=v-*this;
            sgn=-1;
        }
        else if(!q&&w)
        {
            v2=*this-v;
            v.sgn=-1;
        }
        return v2;
    }
    NrInt operator*(NrInt &v){
        int q=0,w=0;
        if(sgn<0)
        {
            sgn=1;
            q=1;
        }
        if(v.sgn<0)
        {
            v.sgn=1;
            w=1;
        }
        char s[1000];
        int i,j,l=lg+v.lg;
        for(i=0;i<l;i++)
            s[i]='0';
        int k,d;
        for(i=0;i<lg;i++)
        {
            k=0;
            for(j=0;j<v.lg;j++)
            {
                d=s[i+j]-'0'+(p[i]-'0')*(v.p[j]-'0');
                d+=k;
                k=d/10;
                d%=10;
                s[i+j]=d+'0';
            }
            s[v.lg+i]+=k;
        }
        if(s[l-1]=='0')
        s[l-1]=0;
        else
            s[l]=0;
        strrev(s);
        NrInt v2=s;
        //cout<<v2<<" ";
        if(q)
        {
            v2.sgn*=-1;
            sgn=-1;
        }
        if(w)
        {
            v2.sgn*=-1;
            v.sgn=-1;
        }
        return v2;
    }
    NrInt operator-(NrInt &v){
        NrInt v2;
        int q=0,w=0;
        if(sgn<0)
        {
            sgn=1;
            q=1;
        }
        if(v.sgn<0)
        {
            v.sgn=1;
            w=1;
        }
        int i, k=0,d,c,e=0;
        char s[100];
        if(q==w)
        {
            if(*this>v)
            {
                for (i=v.lg;i<lg;i++) v.p[i]='0';
                for (i=0;i<lg;i++)
                {
                    d=p[i]-'0'-k;
                    c=v.p[i]-'0';
                    if(d<c)
                    {
                        d+=10;
                        k=1;
                    }
                    else
                        k=0;
                    s[i]=d-c+'0';
                }
                int u=lg-1;
                while(s[u]=='0')
                    u--;
                s[u+1]=0;
                v.p[v.lg]=0;
            }
            else if(*this<v)
            {
                for (i=lg;i<v.lg;i++) p[i]='0';
                for (i=0;i<v.lg;i++)
                {
                    d=v.p[i]-'0'-k;
                    c=p[i]-'0';
                    if(d<c)
                    {
                        d+=10;
                        k=1;
                    }
                    else
                        k=0;
                    s[i]=d-c+'0';
                }
                p[lg]=0;
                e=1;
                int u=v.lg-1;
                while(s[u]=='0')
                    u--;
                s[u+1]=0;
            }
            else
            {
                s[0]='0';
                s[1]=0;
            }
            if(q)
                e=1-e;
        strrev(s);
        v2=s;
        if(e)
            v2.sgn*=-1;
        }
        if(q&&!w)
        {
            v2=v+*this;
            v2.sgn=-1;
            sgn=-1;
        }
        else if(!q&&w)
        {
            v2=*this+v;
            v.sgn=-1;
        }
        return v2;
    }
    NrInt operator/(NrInt &v){
        int q=0,w=0;
        if(sgn<0)
        {
            sgn=1;
            q=1;
        }
        if(v.sgn<0)
        {
            v.sgn=1;
            w=1;
        }
        char s[100],s1[100];
        int j,k,c,o;
        NrInt v1;
        NrInt v2,v3,v4;
        v4="0";
        if(v==v4)
        {
            throw 10;
        }
        else if(*this<v)
        {
            v2="0";
        }
        else
        {
            j=0;k=0;
            s[j]=p[lg-1-j];
            s[j+1]=0;
            v1=s;
            if(lg==1)
                s1[k++]=(s[0]-'0')/(v.p[0]-'0')+'0';
            else while(lg-1-j>0||v1>v||v1==v)
            {
                if(v1>v||v1==v)
                {
                    c=0;
                    while(v1>v||v1==v)
                    {
                        c++;
                        v1=v1-v;
                    }

                    for(int i=0;i<v1.lg;++i)
                        s[v1.lg-i-1]=v1.p[i];
                    for(int i=v1.lg;i<100;++i)
                        s[i]='0';
                    ///strcpy(s,v1.p);
                    ///strrev(s);
                    if(v1==v4)
                        v1.lg=0;
                    s1[k++]=c+'0';
                }
                else if(v1<v)
                {
                    j++;
                    if(v1==v4)
                        v1.lg=0;
                    s[v1.lg]=p[lg-1-j];
                    s[v1.lg+1]=0;
                    v1=s;
                    if(k)
                        if(v1<v)
                            s1[k++]='0';
                }
            }
            s1[k]=0;
            v2=s1;
        }
        if(q)
        {
            v2.sgn*=-1;
            sgn=-1;
        }
        if(w)
        {
            v2.sgn*=-1;
            v.sgn=-1;
        }
        return v2;
    }
    NrInt operator%(NrInt &v){
        int q=0,w=0;
        if(sgn<0)
        {
            sgn=1;
            q=1;
        }
        if(v.sgn<0)
        {
            v.sgn=1;
            w=1;
        }
        NrInt v1,v3;
        v1=*this/v;
        v1=v1*v;
        v3=*this-v1;
        v1=v3;
        if(q)
        {
            v1.sgn*=-1;
            sgn=-1;
        }
        if(w)
        {
            v.sgn=-1;
        }
        return v1;
    }
    NrInt cmmdc(NrInt &v){
        NrInt v1,v2,v3,v4;
        v4="0";
        int q=0,w=0;
        if(sgn<0)
        {
            sgn=1;
            q=1;
        }
        if(v.sgn<0)
        {
            v.sgn=1;
            w=1;
        }
        if(*this<v)
        {
            v2=*this;
            v1=v;
        }
        else
        {
            v1=*this;
            v2=v;
        }
        while(v2>v4)
        {
            v3=v1%v2;
            v1=v2;
            v2=v3;
        }
        if(q)
            sgn=-1;
        if(w)
            sgn=1;
        return v1;
    }
    friend istream &operator>>(istream &i,NrInt &v){
        char s[50];
        i>>s;
        v.lg=strlen(s);
        delete[] v.p;
        if(s[0]=='-')
        {
            v.lg--;
            v.p=new char[v.lg+1];
            v.sgn=-1;
            strcpy(v.p,s+1);
        }
        else
        {
            v.p=new char[v.lg+1];
            v.sgn=1;
            strcpy(v.p,s);
        }
        strrev(v.p);
        return i;
    }
    friend ostream& operator<<(ostream& i, const NrInt &v){
        if(v.sgn==-1)
            i<<'-';
        for(int j=v.lg-1;j>=0;j--)
            i<<v.p[j];
        return i;
    }
    template <class U> friend class NrRat;
};
template <class T>
class NrRat{
private:
    NrInt<T> a,b;
public:
    bool operator<(const NrRat &v)const {
        NrInt<T> v1,v2,v3,v4,v5,v6;
        v1=a;
        v2=b;
        v3=v.a;
        v4=v.b;
        v5=v1*v4;
        v6=v2*v3;
        if(v5<v6)
            return 1;
        return 0;
    }
    bool operator!=(const NrRat &v) const{
        if((*this<v)||(v<*this))
            return 1;
        return 0;
    }
    bool operator==(const NrRat &v) const{
        if(!(*this!=v))
            return 1;
        return 0;
    }
    NrRat operator*(NrRat &v){
        NrRat v1;
        v1.a=a*v.a;
        v1.b=b*v.b;
        return v1;
    }
    NrRat operator/(NrRat &v){
        NrRat v1;
        NrInt<T> v2="0";
        if(v.a==v2)
            throw 10;
        v1.a=a*v.b;
        v1.b=b*v.a;
        return v1;
    }
    NrRat operator+(NrRat &v){
        NrInt<T> v1,v2,v3,v4,v5,v6,v7,v8,v9;
        NrRat v10;
        v1=this->a;
        v2=this->b;
        v3=v.a;
        v4=v.b;
        v5=v2.cmmdc(v4);
        v6=(v1*v4)/v5;
        v7=(v2*v3)/v5;
        v8=v6+v7;
        v9=v2*v4/v5;
        v10.a=v8;
        v10.b=v9;
        return v10;
    }
    NrRat operator-(NrRat &v){
        NrInt<T> v1,v2,v3,v4,v5,v6,v7,v8,v9;
        NrRat v10;
        v1=this->a;
        v2=this->b;
        v3=v.a;
        v4=v.b;
        v5=v2.cmmdc(v4);
        v6=(v1*v4)/v5;
        v7=(v2*v3)/v5;
        v8=v6-v7;
        v9=v2*v4/v5;
        v10.a=v8;
        v10.b=v9;
        return v10;
    }
    NrRat reductibil(){
        NrInt<T> v1,v2,v3;
        v1=this->a;
        v2=this->b;
        v3=v1.cmmdc(v2);
        //cout<<v3;
        v1=v1/v3;
        v2=v2/v3;
        NrRat v4;
        v4.a=v1;
        v4.b=v2;
        return v4;
    }
    friend istream &operator>>(istream &i,NrRat &v){
        i>>v.a;
        i>>v.b;
        if(v.b.getSgn()==-1)
        {
            v.b.setSgn(1);
            v.a.setSgn(-1*v.a.getSgn());
        }
        return i;
    }
    friend ostream& operator<<(ostream& i, const NrRat &v){
        i<<v.a<<" "<<v.b;
        return i;
    }
};

int main()
{
    //NrInt<int> v1,v3,v4="0",v5,v2,v6[100];
    ifstream f("in");
    ofstream g("out");
    int n;
    //NrInt v2="-9";
    //NrRat<double> v1,v2,v3,v6[100];
    //cin>>v1>>v2>>v3;
    //cout<<v1<<"\n"<<v2;
    //cout<<v1*v2;
    //v3=v2.cmmdc(v1);
    //v3=v1+v2;
    //v3=v1.cmmdc(v2);
    //cout<<v3.reductibil()<<"\n";
    /*try
    {
        v3=v1/v2;
    }
    catch(int e)
    {
        if(e==10)
            cout<<"Gresit";
    }*/
    /*f>>n;
    for(int i=1;i<=n;i++)
        f>>v6[i];
    for(int i=1;i<=n;i++)
        g<<v6[i]<<"\n";
    sort(v6+1,v6+1+n);
    for(int i=1;i<=n;i++)
        g<<v6[i]<<"\n";*/
    //cout<<v1*v2+v3;
}
