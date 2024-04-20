#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;



//// 实现一个缓存，查询按照使用次数排序的top N
//// 要求查询效率高

/*
 * 思路：
 * 类似于LRU算法，在LRU算法中，算法的核心在于最新插入的数据能够得到更新，在于顺序性，所以使用队列的结构可以很好的解决问题，
 * 同时由于需要将插入的元素的从队列中取出、并放到队头，所以需要维护一个哈希表来加速队列中的元素的查找。
 *
 * 在“使用次数排序的top N”算法中，可以通过一个有序的map来按照使用次数对元素进行排序；但是当插入一个元素时，不知道它以前使用过几次，
 * 所以需要一个哈希表来记录该元素目前已经使用过的次数
 * */

template<class T>
struct TopNCache {
    explicit TopNCache(size_t N) {
        this->N = N;
    }
// 每次Add, data的使用次数+1
    void Add(T&& data) {

        if(hashMap.find(data) != hashMap.end()) {
            // 如果该元素不是第一次插入的话，在“按次数排序”的表里将该元素先删除掉，再插入
            std::unordered_set<T> &tSet = timesOrderMap[hashMap[data]];
            auto it = tSet.find(data);
            if(it != tSet.end()) {
                tSet.erase(it);
            }
        }
        ++hashMap[data];
        std::unordered_set<T> &tSet = timesOrderMap[hashMap[data]];
        tSet.insert(data);

    }
// 返回按次数排序的top N
    std::vector<T> Get() const {
        size_t i = 0;
        std::vector<T> res;
        for (auto it = timesOrderMap.rbegin(); it != timesOrderMap.rend() && i < N; ++it) {
            auto tmp = it->second;
            for(const auto &item: tmp) {
                ++i;
                res.emplace_back(item);
                if(i >= N) break;
            }
        }
        return res;
    }

private:
    std::unordered_map<T, int> hashMap;
    std::map<int, std::unordered_set<T>> timesOrderMap;
    size_t N{};

};


void TESTCASE(){
    TopNCache<int> cache(3);
    cache.Add(1);
    cache.Add(2);
    cache.Add(3);
    cache.Add(3);
    cache.Add(4);
    cache.Add(4);
    cache.Add(4);
    cache.Add(4);
    cache.Add(4);
    cache.Add(5);
    cache.Add(5);
    cache.Add(5);
    cache.Add(5);
    cache.Add(5);
    cache.Add(5);
    cache.Add(5);
    for(const auto &item: cache.Get()) {
        std::cout<<item;
    }
}


int main(){
    TESTCASE();

    return 0;
}

