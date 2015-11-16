#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
long long int a[100002];
class trie
{
    public:
        int lcount,rcount;
        trie *child[2];


        trie()
        {
            lcount=rcount=0;
            child[0]=child[1]=NULL;
        }
};



    void add(trie *curr,int k)
    {

    //node *curr=head;
     for(int i=20;i>=0;i--)
     {
        int bit=((k>>i)&1?1:0);
        if(bit==0)
        {
            curr->lcount++;
            if(curr->child[0]==NULL)
            {
            curr->child[0]=new trie();
            }
            curr=curr->child[0];
        }
        else
        {
            curr->rcount++;
            if(curr->child[1]==NULL)
            {
                curr->child[1]=new trie();
            }
            curr=curr->child[1];
        }
    }
    }

    long long int getmax(trie *curr,int q,int k)
    {
        //node *curr=head;
        if(curr==NULL)
            return 0;
        long long int res=0;
        for(int i=20;i>=0;i--)
        {

            int bit1=((q>>i)&1?1:0);
            int bit2=((k>>i)&1?1:0);
            if(bit2==1)
            {
                if(bit1==1)
                {
                    res+=(curr->rcount);
                    if(curr->child[0]==NULL)
                        return res;
                    curr=curr->child[0];
                }
                else
                {
                    res+=curr->lcount;
                    if(curr->child[1]==NULL)
                        return res;
                    curr=curr->child[1];
                }
            }
            else
            {
                if(bit1==1)
                {
                    if(curr->child[1]==NULL)
                        return res;
                    curr=curr->child[1];
                }
                else
                {
                    if(curr->child[0]==NULL)
                    {
                        return res;
                    }
                    curr=curr->child[0];
                }
            }
        }
        return res;
    }


int main()
{
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        scanf("%d %d",&n,&k);

        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);

        }
        trie *ti=new trie();
        add(ti,0);
        //t->add(0);
        int p=0;
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            int q=p^a[i];
            ans+=(getmax(ti,q,k));
            //cout<<i<<" "<<ans<<"\n";
            add(ti,q);
            p=q;

        }
        printf("%lld\n",ans);

    }
    return 0;

}
