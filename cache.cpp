/*************************************************************************
        > File Name: cache.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月15日 星期五 19时42分46秒
 ************************************************************************/

#include <iostream>

// cache更新算法,LRU
void up_cache()
{
  int i=0;
  while(i<n)
  {
     int j=0;
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

        for (x=0;x<m;x++)
        cout<<"cache块"<<x<<": "<<cache[x].value<<endl;
		cout<<endl;

          //更新其它cache块没使用时间
          while(kk<m)
          {
            if(kk!=j&&cache[kk].value!=(-1))
                cache[kk].count++;
	        kk++;
          }

          delay();

          break;
       }
       if(cache[j].value==walk_sort[i])
       {
          cout<<endl;
		  cout<<walk_sort[i]<<"命中!!!"<<endl;

		for (x=0;x<m;x++)
        cout<<"cache块"<<x<<": "<<cache[x].value<<endl;
		cout<<endl;

          int kk=0;
          i++;
          cache[j].count=0;
                    //更新其它cache块没使用时间
          while(kk<m)
          {
            if(kk!=j&&cache[kk].value!=(-1))
                cache[kk].count++;
	       kk++;
          }
       }
	 j++;
     }

     if(j==m)
     {
       cout<<"cache已经满了,考虑是否置换."<<endl;
	   cout<<endl;
       int k=0;

       while(k<m)
       {
          if(cache[k].value==walk_sort[i])
          {
               cout<<endl;
			   cout<<walk_sort[i]<<"命中!!!"<<endl;

	    for (x=0;x<m;x++)
        cout<<"cache块"<<x<<": "<<cache[x].value<<endl;

	       i++;
               cache[k].count=0;
               int kk=0;

                //更新其它cache块没使用时间
                while(kk<m)
                {
                  if(kk!=k)
                     cache[kk].count++;
	          kk++;
                 }

               break;
          }
		  k++;
       }

       if(k==m)//考虑置换那一块.
       {
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

		for (x=0;x<m;x++)
        cout<<"cache块"<<x<<": "<<cache[x].value<<endl;
         int kk=0;
          //更新其它cache块没使用时间
           while(kk<m)
           {
              if(kk!=t)
                   cache[kk].count++;
	          kk++;
           }
           delay();
	  }
	 }
   }
}
