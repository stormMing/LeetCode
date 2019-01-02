//20ms,时间复杂度：O(n)，空间复杂度：O(1)
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (flowerbed.size() == 0) return false;
		if (flowerbed[0] == 0) flowerbed.insert(flowerbed.begin(), 0);
		if (flowerbed.back() == 0) flowerbed.push_back(0);
		int len = flowerbed.size(), cnt = 0, sum = 0;
		for (int i = 0; i < len; i++) {
			if (i < len-1 && flowerbed[i] == 0) ++cnt;//统计0的个数，从0到n-2位置
			else if(i == len-1 || flowerbed[i] == 1){ //此位置是1或到了最后一个位置
                		if(flowerbed[i] == 0) ++cnt; //最后一个位置仍为0
				sum += (cnt - 1) / 2; //根据前面0的个数，计算前面可以放几个1
				cnt = 0;
			}
		}
		return sum >= n;
	}
};

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (flowerbed.size() == 0) return false;
		for (int i = 0; i < flowerbed.size() && n > 0; i++) {
			if (flowerbed[i] == 0 && i == 0 && flowerbed[i + 1] == 0) {
				flowerbed[i] = 1;
				n--; //001
			}
			if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
				flowerbed[i] = 1;
				n--; //10001
			}
			if (flowerbed[i] == 0 && i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) {
				flowerbed[i] = 1;
				n--;//100
			}
		}
		return n == 0;
	}
};
