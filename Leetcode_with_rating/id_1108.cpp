/*
# 1108. IP 地址无效化

给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

示例 1：

输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
示例 2：

输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"
 

提示：

给出的 address 是一个有效的 IPv4 地址



按照题目要求，依次将字符串 address 中 ‘.’ 替换为 "[.]" 即可。

作者：力扣官方题
链接：https://leetcode.cn/problems/defanging-an-ip-address/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
#include <typeinfo>
using std::string;


class Solution {
public:
    string defangIPaddr(string address) {
        string answer;
        for (auto & c : address) {
            if (c == '.') answer.append("[.]");
            else answer.push_back(c);
        }
        return answer;
    }
};

