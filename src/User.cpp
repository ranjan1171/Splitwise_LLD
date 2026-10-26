#include"User.h"
#include <stdexcept>


User:: User(const std::string& userId , const std::string&name) :userId(userId) , name(name){

    if( this-> userId.empty() ||this->name.empty()){
        throw std::invalid_argument("UserID  or name cant   be null");

    }
}

std::string User::getUserId()  const {

    return userId;

}

std::string User::getName() const {
    return name;
}
