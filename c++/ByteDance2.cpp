
/*
 * 给你两个字符串数组 creators和ids，和一个整数数组 views，所有数组的长度都是n。
 * 平台上第i个视频的创作者是creator[i]，视频分配的id是 ids[i]，且播放量为views[i]。
 * 视频创作者的流行度是该创作者的所有视频的播放量的总和。请找出流行度最高创作者以及该创作者播放量最大的视频的id .
 * ·如果存在多个创作者流行度都最高，则需要找出所有符合条件的创作者。·如果某个创作者存在多个播放量最高的视频，则只需要找出字典序
 * 最小的id 。
 * 返回一个二维字符串数组answer,其中 answer[i] =[creator(i), id(i)]表示creator(i)的流行度最高且其最流行的视频id是id(i)，可以按任何顺序返回该结果。
 * */


#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct MyPair {
    string name;
    size_t id;
};

size_t GetTopIdInAuthor(map<string, map<size_t, size_t>> &authorVideoPlaySumMap, string &authorName){
    auto &videoPlaySumMap = authorVideoPlaySumMap[authorName];
    size_t res = 0;
    size_t maxCount= 0;
    for(const auto &pair : videoPlaySumMap) {
        if(pair.second  >= maxCount) {
            res = pair.first;
            maxCount = pair.second;
        }
    }
    return res;
}


std::vector<MyPair> GetPopCreators(vector<string> creators, vector<size_t> ids, vector<size_t> views) {
    map<string, map<size_t, size_t>> authorVideoPlaySumMap;
    for(size_t i = 0; i < ids.size(); i++) {
        authorVideoPlaySumMap[creators[i]][ids[i]] = views[i];
    }

    map<string, size_t> authorPlaySumMap;
    for(const auto &pair: authorVideoPlaySumMap) {
        for(const auto &pair2: pair.second) {
            authorPlaySumMap[pair.first] += pair2.second;
        }
    }
    auto authorOfMaxValue = authorPlaySumMap.rbegin()->first;
    auto maxValue = authorPlaySumMap.rbegin()->second;
    std::vector<MyPair> res;
    for(auto it = authorPlaySumMap.rbegin(); it != authorPlaySumMap.rend() && it->second == maxValue; ++it) {
        res.emplace_back(MyPair{it->first, 0});
    }
    for(auto &item : res) {
        item.id = GetTopIdInAuthor(authorVideoPlaySumMap, item.name);
    }

    return res;

}

