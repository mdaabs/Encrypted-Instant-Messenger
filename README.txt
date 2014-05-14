Messenger Encryption 

Team 7:

George Bekandy
Mario Daaboul
Allen Friedman
Demitrious Jackson
Jonathan Nguyen
Nicole Cote

Project Agreement

COMPONENTS

Accounts
  -Create/access all user accounts with account information.
    Username
    Password
    History
    Friends
    IP

Read
  -Read user typed messages and send to Encryption.

Write
  -Display user typed messages after Decryption.

Connect
  -Connect users IP addresses to each other for messaging.

Encryption/Decryption
  -Encrypt or decrypt messages for secure messaging between users.
  -Will be using an existing library for this.

GUI Message Box
  -Contains message box for user’s conversation for display. 
  -Contains “Friends List” for users.
  -Contains “Text Box” for entering and editing message before pressing “send”.
  -Tabs for multiple conversations.

USER INPUT

  -User message that gets sent to other user.
  -Find Users.
  -Edit Friends.
  -View history.

INTERFACE

  -User opens messenger client, and signs in with his/her username and password:
    -If no internet access, error message is displayed
    -If username or password incorrect, error message is displayed. User can try to sign in again
    -If correct username and password, user is signed in
  -User is signed in:
    -Client will contact server to retrieve IP address from user’s computer to ping other users. 
     This will allow user’s computer to obtain a list of contacts that are online as well as update 
     his/her friend’s list to display that he/she is now online.
  -User selects a contact from friend’s list to send a message
  -User can sign out of messenger client:
    -Client will contact server to retrieve IP address from user’s computer to ping other users. 
     This will allow user’s computer to obtain a list of contacts that are online as well as 
     update his/her friend’s list to display that he/she is now offline.

GUI

  -Rectangular box:
    -Friend’s list to the left
    -To the right of friend’s list:
      Conversation box
      Text box: below conversation box, to write messages to show up in conversation box
    -Tabs to hold different conversations




