// atomic_flag as a spinning lock
#include<bits/stdc++.h>
#include <thread>
#include <atomic>         // std::atomic_flag
using namespace std;
#define MEMBAR __sync_synchronize()
atomic_flag lock_stream = ATOMIC_FLAG_INIT;

int test_and_set(int* L)
{
  int prev=*L;
  *L=1;
  return prev;
}
int __lock__=0;
void print(int n, const string &str)  {
  //while(test_and_set(&__lock__)==1){MEMBAR;}
  while (lock_stream.test_and_set()){}
  //CS
  string msg = to_string(n) + " : " + str;
  cout << msg  <<endl;
  lock_stream.clear();
  //__lock__=0;
}
int main() {
  vector<string> s = {
      "Educative.blog",
      "Educative",
      "courses",
      "are great"
  };
  vector<thread> threads;
  for (int i = 0; i < s.size(); i++) {
    threads.push_back(thread(print, i, s[i]));
  }
  for (auto &th : threads) {
    th.join();
  }
  return 0;
}