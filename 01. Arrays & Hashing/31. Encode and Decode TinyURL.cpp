// Reference: https://leetcode.com/problems/encode-and-decode-tinyurl/



// TinyURL is a URL shortening service where you enter a URL such as
//  https://leetcode.com/problems/design-tinyurl and it returns a short URL such as 
// http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

// There is no restriction on how your encode/decode algorithm should work. You just need to 
// ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the 
// original URL.

// Implement the Solution class:
// - Solution() Initializes the object of the system.
// - String encode(String longUrl) Returns a tiny URL for the given longUrl.
// - String decode(String shortUrl) Returns the original long URL for the given shortUrl. 
//      It is guaranteed that the given shortUrl was encoded by the same object.
 


// Example 1:
// ==========
// Input: url = "https://leetcode.com/problems/design-tinyurl"
// Output: "https://leetcode.com/problems/design-tinyurl"

// Explanation:
// Solution obj = new Solution();
// string tiny = obj.encode(url); // returns the encoded tiny url.
// string ans = obj.decode(tiny); // returns the original url after decoding it.
 


// Constraints:
// ============
// 1 <= url.length <= 10^4
// url is guranteed to be a valid URL.





class Solution {
public:
    unordered_map<int, string> urlMapping;

    pair<string, string> splitDomainAndApi(string &url) {
        string domain = "", api = "";
        bool isDomain = true, dotVisited = false;
        for (int i = 0; i < url.size(); ++i) {
            isDomain ? (domain += url[i]) : (api += url[i]);
            if (url[i] == '.')  dotVisited = true;
            if (url[i] == '/' && dotVisited)    isDomain = false;
        }
        return {domain, api};
    }

    int toInt(string &num) {
        int val = 0;
        for (int i = 0; i < num.size(); ++i)
            val = (val * 10) + (num[i] - '0');
        return val;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto [domain, api] = splitDomainAndApi(longUrl);
        string encodedStr = domain + to_string(urlMapping.size());
        urlMapping[urlMapping.size()] = api;
        return encodedStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto [domain, api] = splitDomainAndApi(shortUrl);
        return domain + urlMapping[toInt(api)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
