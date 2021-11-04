function solution(skill, skill_trees) {
  let answer = 0;
  let flag;
  let count;
  skill_trees.forEach((skill_tree) => {
    count = 0;
    flag = true;
    for (let i = 0; i < skill_tree.length; i++) {
      if (skill.indexOf(skill_tree[i]) >= 0) {
        if (skill.indexOf(skill_tree[i]) > count) {
          flag = false;
          break;
        }
        count++;
      }
    }
    if (flag) answer++;
  });
  return answer;
}
