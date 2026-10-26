#include"Group.h"
#include<stdexcept>

Group::Group( const std::string& groupId , const std::string& name): groupId(groupId),name(name){

if( this->groupId.empty()|| this->name.empty()){
    throw std::invalid_argument("Group ID and name can`t  be empty");
}


}

//adding the  members to the group 

void Group::addMember(const User& user){
   const std::string userId= user.getUserId();

   auto result = members.emplace(userId, user);

   if(!result.second){
    throw std::invalid_argument("User is already a member of this group");
   }
}



bool Group::hasMember(const std::string&userId)const {

    return members.find(userId)!= members.end();
}


const User* Group::findMemberById(const std::string& userId)const{

  auto it = members.find(userId);
  if(it== members.end()){
    return nullptr;
  }

  return &it->second;

 
}


void Group::addExpenseId(const std::string&expenseId){

    if(expenseId.empty()){
        throw std::invalid_argument("Expense ID cannot be  empty");
    }

    for (const std::string& existingId:expenseIds){
        if(existingId==expenseId){
            throw std::invalid_argument("Expense ID already exist in group");

        }
    }
    expenseIds.push_back(expenseId);

}


const std::vector<std::string>& Group::getExpenseIds()const {

    return expenseIds;
}



std::string Group::getGroupId() const {
    return  groupId;
}


std::string Group::getName()const {
    return name;
}


int Group::getMemberCount() const {
    return static_cast<int>(members.size());
}
