#pragma once 
#include"User.h"

#include <string>
#include <vector>
#include<unordered_map>


class Group{
std::string groupId;
std::string name;

std::unordered_map<std::string,User> members;

std::vector<std::string > expenseIds;

public:

Group(const std::string& groupId , const std::string&name);

void addMember( const User& user);

bool hasMember(const std::string& userId) const ;

const User* findMemberById( const std::string&userId ) const ;


void addExpenseId(const std::string&expenseId);
 
const std::vector<std::string>&getExpenseIds() const ;


std::string getGroupId() const ;
std::string getName() const ;

int getMemberCount() const ;




};
