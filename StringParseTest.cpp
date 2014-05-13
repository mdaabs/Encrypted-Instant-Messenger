#include <iostream>
std::string to_delimiter="TO:";
std::string from_delimiter="FROM:";
std::string message_delimiter="MESSAGE:";
std::string password_delimiter="PASS:";
std::string new_password_delimiter="NEWPASS:";
std::string star_delimiter="*";
std::string equal_delimiter="=";
void parsepass(std::string input){
	std::string password=input.substr(input.find(star_delimiter)+((password_delimiter.length())+star_delimiter.length()));
	//password=password.substr(password.find(password_delimiter)+(password_delimiter.length()));
	std::cout<<password<<std::endl;
}


void parsename(std::string input){
	std::string username=input.substr(input.find(equal_delimiter)+(equal_delimiter.length()));
	username=username.substr(0,username.find(star_delimiter));
	std::cout<<username<<std::endl;
}
void parseold(std::string input){
	std::string password=input.substr(input.find(password_delimiter)+(password_delimiter.length()));
	password=password.substr(0,password.find(star_delimiter));
	std::cout<<password<<std::endl;
}
void parsenew(std::string input){
	std::string password=input.substr(input.find(new_password_delimiter)+(new_password_delimiter.length()));
	//username=username.substr(0,username.find(star_delimiter));
	std::cout<<password<<std::endl;
}

int main(){
	std::string name, pass, test, test1, pass1;

	//std::cin>>name;
	//std::cin>>pass;

	//test="LOGIN="+name+star_delimiter+password_delimiter+pass;
	//std::cout<<test<<std::endl;

	//parsepass(test);
	//parsename(test);

	test1="CHANGEPASSWORD=username*PASS:password*NEWPASS:newpassword";
	std::cout<<test<<std::endl;
	parsename(test1);
	parseold(test1);
	parsenew(test1);

}
