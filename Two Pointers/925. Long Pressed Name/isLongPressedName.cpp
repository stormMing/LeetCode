	//时间复杂度分析：两个字符串都只遍历了一遍，所以总时间复杂度是 O(n)
  class Solution {
	public:
		bool isLongPressedName(string name, string typed) {
			int i = 0, j = 0;
			while (i < name.size() && j < typed.size()) {
				int ii = i , jj = j ;
				while (ii < name.size() && name[i] == name[ii]) ii++;
				while (jj < typed.size() && typed[j] == typed[jj]) jj++;
				//跳过那些重复的字符，ii、jj现在的位置就是下一个要比较的位置
				if (name[i] != typed[j] || ii - i > jj - j) return false;//输入的重复字符比较少
				i = ii, j = jj;
			}
			return i == name.size() && j == typed.size();
		}
	};
