class Solution {
public:
    string reverseVowels(string s) {

        // unordered_set�� �ؽ� ���̺��� ������� �����ϴ� �ڷᱸ��.
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

        int left = 0;
        int right = s.size() - 1;

        // left�� right�� �� �ε����� ���� ���� ������ ã���� ��� ����.
        while (left < right)
        {
            // vowels.end()�� ������ ����� ������ ����Ű�� �ݺ���.
            while (left < right && vowels.find(s[left]) == vowels.end())
                left++;

            while (left < right && vowels.find(s[right]) == vowels.end())
                right--;

            if (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};