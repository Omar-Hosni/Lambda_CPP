#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

struct Square_Functor{
void operator()(int x){
cout<<x*x<<" ";
}
};

template <typename T>
struct Displayer{
    void operator() (const T &data){
    cout<<data<<" ";
    }
};

class Multiplier{
private:
    int num{};
public:
    Multiplier(int n): num{n}{}
    int operator() (int n) const{
    return n*num;
    }
};

template <typename anyType>
auto bonus = [](vector<anyType> &scores, int bonus){
    for(auto &s: scores){
        s+=bonus;
    }
};

void print_if(vector<int> nums, bool (*predicate) (int)){
    for(int i: nums)
        if(predicate(i))
        cout<<i;
}

int main()
{
   cout<<"\nTest1==============="<<endl;
   Square_Functor square;
   square(4);
   Displayer<int> d1;
   d1(100);
   Displayer<string> d2;

   cout<<"\nTest2=============="<<endl;
   vector<int> vec1 {1,2,3,4};
   vector<string> vec2 {"Larry","Moe","Curly"};

   for_each(vec1.begin(),vec1.end(),square);
   cout<<endl;

   for_each(vec1.begin(),vec1.end(),Displayer<int>());
   cout<<endl;

   for_each(vec1.begin(),vec1.end(),d1);
   cout<<endl;

   for_each(vec2.begin(),vec2.end(),Displayer<string>());
   cout<<endl;

   for_each(vec2.begin(),vec2.end(),d2);
   cout<<endl;

   cout<<"\nTest3==============="<<endl;

   for_each(vec1.begin(),vec1.end(),[](int x){cout<<x*x<<" ";});
   cout<<endl;

   for_each(vec1.begin(),vec1.end(),[](int x){cout<<x*10<<" ";});
   cout<<endl;

   for_each(vec1.begin(),vec1.end(),[](int x){cout<<x<<" ";});
   cout<<endl;

   for_each(vec2.begin(),vec2.end(),[](string s){cout<<s<<" ";});
   cout<<endl;

   cout<<"\nTest4================"<<endl;
   Multiplier multi{100};
   vector<int> vec3 = {1,2,3,4};

   transform(vec3.begin(), vec3.end(),vec3.begin(), multi);
   for_each(vec3.begin(),vec3.end(), d1);
   cout<<endl;

   transform(vec3.begin(), vec3.end(), vec3.begin(), [](int x){return x*100;});
   for_each(vec3.begin(), vec3.end(),[](int x){cout<<x<<" ";});

    print_if(vec3, [](auto x){return x%2==0;});
    print_if(vec3,[](auto x){return x%2!=0;});
}
