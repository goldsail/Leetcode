// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        for (int pos = 0; pos < n; pos++) {
            if (bufferlen == 0) {
                bufferlen = read4(buffer);
                if (bufferlen == 0) return pos;
            }
            buf[pos] = buffer[0];
            memmove(buffer, buffer + 1, 3);
            bufferlen--;
        }
        return n;
    }
    
private:
    char buffer[4];
    int bufferlen = 0;
};
