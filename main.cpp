#include <__algorithm/remove_if.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#define B

#ifdef A
using coord = std::vector<std::pair<int, int>>;

std::pair<int, int> counterIN(coord X,coord Y,int R){
    int Xcount=std::count_if(X.begin(), X.end(), [R](std::pair<int, int> i){return i.first*i.first+i.second*i.second<R*R;});
    int Ycount=std::count_if(X.begin(), X.end(), [R](std::pair<int, int> i){return i.first*i.first+i.second*i.second<R*R;});
    return std::pair<int, int>{Xcount,Ycount};
}

int main(){
    coord X{{2,1}};
    coord Y{{4,5}};
    auto c=counterIN(X, Y, 6);
    std::cout<<c.first<<" "<<c.second<<std::endl;
    return 0;
}
#endif

#ifdef B
using vec = std::vector<float>;

float ret(vec X,vec Y){
    return (std::accumulate(X.begin(),std::remove_if(X.begin(), X.end(), [](float i){return i<0.f;}),0.f)*std::accumulate(Y.begin(),std::remove_if(Y.begin(), Y.end(), [](float i){return i<0.f;}),0.f))/(std::count_if(X.begin(), X.end(), [](float i){return i>0.f;})*std::count_if(Y.begin(), Y.end(), [](float i){return i>0.f;}));
}

int main(){
    vec X{1,-1};
    vec Y{1,-1};
    std::cout<<ret(X, Y);
    return 0; 
}
#endif