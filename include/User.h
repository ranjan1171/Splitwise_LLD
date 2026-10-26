#pragma once 
#include <string>

class User{
    private:
    std::string userId;
    std::string name;
    
    public:
    User(const std::string& userId , const std::string&name);

    std::string getUserId() const ;
    std::string  getName() const ;



};