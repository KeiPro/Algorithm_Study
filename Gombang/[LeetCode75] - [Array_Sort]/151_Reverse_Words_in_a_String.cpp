class Solution {
public:
    string reverseWords(string s) {
        string word;
        vector<string> wordVec; // list�� ���� �ڷᱸ��.

        for (int i = 0; i < s.size(); i++)
        {
            // ���鹮�ڰ� �ƴ϶�� word ���ڿ� ������ ����.
            if (s[i] != ' ')
            {
                word += s[i];
            } // ���� �����̰�, word�� �� ���� �ƴ϶�� wordVec�� �߰�.
            else if (word.empty() == false)
            {
                wordVec.push_back(word);
                word.clear();
            }
        }

        // word�� ��� �� �������� wordVec�� �߰�.
        if (word.empty() == false)
            wordVec.push_back(word);

        // wordVec�� ���ؼ� ���� ����.
        int n = wordVec.size();
        for (int i = 0; i < n / 2; i++)
        {
            string temp = wordVec[i];
            wordVec[i] = wordVec[n - 1 - i];
            wordVec[n - 1 - i] = temp;
        }

        // ���鹮�ڸ� �̿��Ͽ� wordVec�� �ִ� ���ڿ��� �������ֱ�.
        string result = wordVec[0];
        for (int i = 1; i < wordVec.size(); i++)
        {
            result += " " + wordVec[i];
        }

        return result;
    }
};