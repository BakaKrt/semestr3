#include <iostream>
#include <vector>

using namespace std;

#define debug(Expression)\
     std::cout << "\n{" #Expression "}: " << (Expression) << std::endl;


int main()
{
    setlocale(0, "");
    std::cout << "Hello World!\n";
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12};
    for (int a = vec[0]; a += vec[a]; a < vec.size()) {
        printf("%d %d %d\n", a, vec.size(), a < vec.size());
        //debug(a);
        //debug(vec.size());
        if (a > vec.size()) break;
    }

}

