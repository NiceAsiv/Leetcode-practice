# Hashing / Hash Map 分组（哈希分组）

## 核心思想

Hash Map + 特征 Key 分组

元素 → 计算特征 key → 用 hash map 分组

LeetCode 中很多题都可以用这个模板：

```cpp
unordered_map<string, vector<string>> mp;

for(string s : strs)
{
    string key = generateKey(s);
    mp[key].push_back(s);
}

vector<vector<string>> res;

for(auto &p : mp)
{
    res.push_back(p.second);
}
```

关键就在：

```cpp
generateKey(s)
```

常见用法

- 字母异位词
- 字符频率key
- Shifted Strings
- 按长度分组
- 按字符结构分组

## 案例

[49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams/)

**示例 1:**

**输入:** strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

**输出:** [["bat"],["nat","tan"],["ate","eat","tea"]]

**解释：**

- 在 strs 中没有字符串可以通过重新排列来形成 `"bat"`。
- 字符串 `"nat"` 和 `"tan"` 是字母异位词，因为它们可以重新排列以形成彼此。
- 字符串 `"ate"` ，`"eat"` 和 `"tea"` 是字母异位词，因为它们可以重新排列以形成彼此。

**示例 2:**

**输入:** strs = [""]

**输出:** [[""]]

**示例 3:**

**输入:** strs = ["a"]

**输出:** [["a"]]


```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <string> sorted_strs;
        unordered_map<string,vector<string>>  mp;
        vector<vector<string>> outs;
        for(string x: strs){
            string key = x; 
            sort(key.begin(),key.end());
            mp[key].push_back(x);
            // sorted_strs.pushback(sort(x.begin,x.end()));
        }
        for(auto &p: mp)
        {
            outs.push_back(p.second);
        }
        return outs;
    }
};
```

249 Group Shifted Strings

给一组字符串，把它们按“移位等价”分组：
 如果把一个字符串里每个字符都往后移同样的位数（循环 26 个字母），能变成另一个字符串，它们就同组。

例子：`"abc" -> "bcd" -> "xyz"` 都是一组（每个字符都 +1，或 +?）。

对字符串 `s`，定义：

- `diff[i] = s[i] - s[i-1]`（用 0~25 表示）
- 为了处理循环（`'a'` 到 `'z'`），用模 26：
  - `diff = (s[i] - s[i-1] + 26) % 26`

同一组里，整体平移不会改变相邻差值序列，所以 key 相同。

例子：

- `"abc"`：差值 `1,1`
- `"bcd"`：差值 `1,1`
- `"xyz"`：差值 `1,1`
   所以同组。

单字符字符串没有相邻差值，通常 key 设成空串 `""`，它们自然分一起（都能互相移位得到）。

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;

        for (const string& s : strings) {
            string key = buildKey(s);
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(mp.size());
        for (auto &p : mp) {
            res.push_back(p.second);
        }
        return res;
    }

private:
    string buildKey(const string& s) {
        if (s.size() <= 1) return "";  // 单字符/空串：同组

        string key;
        key.reserve((s.size() - 1) * 3);

        for (int i = 1; i < (int)s.size(); i++) {
            int diff = (s[i] - s[i - 1] + 26) % 26;
            key += to_string(diff);
            key.push_back('#'); // 分隔，避免歧义：比如 1 和 11 拼接混淆
        }
        return key;
    }
};
```

输入：
 `["abc","bcd","acef","xyz","az","ba","a","z"]`

- `"abc"` key：`1#1#`
- `"bcd"` key：`1#1#`
- `"xyz"` key：`1#1#`
- `"az"` key：`25#`（a->z差 -1 等价 25）
- `"ba"` key：`25#`
- `"a"` key：`""`
- `"z"` key：`""`
- `"acef"` key：`2#2#1#`

所以分组结果（顺序不保证，unordered_map 本来就无序）：

- `["abc","bcd","xyz"]`
- `["az","ba"]`
- `["a","z"]`
- `["acef"]`

**最长连续序列**

给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

**示例 1：**

```
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

**示例 2：**

```
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
```

**示例 3：**

```
输入：nums = [1,0,1,2]
输出：3
```

**提示：**

- `0 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`

solution：

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(auto &num: nums )
        {
            num_set.insert(num);
        }

        int longLen = 0 ;

        for(auto &num: num_set){
            if(!num_set.count(num-1))
            {
                int currentNum = num ;
                int currentLen = 1 ; 
                while(num_set.count(currentNum +1 ))
                {
                    currentLen ++;
                    currentNum ++;
                }

                longLen = max(currentLen,longLen);
            }
        }
        return longLen;
    }
};
```

如果你看到题目里有这种需求：

- 判断某个数 **是否存在**
- 查找 **x + something**
- 查找 **x - something**
- 查找 **target - x**

而且数据规模比较大。
