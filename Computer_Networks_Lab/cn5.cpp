// Traffic mangement by Leaky Bucket

#include <bits/stdc++.h>
using namespace std;

int main() {
    int bucketSize, outputRate;
    int n;

    cout << "Enter bucket size: ";
    cin >> bucketSize;

    cout << "Enter output rate (packets per time unit): ";
    cin >> outputRate;

    cout << "Enter number of incoming packets: ";
    cin >> n;

    vector<int> packets(n);

    cout << "Enter number of packets arriving at each time unit:\n";
    for (int i = 0; i < n; i++) {
        cin >> packets[i];
    }

    int bucket = 0;

    cout << "\nTime\tIncoming\tSent\tRemaining\tDropped\n";

    for (int time = 0; time < n; time++) {
        int incoming = packets[time];
        int dropped = 0;

        // Check overflow
        if (bucket + incoming > bucketSize) {
            dropped = (bucket + incoming) - bucketSize;
            incoming = bucketSize - bucket;
        }

        bucket += incoming;

        // Leak packets
        int sent = min(bucket, outputRate);
        bucket -= sent;

        cout << time + 1 << "\t"
             << packets[time] << "\t\t"
             << sent << "\t"
             << bucket << "\t\t"
             << dropped << "\n";
    }

    return 0;
}
