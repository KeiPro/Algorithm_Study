class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		const int EMPTY = 0;
		const int NOT_EMPTY = 1;
		const int JUMP_INDEX = 2; // ���� ��ġ�� ���� �Ǹ� ������ ���� ���� �� �����Ƿ�, 2��ŭ ����.

		int currIndex = 0;

		// i�ε����� ��� ������ ��ȸ���� �ʾҰ�, n�� ���� ���� �����ִٸ� ��� ������ ������.
		while (currIndex < flowerbed.size() && n > 0)
		{
			// currIndex�� ���� ������ �ִٸ� continue;
			if (flowerbed[currIndex] == NOT_EMPTY)
			{
				currIndex++;
				continue;
			}

			int prevIndex = currIndex - 1;
			int nextIndex = currIndex + 1;

			// prevIndex�� nextIndex�� �迭 ������ ����ٸ� currIndex�� ���� ���� �Ϳ��� ������ ��ġ�� �����Ƿ�,
			// ���� �� �ִٴ� ó���� ���� ���Ƿ� currIndex���� �־��ش�.
			if (prevIndex < 0) prevIndex = currIndex;
			if (nextIndex >= flowerbed.size()) nextIndex = currIndex;

			// ���� �� �ִ�.
			if (flowerbed[prevIndex] == EMPTY &&
				flowerbed[nextIndex] == EMPTY)
			{
				flowerbed[currIndex] = NOT_EMPTY;
				n--;
				currIndex += JUMP_INDEX;
			}
			else //���� �� ������ ���� �ε��� üũ.
			{
				currIndex++;
			}
		}

		return n == 0;
	}
};