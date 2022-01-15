#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

enum Badge { INFORMED, FANATIC, EPIC, SCHOLAR, TEACHER };
enum ContentType { QUESTION, ANSWER, COMMENT }; 
enum AccountStatus { ACTIVE, CLOSED, BLOCKED };

struct Address{
    string door_no;
    string city;
    string state;
    string country;
    string zipcode;
};

class Person
{
    public:
        string name;
        string mobile;
        string email;
        Address address;
};

struct DateTime
{
    public:
        uint8_t day;
        uint8_t month;
        uint16_t year;
        uint8_t hour;
        uint8_t min;
};

class Account
{
    public:
        uint64_t account_id;
        string username;
        string password;
        AccountStatus status;
        uint32_t reputation;
};

class Content
{
    public:
        uint64_t id;
        string creator_id;
        DateTime created_on;
        DateTime last_edited_on;
        vector<string> tags;
        bool flaged;
        uint32_t upvotes;
};

class Comment : public Content
{
    public:
        string comment;
        vector<Comment> comments;
};

class Answer : public Content
{
    public:
        bool is_accepted;
        string answer;
        vector<Comment> comments;
};

class Question : public Content
{
    public:
        uint32_t votes_for_delete;
        string question;
        vector<Answer> answers;
        vector<Comment> comments;
};

class Guest : public Person 
{
    public:
        uint64_t Id;
        vector<Question> SearchQuestion(string keyword);
        void ViewQuestion(Question question);
};


class Member : public Guest 
{
    public:
        Account account;
        vector<Badge> badges;

        bool PostQuestion(string content);
        bool AddAnswer(Question question, string content);
        bool VoteToDelete(Question question);
        bool AddComment(ContentType type, uint64_t id, string content);
        bool Upvote(ContentType type, uint64_t id);
        bool AddFlag(ContentType type, uint64_t id);
};

class Moderator : public Member 
{
    public:
        bool CloseQuestion(Question question);
        bool UnDeleteQuestion(Question question);
};

class Admin : public Member 
{
    public:
        bool BlockMember(Member member);
        bool UnBlockMember(Member member);
};

class StackOverflowService
{
    public:
        unordered_map <uint64_t, Question> active_questions;
        unordered_map <uint64_t, Question> closed_questions;
        vector<Member> members;
        vector<Moderator> moderators;
        vector<Admin> admins;
};
