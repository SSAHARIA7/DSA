#include <iostream>
#include <string>


class webPage{
    public:
    std::string name;
    webPage *next;
    webPage *prev;

    webPage(std::string n):name(n),next(nullptr),prev(nullptr){}
};






class Browser
{
    public:

    webPage* browsingHead;
    webPage *currentPage;
    Browser(std::string &homepage)
    {
        browsingHead = new webPage(homepage);
        currentPage = browsingHead;
        // Write you code here
    }

    void visit(std::string &url)
    {
        webPage *newPage = new webPage(url);
        currentPage->next = newPage;
        newPage->prev = currentPage;
        currentPage = newPage;
    }

    std::string back(int steps)
    {
        while(steps && currentPage != browsingHead){
            currentPage = currentPage->prev;
            steps--;
        }

        return currentPage->name;
    }

    std::string forward(int steps)
    {
        while(steps && currentPage->next != nullptr){
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->name;
    }
};