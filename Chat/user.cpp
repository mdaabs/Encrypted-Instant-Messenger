#include "user.h"



thisuser splitter(string line){
    thisuser splitUser;
    int i=0;
    int j=0;

    for(i=0;i<line.length();i++){
        if(line.at(i)==Delim){
        splitUser.username=line.substr(j,i);
        i++;
        j=i;
        break;

        }

    }
    splitUser.online=line.substr(j);

    return splitUser;


}


QStringList getusers(){

    QStringList friends;
    int num=0;

    string line;
    thisuser tempuser;
    thisuser allfriends[MAX];

    int countOn=0;

    string online[MAX];



    ifstream userfile;
    userfile.open("/home/george/Messenger/Chat/users.txt");
    if(userfile.is_open()){

        while(getline(userfile,line)){
            tempuser=splitter(line);
            allfriends[num]=tempuser;
            num++;

        }
    }
    userfile.close();

    for(int m=0;m<MAX;m++){
    if(allfriends[m].online=="t"){
        online[countOn]=allfriends[m].username;

        countOn++;
   }
    }

   for(int i=0;i<MAX;i++){
         QString temp= QString::fromStdString(online[i]);
        friends<<temp;
   }


 \
    return friends;


}
QStringList getOffline(){

    QStringList friends;
    int num=0;

    string line;
    thisuser tempuser;
    thisuser allfriends[MAX];


    int countOff=0;

     string offline[MAX];


    ifstream userfile;
    userfile.open("/home/george/Messenger/Chat/users.txt");
    if(userfile.is_open()){

        while(getline(userfile,line)){
            tempuser=splitter(line);
            allfriends[num]=tempuser;
            num++;

        }
    }
    userfile.close();

    for(int m=0;m<MAX;m++){
    if(allfriends[m].online=="t"){

   }
    else{
        offline[countOff]=allfriends[m].username;
        countOff++;
    }}

   for(int i=0;i<MAX;i++){
         QString temp= QString::fromStdString(offline[i]);
        friends<<temp;
   }


 \
    return friends;




}


