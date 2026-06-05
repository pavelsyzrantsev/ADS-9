// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

std::vector<std::vector<char>> getAllPerms(PMTree tree) {
  std::vector<std::vector<char>> result;
  tree.get(result);
  return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
  std::vector<std::vector<char>> all = getAllPerms(tree);
  if (all.size() >= num)
    return all[num - 1];
  else all[0].clear();
  return all[0];
}

std::vector<char> getPerm2(PMTree& tree, int num) {
  return tree.getPermByNumber(num-1);
}
