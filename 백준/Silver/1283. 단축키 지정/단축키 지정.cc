#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
bool visit[26];

string ans(vector<string>& vec) {
    string tmp = "";
    for (auto &t:vec) {
        tmp += t;
        tmp += " ";
    }
    return tmp;
}

string key(char& a) {
    string tmp = "";
    tmp += "[";
    tmp += a;
    tmp += "]";
    return tmp;
}


int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    // & 중요 -> (auto &tmp:v)
    cin >> n;
    cin.ignore();
    for (int i=0; i<n; i++) {
        // 한 줄 입력받기
        string str;
        getline(cin,str);
        
        // 단어 자르기
        int str_s = str.size();
        string tmp = "";
        vector<string> v;
        for (int i=0; i<str_s; i++) {
            if (str[i]==' ') {
                v.push_back(tmp);
                tmp = "";
            }
            else
                tmp += str[i];
        }
        v.push_back(tmp);

        // 단어 첫 글자 확인
        bool flag = false;
        for (string& tmp:v) {
            if (tmp[0]-'A'>=0 && tmp[0]-'A'<=25) {
                if (!visit[tmp[0]-'A']) {
                    visit[tmp[0]-'A'] = true;
                    flag = true;
                    string keyword = key(tmp[0]);
                    tmp = keyword + tmp.substr(1,tmp.size());
                    break;
                }
            }
            else if (tmp[0]-'a'>=0 && tmp[0]-'a'<=25) {
                if (!visit[tmp[0]-'a']) {
                    visit[tmp[0]-'a'] = true;
                    flag = true;
                    string keyword = key(tmp[0]);
                    tmp = keyword + tmp.substr(1,tmp.size());
                    break;
                }
            }
        }

        // 아무 글자 확인
        if (!flag) {
            for (string& tmp:v) {
                int tmp_s = tmp.size();
                bool found = false;
                for (int j=0; j<tmp_s; j++) {
                    if (tmp[j]==' ') continue;
                    if (tmp[j]-'A'>=0 && tmp[j]-'A'<=25) {
                        if (!visit[tmp[j]-'A']) {
                            visit[tmp[j]-'A'] = true;
                            string keyword = key(tmp[j]), pre = tmp.substr(0,j);
                            pre += keyword;
                            pre += tmp.substr(j+1, tmp.size());
                            tmp = pre;
                            found = true;
                            break;
                        }
                    }
                    else if (tmp[j]-'a'>=0 && tmp[j]-'a'<=25) {
                        if (!visit[tmp[j]-'a']) {
                            visit[tmp[j]-'a'] = true;
                            string keyword = key(tmp[j]), pre = tmp.substr(0,j);
                            pre += keyword;
                            pre += tmp.substr(j+1, tmp.size());
                            tmp = pre;
                            found = true;
                            break;
                        }
                    }
                }
                if (found) break;
            }
        }

        cout << ans(v) << "\n";
    }
}