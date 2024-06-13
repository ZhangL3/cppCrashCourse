#include <iostream>
#include <chrono>
#include <thread>

struct TimerClass
{
  TimerClass() {
    this->timeStamp = this->getTimeStamp();
  }

  ~TimerClass() {
    printf("TimerClass instance destroyed, live time: %d ms\n", this->getTimeStamp() - this->timeStamp);
  }

  int getTimeStamp()
  {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    return static_cast<int>(seconds.count());
  }

  void printTime()
  {
    printf("Timestamp: %d\n", this->timeStamp);
  }
  private: int timeStamp;
};

int main(int argc, char const *argv[])
{
  TimerClass timer{};
  timer.printTime();
  std::this_thread::sleep_for(std::chrono::seconds(2));

  return 0;
}
