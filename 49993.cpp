#include <string>
#include <vector>

using namespace std;

bool followSkillTree(string skill, string skill_tree) {
    int pos = 0;
    for (int i = 0 ; i < skill_tree.length() ; i++) {
        for (int j = pos ; j < skill.length() ; j++) {
            if (skill[j] == skill_tree[i]) {
                if (j != pos) return false;
                else {
                    pos++;
                    break;
                }
            } 
        }
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0 ; i < skill_trees.size() ; i++) {
        if (followSkillTree(skill, skill_trees[i])) answer++;
    }
    
    return answer;
}