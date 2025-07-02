class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i, lineLength = 0;

            // Count words that fit in this line
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int spaces = maxWidth - lineLength;
            int numWords = j - i;
            string line = words[i];

            // If this is the last line or there's only one word, left-justify
            if (j == n || numWords == 1) {
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                line += string(maxWidth - line.length(), ' '); // Fill remaining spaces
            } else {
                // Distribute spaces as evenly as possible
                int spaceBetween = spaces / (numWords - 1);
                int extraSpaces = spaces % (numWords - 1);

                for (int k = i + 1; k < j; k++) {
                    line += string(spaceBetween + (extraSpaces-- > 0 ? 1 : 0), ' ') + words[k];
                }
            }

            result.push_back(line);
            i = j; // Move to the next line
        }

        return result;
    }
};