#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

void up_cache();


// 这应该是将要访问的数量是n
// 一共有m块
// cache[]存放cache
// 将要访问的数据在walk_sort中
//
int n,m;

typedef struct cacheblock{
    bool state;
    int value;
    int count;

}cacheblock;


cacheblock cache[MAX_SIZE];
int walk_sort[MAX_SIZE];

void init(){
    for(int i=0;i<m;i++){
        cache[i].state = false;
        cache[i].value = -1;
        cache[i].count = 0;
    }
    
}

int main(){

  cout<<"请输入访存序列长度n: ";
  cin>>n;
  cout<<"请输入cache的大小m: ";
  cin>>m;

  init();
  
  cout<<"请输入访问序列：";
  for(int i=0;i<n;i++){
      cin>>walk_sort[i];
  }

  up_cache();

  return 0;
}

// cache更新算法,LRU
void up_cache()
{
  int i=0;
  while(i<n)
  {
    int s=0;
    //是否命中
    while(s<m){
      if(cache[s].value==walk_sort[i])
      {
        cout<<endl;
        cout<<walk_sort[i]<<"命中!!!"<<endl;

        for (int x=0;x<m;x++)
          cout<<"cache块"<<x<<": "<<cache[x].value<<endl;
        cout<<endl;

        int kk=0;
        i++;
        cache[s].count=0;
        //更新其它cache块没使用时间
        while(kk<m)
        {
          if(kk!=s&&cache[kk].value!=(-1))
              cache[kk].count++;
          kk++;
        }
        break;
      }
      s++;
    }
    //未命中
    int j=0;
    if(s == m){
      cout<<"未命中."<<endl;
      //满么?
      while(j<m)
      {
        if((cache[j].state==false)&&(walk_sort[i]!=cache[j].value))
        {
          cout<<"cache有空闲块,不考虑是否要置换."<<endl;
          cout<<walk_sort[i]<<"被调入cache...."<<endl;
          cache[j].value=walk_sort[i++];
          cache[j].state=true;
          cache[j].count=0;
          int kk=0;

          for (int x=0;x<m;x++)
            cout<<"cache块"<<x<<": "<<cache[x].value<<endl;
          cout<<endl;

          //更新其它cache块没使用时间
          while(kk<m)
          {
            if(kk!=j&&cache[kk].value!=(-1))
                cache[kk].count++;
            kk++;
          }
          //delay();
          break;
        }
        
        j++;
      }
    }

    //遍历完cache,没有空闲位置
    if(j==m)
    {
      cout<<"cache已经满了,考虑置换."<<endl;

      int ii=0;
      int t=0;//要替换的cache块号.
      int max=cache[ii].count;
      ii++;
      while(ii<m)
      {
        if(cache[ii].count>max)
        {
          max=cache[ii].count;
          t=ii;
        }
        ii++;
      }
      //置换
      cout<<cache[t].value<<"被"<<walk_sort[i]<<"在cache的"<<t<<"号块置换..."<<endl;
      cache[t].value=walk_sort[i++];
      cache[t].count=0;

      for (int x=0;x<m;x++)
        cout<<"cache块"<<x<<": "<<cache[x].value<<endl;
      int kk=0;
      //更新其它cache块没使用时间
      while(kk<m)
      {
          if(kk!=t)
            cache[kk].count++;
        kk++;
      }
      //delay();
    }
  }
}
