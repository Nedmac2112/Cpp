#include <iostream>
#include <string>
#include <list>
using namespace std;

struct YouTubeChannel
{
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount)
    {
        Name = name;
        SubscribersCount = subscribersCount;
    }
    bool operator==(const YouTubeChannel &channel) const
    {
        return Name == channel.Name;
    }
};

ostream &operator<<(ostream &COUT, YouTubeChannel &ytChannel)
{
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
    return COUT;
}

struct MyCollection
{
    list<YouTubeChannel> myChannels;

    void operator+=(YouTubeChannel &channel)
    {
        myChannels.push_back(channel);
    }
    void operator-=(YouTubeChannel &channel)
    {
        myChannels.remove(channel);
    }
};

ostream &operator<<(ostream &COUT, MyCollection &myCollection)
{
    for (YouTubeChannel ytChannel : myCollection.myChannels)
        COUT << ytChannel << endl;
    return COUT;
}

int main()
{
    YouTubeChannel yt1 = YouTubeChannel("Camden's Coding Corner", 12000);
    YouTubeChannel yt2 = YouTubeChannel("My second channel", 3500);
    MyCollection myCollection;

    myCollection += yt1;
    cout << "Original channel: " << endl;
    cout << myCollection;

    myCollection += yt2;
    cout << "Channel added: " << endl;
    cout << myCollection;

    myCollection -= yt2;
    cout << "Channel removed: " << endl;
    cout << myCollection;

    cin.get();
}