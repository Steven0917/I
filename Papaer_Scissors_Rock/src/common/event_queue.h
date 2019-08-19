#pragma once

#include <queue>
#include <mutex>
#include <memory>
#include <message.pb.h>

using namespace std;

namespace Game {
namespace PSR {

class EventQueue
{
public:
    EventQueue();
    ~EventQueue();

    bool CheckEvents();
    void PushMsg(shared_ptr<Message>& message);
    shared_ptr<Message> GetMsg();

protected:
    mutex mMutex;
    queue<shared_ptr<Message>> mEvents;
};

}  // namespace PSR
}  // namespace Game

