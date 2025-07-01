#include<bits/stdc++.h>
#include<chrono>
#include<thread>
typedef long long lli;
#define endl '\n'
#define tab '\t'
using namespace std;


class Timer
{
    public:
    Timer()
    {
        m_StartTimepoint=chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        stop();
    }
    void  stop()
    {
        auto m_endTimepoint=chrono::high_resolution_clock::now();
        chrono::duration<float> duration=m_endTimepoint-m_StartTimepoint;
        auto ms=duration.count()*1000.0f;
        cout<<"duration:"<<ms<<"ms"<<endl;
    }
    private:
    std::chrono::_V2::system_clock::time_point  m_StartTimepoint;
};


signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  {
    Timer timer;
  }


}