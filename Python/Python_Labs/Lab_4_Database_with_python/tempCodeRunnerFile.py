import re
import time
from datetime import datetime
from getpass import getpass
from user_Register import get_password,register
from creat_Project_Operations import create_project,edit_project,delete_project,search_project_by_date
from view_RegiserUsers_projects import view_projects
from validate_Input import validate_date
from user_Choice import user_Choice
def login():
    email = input("Enter Email for Login: ")
    password = get_password()

    with open("users_data.txt", "r") as file:
        Flag = False
        user_id = 0
        for line in file:
            user_data = line.strip().split(" : ")
            if user_data[7] == email and user_data[9] == password:
                Flag = True
                user_id = int(user_data[1])
                print(f"\nLogin successful...., {user_data[3]} {user_data[5]}")
                return user_id

        if not Flag:
            print("Login failed Invalid email or password")
            return None

if __name__ == "__main__":
    print("\nYou Have Account Before Or NOT ? (y/n) : ")
    ch = input("\nEnter your choice: (y/n) : ")
    if ch.lower()=='y':
        print("\nLogin TO Your Account ... \nPlease Enter Your Email and Password \n")
        user_id = login()
        user_Choice(user_id)
    else:
        print("\nYou Don't Have An Account You can Register.Do You Want To Creat New Account ? (y/n): ")
        ch = input("\nEnter your choice: (y/n) ")
        if ch.lower()=='y':
            register()
            print("\nDo You want to Login Now? (y/n)")
            ch = input("\nEnter your choice: (y/n) : ")
            if ch.lower()=='y':
                user_id=login()
                user_Choice(user_id)
            else:
                print("Thank you for your Registeration ....")    
        else:
            print("Thank Youuu ")                
