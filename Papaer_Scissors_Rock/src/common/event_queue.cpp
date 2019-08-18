#include "event_queue.h"
//#include "glog\logging.h"

namespace PUMA {
namespace Kernel {


EventQueue::EventQueue()
{
}

EventQueue::~EventQueue()
{
}

bool EventQueue::CheckEvents()
{
    lock_guard<mutex> guard(mMutex);
    return !mEvents.empty();
}

void EventQueue::PushMsg(shared_ptr<Message>& message)
{
    lock_guard<mutex> guard(mMutex);
    mEvents.push(message);
}

shared_ptr<Message> EventQueue::GetMsg()
{
    lock_guard<mutex> guard(mMutex);
    
    if (!mEvents.empty())
    {
        shared_ptr<Message> msg;
        msg = mEvents.front();
        mEvents.pop();
        return msg;
    }

    return shared_ptr<Message>(nullptr);
}

}  // namespace Kernel
}  // namespace PUMA