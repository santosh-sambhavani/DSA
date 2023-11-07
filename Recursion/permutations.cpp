// https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254?leftPanelTabValue=SUBMISSION
/*
* swap all charachters from inex till end of the string and backtrack 
*/
#include <algorithm>

void utils(string& str, int index, vector<string>& result) {
    if(index == str.size() - 1) {
        result.push_back(str);
        return ;
    } 

    for(int j = index; j < str.size(); j++) {
        swap(str[index], str[j]);
        utils(str, index + 1, result);
        swap(str[index], str[j]); // backtrack
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> result;
    utils(str, 0, result);
    sort(result.begin(), result.end());
    return result;
}
