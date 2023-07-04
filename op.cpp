#include <iostream>
#include <cmath>
#include <list>



using namespace std;

class media{
    string name;
    int user;
 public:
    media(string s,int u)
    {
         name = s;
         user = u;
    }
    friend ostream& operator<<(ostream& COUT,media& m);
    bool operator==(const media& m)const
    {
        return name==m.name && user==m.user;
    }
  
    
};

class collection{
      list<media> grp;

public:
      void operator+=(media& m)
      {
          grp.push_back(m);
      }
      void operator-=(media& m)
      {
          grp.remove(m);
      }
      friend ostream& operator<<(ostream& COUT,collection& c);
};

ostream& operator<<(ostream& COUT,media& m)  
    {
         COUT<<m.name<<endl;
         COUT<<m.user<<endl;
         return COUT;
    }

ostream& operator<<(ostream& COUT,collection& c)
{
    for(media& m:c.grp)
    {
        COUT<<m;
    }
    return COUT;
}  

int main()
{
     media m1("insta",200);
     media m2("twitter",400);
     collection collect;
     collect += m1;
     collect += m2;
     collect -= m1;
     cout<<collect;
     






    return 0;
}