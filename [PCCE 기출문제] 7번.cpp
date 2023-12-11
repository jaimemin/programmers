#include <string>
#include <vector>

using namespace std;

int func1(int humidity, int val_set){
    if(humidity < val_set)
        return 3;
    return 1;
}

int func2(int humidity){
    if(humidity >= 50)
        return 0;
    else if (humidity >= 40)
        return 1;
    else if (humidity >= 30)
        return 2;
    else if (humidity >= 20)
        return 3;
    else if (humidity >= 10)
        return 4;
    else
      return 5;
}

int func3(int humidity, int val_set){
    if(humidity < val_set)
        return 1;
    return 0;
}

int solution(string mode_type, int humidity, int val_set) {
    int answer = 0;
    if(mode_type == "auto"){
        answer = func2(humidity);
    }
    else if(mode_type == "target"){
        answer = func1(humidity, val_set);
    }
    else if(mode_type == "minimum"){
        answer = func3(humidity, val_set);
    }
    return answer;
}
