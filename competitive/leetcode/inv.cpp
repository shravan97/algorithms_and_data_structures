#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

map < pair<int,int> , int> num;
void merge(vector < pair<int,int> > &v,int l1,int r1,int l2,int r2)
{
    int ptr1=l1,ptr2=l2;
    bool done1=0,done2=0;
    cout<<" in func "<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
    vector < pair<int,int> > v1;
    while(!done1 && !done2)
    {
        cout<<" here "<<l1<<' '<<r1<<' '<<ptr1<<endl;
        if(v[ptr1].first<v[ptr2].first && !done1)
        {
            v1.push_back(v[ptr1]);
            ptr1++;
        }
        else if(v[ptr1].first>v[ptr2].first && !done2)
        {
            v1.push_back(v[ptr2]);
            num[v[ptr2]]++;
            cout<<" in "<<v[ptr2].first<<endl;
            ptr2++;
        }
        else if(done2 && !done1)
        {
            v1.push_back(v[ptr1]);
            ptr1++;
        }
        else if(done1 && !done2)
        {
            v1.push_back(v[ptr2]);
            ptr2++;
        }
        
        if(ptr1==r1)
            done1=1;
        if(ptr2==r2)
            done2=1;
        
    }
    
    for(int i=0;i<v1.size();i++)
    {
        if(i>r1)
            v[l2+(i-r1-1)]=v1[i];
        else
            v[l1+i]=v1[i];
    }
}

void split(vector < pair<int,int> >&v,int l,int r)
{
    if(l>=r)
        return;
        
    int mid=(l+r)/2;
    split(v,l,mid-1);
    split(v,mid+1,r);

    bool eq=0;

    if(mid==l)
        eq=1;

    if(eq)
        merge(v,l,mid,mid+1,r);
    else 
        merge(v,l,mid-1,mid+1,r);
}
vector<int> countSmaller(vector<int>& nums) {
    // num=0;
    vector < pair<int,int> > v1;
    
    for(int i=0;i<nums.size();i++)
        v1.push_back(make_pair(nums[i],i));
        
    split(v1,0,v1.size()-1);
    vector <int> res(nums.size());
    
    for(auto e:num)
    {
        res[e.first.second]=e.second;
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v={5,2,6,1},r;

    r = countSmaller(v);


    for(auto a:r)
        cout<<a<<endl;

    return 0;
}
