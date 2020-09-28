#include "Node.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace ds_course;
using namespace std;

vector<Node> finalNodeList;

int findHeadNode(int child, vector <ds_course::Node> nodeList) {
    int foundNTimes = 0;
    for (int i = 0; i < nodeList.size(); i++) {
        for (int j = 0; j < nodeList[i].children.size(); j++) {
            if (child == nodeList[i].children[j].getVal()) {
                return 0;
            }
        }
    }
    return 1;
}

void subTrees(int child, vector <ds_course::Node> nodeList) {
    for (int i = 0; i < nodeList.size(); i++) {
        for (int j = 0; j < nodeList[i].children.size(); j++) {
            if (nodeList[i].getVal() == child && nodeList[i].isInList == false) {
                nodeList[i].isInList = true;
                finalNodeList.push_back(nodeList[i]);
                for (int k = 0; k < nodeList[i].children.size(); k++) {
                    subTrees(nodeList[i].children[k].getVal(), nodeList);
                }
            }
        }
    }
    
}

int main() {
    /*ifstream inputFile("in.txt");*/
    string line;
    vector<Node> nodeList;
    /*if (inputFile.is_open())
    {*/
        while (getline(cin, line))
        {
            if (line[0] == '0')
            {
                break;
            }
            vector<int> numberList;
            istringstream treeline(line);
            int currentNode;
            while (treeline >> currentNode) 
            {
                numberList.push_back(currentNode);
            }
            Node myNode(numberList[0]);
            for (int i = 1; i < numberList.size(); i++) 
            {
                myNode.addChild(numberList[i]);
                
            }
            nodeList.push_back(myNode);
        }
    /*}*/
    /*else 
    {
        cout << "Unable to open the file! The input file name should be 'in.txt'! ";
        return 0;
    }*/

    for (int i = 0; i < nodeList.size(); i++)
    {
        nodeList[i].reflect();
        if (findHeadNode(nodeList[i].getVal(), nodeList) == 1) 
            finalNodeList.push_back(nodeList[i]);
    }

    for (int i = 0; i < finalNodeList[0].children.size(); i++)
        subTrees(finalNodeList[0].children[i].getVal(), nodeList);
    
    for (int i = 0; i < finalNodeList.size(); i++) 
        finalNodeList[i].printPreorder();

    cout << '0';
   /* inputFile.close();*/
}