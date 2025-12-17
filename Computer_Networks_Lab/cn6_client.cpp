#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

int main() {
    int clientSocket;
    sockaddr_in serverAddr;
    char buffer[1024] = {0};

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;

    // Send file name
    send(clientSocket, fileName.c_str(), fileName.length(), 0);

    // Receive file content
    recv(clientSocket, buffer, sizeof(buffer), 0);

    cout << "\nServer Response:\n";
    cout << buffer << endl;

    close(clientSocket);
    return 0;
}
