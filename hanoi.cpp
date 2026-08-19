#include <iostream>
#include <stack>
using namespace std;

struct State
{
    int n;
    char source, auxiliary, destination;
};

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    stack<State> st;

    st.push({n, 'A', 'B', 'C'});

    while (!st.empty())
    {
        State cur = st.top();
        st.pop();

        if (cur.n == 1)
        {
            cout << "Move disk 1 from "
                 << cur.source << " to "
                 << cur.destination << endl;
        }
        else
        {
            st.push({cur.n - 1, cur.auxiliary,
                     cur.source, cur.destination});

            st.push({1, cur.source,
                     cur.auxiliary, cur.destination});

            st.push({cur.n - 1, cur.source,
                     cur.destination, cur.auxiliary});
        }
    }

    return 0;
}