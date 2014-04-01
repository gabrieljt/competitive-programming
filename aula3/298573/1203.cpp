// Gabriel Trabasso - 298573
// ARGUS problem - UVa - 1203
// Solution #13428754 - 2014-04-01 17:59:03
// Compile with -std=c++11 flag

#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>

typedef std::pair<unsigned int, std::pair<unsigned int, unsigned int>> Query;
typedef std::priority_queue<Query, std::vector<Query>, std::greater<Query>> QueryPriorityQueue;

class ARGUS
{

public: 

    ARGUS(std::string register_cmd)
    : register_cmd(register_cmd)
    , query_buffer()
    {
    }

    const std::string register_cmd; 
    QueryPriorityQueue query_buffer;
};

int main()
{
    ARGUS sys("Register");
    std::string input;
    unsigned int id, period, K;

    while (std::cin >> input && input == sys.register_cmd)
    {
        scanf("%u %u", &id, &period);
        auto query_data = std::make_pair(id, period);
        Query query(period, query_data);
        sys.query_buffer.push(query);
    }
    scanf("%u", &K);    
    do
    {
        Query query = sys.query_buffer.top();
        sys.query_buffer.pop();

        printf("%u\n", query.second.first);

        query.first += query.second.second;
        sys.query_buffer.push(query);
    } while(--K);
    
    return 0;
}
