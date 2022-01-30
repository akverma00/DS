#include <bits/stdc++.h>
#define ll int
using namespace std;
struct UserDetails
{
    map<string, vector<ll>> events;
    map<string, vector<bool>> TimeAvail;
};
struct EventDetails
{
    ll id;
    string date;
    ll start;
    ll duration;
    vector<string> userList;
};
vector<EventDetails> AllEvents;
map<string, UserDetails> RegUsers;
bool AddUser()
{
    string uname;
    cin >> uname;
    if (RegUsers.find(uname) != RegUsers.end())
        return 0;
    UserDetails temp;
    RegUsers[uname] = temp;
    return 1;
}
bool isSlotAvailable(string &uname, string &date, ll st, ll en)
{
    if (st < 0 || en > 1400 || RegUsers.find(uname) == RegUsers.end())
        return 0;
    auto &timeA = RegUsers[uname].TimeAvail;
    if (timeA.find(date) == timeA.end())
        return 1;
    auto &vecD = timeA[date];
    for (int i = st; i < en; i++)
    {
        if (vecD[i] == false)
            return 0;
    }
    return 1;
}
bool AddEvent()
{
    ll n, c = 0;
    EventDetails e1;
    cin >> e1.date >> e1.start >> e1.duration >> n;
    for (int i = 0; i < n; i++)
    {
        string stemp;
        cin >> stemp;
        e1.userList.push_back(stemp);
        if (isSlotAvailable(stemp, e1.date, e1.start, e1.start + e1.duration))
        {
            c++;
        }
    }
    if (c < n)
        return 0;
    e1.id = AllEvents.size();
    AllEvents.push_back(e1);
    for (auto &uname : e1.userList)
    {
        auto &timeA = RegUsers[uname].TimeAvail;
        if (timeA.find(e1.date) == timeA.end())
        {
            vector<bool> temp(1400, true);
            timeA[e1.date] = temp;
        }
        auto &vecD = timeA[e1.date];
        for (int i = 0; i < e1.duration; i++)
        {
            vecD[e1.start + i] = false;
        }
        RegUsers[uname].events[e1.date].push_back(e1.id);
    }
    return 1;
}
void ShowEvents()
{
    string date, uname;
    cin >> date >> uname;
    if (RegUsers.find(uname) == RegUsers.end() || RegUsers[uname].events[date].size() == 0)
    {
        cout << "none\n";
        return;
    }
    for (auto &id : RegUsers[uname].events[date])
    {
        cout << AllEvents[id].start << "-" << AllEvents[id].start + AllEvents[id].duration
             << " ";
        for (auto &usr : AllEvents[id].userList)
        {
            cout << usr << " ";
        }
        cout << "\n";
    }
    return;
}
void SuggestSlots()
{
    string date;
    ll n, stRange, enRange, dur, c;
    cin >> date >> stRange >> enRange >> dur >> n;
    vector<string> tempLst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempLst[i];
    }
    int found = -1;
    for (int i = stRange; i + dur <= enRange; i++)
    {
        c = 0;
        for (auto uname : tempLst)
        {
            if (isSlotAvailable(uname, date, i, i + dur))
                c++;
        }
        if (c == n)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        cout << "none\n";
        return;
    }
    cout << found << "\n";
    return;
}
int main()
{
    string choice;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> choice;
        if (choice == "add-user")
        {
            cout << (AddUser() ? "success\n" : "failure\n");
        }
        else if (choice == "create-event")
        {
            cout << (AddEvent() ? "success\n" : "failure\n");
        }
        else if (choice == "show-events")
        {
            ShowEvents();
        }
        else if (choice == "suggest-slot")
        {
            SuggestSlots();
        }
        else
        {
        }
    }
    return 0;
}
