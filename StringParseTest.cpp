#include <iostream>
std::string to_delimiter="TO:";
std::string from_delimiter="FROM:";
std::string message_delimiter="MESSAGE:";
std::string password_delimiter="PASS:";
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


int main(){
	std::string name, pass, test;

	std::cin>>name;
	std::cin>>pass;

	test="LOGIN="+name+star_delimiter+password_delimiter+pass;
	std::cout<<test<<std::endl;

	parsepass(test);
	parsename(test);

}
