#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

int main() {
    int serverSocket, clientSocket;
    sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize;

    char buffer[1024] = {0};

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Listen
    listen(serverSocket, 5);
    cout << "Server listening on port 8080...\n";

    addrSize = sizeof(clientAddr);
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);

    // Receive file name
    recv(clientSocket, buffer, sizeof(buffer), 0);
    string fileName(buffer);

    ifstream file(fileName);

    if (!file) {
        string errorMsg = "Error: File not found on server";
        send(clientSocket, errorMsg.c_str(), errorMsg.length(), 0);
    } else {
        string content;
        getline(file, content);
        send(clientSocket, content.c_str(), content.length(), 0);
        file.close();
    }

    close(clientSocket);
    close(serverSocket);

    return 0;
}
